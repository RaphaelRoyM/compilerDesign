%{
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
float a;
int flag=0;
%}
DIGIT [0-9]
%%
"+" {
	flag=1;
}
"-" {
	flag=2;
}
"*" {
	flag=3;
}
"/" {
	flag=4;
}
"^" {
	flag=5;
}
{DIGIT}+ {
	if(flag==0){
		a=atoi(yytext);
	}
	else if(flag==1){
		a+=atoi(yytext);
	}
	else if(flag==2){
		a-=atoi(yytext);
	}
	else if(flag==3){
		a*=atoi(yytext);
	}
	else if(flag==4){
		a/=atoi(yytext);
	}
	else if(flag==5){
		a=pow(a,atoi(yytext));
	}
	else{
		printf("Invalid operation\n");
		exit(0);
	}
}
"\n" {
	printf("Result is %.2f\n",a);
	exit(0);
}
. {
	printf("Invalid Operation\n");
}
%%
void main(){
	printf("\nSimple Lex Calculator\nEnter the expression:\t");
	yyin=stdin;
	yylex();
}
int yywrap(){
	return -1;
}


