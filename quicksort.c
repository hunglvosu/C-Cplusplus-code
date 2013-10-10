#include<stdio.h>
#define MAX 9 

int *qsort(int *arr, int n);
void swap(int *a, int *b);
int a[MAX] = {5,4,3,6,7,8,2,1,0};
int *p = a;

int main(){
int i = 0;
for (i = 0; i < MAX; i++){
	printf("%d\n",*(p+i));
 }
qsort(p, MAX);
printf("Array after being sorted\n");
for (i = 0; i < MAX; i++){
	printf("%d\n",*(p+i));
 }
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
