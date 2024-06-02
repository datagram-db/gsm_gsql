package uk.ncl.giacomobergami;

import java.util.HashMap;

public class ConvertingMap {

    private HashMap<Long, Long> map = new HashMap<>();


    public Long convert(long id) {
        Long object = map.get(id);
        if (object != null)
            return object;
        else {
            object = (long)map.size();
            map.put(id, object);
            return object;
        }
    }

}
