package it.giacomobergami.datatypelang.compiler.parser.cp;

/**
 * Created by vasistas on 11/12/16.
 */
public class CPNull implements CP {
    @Override
    public boolean isTerminal() {
        return false;
    }

    @Override
    public boolean isNull() {
        return true;
    }
}
