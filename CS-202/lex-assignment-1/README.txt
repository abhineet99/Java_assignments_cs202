System specifications:
Ubuntu 18.04
flex 2.6.4 (may be installed with "sudo apt-get flex" on ubuntu terminal)
gcc 7.3.0

Assumptions:
1. Any declarations end with ";"
2. Data types considered are int,char,float,double.
3. Parameters to functions cant be functions.
HOW TO RUN
1. On ubuntu terminal, type "flex myscanner.l" and press enter.
2. Next, type "gcc myscanner.c lex.yy.c myscanner" and press enter.
3. Now lets assume the name of the file which you need to check is abhineet.c. Type myscanner<abhineet.c and press enter.

How it works:
It basically uses lex tool to extract lexemes from the source code given as input, then it is verified as per the standards set in myscanner.c file. Lex tool gives an integer output as specified in the library myscanner.h and in lex file myscanner.l.

