EXPLAIN
MATCH (a)-[b:cc]->(c)
WITH Collect(a.name) as names, c, Collect(DISTINCT a) as nameNodes
CREATE (x {name: apoc.text.join(names, ' '), cc: c.name})
WITH x, nameNodes
FOREACH (p IN nameNodes | CREATE (y {name: p.name})<-[:orig]-(x))
WITH x
MATCH (a)-[:dobj]->(b)
CREATE (y {name: b.name})
WITH a, x, y
CALL apoc.create.relationship(x, a.name, {}, y) YIELD rel
WITH y
MATCH q=()-[]->()
RETURN q