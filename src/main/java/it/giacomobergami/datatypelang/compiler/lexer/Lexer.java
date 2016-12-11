package it.giacomobergami.datatypelang.compiler.lexer;

import it.giacomobergami.datatypelang.compiler.parser.cp.Terminal;
import it.giacomobergami.datatypelang.utils.Streams;
import it.giacomobergami.datatypelang.utils.regex.Match;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.function.Function;
import java.util.regex.Pattern;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Lexer<T extends Enum> {

    private final Class<T> enumClazz;
    public Lexer(Class<T> enumClazz) {
        this.enumClazz = enumClazz;
    }

    public Stream<Token<T>> lex(String input) {
        // The tokens to return
        ArrayList<Token<T>> tokens = new ArrayList<>();

        Pattern tokenPatterns = Pattern.compile(Streams.toStream(enumClazz.getEnumConstants()).map(
                x-> String.format("(?<%s>%s)", x.name(), x.toString())
        ).collect(Collectors.joining("|")));

        return Streams.toStream(Match.patterns(tokenPatterns).with(input)).map(matcher -> {
            for (T tokenType : enumClazz.getEnumConstants()) {
                String match = matcher.fromGroupsGet(tokenType.name());
                if (match!=null) {
                    return new Token<T>(tokenType,match);
                }
            }
            return new Token<T>();
        }).filter(Token::isNotEmpty);
    }

    public Stream<Terminal<T>> terminals(String input) {
        return lex(input).map(Terminal::new);
    }

    public Iterator<Terminal<T>> terminalIterator(String input) {
        return lex(input).map(Terminal::new).iterator();
    }


}
