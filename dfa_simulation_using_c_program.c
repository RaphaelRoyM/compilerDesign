/*
  stc = state count
  syc = input symbol count
  stm = state transition matrix
  fs = final states
  fsc = final state count
  cs = current state
  ch = character
  sym = symbol
  insy[] = input symbol array
  index = used to track the input symbols in insy[]
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main(){

    int stc;
    printf("enter the no of states\t");
    scanf("%d",&stc);
    
    int syc;
    printf("enter the no of input symbols\t");
    scanf("%d",&syc);
    char insy[syc];
    printf("enter the input symbols\n");
    for(int i=0;i<syc;i++){
        scanf(" %c",&insy[i]);
    }
    
    int stm[stc][syc];
    printf("enter the state transition matrix\n");
    for(int i=0;i<stc;i++){
      for(int j=0;j<syc;j++){
        printf("(q%d,%c)",i,insy[j]);
        scanf("%d",&stm[i][j]);
      }
    }
    
    int fsc;
    printf("enter the no of final states\t");
    scanf("%d",&fsc);
    
    int fs[fsc];
    printf("enter the final states");
    for(int i=0;i<fsc;i++){
        scanf("%d",&fs[i]);
    }
    
    char in[100];
    printf("enter the input string\t");
    scanf("%s",in);
    
    int k=0,cs=0,index=-1;
    char ch;
    while((ch=in[k])!='\0'){
        for(int i=0;i<syc;i++){
            if(ch==insy[i]){
            index=i;
            break;
            }
        }
        if(index==-1){
            printf("invalid input\n");
            return 1;
        }
        else{
            cs=stm[cs][index];
            k++;
        }
    }
    for(int i=0;i<fsc;i++){
        if(cs==fs[i]){
          printf("accepted\n");
          return 0;
        }
    }
    printf("rejected\n");  
}
/*
sample output
**accepted condition**
enter the no of states	4
enter the no of input symbols	2
enter the input symbols
a
b
enter the state transition matrix
(q0,a)1
(q0,b)3
(q1,a)3
(q1,b)2
(q2,a)2
(q2,b)2
(q3,a)3
(q3,b)3
enter the no of final states	1
enter the final states2
enter the input string	abbba
accepted

**rejected condition**
gcc dfa.c 
./a.out
enter the no of states	4
enter the no of input symbols	2
enter the input symbols
a
b
enter the state transition matrix
(q0,a)1
(q0,b)3
(q1,a)3
(q1,b)2
(q2,a)2
(q2,b)2
(q3,a)3
(q3,b)3
enter the no of final states	1
enter the final states2
enter the input string	bbaab
rejected

*/
