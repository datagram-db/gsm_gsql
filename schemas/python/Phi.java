import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.fasterxml.jackson.annotation.JsonPropertyDescription;
import com.fasterxml.jackson.annotation.JsonPropertyOrder;


/**
 * Generated with https://www.jsonschema2pojo.org/
 * Content
 * <p>
 * a single contained object
 * 
 */
@JsonInclude(JsonInclude.Include.NON_NULL)
@JsonPropertyOrder({
    "containment",
    "content",
    "score"
})
public class Phi {

    /**
     * the containment relation associating the parent object to the included child
     * (Required)
     * 
     */
    @JsonProperty("containment")
    @JsonPropertyDescription("the containment relation associating the parent object to the included child")
    private String containment;
    /**
     * object id providing a content to the object
     * (Required)
     * 
     */
    @JsonProperty("content")
    @JsonPropertyDescription("object id providing a content to the object")
    private Integer content;
    /**
     * confidence value of the parent object containing the content object
     * 
     */
    @JsonProperty("score")
    @JsonPropertyDescription("confidence value of the parent object containing the content object")
    private Double score = 1.0D;

    /**
     * the containment relation associating the parent object to the included child
     * (Required)
     * 
     */
    @JsonProperty("containment")
    public String getContainment() {
        return containment;
    }

    /**
     * the containment relation associating the parent object to the included child
     * (Required)
     * 
     */
    @JsonProperty("containment")
    public void setContainment(String containment) {
        this.containment = containment;
    }

    /**
     * object id providing a content to the object
     * (Required)
     * 
     */
    @JsonProperty("content")
    public Integer getContent() {
        return content;
    }

    /**
     * object id providing a content to the object
     * (Required)
     * 
     */
    @JsonProperty("content")
    public void setContent(Integer content) {
        this.content = content;
    }

    /**
     * confidence value of the parent object containing the content object
     * 
     */
    @JsonProperty("score")
    public Double getScore() {
        return score;
    }

    /**
     * confidence value of the parent object containing the content object
     * 
     */
    @JsonProperty("score")
    public void setScore(Double score) {
        this.score = score;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(Phi.class.getName()).append('@').append(Integer.toHexString(System.identityHashCode(this))).append('[');
        sb.append("containment");
        sb.append('=');
        sb.append(((this.containment == null)?"<null>":this.containment));
        sb.append(',');
        sb.append("content");
        sb.append('=');
        sb.append(((this.content == null)?"<null>":this.content));
        sb.append(',');
        sb.append("score");
        sb.append('=');
        sb.append(((this.score == null)?"<null>":this.score));
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
        result = ((result* 31)+((this.containment == null)? 0 :this.containment.hashCode()));
        result = ((result* 31)+((this.score == null)? 0 :this.score.hashCode()));
        result = ((result* 31)+((this.content == null)? 0 :this.content.hashCode()));
        return result;
    }

    @Override
    public boolean equals(Object other) {
        if (other == this) {
            return true;
        }
        if ((other instanceof Phi) == false) {
            return false;
        }
        Phi rhs = ((Phi) other);
        return ((((this.containment == rhs.containment)||((this.containment!= null)&&this.containment.equals(rhs.containment)))&&((this.score == rhs.score)||((this.score!= null)&&this.score.equals(rhs.score))))&&((this.content == rhs.content)||((this.content!= null)&&this.content.equals(rhs.content))));
    }

}
