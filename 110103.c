#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
float *a;// dynamic array declaration
void process(float *p, int length);
float round2f(float a);// round a float number upto 2 digits
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
    a = (float*) malloc(count*sizeof(float));
    int i = 0;
    for (i = 0; i < count; i++){
	float temp;
	//fscanf(fp,"%f",&temp);
        scanf("%f", &temp);
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

void process(float *p, int length){
 //printf("numelements: %d\n", length);
 int i = 0;
 float sum = 0.0; 
 float avg = 0.0;
 for (i = 0; i < length; i++){
   //printf("element at %d: %.2f\n",i,*(p+i));
   sum += *(p+i);
 }
 avg = round2f(sum / length);
 //printf("avg: %f\n", avg);
 float exchange = 0.0f;
 float gamount = 0.0f;
 float ramount = 0.0f;
 if (sum > avg*length){
   for (i = 0; i < length; i++){
	if(*(p+i) > avg){
	    gamount += *(p+i) - avg;
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
 printf("$%.2f\n",exchange);

}

float round2f(float a){
 int b = (int)(a*100.0f);
 return b/100.0f; 
}
