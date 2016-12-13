package it.giacomobergami.datatypelang.representation.compiler;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.type.MapType;
import com.fasterxml.jackson.databind.type.TypeFactory;
import it.giacomobergami.datatypelang.utils.ForFiles;
import it.giacomobergami.datatypelang.representation.NativeType;
import it.giacomobergami.datatypelang.representation.Type;
import it.giacomobergami.datatypelang.representation.TypeEnvironment;
import it.giacomobergami.datatypelang.representation.compiler.metacommands.MetaCommandInit;
import it.giacomobergami.datatypelang.representation.compiler.metacommands.MetaCommandType;
import it.giacomobergami.datatypelang.representation.compiler.metacommands.MetaEnv;
import it.giacomobergami.datatypelang.representation.compiler.metacommands.Statement;
import it.giacomobergami.datatypelang.utils.Streams;
import it.giacomobergami.datatypelang.utils.regex.GroupMatcher;
import it.giacomobergami.datatypelang.utils.regex.Match;
import it.giacomobergami.datatypelang.utils.regex.NotPresentException;
import it.giacomobergami.datatypelang.utils.funcs.Accum;
import it.giacomobergami.datatypelang.utils.empties.EIl;
import it.giacomobergami.datatypelang.utils.funcs.OnExcpt;
import it.giacomobergami.datatypelang.utils.funcs.ToStream;
import it.giacomobergami.datatypelang.utils.data.Pair;

import java.io.File;
import java.io.IOException;
import java.util.*;
import java.util.function.Predicate;
import java.util.stream.Stream;

/**
 * Created by vasistas on 05/12/16.
 */
public class Filler {
    public final HashMap<String,String> file_to_content;
    ObjectMapper mapper;
    TypeFactory typeFactory;
    MapType mapType;
    public final TypeEnvironment env;

    //Meta-Space
    //public boolean inMeta;
    public HashMap<String,MetaCommandInit> metaData;

    /**
     * Prepares the compiler for a specific target language in path @param s
     * @param s
     */
    public Filler(String s) {
        //inMeta = false;
        metaData = null;
        file_to_content = new HashMap<>();
        File folder = new File(s);
        File[] listOfFiles = folder.listFiles();
        env = new TypeEnvironment();

        mapper = new ObjectMapper();
        typeFactory = mapper.getTypeFactory();
        mapType = typeFactory.constructMapType(HashMap.class, String.class, JSONElem.class);
        for (File fi : listOfFiles) {
            if (fi.isFile()) {
                String name = fi.getName();
                if (name.endsWith(".spe")) {
                    file_to_content.put(fi.getName().replace(".spe", ""), ForFiles.toString(fi));
                } else if (name.equals("native.json")) {
                    try {
                        HashMap<String, JSONElem> map = mapper.readValue(new File(fi.getAbsolutePath()), mapType);
                        map.forEach(env::declareEnvType);
                    } catch (IOException e) { }
                }
            }
        }
    }

    /**
     * Replaces the custom types with the types declared in th
     * @param value
     * @return
     */
    private String nativeReplace(String value) {
        String toret = value;
        for (GroupMatcher m : Match.regex("native\\(([^\\)]+)\\)").allWith(value)) {
            String val = m.getAllGroup().replace("native(", "").replace(")", "");
            String original = val;
            try {
                final String ftoret = toret;
                // Checking if the type has some type arguments
                toret = Match.regex("<([^>]+)>").with(original).ifPresentAtLeastOnce()
                        .ifte(
                                //If if the regex matches, it means that I have to translate both types
                                match -> {
                                    String val2 = match.getAllGroup();
                                    val2 = val2.substring(val2.indexOf('<') + 1, val2.indexOf('>'));
                                    NativeType t = ((NativeType) env.get(original.substring(0, original.indexOf('<'))));
                                    return ftoret.replace("native(" + original + ")", t.getNativeTypeName().replace("@@", ((NativeType)env.get(val2)).getNativeTypeName()));
                                },

                                //Otherwise, I only have to translate the original one
                                () -> ftoret.replace("native(" + original + ")", ((NativeType) env.get(original)).getNativeTypeName())
                        );

            } catch (Exception e) {
                //Get all the other possible errors
                e.printStackTrace();
                System.err.println("Warning: native type " + original + " not found. Check your .json file");
                return original;
            }
        }
        return toret;
    }

