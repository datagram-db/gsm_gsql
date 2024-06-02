import java.io.Serializable;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Map;
import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.fasterxml.jackson.annotation.JsonPropertyDescription;
import com.fasterxml.jackson.annotation.JsonPropertyOrder;


/**
 * Generated with https://www.jsonschema2pojo.org/
 * Command: './bin/jsonschema2pojo --source GSM.schema.json -t .'
 * GSM Specification
 * <p>
 * This document describes the JSON linearization of the GSM model
 * 
 */
@JsonInclude(JsonInclude.Include.NON_NULL)
@JsonPropertyOrder({
    "id",
    "scores",
    "ell",
    "xi",
    "properties",
    "phi"
})
public class TestSchema implements Serializable, Cloneable
{

    /**
     * A unique identifier for an GSM object
     * (Required)
     * 
     */
    @JsonProperty("id")
    @JsonPropertyDescription("A unique identifier for an GSM object")
    private Integer id;
    /**
     * list of confidence scores associated to the object
     * (Required)
     * 
     */
    @JsonProperty("scores")
    @JsonPropertyDescription("list of confidence scores associated to the object")
    private List<Double> scores = new ArrayList<Double>(Arrays.asList(1.0D));
    /**
     * list of labels/types associated to the object
     * (Required)
     * 
     */
    @JsonProperty("ell")
    @JsonPropertyDescription("list of labels/types associated to the object")
    private List<java.lang.String> ell = new ArrayList<java.lang.String>();
    /**
     * list of string-based values associated to the object
     * (Required)
     * 
     */
    @JsonProperty("xi")
    @JsonPropertyDescription("list of string-based values associated to the object")
    private List<java.lang.String> xi = new ArrayList<java.lang.String>();
    /**
     * Map<String,String>
     * <p>
     * key-value representation associated to each object
     * (Required)
     * 
     */
    @JsonProperty("properties")
    @JsonPropertyDescription("key-value representation associated to each object")
    private Map<String, String> properties;
    /**
     * Map<String,List<Content>>
     * <p>
     * associating a content label to some content
     * (Required)
     * 
     */
    @JsonProperty("phi")
    @JsonPropertyDescription("associating a content label to some content")
    private List<Phi> phi = new ArrayList<Phi>();

    /**
     * A unique identifier for an GSM object
     * (Required)
     * 
     */
    @JsonProperty("id")
    public Integer getId() {
        return id;
    }

    /**
     * A unique identifier for an GSM object
     * (Required)
     * 
     */
    @JsonProperty("id")
    public void setId(Integer id) {
        this.id = id;
    }

    /**
     * list of confidence scores associated to the object
     * (Required)
     * 
     */
    @JsonProperty("scores")
    public List<Double> getScores() {
        return scores;
    }

    /**
     * list of confidence scores associated to the object
     * (Required)
     * 
     */
    @JsonProperty("scores")
    public void setScores(List<Double> scores) {
        this.scores = scores;
    }

    /**
     * list of labels/types associated to the object
     * (Required)
     * 
     */
    @JsonProperty("ell")
    public List<java.lang.String> getEll() {
        return ell;
    }

    /**
     * list of labels/types associated to the object
     * (Required)
     * 
     */
    @JsonProperty("ell")
    public void setEll(List<java.lang.String> ell) {
        this.ell = ell;
    }

    /**
     * list of string-based values associated to the object
     * (Required)
     * 
     */
    @JsonProperty("xi")
    public List<java.lang.String> getXi() {
        return xi;
    }

    /**
     * list of string-based values associated to the object
     * (Required)
     * 
     */
    @JsonProperty("xi")
    public void setXi(List<java.lang.String> xi) {
        this.xi = xi;
    }

    /**
     * Map<String,String>
     * <p>
     * key-value representation associated to each object
     * (Required)
     * 
     */
    @JsonProperty("properties")
    public Map<String, String> getProperties() {
        return properties;
    }

    /**
     * Map<String,String>
     * <p>
     * key-value representation associated to each object
     * (Required)
     * 
     */
    @JsonProperty("properties")
    public void setProperties(Map<String, String> properties) {
        this.properties = properties;
    }

    /**
     * Map<String,List<Content>>
     * <p>
     * associating a content label to some content
     * (Required)
     * 
     */
    @JsonProperty("phi")
    public List<Phi> getPhi() {
        return phi;
    }

    /**
     * Map<String,List<Content>>
     * <p>
     * associating a content label to some content
     * (Required)
     * 
     */
    @JsonProperty("phi")
    public void setPhi(List<Phi> phi) {
        this.phi = phi;
    }

    @Override
    public java.lang.String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(TestSchema.class.getName()).append('@').append(Integer.toHexString(System.identityHashCode(this))).append('[');
        sb.append("id");
        sb.append('=');
        sb.append(((this.id == null)?"<null>":this.id));
        sb.append(',');
        sb.append("scores");
        sb.append('=');
        sb.append(((this.scores == null)?"<null>":this.scores));
        sb.append(',');
        sb.append("ell");
        sb.append('=');
        sb.append(((this.ell == null)?"<null>":this.ell));
        sb.append(',');
        sb.append("xi");
        sb.append('=');
        sb.append(((this.xi == null)?"<null>":this.xi));
        sb.append(',');
        sb.append("properties");
        sb.append('=');
        sb.append(((this.properties == null)?"<null>":this.properties));
        sb.append(',');
        sb.append("phi");
        sb.append('=');
        sb.append(((this.phi == null)?"<null>":this.phi));
        sb.append(',');
        if (sb.charAt((sb.length()- 1)) == ',') {
            sb.setCharAt((sb.length()- 1), ']');
        } else {
            sb.append(']');
        }
        return sb.toString();
    }

    @Override
    public int hashCode() {
        int result = 1;
        result = ((result* 31)+((this.phi == null)? 0 :this.phi.hashCode()));
        result = ((result* 31)+((this.xi == null)? 0 :this.xi.hashCode()));
        result = ((result* 31)+((this.ell == null)? 0 :this.ell.hashCode()));
        result = ((result* 31)+((this.scores == null)? 0 :this.scores.hashCode()));
        result = ((result* 31)+((this.id == null)? 0 :this.id.hashCode()));
        result = ((result* 31)+((this.properties == null)? 0 :this.properties.hashCode()));
        return result;
    }

    @Override
    public boolean equals(Object other) {
        if (other == this) {
            return true;
        }
        if ((other instanceof TestSchema) == false) {
            return false;
        }
        TestSchema rhs = ((TestSchema) other);
        return (((((((this.phi == rhs.phi)||((this.phi!= null)&&this.phi.equals(rhs.phi)))&&((this.xi == rhs.xi)||((this.xi!= null)&&this.xi.equals(rhs.xi))))&&((this.ell == rhs.ell)||((this.ell!= null)&&this.ell.equals(rhs.ell))))&&((this.scores == rhs.scores)||((this.scores!= null)&&this.scores.equals(rhs.scores))))&&((this.id == rhs.id)||((this.id!= null)&&this.id.equals(rhs.id))))&&((this.properties == rhs.properties)||((this.properties!= null)&&this.properties.equals(rhs.properties))));
    }

}
