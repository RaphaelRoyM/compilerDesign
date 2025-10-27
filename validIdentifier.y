%{
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
%}
%token LETTER DIGIT
%%
L: A'\n' {
	printf("valid\n");
	exit(0);
}
;
A: LETTER B | '_' B;
B: LETTER B | DIGIT B | LETTER | DIGIT;
%%
void main(){
 printf("enter the variable name :");
 yyparse();
}
yylex(){
	char ch = getchar();
	printf("%c\n",ch);
	if(isalpha(ch))
		return LETTER;
	else if(isdigit(ch))
		return DIGIT;
	else
		return ch;
}
yyerror(){
	printf("Invalid\n");
	exit(0);
}
