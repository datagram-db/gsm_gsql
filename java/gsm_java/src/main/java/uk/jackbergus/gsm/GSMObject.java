package uk.jackbergus.gsm;

import java.io.Serializable;
import java.util.*;

import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.fasterxml.jackson.annotation.JsonPropertyDescription;
import com.fasterxml.jackson.annotation.JsonPropertyOrder;


/**
 * Generated with https://www.jsonschema2pojo.org/
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
public class GSMObject implements Serializable, Cloneable
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
    private List<Double> scores = new ArrayList<>(Arrays.asList(1.0D));
    /**
     * list of labels/types associated to the object
     * (Required)
     * 
     */
    @JsonProperty("ell")
    @JsonPropertyDescription("list of labels/types associated to the object")
    private List<String> ell = new ArrayList<>();
    /**
     * list of string-based values associated to the object
     * (Required)
     * 
     */
    @JsonProperty("xi")
    @JsonPropertyDescription("list of string-based values associated to the object")
    private List<String> xi = new ArrayList<>();
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
    private List<Phi> phi = new ArrayList<>();

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
    public List<String> getEll() {
        return ell;
    }

    /**
     * list of labels/types associated to the object
     * (Required)
     * 
     */
    @JsonProperty("ell")
    public void setEll(List<String> ell) {
        this.ell = ell;
    }

    /**
     * list of string-based values associated to the object
     * (Required)
     * 
     */
    @JsonProperty("xi")
    public List<String> getXi() {
        return xi;
    }

    /**
     * list of string-based values associated to the object
     * (Required)
     * 
     */
    @JsonProperty("xi")
    public void setXi(List<String> xi) {
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

    /**
     * Actual paper representation of Phi
     * @return
     */
    public Map<String, List<Phi>> navigablePhi() {
        Map<String, List<Phi>> m = new HashMap<>();
        for (var x : this.phi) {
            if (!m.containsKey(x.getContainment()))
                m.put(x.getContainment(), new ArrayList<>());
            m.get(x.getContainment()).add(x);
        }
        return m;
    }

    /**
     * Returning the comparable representation useful for our current implementation of GSM
     * @return
     */
    @Override
    public String toString() {
        StringBuilder b = new StringBuilder();
        b.append("id:").append(id).append("\n");

        b.append("ell:\n");
        ell.forEach(x->b.append(x).append("\n"));
        b.append(".\n");

        b.append("xi:\n");
        xi.forEach(x->b.append(x).append("\n"));
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
        navigablePhi().forEach((c,p)-> {
            b.append(JSONUtil.escape(c)).append("\n");
            p.forEach(k-> {
                b.append("\t").append(k.getScore()).append("\t").append(k.getContent()).append("\n");
            });
            b.append(";");
        });
        b.append(".\n\n");

        return b.toString();
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
        if ((other instanceof GSMObject) == false) {
            return false;
        }
        GSMObject rhs = ((GSMObject) other);
        return (((((((this.phi == rhs.phi)||((this.phi!= null)&&this.phi.equals(rhs.phi)))&&((this.xi == rhs.xi)||((this.xi!= null)&&this.xi.equals(rhs.xi))))&&((this.ell == rhs.ell)||((this.ell!= null)&&this.ell.equals(rhs.ell))))&&((this.scores == rhs.scores)||((this.scores!= null)&&this.scores.equals(rhs.scores))))&&((this.id == rhs.id)||((this.id!= null)&&this.id.equals(rhs.id))))&&((this.properties == rhs.properties)||((this.properties!= null)&&this.properties.equals(rhs.properties))));
    }

}
