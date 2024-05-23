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
   <li>
       <b>Lex</b>: is a tool for generating lexical analyzers, also known as lexers or scanners. A lexical analyzer processes an input stream of characters (such as source code) and divides it into a sequence of tokens. Tokens are meaningful sequences of characters, such as keywords, operators, identifiers, and literals.
   </li>
   <li>
       <b>Yacc</b>: Yacc stands for "Yet Another Compiler Compiler." It is a tool used to generate parsers, which analyze the structure of the token sequence produced by the lexer to ensure it conforms to the grammatical rules of the programming language.
   </li>
</ol>


# Workflow

<ol>
 <li>
      <b>Define Tokens with Lex</b> : Create a .l file specifying the tokens and their patterns.
 </li>   
<li>
      <b>Define Grammar with Yacc</b> : Create a .y file specifying the grammar rules and associated actions.
 </li> 
<li>
      <b>Compile and Link</b> : Use Lex to generate a C source file for the lexer, and Yacc to generate a C source file for the parser. Compile and link these with a C compiler.
 </li>
</ol>


## Tokens

<table>
   <tr>
      <th align="left">Token</th>
      <th align="left">Regex</th>
      <th align="left">Description</th>
   </tr>
   <tr>
      <td>FLOAT_VAL</td>
      <td>[0-9]*"."[0-9]+</td>
      <td>Float Numbers.</td>
   </tr>
   <tr>
      <td>INTEGER_VAL</td>
      <td>0 | ([1-9][0-9]*)</td>
      <td>Integer Numbers.</td>
   </tr>
   <tr>
      <td>CHAR_VAL</td>
      <td>'[^\\']'</td>
      <td>One character inside sinqle quotes.</td>
   </tr>
   <tr>
      <td>STRING_VAL</td>
      <td>\"([^\"\\;]|\\.)*\"</td>
      <td>string between double quotes.</td>
   </tr>
   <tr>
      <td>TRUE_VAL</td>
      <td>"true"</td>
      <td>True value.</td>
   </tr>
   <tr>
      <td>FALSE_VAL</td>
      <td>"false"</td>
      <td>False value.</td>
   </tr>
   <tr>
      <td>skip this token</td>
      <td>\/\*([^*]|\*+[^/])*\*+\/</td>
      <td>Multi-line comment.</td>
   </tr>
   <tr>
      <td>skip this token</td>
      <td>\/\/.*</td>
      <td>In-line comment.</td>
   </tr>
   <tr>
      <td>NEW_LINE</td>
      <td>"\n"</td>
      <td>new line.</td>
   </tr>
   <tr>
      <td>IDENTIFIER</td>
      <td>[a-zA-Z_][a-zA-Z0-9_]*</td>
      <td>Identifiers (variables and contants names).</td>
   </tr>
</table>

## Syntax

### Data Types

Tha language supports the following data types:

- Integer
- Float
- Boolean
- String
- Character

It supports modifiers like `const` as well.

```c
const int a = 10;
int b = 20;
float c = 10.5;
bool d = true;
string e = "Hello World";
char f = 'c';
```

### Operators

The language supports the common operators.

```c
// Arithmetic operators
a = b + c;
a = b - c;
a = b * c;
a = b / c;
a = b % c;
a = b++;
a = ++b;
a = b--;
a = --b;
// Logical operators
a = b && c;
a = b || c;
a = !b;
// Relational operators
a = b == c;
a = b != c;
a = b > c;
a = b >= c;
a = b < c;
a = b <= c;
```
