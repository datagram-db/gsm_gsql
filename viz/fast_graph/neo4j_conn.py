import functools

from neo4j import Session, Driver

def ext_neo4j(folder):
    import os
    with open(os.path.join("data", str(folder), "input.json")) as f:
        from gsm.as_cypher_graph import CreateGraph
        builder = CreateGraph()
        import json
        data = json.load(f)
        return builder.cypher_graph(data)
    return ""


@functools.lru_cache
def get_external_content(url):
    import urllib.request
    with urllib.request.urlopen(url) as f:
        return f.read().decode('utf-8')
    return None

class GraphDB():
    def __init__(self, URI, username,pw, db):
        self.URI = URI
        self.AUTH = (username, pw)
        self.db = db

    def runQueryFromFullTextHTTPResponse(self, url):
        return self.execute_operation(get_external_content(url))

    def execute_operation(self, op):
        from neo4j import GraphDatabase
        with GraphDatabase.driver(self.URI, auth=self.AUTH) as driver:
            driver.verify_connectivity()
            import time
            t1 = time.time()*1000.0
            records, summary, keys = driver.execute_query(
                op,
                database_=self.db,
            )
            t2 = time.time()*1000.0
        return records, summary, keys, t2 - t1

    def deleteAll(self):
        return self.execute_operation("""MATCH (n)
DETACH DELETE n""")



if __name__ == '__main__':
    simple_data = ["https://osf.io/download/a7un2/?view_only=f31eda86e7b04ac886734a26cd2ce43d",
                   "https://osf.io/download/jbg8u/?view_only=f31eda86e7b04ac886734a26cd2ce43d"]
    complex_data = ["https://osf.io/download/zs5h6/?view_only=f31eda86e7b04ac886734a26cd2ce43d",
                   "https://osf.io/download/jbg8u/?view_only=f31eda86e7b04ac886734a26cd2ce43d"]

    times = [0, 0]
    time_names = ["loading+indexing", "querying+materialisation"]
    i = 20.0
    orig = i
    q = complex_data
    # print(ext_neo4j(0))
    g = GraphDB("bolt://localhost:7687", "neo4j", "noncaperet", "neo4j")
    while i>0:
        print(i)
        for idx in range(len(q)):
            _, _, _, t = g.runQueryFromFullTextHTTPResponse(q[idx])
            times[idx] += t
        records, summary, keys, time = g.deleteAll()
        i -= 1
    for idx in range(len(q)):
        times[idx] = times[idx]/orig
        print(f"{time_names[idx]} (ms): {times[idx]}")
    # # assert g.open()
    # records, summary, keys, time = g.execute_operation(ext_neo4j(0))
    # print(f"Creation time (ms): {time}")
    records, summary, keys, time = g.deleteAll()
    print(f"Final Deletion time (ms): {time}")

