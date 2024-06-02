package uk.ncl.giacomobergami;

import java.util.Arrays;
import java.util.Optional;

/**
 * Created by vasistas on 13/08/16.
 */
public enum UniversalDependenciesEdgeTypes {
    acl("acl"),
    acl_recl("acl:relcl"),
    advcl("advcl"),
    advmod("advmod"),
    amod("amod"),
    appos("appos"),
    aux("aux"),
    auxpass("auxpass"),
    ccase("case"),
    cc("cc"),
    ccomp("ccomp"),
    compound("compound"),
    compound_prt("compound:prt"),
    conj("conj"),
    cop("cop"),
    csubj("csubj"),
    csubjpass("csubjpass"),
    dep("dep"),
    det("det"),
    det_predet("det:predet"),
    discourse("discourse"),
    dislocated("dislocated"),
    dobj("dobj"),
    expl("expl"),
    foreign("foreign"),
    goeswith("goeswith"),
    iobj("iobj"),
    list("list"),
    mark("mark"),
    mwe("mwe"),
    name("name"),
    neg("neg"),
    nmod("nmod"),
    nmod_npmod("nmod:npmod"),
    nmod_poss("nmod:poss"),
    nmod_tmod("nmod:tmod"),
    nsubj("nsubj"),
    nsubjpass("nsubjpass"),
    nummod("nummod"),
    parataxis("parataxis"),
    punct("punct"),
    remnant("remnant"),
    reparandum("reparandum"),
    root("root"),
    vocative("vocative"),
    xcomp("xcomp"),
    obl("obl"),
    obj("obj"),
    none("none");

    private final String t;
    UniversalDependenciesEdgeTypes(String acl) {
        this.t = acl;
    }

    public static Optional<UniversalDependenciesEdgeTypes> fromString(String s) {
        return Arrays.stream(UniversalDependenciesEdgeTypes.values()).filter(x->x.toString().equals(s)).findFirst();
    }

    @Override
    public String toString() {
        return t;
    }

    public static void main(String args[]) {
        UniversalDependenciesEdgeTypes l = UniversalDependenciesEdgeTypes.fromString
          ("acl:relcl").get();
        System.out.println(l);
    }

}
