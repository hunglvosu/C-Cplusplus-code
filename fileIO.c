#include<stdio.h>

int readwrite(char *inFileName, char *outFileName);
int main(){
 readwrite("newfile.txt", "copyOfNewfile.txt");
}
int readwrite(char* inFileName, char *outFileName){
 FILE *ifp = fopen(inFileName, "r");
 FILE *ofp = fopen(outFileName, "w");
 if (ifp == NULL){
   printf("Error in opening file\n");
   return -1;
 }
 int i = 0;
 fscanf(ifp, "%d",&i);
 while(!feof(ifp)){
   printf("%d\n", i);
   fprintf(ofp,"%d\n",i);
   fscanf(ifp, "%d", &i);
   //fprintf(ofp, "%d\n",i);
 }
 fclose(ifp);
 fclose(ofp);
 return 0;
}

