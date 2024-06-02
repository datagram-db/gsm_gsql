package uk.ncl.giacomobergami;

import edu.stanford.nlp.semgraph.SemanticGraphEdge;

import java.util.Optional;
import java.util.function.Function;

/**
 * Created by vasistas on 14/08/16.
 */
public class GetEdgeType implements Function<SemanticGraphEdge, UniversalDependenciesEdgeTypes> {
    @Override
    public UniversalDependenciesEdgeTypes apply(SemanticGraphEdge toGetType) {
        String shortName = toGetType.getRelation().getShortName();
        Optional<UniversalDependenciesEdgeTypes> t = UniversalDependenciesEdgeTypes.fromString(shortName);
        if (t.isPresent())
            return t.get();
        else {
            String[] ar = shortName.split(":");
            if (ar.length==2) {
                shortName = ar[0];
            }
            var x = UniversalDependenciesEdgeTypes.fromString(shortName);
            if (x.isPresent())
                return x.get();
            else
                return UniversalDependenciesEdgeTypes.none;
        }
    }

    private GetEdgeType() {}
    private static GetEdgeType self = null;
    public static GetEdgeType getInstance() {
        if (self==null) self = new GetEdgeType();
        return self;
    }

}
