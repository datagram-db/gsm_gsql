EXPLAIN
CREATE (matt {name: 'Matt'}),
    (and1 {name: 'and'}),
    (tray {name: 'Tray'}),
    (believe {name: 'believe'}),
    (that {name: 'that'}),
    (either {name: 'either'}),
    (alice {name: 'Alice'}),
    (and2 {name: 'and'}),
    (bob {name: 'Bob'}),
    (carl {name: 'Carl'}),
    (play {name: 'play'}),
    (cricket {name: 'cricket'}),
    (or1 {name: 'or'}),
    (carl2 {name: 'Carl'}),
    (and3 {name: 'and'}),
    (dan {name: 'Dan'}),
    (will {name: 'will'}),
    (not1 {name: 'not'}),
    (have {name: 'have'}),
    (a {name: 'a'}),
    (way {name: 'way'}),
    (to1 {name: 'to'}),
    (amuse {name: 'amuse'}),
    (themselves {name: 'themselves'})
CREATE (matt)-[:cc]->(and1)
CREATE (tray)-[:cc]->(and1)
CREATE (matt)-[:conj]->(tray)
CREATE (matt)<-[:subj]-(believe)
CREATE (tray)<-[:subj]-(believe)
CREATE (believe)-[:ccomp]->(play)
CREATE (that)<-[:mark]-(play)
CREATE (either)<-[:cc]-(alice)
CREATE (alice)<-[:subj]-(play)
CREATE (bob)<-[:subj]-(play)
CREATE (carl)<-[:subj]-(play)
CREATE (alice)-[:cc]->(and2)
CREATE (bob)-[:cc]->(and2)
CREATE (carl)-[:cc]->(and2)
CREATE (alice)-[:conj]->(bob)
CREATE (bob)-[:conj]->(carl)
CREATE (play)-[:conj]->(have)
CREATE (play)-[:cc]->(or1)
CREATE (cricket)<-[:dobj]-(play)
CREATE (have)-[:cc]->(or1)
CREATE (have)-[:subj]->(carl2)
CREATE (have)-[:subj]->(dan)
CREATE (carl2)-[:cc]->(and3)
CREATE (dan)-[:cc]->(and3)
CREATE (carl2)-[:conj]->(dan)
CREATE (will)<-[:aux]-(have)
CREATE (not1)<-[:neg]-(have)
CREATE (have)-[:dobj]->(way)
CREATE (a)<-[:det]-(way)
CREATE (way)-[:acl]->(amuse)
CREATE (to1)<-[:mark]-(amuse)
CREATE (amuse)-[:dobj]->(themselves)