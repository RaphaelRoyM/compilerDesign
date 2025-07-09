/*full forms
  lc -> line count
  ch -> charecter read from input file
  sn -> serial number in output
  relational_op -> relatioal operand

*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(int argc, char *argv[])
{
  // declarations
  FILE *fp1, *fp2;
  int flag1 = 0;
  char word[40];
  fp1 = fopen(argv[1], "r");
  fp2 = fopen(argv[2], "w");
  char key1[34][40] = {
      "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

  char ch, ch1;
  int lc = 1, sn = 1;
  printf("\nSINo\tlexeme\ttoken\tlineNo\t");
  while ((ch = fgetc(fp1)) != EOF)
  {
    if (isalpha(ch))
    {
      int i = 0;
      word[0] = '\0';
      printf("\n%d\t", sn);
      sn++;
      do
      {
        word[i++] = ch;
        printf("%c", ch);
      } while (isalnum(ch = fgetc(fp1))); // Accept letters and digits
      word[i] = '\0';

      int isKeyword = 0;
      for (int k = 0; k < 34; k++)
      {
        if (strcmp(word, key1[k]) == 0)
        {
          isKeyword = 1;
          break;
        }
      }

      if (isKeyword)
      {
        printf("\tkeyword   \t%d", lc);
      }
      else
      {
        printf("\tidentifier   \t%d", lc);
      }
    }

    else if (isdigit(ch))
    {
      printf("\n%d\t", sn); // print serial number
      do
      {
        printf("%c", ch);
      } while (isdigit(ch = fgetc(fp1)) || (ch == '.'));
      ungetc(ch, fp1);
      printf("\tdigit    \t%d", lc);
    }
    else if ((ch == ' ') || (ch == '\t'))
    {
    }
    else if (ch == '\n')
    {
      lc++;
    }
    else if (ch == ';')
    {
      printf("\n%d\t%c\tsemi_colon\t%d", sn, ch, lc);
      sn++;
    }
    else if ((ch == '(') || (ch == '{') || (ch == '['))
    {
      printf("\n%d\t%c\topen_bracket\t%d", sn, ch, lc);
      sn++;
    }
    else if ((ch == ')') || (ch == '}') || (ch == ']'))
    {
      printf("\n%d\t%c\tclose_bracket\t%d", sn, ch, lc);
      sn++;
    }
    else if ((ch == '+') || (ch == '/') || (ch == '*') || (ch == '-'))
    {
      printf("\n%d\t%c\tarithematic_op\t%d", sn, ch, lc);
      sn++;
    }
    else if ((ch == '!') || (ch == '>') || (ch == '<'))
    {
      printf("\n%d\t%c", sn, ch);
      sn++;
      if ((ch1 = fgetc(fp1)) == '=')
      {
        printf("%c\trelational_op\t%d", ch1, lc);
        sn++;
      }
      else
      {
        printf("\trelational_op\t%d", lc);
        ungetc(ch1, fp1);
        sn++;
      }
    }
    else if ((ch) == '=')
    {
      printf("\n%d\t%c\tassignment_op\t%d", sn, ch, lc);
      sn++;
    }
    else
    {
      printf("\n%d\t%c\tundefined\t%d", sn, ch, lc);
      sn++;
    }
  }
}