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
void assem(int start, char *argv[]){
    top=-1;
    
    FILE *fp2 = fopen(argv[1],"w");
    fprintf(fp2,"assembly code generation\n");
    int j=0;
    char ch;
    while(postfix[j]!='\0'){
        ch=postfix[j];
        if(isalnum(ch)){
            
            fprintf(fp2,"%d:\tMOV A,%c\n%d:\tPUSH A\n",start,ch,start++);
        }
        else{
            if(ch=='+'){
                fprintf(fp2,"%d:\tPOP B\n%d:\tPOP A\n%d:\tADD B\n%d:\tPUSH A\n",start++,start++,start++,start++);
            }
            else if(ch=='*'){
                fprintf(fp2,"%d:\tPOP B\n%d:\tPOP A\n%d:\tMUL B\n%d:\tPUSH A\n",start++,start++,start++,start++);
            }
            else if(ch=='/'){
                fprintf(fp2,"%d:\tPOP B\n%d:\tPOP A\n%d:\tDIV B\n%d:\tPUSH A\n",start++,start++,start++,start++);
            }
            else if(ch=='-'){
                fprintf(fp2,"%d:\tPOP B\n%d:\tPOP A\n%d:\tSUB B\n%d:\tPUSH A\n",start++,start++,start++,start++);
            }
        }
        j++;
    }
    fprintf(fp2,"%d:\tHALT\n",start++);
    
}
int main(int argc,char *argv[]){
	printf("enter the infix expression\n");
	scanf("%s",infix);
	printf("enter the starting address\n");
	int start;
	scanf("%d",&start);
	inToPost(infix);
	assem(start,argv);
	
}
