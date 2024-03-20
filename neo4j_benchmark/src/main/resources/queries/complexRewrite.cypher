MATCH (a)-[:subj]->(b)-[:cc]->(c)
WHERE (b)<-[:conj]-() OR (b)-[:conj]->()
WITH a, Collect(b.name) as names, c
WHERE size(names) > 1
OPTIONAL MATCH (a)-[:neg]->(d)
CREATE (x {name: apoc.text.join(names, ' '), cc: c.name, dobjRel: a.name})
WITH a, c, d, x, names
CALL apoc.create.addLabels(x, names) YIELD node
CALL apoc.do.when(
    d IS NOT NULL,
    "SET x.neg = d.name",
    '',
    {c:c, d:d, a:a, x:x})
YIELD value as neg
WITH neg
MATCH (n)
WITH LABELS(n) as nameLabels, Collect(DISTINCT n) as nameNodes
WHERE size(nameLabels) > 0
FOREACH (nNode IN nameNodes | 
    FOREACH (nLabel IN nameLabels |
        CREATE (y {name: nLabel})<-[:orig]-(nNode)))
WITH *
MATCH (d)<-[:dobj]-(a)
WITH Collect(DISTINCT d.name) as objects, a
FOREACH (obj IN objects | 
    CREATE (y {name: obj, dobjRel: a.name}))
WITH *
MATCH (n) WHERE NOT (n)-[]->() AND NOT (n)<-[]-()
WITH n
MATCH (d)<-[:dobj]-(a)
MATCH (e)-[:orig]->()
WHERE e.dobjRel = a.name AND d.name = n.name
OPTIONAL MATCH (d)-[:det]->(f)
CALL apoc.do.when(
    f IS NOT NULL,
    'SET n.det = f.name',
    '',
    {n:n, f:f})
YIELD value as det
WITH det
MATCH (m) WHERE NOT (m)-[]->() AND NOT (m)<-[]-()
WITH m
MATCH (d)<-[:dobj]-()
MATCH (e)-[:orig]->()
WHERE e.dobjRel = m.dobjRel
WITH DISTINCT e, m
CALL apoc.do.when(
    e.neg IS NOT NULL,
    'CALL apoc.create.relationship(e, e.neg + " " + e.dobjRel, {}, m) YIELD rel RETURN rel',
    'CALL apoc.create.relationship(e, e.dobjRel, {}, m) YIELD rel RETURN rel',
    {e:e, m:m})
YIELD value as dobjRel
WITH dobjRel
MATCH (p) WHERE NOT (p)-[]->() AND NOT (p)<-[]-()
WITH p
MATCH (a)-[:acl]->(b)
MATCH (c)<-[:orig]-(d)-[]->(e)
WITH DISTINCT p, a, e
WHERE e.name = a.name
CREATE (y {name: '?'})<-[:acl]-(e)
WITH p, y
CALL apoc.create.relationship(y, p.dobjRel, {}, p) YIELD rel as aclRel
WITH aclRel
MATCH (a)-[:conj]->(b)-[:cc]->(c)<-[:cc]-(a)
MATCH ()<-[:orig]-(d)-[r]->()
WHERE type(r) CONTAINS a.name OR type(r) CONTAINS b.name
WITH a, b, c, d, r
ORDER BY d.name ASC
WITH Collect(DISTINCT d.name) as names, c
CREATE (x {name: apoc.text.join(names, ' ' + c.name + ' ')})
WITH x, names
CALL apoc.create.addLabels(x, names) YIELD node as groupedGroup
WITH groupedGroup
MATCH (c)<-[:mark]-(a)-[:dobj]->(b) 
MATCH (d)-[r]->(e)
WHERE type(r) CONTAINS a.name AND b.name = e.name
CALL apoc.create.setRelProperty(r, 'mark', c.name) YIELD rel as markRel
WITH markRel
MATCH (d)<-[:aux]-(a)-[:subj]->()-[:cc]->()
MATCH ()<-[:orig]-(f)-[r]->()
WHERE type(r) CONTAINS a.name
CALL apoc.create.setRelProperty(r, 'aux', d.name) YIELD rel as auxRel
WITH auxRel
MATCH (a)-[:orig]->(b)
MATCH (x) WHERE NOT (x)-[]->() AND NOT (x)<-[]-()
WITH DISTINCT a, x
WHERE apoc.text.join(LABELS(a), ' ') IN LABELS(x)
CALL apoc.create.relationship(x, 'orig', {}, a) YIELD rel as origRel
WITH x
MATCH (d)<-[:subj]-(a)-[:ccomp]->(b)-[:subj]->(c)
MATCH (e)-[:orig]->(f)
WITH a, b, c, d, e, f, x
ORDER BY d.name ASC, c.name ASC
WITH Collect(DISTINCT c.name) as endNames, x, Collect(DISTINCT d.name) as startNames, e, a
WHERE apoc.text.join(startNames, ' ') = e.name AND apoc.text.join(endNames, ' ') IN LABELS(x)
CALL apoc.create.relationship(e, a.name, {}, x) YIELD rel as finalRel
WITH finalRel
MATCH q=()-[]->()
MATCH (z)
CALL apoc.create.removeLabels(z, LABELS(z)) YIELD node
WITH q, z
RETURN q, z
