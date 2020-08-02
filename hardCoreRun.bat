flex scanner.l
bison parser_m.y -d --verbose -o parser_m.tab.c
gcc parser_m.tab.c -o a.out
a.out tests/temp.d out/temp.out
PAUSE
