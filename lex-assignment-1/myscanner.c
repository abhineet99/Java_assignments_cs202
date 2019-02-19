#include <stdio.h>
#include "myscanner.h"

extern int yylex();
extern int yylineno;
//extern char* yytext;


int main(void) 
{
	int error_check=0;
	int super_error_check=0; //checks whether even one error has occured in the source code or not
	int now_token,next_token;
	now_token = yylex();
	while(now_token) {
		error_check=0;
		//////////////////////////////////////////////////////////
		if (now_token==TYPE)
		{	
			printf("Line %d: ERROR: Function/Variable declaration without previous comment!\n ",yylineno);
			//now_token=yylex();
			super_error_check=1;
			error_check=1;
			next_token=yylex();
			if (next_token==UNKNOWN)
			{
				printf("Line %d: ERROR: Function/Variable Name is not following conventions\n ",yylineno);
				super_error_check=1;
				while(next_token!=SEMI_COLON&&next_token!=LEFT_CURLY)
					next_token=yylex();
					error_check=1;
			}
			else if(next_token==NAME)
			{
				while(next_token!=SEMI_COLON&&next_token!=LEFT_CURLY)
					next_token=yylex();
					error_check=1;
			}
			else if(next_token==FUNC_NAME)
			{
				error_check=0;
				next_token=yylex();
				if(next_token!=LEFT_BRACKET)
				{
					super_error_check=1;
				printf("Line %d: ERROR: Expected a '(' after function name as the name doesnt follow variable conventions\n",yylineno);
				error_check=1;
				}
				else{
					next_token=yylex();
					while(next_token!=RIGHT_BRACKET)
						next_token=yylex();
					}
				next_token=yylex();

			}
			else if(next_token==VAR_NAME)
			{
				next_token=yylex();
				error_check=0;
				if(next_token!=SEMI_COLON)
				{
					super_error_check=1;
					printf("Line %d: ERROR: Expected a semi colon after function name\n",yylineno);
					error_check=1;
				}

			}
		}
		////////////////////////////////////////////////////////////
		else if (error_check==0&&now_token==CMT_START)
		{
			while(now_token!=CMT_END)
				now_token=yylex();
			now_token=yylex();
		}
		if(error_check==0&&now_token==TYPE)
		{
			next_token=yylex();
			if (next_token==UNKNOWN)
			{
				super_error_check=1;
				printf("Line %d: ERROR: Function/Variable Name is not following conventions\n ",yylineno);
			}
			else if(next_token==NAME)
			{
				while(next_token!=SEMI_COLON&&next_token!=LEFT_CURLY)
					next_token=yylex();
					//error_check=1;
			}
			else if(next_token==FUNC_NAME)
			{
				error_check=0;
				next_token=yylex();
				if(next_token!=LEFT_BRACKET)
				{
					super_error_check=1;
				printf("Line %d: ERROR: Expected a '(' after function name as the name doesnt follow variable conventions\n",yylineno);
				error_check=1;
				}
				else{
					next_token=yylex();
					while(next_token!=RIGHT_BRACKET)
						next_token=yylex();
					}
				next_token=yylex();	
			}
			else if(next_token==VAR_NAME)
			{
				next_token=yylex();
				error_check=0;
				if(next_token!=SEMI_COLON)
				{
					super_error_check=1;
					printf("Line %d: ERROR: Expected a semi colon after function name\n",yylineno);
					error_check=1;
				}

			}
		}
		next_token=yylex();
		now_token=next_token;
	}
	if (super_error_check==0)
		printf("Everything looks good!!\n");
	return 0;
}