    private String replaceFromFile(String key, Object attributes) {
        String value = file_to_content.get(key);
        String toret = new String(value);

        toret = ToStream.from(Match.regex("@@([^@])+@@").allWith(value)).collect(new Accum<GroupMatcher,String>(toret) {
            @Override
            public String apply(Pair<GroupMatcher, String> p) {
                GroupMatcher x = p.getKey();
                String toret = p.getValue();

                String val = x.getAllGroup().replace("@@", "");
                String original = val;
                String args[] = new String[]{};
                boolean doAll = false;
                boolean isCond = false;

                // Matching (…) arguments
                try (GroupMatcher m = Match.regex("\\((.)+\\)").with(val).ifFirstPresent()) {
                    String arg = m.getAllGroup();
                    arg = arg.substring(arg.indexOf('(')+1,arg.indexOf(')'));
                    args = arg.split(",");
                    val = val.substring(0,val.indexOf('('));
                } catch (NotPresentException e) { }

                // Matching […] arguments
                String mask = val;
                try (GroupMatcher m = Match.regex("\\[(.)+\\]").with(val).ifFirstPresent()) {
                    String arg = m.getAllGroup();
                    mask = arg.substring(arg.indexOf('[')+1,arg.indexOf(']'));
                    val = val.substring(0,val.indexOf('['));
                } catch (NotPresentException e) { }

                // Check if is a boolean
                if (val.endsWith("?")) {
                    isCond = true;
                    val = val.substring(0,val.indexOf('?'));
                }

                if (!val.endsWith("s")) {
                    toret = toret.replace("@@"+val+"@@",choice(mask,attributes));
                } else {
                    Iterable it = (Iterable)new OnExcpt<>(val).as(
                            y-> (Iterable)attributes.getClass().getField(y).get(attributes),
                            y -> new EIl<>()
                    );
                    String toCatch = mask.equals(val) ? val.substring(0,val.length()-1) : mask;
                    StringBuilder sb = new StringBuilder();
                    final String arguments[] = args;

                    Predicate<Object> toSelect =
                            o -> {
                                if (arguments.length == 0) return true;
                                for (String arg : arguments) {
                                    try {
                                        boolean negated = false;
                                        if (arg.startsWith("!")) {
                                            arg = arg.replaceFirst("\\!", "");
                                            negated = true;
                                        }
                                        Object ret = o.getClass().getField(arg).get(o);
                                        if (ret == null) return false;
                                        else {
                                            try {
                                                Boolean bol = (Boolean) ret;
                                                if (bol == negated) return false;
                                            } catch (Exception e) {
                                                return false;
                                            }
                                        }
                                    } catch (Exception e) {
                                        return false;
                                    }
                                }
                                return true;
                            };
                    Stream<Object> stream = Streams.toStream(it.iterator());
                    if (isCond) {
                        if (stream.anyMatch(toSelect)) {
                            sb.append(choice(toCatch,attributes));
                        }
                    } else {
                        stream.filter(toSelect).forEach(y -> sb.append(choice(toCatch,y)));
                    }
                    toret = toret.replace("@@"+original+"@@",sb.toString());
                }

                return toret;
            }
        });
        return toret;
    }

    /**
     * Expands the macros within the .spe files
     * @param key
     * @param attributes
     * @return
     */
    private String choice(String key, Object attributes) {
        if (file_to_content.containsKey(key)) {
            // A file contains the desired macro informations
            return replaceFromFile(key,attributes);
        } else {
            // Otherwise, resolve the informations
            return new OnExcpt<Pair<String,Object>,String>(new Pair<>(key,attributes)).as(
                    //Checks if the TypeEnvironment has the desired type
                    z -> env.get(z.getKey()).getTypeName(),

                    // If not, check if the passed object stores the desired information
                    p2 -> new OnExcpt<Pair<String,Object>,String>(p2).as(
                            z -> attributes.getClass().getField(z.getKey()).get(z.getValue()).toString(),

                            // If not, check as a last chance if the metadata map has the informations. If not, then return the empty string as a default asTableColumnValue
                            z -> metaData == null ? "" : metaData.getOrDefault(z.getKey(),new MetaCommandInit(MetaCommandType.SingleVariable,"")).value
                    ));
        }
    }



    public static class Mutable<T> {
        public Mutable(T val) {
            this.val = val;
        }
        public T val;
    }

    public static String commandWithContext(Mutable<String> command) {
        if (command.val.trim().contains(" context=")) {
            String arrayo[] = command.val.trim().split(" context");
            command.val = arrayo[0].trim();
            return arrayo[1].substring(1);
        }
        else return null;
    }


    public void matchMeta(Mutable<String> mutable,Object objToCompile,MetaEnv contextVarName) {
        try {
            mutable.val = mutable.val.replaceAll("\\!\\!context\\!\\!", contextVarName.contextVarName);
        } catch (Exception e) {
            System.err.println(contextVarName.contextVarName);
            System.exit(1);
        }
        String toret = mutable.val;
        for (GroupMatcher m : Match.regex("\\!\\!([^\\!]+)\\!\\!").allWith(mutable.val)) {
            String elem = m.fromGroupsGet(1);
            if (file_to_content.containsKey(elem)) {
                toret = toret.replace("!!"+elem+"!!",file_to_content.get(elem));
            } else {
                if (elem.contains("_")) {
                    String[] typesWithCommand = elem.split("_");
                    String type = (env.get(typesWithCommand[0]).isMutable() ? "mutable" : "fixed");
                    String command = typesWithCommand[1];
                    String tryWith = type+"_"+command;
                    String ret = compile(tryWith,objToCompile,contextVarName.pass());
                    toret = toret.replace("!!"+elem+"!!",ret);
                }
            }

        }
        mutable.val = toret;
    }

    public String compile(String arg,Object obj) {
        return compile(arg,obj,new MetaEnv());
    }

