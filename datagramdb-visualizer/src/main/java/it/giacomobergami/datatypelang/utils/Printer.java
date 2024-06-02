package it.giacomobergami.datatypelang.utils;

/**
 * Created by vasistas on 11/12/16.
 */
public class Printer {
    public static void Registering(String toRegister, int fromPos) {
        System.err.println("Trailing the string at position "+ fromPos+", that is ["+toRegister.substring(fromPos,fromPos+3)+"...]");
    }
    public static void Registering(String toRegister, int fromPos, int toPos) {

        try {
            System.err.println("Trailing the string at position " + fromPos + ", that is [" + toRegister.substring(fromPos, toPos).trim() + "...]");
        } catch (Exception e) {
            System.err.flush();
            System.err.println(toRegister);
            System.exit(1);
        }

    }
    public static void Registering(String toRegister, int fromPos, int toPos, boolean got) {
        System.err.println("Finally got the string at position "+ fromPos+", that is ["+toRegister.substring(fromPos,toPos)+"]");
    }

}
