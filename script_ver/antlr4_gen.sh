#!/bin/bash
java -jar submodules/yaucl/submodules/antlr4/tool/target/antlr4-4.11.1-complete.jar -Dlanguage=Cpp -visitor $1 -o antlr4/cpp
