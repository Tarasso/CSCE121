#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
 char buf[1000];
 printf("> ");
 while(gets(buf))  // not secure
 {
  printf("%s\n",buf);
  printf("length = %d\n",strlen(buf));
  if(strchr(buf,'a')!=NULL)
  {
  printf("position of first 'a' is %d\n",strchr(buf,'a')-buf);
  }
  for (int i = 0; i<strlen(buf); i++)
  {
   buf[i] = toupper(buf[i]);
  }
  printf("%s\n",buf);
  printf("> ");
 }
}
