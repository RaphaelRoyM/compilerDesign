#include <stdio.h>
int main(int argc, char *argv[])
{
  char ch1, ch2;
  printf("this is the count :%d", argc);
  FILE *fp1, *fp2;
  fp1 = fopen(argv[1], "r");
  fp2 = fopen(argv[2], "w");
  while ((ch1 = fgetc(fp1)) != EOF)
  {

    if (ch1 == '/')
    {
      ch2 = fgetc(fp1);
      if (ch2 == '/')
      {
        while ((ch1 = fgetc(fp1)) != '\n')
          ;
      }
      else if (ch2 == '*')
      {
        while (((ch1 = fgetc(fp1)) != '*') && ((ch2 = fgetc(fp1)) != '/'))
        {
          ungetc(ch2, fp1);
        };
        fgetc(fp1);
      }
      else
      {
        fputc(ch1, fp2);
        ungetc(ch2, fp1);
      }
    }
    else if ((ch1 == ' ') || (ch1 == '\t') || (ch1 == '\n'))
    {
    }
    else
    {
      fputc(ch1, fp2);
    }
  }
}