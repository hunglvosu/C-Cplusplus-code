#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
double *a;// dynamic array declaration
void process(double *p, int length);
double round2d(double a);// round a float number upto 2 digits
//FILE *ofp; 

int main(int argc, char *argv[]){
 //char *filename = argv[1];
 //FILE *fp = fopen(filename, "r");
 //ofp = fopen("110103.oup","w");
 int count = -1;
 //fscanf(fp,"%d",&count);
 while( scanf("%d",&count) > 0){
    if (count == 0) break;
    //fscanf(fp, "%d",&count);
    a = (double*) malloc(count*sizeof(double));
    int i = 0;
    for (i = 0; i < count; i++){
	double temp;
	//fscanf(fp,"%f",&temp);
        scanf("%lf", &temp);
	a[i] = temp;
    }
    //if (count == 0) break;
    process(a,count); 
    memset(a,0,sizeof(a)); 
 }
 //printf("input file: %s\n", filename);
 //fclose(fp);
 //fclose(ofp);
 
}

void process(double *p, int length){
 //printf("numelements: %d\n", length);
 int i = 0;
 double sum = 0.0; 
 double avg = 0.0;
 for (i = 0; i < length; i++){
   //printf("element at %d: %.2f\n",i,*(p+i));
   sum += *(p+i);
 }
 //printf("avg: %f\n", avg);
 avg = round2d(sum/length);
 double exchange = 0.0f;
 double residual= 0.0f;
 double ramount = 0.0f;
 if (sum > avg*length){
   for (i = 0; i < length; i++){
	if(*(p+i) > avg){
	    residual += *(p+i) - avg - 0.01f;
        }else {
	    ramount += avg - *(p+i);
	}
  }
  exchange = ramount;
  //printf("give amount : %f\n", gamount);
  //printf("recieve amount: %f\n", ramount);
 }else {
   for (i = 0; i < length; i++){
	if(*(p+i) > avg){
	  exchange += *(p+i)-avg;
	}
    }
 }
 //printf("exchange:%0.2f\n",exchange);
 //fprintf(ofp, "$%.2f\n",exchange);
 if (residual > ramount) exchange += residual - ramount;
 printf("$%.2lf\n",exchange);

}

double round2d(double a){
 int b = (int)(a*100.0);
 return b/100.0; 
}
