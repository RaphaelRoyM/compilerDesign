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

void ThreeAddressCode(){
  printf("Three address code\n");
  int slno=1;
  char ch1,ch2,ch3;
  top=-1;
  for(int i=0;i<strlen(postfix);i++){
    ch2=postfix[i];
    if(isalnum(postfix[i])){
      stack[++top]=postfix[i];
    }
    else{
      ch3=stack[top--];
      ch1=stack[top--];
      if(isalpha(ch1)&&isalpha(ch3)){
        printf("t%d = %c%c%c\n",slno,ch1,ch2,ch3);
      }
      else if(isdigit(ch1)&&isalpha(ch3)){
        printf("t%d = t%c%c%c\n",slno,ch1,ch2,ch3);
      }
      else if(isalpha(ch1)&&isdigit(ch3)){
        printf("t%d = %c%ct%c\n",slno,ch1,ch2,ch3);
      }
      else if(isdigit(ch1)&&isdigit(ch3)){
        printf("t%d = t%c%ct%c\n",slno,ch1,ch2,ch3);
      }
      stack[++top]=slno+'0';
      slno++;
    }
    
  }
}

void QuadTuple(){
    printf("Quad tuple representation\nslno\top\targ1\targ2\tresult\n");
  int slno=1;
  char ch1,ch2,ch3;
  top=-1;
  for(int i=0;i<strlen(postfix);i++){
    ch2=postfix[i];
    if(isalnum(postfix[i])){
      stack[++top]=postfix[i];
    }
    else{
      ch3=stack[top--];
      ch1=stack[top--];
      if(isalpha(ch1)&&isalpha(ch3)){
        printf("%d\t%c\t%c\t%c\tt%d\n",slno,ch2,ch1,ch3,slno);
      }
      else if(isdigit(ch1)&&isalpha(ch3)){
        printf("%d\t%c\tt%c\t%c\tt%d\n",slno,ch2,ch1,ch3,slno);
      }
      else if(isalpha(ch1)&&isdigit(ch3)){
        printf("%d\t%c\t%c\tt%c\tt%d\n",slno,ch2,ch1,ch3,slno);
      }
      else if(isdigit(ch1)&&isdigit(ch3)){
        printf("%d\t%c\tt%c\tt%c\tt%d\n",slno,ch2,ch1,ch3,slno);
      }
      stack[++top]=slno+'0';
      slno++;
    }
    
  }
}

void Triple(){
  printf("Triple representation\nIndex\top\targ1\targ2\n");
  int slno=1;
  char ch1,ch2,ch3;
  top=-1;
  for(int i=0;i<strlen(postfix);i++){
    ch2=postfix[i];
    if(isalnum(postfix[i])){
      stack[++top]=postfix[i];
    }
    else{
      ch3=stack[top--];
      ch1=stack[top--];
      if(isalpha(ch1)&&isalpha(ch3)){
        printf("(%d)\t%c\t%c\t%c\n",slno,ch2,ch1,ch3);
      }
      else if(isdigit(ch1)&&isalpha(ch3)){
        printf("(%d)\t%c\t(%c)\t%c\n",slno,ch2,ch1,ch3);
      }
      else if(isalpha(ch1)&&isdigit(ch3)){
        printf("(%d)\t%c\t%c\t(%c)\n",slno,ch2,ch1,ch3);
      }
      else if(isdigit(ch1)&&isdigit(ch3)){
        printf("(%d)\t%c\t(%c)\t(%c)\n",slno,ch2,ch1,ch3);
      }
      stack[++top]=slno+'0';
      slno++;
    }
    
  }
}

int main(){
  printf("Enter the exprression\n");
  scanf("%s",expr);
  intopo();
  expr[strcspn(expr,"\n")]='\0';
  printf("postfix expression is:\t%s\n",postfix);
  ThreeAddressCode();
  QuadTuple();
  Triple();
}
