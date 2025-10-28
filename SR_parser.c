#include<stdio.h>
char input[20]={0}, stack[21]={0};
int top=-1,j=0,slno=1;

void reduce(){
  for(int z=0;z<=top;z++){
    if(stack[z]=='i'){
      stack[z]='E';
      stack[z+1]='\0';
      printf("%d\t%s\t%s\treduce E->i \n",slno++,stack,input);
    }
  }
  for(int z=0;z<=top;z++){
    if(stack[z]=='('&&stack[z+1]=='E'&&stack[z+2]==')'){
      stack[z]='E';
      stack[z+1]='\0';
      top-=2;
      printf("%d\t%s\t%s\treduce E->(E) \n",slno++,stack,input);
    }
  }
  for(int z=0;z<=top;z++){
    if(stack[z]=='E'&&stack[z+1]=='+'&&stack[z+2]=='E'){
      stack[z]='E';
      stack[z+1]='\0';
      top-=2;
      printf("%d\t%s\t%s\treduce E->E+E\n",slno++,stack,input);
    }
  }
  for(int z=0;z<=top;z++){
    if(stack[z]=='E'&&stack[z+1]=='*'&&stack[z+2]=='E'){
      stack[z]='E';
      stack[z+1]='\0';
      top-=2;
      printf("%d\t%s\t%s\treduce E->E*E\n",slno++,stack,input);
    }
  }
}

int main(){
  
  printf("Enter the string:\t");
  scanf("%s",input);
  
  char ch;
  printf("slno\tstack\tinput\taction\n");
  while(input[j]!='\0'){
    ch=input[j];
    stack[++top]=ch;
    stack[top+1]='\0';
    input[j++]=' ';
    printf("%d\t%s\t%s\tshifting %c\n",slno++,stack,input,ch);
    reduce();
  }
  if(stack[0]=='E'&&stack[1]=='\0'){
    printf("Accepted\n");
  }
  else{
    printf("Rejected\n");
  }
  
}
