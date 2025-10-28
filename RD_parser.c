/*
E-> T E1
E1-> + T E1 |epslon
T-> F T1
T1-> * F T1 | epslon
F-> ( E ) | i
*/
#include<stdio.h>
char input[100]={0};
int j=0;
int E();
int E1();
int T();
int T1();
int F();

int main(){
  printf("Enter the input string:\t");
  scanf("%s",input);
  
  if(E() && input[j]=='\0'){
    printf("Accepted\n");
  }
  else{
    printf("rejected\n");
  }
  return 0;
}
//E-> T E1
int E(){
  printf("Expanding E->T E1\n");
  if(T()){
    if(E1()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    return 0;
  }
}
//T-> F T1
int T(){
  printf("Expanding T->F T1\n");
  if(F()){
    if(T1()){
      return 1;
    }
    else{
      return 0;
    }
  }
  else{
    return 0;
  }
}
//E1-> + T E1 |epslon
int E1(){
  if(input[j]=='+'){
    printf("Expanding E1-> + T E1\n");
    printf("Consuming +\n");
    j++;    
    if(T()){
      if(E1()){
        return 1;
      }
      else{
        return 0;
      }
    }
    else{
      return 0;
    }
  }
  else{
    printf("Expanding E1-> epslon\n");
    return 1;
  }
}
//T1-> * F T1 | epslon
int T1(){
  if(input[j]=='*'){
    printf("Expanding T1-> * F T1\n");
    printf("Consuming *\n");
    j++; 
    if(F()){
      if(T1()){
        return 1;
      }
      else{
        return 0;
      }
    }
    else{
      return 0;
    }
  }
  else{
    printf("Expanding T1-> epslon\n");
    return 1;
  }
}
//F-> ( E ) | i
int F(){
  if(input[j]=='('){
  printf("Expanding F-> ( E )\n");
  printf("Consuming (\n");
    j++; 
    if(E()){
      if(input[j]==')'){
        printf("Consuming )\n");
        j++; 
        return 1;
      }
      else{
        return 0;
      }
    }
  }
  else if(input[j]=='i'){
      printf("Expanding F-> i\n");
      printf("Consuming i\n");
      j++;
      return 1;
    }
  else{
    return 0;
  }
}
