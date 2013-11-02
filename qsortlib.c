#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b);

int array[] = {1,2,3,4,9,8,7,6,5,4};
int main(){
  qsort(array, 10, sizeof(int), compare);
  int i = 0; 
  for(i = 0;i < 10; i++){
   printf("%d---",array[i]);
  }
 
}
int compare(const void *a, const void *b){
  return(*(int*)a - *(int *)b);
 }
