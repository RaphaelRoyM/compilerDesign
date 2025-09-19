%{
#include<stdio.h>
#include<ctype.h>
%}
%token DIGIT LETTER
%%
L:A'\n' {
	printf("valid\n");
	exit(0);
}
;
A:LETTER B
|'_' LETTER B
| LETTER
;
B:LETTER B
|DIGIT B
|LETTER
|DIGIT
;
%%
void main(){
	printf("Enter a Identifier\n");
	yyparse();
}
yylex(){
	char ch;
	ch=getchar();
	if(isalpha(ch)){
		return LETTER;
	}
	else if(isdigit(ch)){
		return DIGIT;
	}
	else{
		return ch;
	}
}
yyerror(){
	printf("invalid\n");
	exit(0);
}
