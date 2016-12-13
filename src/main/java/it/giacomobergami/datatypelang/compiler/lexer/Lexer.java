package it.giacomobergami.datatypelang.compiler.lexer;

import it.giacomobergami.datatypelang.compiler.parser.grammar.input.OnInput;
import it.giacomobergami.datatypelang.compiler.parser.grammar.terms.Varepsilon;
import it.giacomobergami.datatypelang.compiler.parser.grammar.stack.Token;
import it.giacomobergami.datatypelang.utils.Streams;
import it.giacomobergami.datatypelang.utils.regex.Match;

import java.util.ArrayList;
import java.util.regex.Pattern;
import java.util.stream.Collectors;

public class Lexer<T extends Enum> {

    private final Class<T> enumClazz;
    public Lexer(Class<T> enumClazz) {
        this.enumClazz = enumClazz;
    }

    public TerminalIterator<T> lex(String input) {
        // The tokens to return
        ArrayList<Token<T>> tokens = new ArrayList<>();

        Pattern tokenPatterns = Pattern.compile(Streams.toStream(enumClazz.getEnumConstants()).map(
                x-> String.format("(?<%s>%s)", x.name(), x.toString())
        ).collect(Collectors.joining("|")));

        return new TerminalIterator<T>(Streams.toStream(Match.patterns(tokenPatterns).with(input)).map(matcher -> {
            for (T tokenType : enumClazz.getEnumConstants()) {
                String match = matcher.fromGroupsGet(tokenType.name());
                if (match!=null) {
                    return new Token<T>(tokenType,match);
                }
            }
            return new Varepsilon<T>();
        }).filter(OnInput::nonEmpty));
    }


}
