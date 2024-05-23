# Expresso

![logo](assets/logo_1.png)

## Introduction

It's a C liked programming language

Sample program:

```c
const int a = 5;
string b = "hello";
if (a == 5) {
    print (a);
}
else {
    if (b == "hello") {
        print (b);
    }
}
```

## Run Steps

- `yacc -d parser.y`: create y.tab.h and y.tab.c
- `lex lex.l`: create lex.yy.c
- `gcc -g lex.yy.c y.tab.c -o main`: create main
- `./main example.txt`: run main

  To run another example change "example.txt" with the example path


## Tools and Technologies

Lex and Yacc are tools commonly used in the field of computer science for constructing compilers and interpreters. They are used to generate lexical analyzers and parsers, which are critical components in the process of translating high-level programming languages into machine-readable code.

<ol>
   <li>Lex:  is a tool for generating lexical analyzers, also known as lexers or scanners. A lexical analyzer processes an input stream of characters (such as source code) and divides it into a sequence of tokens. Tokens are meaningful sequences of characters, such as keywords, operators, identifiers, and literals..</li>
   <li>Yacc: Yacc stands for "Yet Another Compiler Compiler." It is a tool used to generate parsers, which analyze the structure of the token sequence produced by the lexer to ensure it conforms to the grammatical rules of the programming language..</li>
</ol>
