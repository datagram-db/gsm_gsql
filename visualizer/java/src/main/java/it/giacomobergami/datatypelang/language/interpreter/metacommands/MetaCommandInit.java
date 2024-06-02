package it.giacomobergami.datatypelang.language.interpreter.metacommands;

/**
 * Created by vasistas on 10/12/16.
 */
public class MetaCommandInit {
    public MetaCommandInit(MetaCommandType t, String value) {
        this.t = t;
        this.value = value;
    }

    public final MetaCommandType t;
    public final String value;
}
