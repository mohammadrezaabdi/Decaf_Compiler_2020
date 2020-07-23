flex scanner.l
bison parser.y -o parser.tab.c
gcc parser.tab.c -o a.out
a.out tests/Test.in out/Test.out
PAUSE