    public String compile(String arg, Object obj, MetaEnv menv) {

        //Prehistoric basic working
        String tmp =  nativeReplace(choice(arg,obj));

        //System.err.println(tmp);

        //Now for some meta-expansion
        //Obtaining the annotations of the native types that have to be used at the meta level
        boolean prevInMeta = menv.inMeta;
        menv.inMeta = true;

        String context = menv.contextVarName;

        Match.regex("//\\^([^\\^]+) : ([^\\^]+)\\^").with(tmp).forEachRemaining(
                x -> menv.var_to_type.put(x.fromGroupsGet(1),x.fromGroupsGet(2))
        );
        //tmp = tmp.replaceAll(regex,"");

        //Expanding the !(...)! syntax

        while (tmp.contains("!(") && tmp.contains(")!")) {
            Deque<Integer> stack = new ArrayDeque<>();
            stack.push(tmp.indexOf("!(")+2);
            while (!stack.isEmpty()) {
                int pos = stack.peek();
                int newColl, newClose;
                boolean right = true;

                //Getting the most inner parenthesis for matching purposes
                while ((newColl = tmp.indexOf("!(",pos))<(newClose = tmp.indexOf(")!",pos)) && newColl>0) {
                    right = false;
                    stack.push(newColl+2);
                    pos = newColl+2;
                }

                if (right) stack.pop();

                //For the most inner, getting the most outer
                while (!stack.isEmpty()) {
                    newClose = tmp.indexOf(")!",newClose)+2;
                    pos = stack.pop();
                }
                //Printer.Registering(tmp, pos, newClose);
                if (!right) newClose -= 2;

                String toOp = tmp.substring(pos,newClose);
                String result = "";
                Mutable<String> mutOp;
                boolean multi = toOp.contains(",");

                if (multi) {
                    mutOp = new Mutable<>(toOp.substring(0,toOp.indexOf(',')));
                    toOp = toOp.substring(toOp.indexOf(',')+1);
                    metaData = parseToOp(toOp, menv.pass());
                } else {
                     mutOp = new Mutable<>(toOp);
                }

                context = commandWithContext(mutOp);
                Object objToCompile = obj;
                if (context!=null) objToCompile = this.env.get(menv.var_to_type.get(context));

                Mutable<String> s = new Mutable<>(compile(mutOp.val,objToCompile,menv.pass(context).pass(false)));
                matchMeta(s,objToCompile,menv.pass(context));
                result = s.val;

                if (multi) {
                    for (Map.Entry<String,MetaCommandInit> x : metaData.entrySet()) {
                        result = result.replace("!!"+x.getKey()+"!!",x.getValue().value);
                    }
                    metaData = null;
                }


                StringBuffer sb = new StringBuffer(tmp);
                tmp = sb.replace(pos-2,newClose+2,result).toString();
            }
        }
        menv.inMeta = prevInMeta;

        if (menv.inMeta && tmp.contains("!!")) {
            Mutable<String> meta = new Mutable<>(tmp);
            if (menv.contextVarName==null) {
                menv.contextVarName = context;
            }
            matchMeta(meta,obj,menv);
            tmp = meta.val;
        }
        return tmp;
    }

    private HashMap<String,MetaCommandInit> parseToOp(String toOp,MetaEnv me) {
        HashMap<String,MetaCommandInit> toret = new HashMap<>();
        String sArr[] = toOp.split("statement\\{");
        String statement = null;
        if (sArr.length>1) {
            toOp = sArr[0];
            statement = sArr[1].trim();
            statement = statement.substring(0,statement.length()-1);
        }
        while (toOp.contains("=")) {
            String key = toOp.substring(0,toOp.indexOf('=')).trim();
            toOp = toOp.substring(toOp.indexOf('=')+1);
            toOp = toOp.trim();
            String value = "";
                int idx = toOp.indexOf(',');
                if (idx>0) {
                    value = toOp.substring(0,toOp.indexOf(','));
                    toOp = toOp.substring(toOp.indexOf(',')+1);
                } else {
                    value = toOp;
                }
                value = value.trim();
            toret.put(key,new MetaCommandInit(MetaCommandType.SingleVariable,value));
        }
        if (statement!=null) {
            toret.put("statement",new MetaCommandInit( MetaCommandType.CodeExpansion,compile("statement",new Statement(statement),me.pass(true))));
        }
        return toret;
    }


    public static void main(String[] args) {
        // Load the C++ configurations for compiling to C++ types
        Filler f = new Filler("cpp/");

        //User custom types declaration
        f.env.declareRecord("genoveffo").addField("ciao","string").addField("id","int").addFieldOfInternalArray("afield",f.env.get("string")).close();
        Type geno = f.env.get("genoveffo");
        //System.out.println(f.compile("secondary",geno));
        //System.out.println(f.compile("primary",geno));

        //Pass the internal type of the array
        System.out.println(f.compile("serialize_vector(mutable)",f.env.get("string")));



        /*

        record <name> =
            <field_type> <field_name>
            ..
        using [<compile> ]+
        */

    }

}
