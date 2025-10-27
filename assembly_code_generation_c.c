/*
exp - expression
prec - precedence check function
intopo - infix to postfix convertion function
postfix - postfix array
c - charecter read from infix expression
slno - to mark the number like (t1, t2,..)
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

char postfix[MAX]={0},stack[MAX]={0},expr[MAX]={0};
int top=-1;

int prec(char c){
  if(c=='^'){
    return 3;
  }
  else if(c=='/'||c=='*'){
    return 2;
  }
  else if(c=='+'||c=='-'){
    return 1;
  }
  else{
    return -1;
  }
}

void intopo(){
  int len=strlen(expr),j=0;
  for(int i=0;i<len;i++){
    int c=expr[i];
    if(isalnum(c)){
      postfix[j++]=c;
    }
    else if(c=='('){
      stack[++top]=c;
    }
    else if(c==')'){
      while(top>-1 && stack[top]!='('){
        postfix[j++]=stack[top--];
      }
      top--;
    }
    else{
      while(top!=-1&&prec(c)<=prec(stack[top])){
        postfix[j++]=stack[top--];
      }
      stack[++top]=c;
    }
  }
  while(top>-1){
    postfix[j++]=stack[top--];
  }
  postfix[j]='\0';
}
void assemblyCodeGenerator(FILE *fp){
  for(int i=0;i<strlen(postfix);i++){
    int ch=postfix[i];
    if(isalnum(ch)){
      fprintf(fp,"MOV A,%c\nPUSH A\n",ch);
    }
    
    else{
      fprintf(fp,"POP B\nPOP A\n");
      if(ch=='+'){
        fprintf(fp,"ADD B\n");
      }
      else if(ch=='-'){
        fprintf(fp,"SUB B\n");
      }
      else if(ch=='*'){
        fprintf(fp,"MUL B\n");
      }
      else if(ch=='/'){
        fprintf(fp,"DIV B\n");
      }
      fprintf(fp,"PUSH A\n");
    }
  }
}

int main(){
  FILE *fp = fopen("assembly_code_generated.txt","w");
  printf("Enter the exprression\n");
  scanf("%s",expr);
  intopo();
  expr[strcspn(expr,"\n")]='\0';
  printf("postfix expression is:\t%s\n",postfix);
  assemblyCodeGenerator(fp);
  fclose(fp);
}
