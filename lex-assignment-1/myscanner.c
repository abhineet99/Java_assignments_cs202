#include <stdio.h>
#include "myscanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;


int main(void) 
{

	int ntoken, vtoken,prevtoken;
	prevtoken=0;

	ntoken = yylex();
	while(ntoken) {
		if(ntoken==)
	}
	return 0;
}
