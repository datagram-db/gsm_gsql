#!/bin/bash
java -jar submodules/yaucl/submodules/antlr4/tool/target/antlr4-4.11.1-complete.jar -Dlanguage=Cpp -visitor -listener antlr4/graph_grammar/simple_graph_grammar.g4
java -jar submodules/yaucl/submodules/antlr4/tool/target/antlr4-4.11.1-complete.jar -Dlanguage=Cpp -visitor -listener antlr4/scriptv2/script.g4
java -jar submodules/yaucl/submodules/antlr4/tool/target/antlr4-4.11.1-complete.jar -Dlanguage=Cpp -visitor -listener antlr4/schema_language/schema.g4
