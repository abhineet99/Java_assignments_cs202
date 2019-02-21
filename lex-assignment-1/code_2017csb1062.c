#include <stdio.h>
#include "myscanner.h"

extern int yylex();
extern int yylineno;
//extern char* yytext;
	int now_token,next_token,prev_token;
	int error_check=0;
	int super_error_check=0;
void documented_check(int next_token) // to check name of variables declared as parameters
{
	
	if(!(next_token==NAME||next_token==VAR_NAME))
		printf("Line %d ERROR:variable name  is not following convention\n",yylineno);
	return;
}


int main() 
{
	//printf("hello\n");
	int now_token,next_token;
	int error_check=0;
	int super_error_check=0; //checks whether even one error has occured in the source code or not
	
	now_token = yylex();
	while(now_token) {
		error_check=0;
		//////////////////////////////////////////////////////////
		if (now_token==TYPE) // a type is declared without documentation in comments
		{	
			//printf("Line %d l2\n",yylineno );
			//printf("Line %d: ERROR: Function/Variable declaration without previous comment!\n ",yylineno);
			//now_token=yylex();
			//super_error_check=1;
			error_check=1;
			next_token=yylex();
			if (next_token==UNKNOWN)//doesnt satisfy any name convention
			{
				//printf("Line %d l2.1\n",yylineno );
				printf("Line %d : ERROR: Function/Variable declaration without previous comment!\n",yylineno);
				printf("Line %d : ERROR: Function/Variable Name is not following conventions\n",yylineno);
				super_error_check=1;
				while(next_token!=SEMI_COLON&&next_token!=LEFT_BRACKET)
					next_token=yylex();
				printf("%d\n",next_token );
					error_check=1;
					if(next_token==LEFT_BRACKET)
						prev_token=TYPE;
					while(next_token!=RIGHT_BRACKET)	
					{
						
						now_token=next_token=yylex();
						//printf("%d %d\n",yylineno,next_token );
						if(prev_token==TYPE)
						documented_check(next_token);
						prev_token=now_token=next_token;



					}

			}
			else if(next_token==NAME)//satisfies convention of both functions and variable
			{
				//printf("Line %d l3\n",yylineno );
				next_token=yylex();
				//printf("%d\n",next_token );
				if(next_token==SEMI_COLON||next_token==COMMA||next_token==UNKNOWN)
				{
					super_error_check=1;
					printf("Line %d: ERROR: Variable declaration without previous comment!\n",yylineno);
				}
				else if(next_token==LEFT_BRACKET)
				{
					printf("Line %d: ERROR: Function declaration without previous comment!\n",yylineno);
				if(next_token==LEFT_BRACKET)
						prev_token=LEFT_BRACKET;
					while(next_token!=RIGHT_BRACKET)	
					{
						
						now_token=next_token=yylex();
						//printf("%d %d\n",yylineno,next_token );
						if(prev_token==TYPE)
						documented_check(next_token);
						prev_token=now_token=next_token;



					}
				}
			}
			else if(next_token==FUNC_NAME)//satisfies function name convention
			{
				//printf("Line %d l4\n",yylineno );
				//printf("yo\n" );
				error_check=0;
				next_token=yylex();
				if(next_token!=LEFT_BRACKET)
				{
					super_error_check=1;
				printf("Line %d: ERROR: Name doesnt follow variable conventions\n",yylineno);
				error_check=1;
				}
				else{
					if(next_token==LEFT_BRACKET)
						prev_token=LEFT_BRACKET;
					while(next_token!=RIGHT_BRACKET)	
					{
						
						now_token=next_token=yylex();
				//		printf("%d %d\n",yylineno,next_token );
						if(prev_token==TYPE)
						documented_check(next_token);
						prev_token=now_token=next_token;



					}
				// 	next_token=yylex();
				// 	while(next_token!=RIGHT_BRACKET)
				// 		next_token=yylex();
				// 	}
				// next_token=yylex();
				// if(next_token==LEFT_CURLY)
				// 	{
				// 	super_error_check=1;
				// 	printf("Line %d: ERROR: Function declaration without previous comment!\n",yylineno);
					}

			}
			else if(next_token==VAR_NAME) //satisfies variable name convention
			{
				//printf("Line %d l5\n",yylineno );
				next_token=yylex();
				if(next_token==LEFT_BRACKET)
				{
					printf("Line %d: ERROR: Function declaration without previous comment!\n",yylineno);
					printf("Line %d : ERROR: Function Name is not following conventions\n",yylineno);
					if(next_token==LEFT_BRACKET)
						prev_token=LEFT_BRACKET;
					while(next_token!=RIGHT_BRACKET)	
					{
						
						now_token=next_token=yylex();
					//	printf("%d %d\n",yylineno,next_token );
						if(prev_token==TYPE)
						documented_check(next_token);
						prev_token=now_token=next_token;



					}
				}
				else
				printf("Line %d: ERROR: Variable declaration without previous comment!\n",yylineno);
				super_error_check=1;
				
				error_check=0;
				// if(next_token!=SEMI_COLON&&next_token!=COMMA)
				// {
				// 	super_error_check=1;
				// 	printf("Line %d: ERROR: Expected a comma or a semi colon after variable name\n",yylineno);
				// 	error_check=1;
				// }

			}
		}
		////////////////////////////////////////////////////////////
		else if (error_check==0&&next_token==CMT_START)// comment is declared 
		{

			while(next_token!=CMT_END)
				next_token=yylex();
			next_token=yylex();// comment ends here
		}
		cmt_there:
		if(error_check==0&&next_token==TYPE)
		{
			//printf("Line %d l6\n",yylineno );
			type_rec:
			next_token=yylex();
			if (next_token==UNKNOWN||next_token==COMMA)
			{
				//printf("Line %d %d l7\n",yylineno,next_token );
				super_error_check=1;
				//printf("%d\n",next_token );
				while(next_token!=LEFT_BRACKET&&next_token!=COMMA)
				{
				next_token=yylex();
				//printf("yo\n");
				}
				//printf("%d\n",next_token );
				if (next_token==COMMA)
				printf("Line %d: ERROR: 2Variable Name is not following conventions\n",yylineno);
				else
				{
				//	printf("%d\n",next_token );
					//next_token=yylex();
					if(next_token==LEFT_BRACKET)
					{
						printf("Line %d: ERROR: Function Name is not following conventions\n",yylineno);
						if(next_token==LEFT_BRACKET)
						prev_token=LEFT_BRACKET;
					while(next_token!=RIGHT_BRACKET)	
					{
						
						now_token=next_token=yylex();
					//	printf("%d %d\n",yylineno,next_token );
						if(prev_token==TYPE)
						documented_check(next_token);
						prev_token=now_token=next_token;



					}
					}
					else
						printf("Line %d: ERROR: 1Variable Name is not following conventions\n",yylineno);

				}
			}
			else if(next_token==NAME)//satifies naming convention of both function and variable 
			{
			//	printf("Line %d l8\n",yylineno );
				while(next_token!=SEMI_COLON&&next_token!=LEFT_BRACKET&&next_token!=COMMA)
					next_token=yylex();
				if(next_token==LEFT_BRACKET)
				{
					if(next_token==LEFT_BRACKET)
						prev_token=LEFT_BRACKET;
					while(next_token!=RIGHT_BRACKET)	
					{
						
						now_token=next_token=yylex();
						//printf("%d %d\n",yylineno,next_token );
						if(prev_token==TYPE)
						documented_check(next_token);
						prev_token=now_token=next_token;



					}
				}
				if (next_token==COMMA)
				{
				//	printf("lol\n");
					goto type_rec;
				}
					//error_check=1;
			}
			else if(next_token==FUNC_NAME)//satisfies function name convention
			{
				//printf("Line %d l9\n",yylineno );
				error_check=0;
				next_token=yylex();
				if(next_token!=LEFT_BRACKET)
				{
					super_error_check=1;
			//	printf("Line %d: ERROR: name doesnt follow variable conventions\n",yylineno);
				error_check=1;
				}
				else{
					if(next_token==LEFT_BRACKET)
						prev_token=LEFT_BRACKET;
					while(next_token!=RIGHT_BRACKET)	
					{
						
						now_token=next_token=yylex();
					//	printf("%d %d\n",yylineno,next_token );
						if(prev_token==TYPE)
						documented_check(next_token);
						prev_token=now_token=next_token;



					}
					}
				//next_token=yylex();	
			}
			else if(next_token==VAR_NAME)//satisfies variable name convention
			{
			//	printf("Line %d l10\n",yylineno );
				next_token=yylex();
				error_check=0;
				//next_token=yylex();
				if(next_token==LEFT_BRACKET)
				{
					super_error_check=1;
					printf("Line %d: ERROR: Function declaration without previous comment!\n",yylineno);
					printf("Line %d : ERROR: Function Name is not following conventions\n",yylineno);
					if(next_token==LEFT_BRACKET)
						prev_token=LEFT_BRACKET;
					while(next_token!=RIGHT_BRACKET)	
					{
						
						now_token=next_token=yylex();
					//	printf("%d %d\n",yylineno,next_token );
						if(prev_token==TYPE)
						documented_check(next_token);
						prev_token=now_token=next_token;



					}
				}
				else if(next_token!=SEMI_COLON&&next_token!=COMMA)
				{
					super_error_check=1;
					printf("Line %d: ERROR: Expected a comma or semi colon after variable name\n",yylineno);
					error_check=1;
				}

			}
		}
		next_token=yylex();
		now_token=next_token;
	}
	if (super_error_check==0)
		printf("Program meets the coding conventions!\n");
	return 0;
}
