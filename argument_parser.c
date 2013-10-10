#include<stdio.h>
#include<string.h>
int main(int argc, char*argv[]){
 int c = 0;
 char *inputStr;
 for (c = 1; c < argc; c++){
   if (strcmp(argv[c],"f")){
      printf("this works\n");
      c++;
      inputStr = argv[c];
   }
 }
 printf("input string is %s\n",inputStr);
 return 0;
}
