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
void ThreeAddressCode(){
	printf("GENERAL THREE ADDRESS CODE\n");
	int top=-1,i=0,slno=1;
	char ch1,ch2,ch3;
	while(postfix[i]!='\0'){
		ch1=postfix[i];
		if(isalpha(ch1)){
			stack[++top]=ch1;
		}
		else{
			ch3=stack[top--];
			ch2=stack[top--];
			if(isalpha(ch2)&&isalpha(ch3)){
				printf("t%d = %c%c%c\n",slno,ch2,ch1,ch3);
			}
			else if(isalpha(ch2)&&isdigit(ch3)){
				printf("t%d = %c%ct%c\n",slno,ch2,ch1,ch3);
			}
			else if(isdigit(ch2)&&isalpha(ch3)){
				printf("t%d = t%c%c%c\n",slno,ch2,ch1,ch3);
			}
			else if(isdigit(ch2)&&isdigit(ch3)){
				printf("t%d = t%c%ct%c\n",slno,ch2,ch1,ch3);
			}
			stack[++top]=(slno+'0');
			slno++;
		}
		i++;
	}
}

void QuadTuple(){
	printf("QUAD TUPLEs\nOP\tARG1\tARG2\tRESULT\n");
	int top=-1,i=0,slno=1;
	char ch1,ch2,ch3;
	while(postfix[i]!='\0'){
		ch1=postfix[i];
		if(isalpha(ch1)){
			stack[++top]=ch1;
		}
		else{
			ch3=stack[top--];
			ch2=stack[top--];
			if(isalpha(ch2)&&isalpha(ch3)){
				printf("%c\t%c\t%c\tt%c\n",ch1,ch2,ch3,slno+'0');
			}
			else if(isalpha(ch2)&&isdigit(ch3)){
				printf("%c\t%c\tt%c\tt%c\n",ch1,ch2,ch3,slno+'0');
			}
			else if(isdigit(ch2)&&isalpha(ch3)){
				printf("%c\tt%c\t%c\tt%c\n",ch1,ch2,ch3,slno+'0');
			}
			else if(isdigit(ch2)&&isdigit(ch3)){
				printf("%c\tt%c\tt%c\tt%c\n",ch1,ch2,ch3,slno+'0');
			}
			stack[++top]=(slno+'0');
			slno++;
		}
		i++;
	}
}

void Triple(){
	printf("QUAD TUPLEs\nOP\tARG1\tARG2\tRESULT\n");
	int top=-1,i=0,slno=1;
	char ch1,ch2,ch3;
	while(postfix[i]!='\0'){
		ch1=postfix[i];
		if(isalpha(ch1)){
			stack[++top]=ch1;
		}
		else{
			ch3=stack[top--];
			ch2=stack[top--];
			if(isalpha(ch2)&&isalpha(ch3)){
				printf("%c\t%c\t%c\t%c\n",ch1,ch2,ch3,slno+'0');
			}
			else if(isalpha(ch2)&&isdigit(ch3)){
				printf("%c\t%c\tt%c\tt%c\n",ch1,ch2,ch3,slno+'0');
			}
			else if(isdigit(ch2)&&isalpha(ch3)){
				printf("%c\tt%c\t%c\tt%c\n",ch1,ch2,ch3,slno+'0');
			}
			else if(isdigit(ch2)&&isdigit(ch3)){
				printf("%c\tt%c\tt%c\tt%c\n",ch1,ch2,ch3,slno+'0');
			}
			stack[++top]=(slno+'0');
			slno++;
		}
		i++;
	}
}

int main(){
	printf("enter the infix expression\n");
	scanf("%s",infix);
	inToPost(infix);
	ThreeAddressCode();
	QuadTuple();
}
