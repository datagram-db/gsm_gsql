package it.giacomobergami.datatypelang.language.interpreter.metacommands;

import java.util.HashMap;

/**
 * Created by vasistas on 10/12/16.
 */
public class MetaEnv {
    public MetaEnv() {
        this.var_to_type = new HashMap<>();
        contextVarName = null;
        this.inMeta = false;
    }

    public MetaEnv(HashMap<String, String> var_to_type) {
        this.var_to_type = new HashMap<>();
        this.var_to_type.putAll(var_to_type);
        contextVarName = null;
        inMeta = false;
    }

    public MetaEnv(HashMap<String, String> var_to_type, String varname) {
        this.var_to_type = new HashMap<>();
        this.var_to_type.putAll(var_to_type);
        this.inMeta = false;
        contextVarName = varname;
    }

    public MetaEnv(HashMap<String, String> var_to_type, String varname, boolean isInMeta) {
        this.var_to_type = new HashMap<>();
        this.var_to_type.putAll(var_to_type);
        contextVarName = varname;
        this.inMeta = isInMeta;
    }

    public MetaEnv(boolean b) {
        this.var_to_type = new HashMap<>();
        contextVarName = null;
        this.inMeta = b;
    }

    public MetaEnv pass(boolean inMeta) {
        return new MetaEnv(var_to_type, contextVarName, inMeta);
    }

    public MetaEnv pass() {
        return new MetaEnv(var_to_type, contextVarName, inMeta);
    }

    public MetaEnv pass(String newVarName) {
        return new MetaEnv(var_to_type, newVarName, inMeta);
    }

    public HashMap<String, String> var_to_type;
    public String contextVarName;
    public boolean inMeta;
}
