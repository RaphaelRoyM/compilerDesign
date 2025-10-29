%{
#include <stdio.h>
#include <string.h>
int lc = 1;
int sn = 1;
FILE *fp2;
%}
%%
"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"inline"|"int"|"long"|"register"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while" {
    fprintf(fp2, "\n%d\t%s\tkeyword\t\t%d", sn++, yytext, lc);
}
[a-zA-Z_][a-zA-Z0-9_]* {
    fprintf(fp2, "\n%d\t%s\tidentifier\t%d", sn++, yytext, lc);
}
[0-9]+(\.[0-9]+)? {
    fprintf(fp2, "\n%d\t%s\tnumber\t\t%d", sn++, yytext, lc);
}
";" {
    fprintf(fp2, "\n%d\t%s\tsemi_colon\t%d", sn++, yytext, lc);
}
"("|"{"|"[" {
    fprintf(fp2, "\n%d\t%s\topen_bracket\t%d", sn++, yytext, lc);
}
")"|"}"|"]" {
    fprintf(fp2, "\n%d\t%s\tclose_bracket\t%d", sn++, yytext, lc);
}
"+"|"-"|"*"|"/" {
    fprintf(fp2, "\n%d\t%s\tarithmetic_op\t%d", sn++, yytext, lc);
}
"=="|">="|"<="|"<"|">"|"!=" {
    fprintf(fp2, "\n%d\t%s\trelational_op\t%d", sn++, yytext, lc);
}
"=" {
    fprintf(fp2, "\n%d\t%s\tassignment_op\t%d", sn++, yytext, lc);
}
[ \t]+    ;     // ignore spaces and tabs
\n        { lc++; }
. {
    fprintf(fp2, "\n%d\t%s\tundefined\t%d", sn++, yytext, lc);
}
%%
int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: ./a.out <inputfile> <outputfile>\n");
        return 1;
    }
    FILE *fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "w");
    yyin = fp1;
    fprintf(fp2, "SNo\tLexeme\tToken\t\tLineNo\n");
    yylex();
    fclose(fp1);
    fclose(fp2);
    printf("Output successfully written to %s\n", argv[2]);
    return 0;
}
int yywrap() {
	return 1;
}
