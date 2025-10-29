#include<stdio.h>
#include<string.h>
#define MAX 20
int main(){
  int stc;
  printf("Enter the number of states:\t");
  scanf("%d",&stc);
  
  int syc;
  char sym[MAX];
  printf("Enter the number of input symbols\t");
  scanf("%d",&syc);
  printf("Enter input symbols\n");
  for(int i=0;i<syc;i++){
    scanf(" %c",&sym[i]);
  }
  
  printf("Enter state transition matrix\n");
  int stm[stc][syc];
  for(int i=0;i<stc;i++){
    for(int j=0;j<syc;j++){
      printf("(q%d,%c)-->\t",i,sym[j]);
      scanf("%d",&stm[i][j]);
    }
  }
  
  int fsc;
  printf("Enter the number of final states:\t");
  scanf("%d",&fsc);
  printf("Enter the final states:\t");
  int finalStates[fsc];
  for(int i=0;i<fsc;i++){
    scanf("%d",&finalStates[i]);
  }
  
  int cs=0;
  while(1){
    char input[MAX]={0}; 
    printf("Enter input string:\t");
    scanf(" %s",input);
    
    char c;
    cs=0;
    for(int i=0;i<strlen(input);i++){
    
      int index=-1;
      c=input[i];
      
      for(int j=0;j<syc;j++){
        if(c==sym[j]){
          index=j;
          break;
        }
      }
      if(index==-1){
        printf("invalid symbol %c\n",c);
        return 1;
      }
      cs=stm[cs][index];
    }
    
    int accepted=0;
    for(int i=0;i<fsc;i++){
      if(cs==finalStates[i]){
        accepted=1;
        break;
      }
    }
    if(accepted){
      printf("accepted\n");
    }else{
      printf("rejected\n");
    }
  }
}
/*
stc - states count
syc - symbol count
sym - symbols array
stm - state transition matrix
finalStates - final states array
fsc - final states count
cs - current state
input - input string
index - index of the symbol
*/
