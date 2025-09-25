#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 15
char postfix[MAX],infix[MAX],stack[MAX];
int top=-1;
int prec(char c){
	if(c=='^')
		return 3;
	else if(c=='*'||c=='/')
		return 2;
	else if(c=='+'||c=='-')
		return 1;
	return -1;
}

void inToPost(char *infix){
	int j=0;
	int len = strlen(infix);
	for(int i=0;i<len;i++){
		char c=infix[i];
		
		if(isalnum(c))
			postfix[j++]=c;
		else if(c=='(')
			stack[++top]=c;
		else if(c==')'){
			while(stack[top]!='('&& top>-1){
				postfix[j++]=stack[top--];
			}
			top--;// for removing '('
		}
		else{
			int p=prec(c);
			while(top>-1 && prec(stack[top])>p && prec(stack[top])==p){
				postfix[j++]=stack[top--];
			}
			stack[++top]=c;
		}
	}
	while(top>-1)
		postfix[j++]=stack[top--];
	postfix[j]='\0';
	printf("infix [%s] -> postfix[%s]\n",infix,postfix);
}
int main(){
	printf("enter the infix expression\n");
	scanf("%s",infix);
	inToPost(infix);
}
