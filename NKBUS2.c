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
int maxtime;
int take_time = 0;
int _t = 0;
int main(){
 maxtime = 0;
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
 	if(data[i][j] > maxtime) maxtime = data[i][j];
  }
  qsort(data[i], m[i], sizeof(int), compare);
 }
// printdata();
// printf("max : %d\n",maxtime);
 init(); 
 solve();
 printf("%d\n", take_time+_t);

}

void init(){
 int i = 0;
 for(i = 0; i < N; i++){
  take_time += t[i];
 }
// take_time += maxtime;// the maximum time needed to take m people
  
 }

void solve(){
 int delta = maxtime;
 int taccept = 0;
 int npeople = 0;
 int i = 0, j = 0;
 int time = 0;
 while(delta > 1){
    //printf("delta : %d\n",delta);
    _t += delta/2;
    time = _t;
    for(i = 0; i < N; i++){
        if(taccept == 1) break;
	for(j = 0; j < m[i]; j++){
	  if(data[i][j] <= time) npeople++;
	  if(M <= npeople)taccept = 1;
 	}
	time += t[i];
    }
   if (taccept == 0) {
  	//take_time += time/2;
	printf("plus\n");
   } else{
       if(delta != 2)_t -= delta/2;
       	
   }
   delta -= delta/2; 
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
