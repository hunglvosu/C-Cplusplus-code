#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

void printdata();
void init();
void solve();
int compare(const void *a, const void *b);

int **data;
int *t,*m;
int N,M;

int main(){
 scanf("%d%d",&N,&M);
 data = (int **)malloc(N*sizeof(int*));
 t = (int *)malloc(N*sizeof(int));
 m = (int *)malloc(N*sizeof(int));
 int i = 0,j = 0;
 for(i = 0; i < N; i++){
   scanf("%d%d", &t[i],&m[i]);
   data[i] = (int *)malloc(m[i]*sizeof(int));
   for(j = 0; j < m[i]; j++){
	scanf("%d", &data[i][j]);
  }
  qsort(data[i], m[i], sizeof(int), compare);
 }
// printdata();
 init(); 
 solve();

}

void init(){
 
  
 }

void solve(){
 
   
}


int compare(const void *a, const void *b){
  return (*(int* )a -*(int *)b);  
}
void printdata(){
 int i = 0,j = 0;
 for(i = 0; i < N; i++){
   for(j = 0;j < m[i]; j++){
	printf("%d--", data[i][j]);
  }
  printf("\n");
 }
}
