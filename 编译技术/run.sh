flex lex.l
bison -d  parser.ypp
gcc -c lex.yy.c
g++ -c ast.cpp semantics.cpp GenIR.cpp GenObject.cpp parser.tab.cpp -w
g++ -o parser ast.o semantics.o GenIR.o GenObject.o parser.tab.o lex.yy.o
