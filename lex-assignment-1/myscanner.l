%{
#include "myscanner.h"
%}
%option nounput yylineno

%%
:					return TYPE;
"int"			return TYPE;
"char"			return TYPE;
"float"	return TYPE;
"double"			return TYPE;
"int*"			return TYPE;
"char*"			return TYPE;
"float*"	return TYPE;
"double*"			return TYPE;
"()"			return DBL_BRACKETS;
[a-zA-Z][_a-zA-Z0-9]*	return IDENTIFIER;
[1-9][0-9]*				return INTEGER;
[ \t\n]					;
.					printf("unexpected character\n");

%%

int yywrap(void)
{
	return 1;
}
