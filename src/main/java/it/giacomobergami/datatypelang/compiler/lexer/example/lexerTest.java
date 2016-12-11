package it.giacomobergami.datatypelang.compiler.lexer.example;

import it.giacomobergami.datatypelang.compiler.lexer.Lexer;

/**
 * Created by vasistas on 11/12/16.
 */
public class lexerTest {

    public static void main(String[] args) {
        new Lexer<>(TokenType.class).lex("11 + 22 - 33").forEach(System.out::println);
    }

}
