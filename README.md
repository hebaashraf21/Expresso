# Expresso


How to run:

1- bison -d parser.y
2- flex lex.l
3- gcc lex.yy.c parser.tab.c -o test
4- test


example:


C:\Users\user\Downloads\Expresso>bison -d parser.y
parser.y: conflicts: 16 shift/reduce

C:\Users\user\Downloads\Expresso>flex lex.l

C:\Users\user\Downloads\Expresso>gcc lex.yy.c parser.tab.c -o test

C:\Users\user\Downloads\Expresso>test
int a
INTEGER: int
Error: syntax error

C:\Users\user\Downloads\Expresso>test
heba
IDENTIFIER: heba
Error: syntax error
