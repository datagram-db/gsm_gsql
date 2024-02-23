# Cypher Benchmark Program
Java program that runs creates a Cypher graph and rewrites, outputting the results to a .csv.  
## How to run
- You must be running Neo4j Desktop environment with a database running, ensure URI, username, password in program match Neo4j database
- Change the `import.cypher` file to your local directory with `/temp.json` at the end
  - `'/{local_path}/gsm_gsql/neo4j_benchmark/temp.json'`
- Place the database JSON inside the resources folder
### Example
`-it 10 -db table_data/final_gsm_db.json`
### Arguments
- `-it [number of iterations for each query]`
- `-db [file path of database from news_scraper project]`
- `-articles [number of articles to run through from .json]`
- `-shouldDelete [true/false]` 
  - _whether the database should clear after execution_