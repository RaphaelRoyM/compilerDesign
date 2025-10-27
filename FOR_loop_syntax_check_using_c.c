#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(int argc, char *argv[]){
	if(argc<2){//check if user send input file with ./a.out
		printf("usage ./a.out filename\n");
		return 1;
	}
	FILE *fp = fopen(argv[1],"r");//opening file in reading mode
	if(!fp)
		return -1;
		
	char ch;//for reading each charecter from file
	char lexeme[50][20]={{'\0'}};//since 2d marix we use {{}} else we use {} to set all space of matrix with '\0'.this matrix is used to store tokens .each row have a token
	int row=0,col=0;
	while((ch = fgetc(fp))!=EOF){//read each charecter till end of file.
	        if(ch=='\n')//if this is removed there will be empty row in matrix
	          continue;
		if(isspace(ch)){ //check for space
			if(col!=-1){
				lexeme[row++][col]='\0';
				col=0;
			}
		}
		else if(ch=='(' || ch == '=' || ch == ';' || ch == ')' || ch=='{' || ch == '}' || ch == '[' || ch==']'){    //it is better to add more single charecter tokens for more efficiency.
	          if(col>0){
	            lexeme[row++][col]='\0';    //before adding the above token '\0' is added to the current token in 2d marix 
	            col=0;
	          }
		  lexeme[row][0]=ch;    //the new token is stored in the 2d matrix 
		  lexeme[row][1]='\0';    //the next charecter is set to \0 so that we can read the whole row (token ) as a string
		  row++;    //completed the token increment for the next token
		  col=0;    //col is set to zero for next charecter read
		}
		else{
		    lexeme[row][col++]=ch;  //alphanumaric values {} etc
		}
	}
	fclose(fp);//closing file because the content is stored in 2d matrix
	
	//to check for loop syntax
	//idea- 1. check for 'for' token .2. check for '('. 2. check for ')' ,in the way count ;. 3. when ')' is found look the count of semi colon
	int i=0,foundFor,semicolonCount,closeBracket;
	while(i!=row){
	        semicolonCount=0;
	        closeBracket=0;
	        foundFor=0;
		//printf("%s\n",lexeme[i]);
		if(strcmp(lexeme[i],"for")==0){
		  foundFor=1;
		  if(i+1<row && strcmp(lexeme[i+1],"(")==0){
		    int j=i+2;
		    while(j!=row){
		      if(strcmp(lexeme[j],")")==0){
		        closeBracket=1;
		        if(semicolonCount>2){//if semicolon inside for is less than 2
		          printf("more no of semicolons\n");
		          return -1;
		        }
		        else if(semicolonCount<2){    //if semicolon inside for is more than 2
		          printf("fever no of semicolons\n");
		          return -1;
		        }
		        break;
		      }
		      if(strcmp(lexeme[j],";")==0){
		        semicolonCount++;
		      }
		      j++;
		    }
		  }
		  else{
		    printf("error- no open bracket found after 'for'\n");
		    return -1;
		  }
		}
		i++;
	}
	printf("no error found or no for loop found\n");
}
