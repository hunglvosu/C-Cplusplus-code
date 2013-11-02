#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

void printdata();
void init();
void solve();
int *qsort(int *arr, int n);
void swap(int *a, int *b);

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
 init(); 
 solve();
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

int *qsort(int *arr, int n){
if (n < 2) {
// the array contains 1 element or smaller
return arr;

} else {

// pivot is the first element of the array
int pivot = *arr;

int i = 0;
int k = 0;
for (i = 1; i < n; i++){
 if (*(arr+i)< pivot){
        if(k>0){
                swap(arr+i, arr+k);
                k++;
   }
  } else {
        if (k==0){
                k = i;
        }
  }
}
i--;
if ( k > 0){
   swap(arr+k-1, arr);
   pivot = k-1;
} else {
   swap(arr+i, arr);
   pivot = i;
}
//sort the left array
qsort(arr,pivot);
// sort the right array
qsort(arr+pivot+1, n-pivot-1);

return arr;
 }
}
void swap(int *a, int *b){
   int x = *a;
   *a = *b;
   *b = x;
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
