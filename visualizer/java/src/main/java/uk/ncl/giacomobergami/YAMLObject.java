package uk.ncl.giacomobergami;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class YAMLObject {
    public long id;
    public List<String> ell;
    public List<String> xi;
    public Map<String, String> properties;
    public Map<String, List<Content>> phi;

    public YAMLObject(long id, List<String> ell, List<String> xi, Map<String, String> properties, Map<String, List<Content>> phi) {
        this.id = id;
        this.ell = ell;
        this.xi = xi;
        this.properties = properties;
        this.phi = phi;
    }

    public YAMLObject() {
        id = 0;
        ell = new ArrayList<>();
        xi = new ArrayList<>();
        properties = new HashMap<>();
        phi = new HashMap<>();
    }

    public YAMLObject(PropertyGraph.Vertex x) {
        id = x.id;
        ell = x.labels;
        xi = x.xi;
        properties = x.properties;
        phi = new HashMap<>();
    }

    public String toString(ConvertingMap map) {
        StringBuilder b = new StringBuilder();
        b.append("id:").append(map.convert(id)).append("\n");

        b.append("ell:\n");
        ell.forEach(x->b.append(x.replace(".","<dot>")).append("\n"));
        b.append(".\n");

        b.append("xi:\n");
        xi.forEach(x->b.append(x.replace(".","<dot>")).append("\n"));
        b.append(".\n");

        b.append("properties:\n");
        properties.forEach((c,p)-> {
            b.append(JSONUtil.escape(c))
                    .append("\t")
                    .append(JSONUtil.escape(p))
                    .append("\n");
        });
        b.append(".\n");

        b.append("phi:\n");
        phi.forEach((c,p)-> {
            b.append(JSONUtil.escape(c)).append("\n");
            p.forEach(k-> {
                b.append("\t").append(k.weight).append("\t").append(map.convert(k.content)).append("\n");
            });
            b.append(";");
        });
        b.append(".\n\n");

        return b.toString();
    }

    public static class Content {
        public double weight;
        public long   content;

        public Content(double weight, long content) {
            this.weight = weight;
            this.content = content;
        }

        public Content() {
            weight = 1.0;
            content = 1;
        }
    }
}
