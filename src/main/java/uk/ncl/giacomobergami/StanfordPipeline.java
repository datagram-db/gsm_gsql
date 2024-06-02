package uk.ncl.giacomobergami;

import edu.stanford.nlp.pipeline.Annotation;
import edu.stanford.nlp.pipeline.CoreDocument;
import edu.stanford.nlp.pipeline.StanfordCoreNLP;

import java.util.Properties;

public class StanfordPipeline {

    public final static StanfordPipeline self = new StanfordPipeline();
    private StanfordCoreNLP pipeline;
    private StanfordPipeline() {
        // creates a StanfordCoreNLP object, with POS tagging, lemmatization, NER, parsing, and coreference resolution
        Properties props = new Properties();
        props.put("annotators", "tokenize, ssplit, pos, lemma, ner, parse, dcoref");
        props.setProperty("ner.docdate.usePresent", "true");
        props.setProperty("sutime.includeRange", "true");
        props.setProperty("sutime.markTimeRanges", "true");
        pipeline = new StanfordCoreNLP(props);
    }

    public static Annotation annotate(String annotation) {
        Annotation toret = new Annotation(annotation);
        self.pipeline.annotate(toret);
        return toret;
    }

    public static CoreDocument timeAnnotate(String example) {
        CoreDocument document = new CoreDocument(example);
        self.pipeline.annotate(document);
        return document;
    }

}
