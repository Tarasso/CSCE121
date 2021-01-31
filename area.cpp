#include <stdio.h>
#include <stdlib.h>

int main()
{

 printf("area\n");
 char buf[1000];

 float length;
 printf("input a length:");
 gets(buf);
 length = atof(buf);
 printf("length = %s\n",buf);


 float width;
 printf("input a width:");
 gets(buf);
 width = atof(buf);
 printf("width = %s\n",buf);

 printf("the area is %f.\n", length*width);

}
