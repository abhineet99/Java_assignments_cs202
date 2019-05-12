%{
#include "myscanner.h"
%}
%option nounput yylineno

%%
"int"			return TYPE;
"char"			return TYPE;
"float"	return TYPE;
"double"			return TYPE;
"int*"			return TYPE;
"char*"			return TYPE;
"float*"	return TYPE;
"double*"			return TYPE;
"()"			return DBL_BRACKETS;
"("             return LEFT_BRACKET;
")"				return RIGHT_BRACKET;
"{"				return LEFT_CURLY;
"}"				return RIGHT_CURLY;
","				return COMMA;
[a-z][a-z]* return NAME;
[_a-z][_a-z]*    return FUNC_NAME;
[a-z][a-z0-9]*    return VAR_NAME;
"/*"	return CMT_START;
"*/"    return CMT_END;
[ \t\n]					;
";"		return SEMI_COLON;
.					return UNKNOWN;

%%

int yywrap(void)
{
	return 1;
}

