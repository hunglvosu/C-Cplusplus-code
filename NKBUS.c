#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

void printdata();
void init();
void solve();

int **data;
int **F;
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
  
 }
 printdata();
 //init(); 
 //solve();
}

void init(){
  F = (int **)malloc(N*sizeof(int *));
  int i = 0;
  for(i = 0; i < N; i++){
   F[i] = (int*)malloc(M*sizeof(int));
   memset(F[i], 0, M*sizeof(int));
  }
  F[0][0] = t[0]
  for(i = 1; i < m[0]; i++){
    //if(data[0][i] <= t[0) F[][]
  }
 }

void solve(){
  
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
