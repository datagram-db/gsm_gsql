package uk.jackbergus.gsm;

import com.google.common.collect.HashMultimap;

import java.io.Serializable;
import java.lang.reflect.Field;
import java.util.*;
import java.util.function.BiConsumer;
import java.util.stream.Collectors;

public class GSMUtil {

    /**
     * This utility class helps in representing any Java object into a GSM object. This allows to represent in this format
     * any possible Java object
     * @param object        Actual object to represent as a GSM object
     * @return              Object representation according to the GSM model
     * @throws IllegalAccessException
     */
    public static  GSMObject fromObject(Object object) throws IllegalAccessException {
        GSMObject obj = new GSMObject();
//
        List<Phi> content = new ArrayList<>();
        var clazz = object.getClass();
        obj.setEll(List.of(clazz.getCanonicalName()));
        HashMultimap<String, String> phiForSerialise = HashMultimap.create();
        for (Field f : clazz.getDeclaredFields()) {
            f.setAccessible(true);
            String fieldName = f.getName();
            Object fromField = f.get(object);
            if (fromField != null) {
                if (fromField instanceof String) {
                    phiForSerialise.put(fieldName, fromField.toString());
                } else if (f.getType().isPrimitive()) {
                    phiForSerialise.put(fieldName, String.valueOf(fromField));
                } else if (fromField instanceof Collection<?>) {
                    for (Object x : (Collection<?>)fromField) {
                        if (x == null) continue;
                        if (x instanceof String) {
                            phiForSerialise.put(fieldName, x.toString());
                        } else if (x.getClass().isPrimitive()) {
                            phiForSerialise.put(fieldName, String.valueOf(x));
                        } else {
                            Phi p = new Phi();
                            p.setContent(System.identityHashCode(x));
                            p.setScore(1.0);
                            p.setContainment(fieldName);
                            content.add(p);
                        }
                    }
                } else {
                    Phi p = new Phi();
                    p.setContent(System.identityHashCode(fromField));
                    p.setScore(1.0);
                    p.setContainment(fieldName);
                    content.add(p);
                }
            }
        }
        obj.setPhi(content);
        Map<String, String> m = new HashMap<>();
        phiForSerialise.asMap().forEach((s, strings) -> {
            if (strings.size() > 1)
                m.put(s, strings.stream().collect(Collectors.joining(",", "[", "]")));
            else if (strings.size() == 1)
                m.put(s, strings.iterator().next());
        });
        obj.setProperties(m);
        if (object instanceof Serializable) {
            obj.setXi(List.of(object.toString()));
        }
        obj.setId(System.identityHashCode(object));
        return obj;
    }

}
