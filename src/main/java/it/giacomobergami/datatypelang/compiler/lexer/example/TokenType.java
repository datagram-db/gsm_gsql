package it.giacomobergami.datatypelang.compiler.lexer.example;

public enum TokenType {
        // Token types cannot have underscores
        NUMBER("-?[0-9]+"), BINARYOP("[*|/|+|-]"), WHITESPACE("[ \t\f\r\n]+");

        public final String pattern;

        @Override
        public String toString() {
            return pattern;
        }

        TokenType(String pattern) {
            this.pattern = pattern;
        }
}