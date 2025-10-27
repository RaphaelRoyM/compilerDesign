%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
%}
%token NUMBER
%%
L:E'\n' {
	printf("Result is %d\n",$1);
	exit(0);
}
;
E:E'+'T {
	$$=$1+$3;
}
|T {
	$$=$1;
}
;
T:T'*'F {
	$$=$1*$3;
}
|F {
	$$=$1;
}
;
F:NUMBER {
	$$=$1;
}
;
%%
void main(){
	printf("Enter the expression:\t");
	yyparse();
}
yylex(){
	char ch = getchar();
	if(isdigit(ch)){
		ungetc(ch,stdin);
		scanf("%d",&yylval);
		return NUMBER;
	}
	else{
		return ch;
	}
}
yyerror(){
	printf("Invalid Operation\n");
	exit(0);
}
