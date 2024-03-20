EXPLAIN
CREATE q=(a {name: 'play'}), (b {name: 'cricket'}), (c {name: 'Alice'}), (d {name: 'Bob'}), (e {name: 'and'})
CREATE (a)-[r:dobj]->(b)
CREATE (a)-[s:subj]->(c)
CREATE (a)-[t:subj]->(d)
CREATE (c)-[u:conj]->(d)
CREATE (c)-[v:cc]->(e)
CREATE (d)-[w:cc]->(e)
RETURN *