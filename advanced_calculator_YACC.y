%{
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
%}
%token NUMBER
%left '+''-'
%left '*''/'
%right UMINUS
%%
L:E'\n' {
	printf("Result is %d\n",$1);
	exit(0);
}
;
E:E'+'E {
	$$=$1+$3;
}
| E'*'E {
	$$=$1*$3;
}
| E'-'E {
	$$=$1-$3;
}
| E'/'E {
	$$=$1/$3;
}
| E'^'E {
	$$=pow($1,$3);
}
| '-'E {
	$$=-$2;
}
|'('E')' {
	$$=$2;
}
| NUMBER {
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
