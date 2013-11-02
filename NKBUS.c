#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

void printdata();
void init();
void solve();
int compare(const void *a, const void *b);

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
  qsort(data[i], m[i], sizeof(int), compare);
 }
// printdata();
 init(); 
 solve();
 printf("%d\n", F[N-1][M]+ t[N-1]);
// for(i = 0; i < N; i++){
//   for(j = 0; j < M+1; j++){
//     printf("F[%d][%d]= %d--",i,j,F[i][j]);
//   }
//  printf("\n");
// }
}

void init(){
  F = (int **)malloc(N*sizeof(int *));
  int i = 0;
  for(i = 0; i < N; i++){
   F[i] = (int*)malloc((M+1)*sizeof(int));
   memset(F[i], 0, (M+1)*sizeof(int));
  }
  F[0][0] = 0;
  int jmax = M;
  if (m[0] < M) jmax = m[0];
//  printf("F[0][0] = %d\n",F[0][0]);  
  for(i = 1; i <= jmax; i++){
    if(data[0][i-1] == F[0][i-1]) F[0][i] = F[0][i-1];
    else {
	F[0][i] = data[0][i-1];
   }
  // printf("F[0][%d] = %d\n",i,F[0][i]);
  }
  
 }

void solve(){
 int i = 0, j = 0, k = 0, s = 0, time = 0;
 int p = 0;// the maximal number of people at i
 for (i = 1; i < N; i++){
//    printf("sove %d\n",i);
    p += m[i-1];
    int jmax = M;
    if (p + m[i] < jmax) jmax = p + m[i];
    F[i][0] = F[i-1][0] + t[i-1];
    for (j = 1; j <= jmax; j++){
        int minsplit = 2000000000; 
        int splittemp = 0;
        if( j <= m[i]){
	    for(s = 1; s <=j; s++){
		splittemp = F[i-1][j-s] + t[i-1];
		if(data[i][s-1] > splittemp) splittemp = data[i][s-1];
		if(splittemp < minsplit) minsplit = splittemp;
   	    }
           if(F[i-1][j] > 0 && F[i-1][j] + t[i-1] < minsplit) minsplit = F[i-1][j] + t[i-1];
	 
	 } 
	else {
	   for(s = 1; s <= m[i]; s++){
		splittemp = F[i-1][j-s] + t[i-1];
		if(data[i][s-1]>splittemp) splittemp = data[i][s-1];
		if (splittemp< minsplit) minsplit = splittemp;
	   }
      	  if(F[i-1][j] > 0 && F[i-1][j] + t[i-1] < minsplit)minsplit = F[i-1][j] + t[i-1];
 
	 }
 
	F[i][j] = minsplit;      
        }
    }
   
   
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
