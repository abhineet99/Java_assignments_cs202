#include <stdio.h>
#include "myscanner.h"

extern int yylex();
extern int yylineno;
//extern char* yytext;


int main(void) 
{
	int error_check=0;
	int now_token,prev_token,next_token;
	ntoken = yylex();
	while(ntoken) {
		if(ntoken==TYPE)
		{
			next_token=yylex();
			if (next_token==UNKNOWN)
			{
				printf("Line %d: ERROR: Function/Variable Name is not following conventions ",yylineno)
			}
			else if(next_token==FUNC_NAME)
			{
				error_check=0;
				next_token=yylex();
				if(next_token!=LEFT_BRACKET)
				{
				printf("Line %d: ERROR: Expected a '(' after function name",yylineno);
				error_check=1;
				}
				else{
					next_token=yylex();
					while(next_token!=RIGHT_BRACKET)
						next_token=yylex();
					}
				next_token=yylex();
				if(error_check==0)
				{
					if(next_token!=CMT_START)
						printf("Line %d: ERROR: Expected a comment start after function name",yylineno);
					else
						while(next_token!=CMT_END)
							next_token=yylex();
				}	
			}
			else if(next_token==VAR_NAME)
			{
				next_token=yylex();
				error_check=0;
				if(next_token!=SEMI_COLON)
				{
					printf("Line %d: ERROR: Expected a semi colon after function name",yylineno);
					error_check=1;
				}
				if(error_check!=1)
				{
					next_token==yylex();
					if(next_token!=CMT_START)
						printf("Line %d: ERROR: Expected a comment start after function name",yylineno);
					else
						while(next_token!=CMT_END)
							next_token=yylex();
				}
			}
		}
		next_token=yylex();
		now_token=next_token;
	}
	return 0;
}
