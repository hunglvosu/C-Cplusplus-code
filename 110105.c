#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stackElement{
  int x;
  int y;
  struct stackElement *next;
};
typedef struct stackElement selement;

char **initImg(char **imgdata,int N, int M);
void clear(char **imgdata, int N, int M);
void coloringpixel(char **imgdata,int x, int y, char c);
void drawVertical(char **imgdata, int x, int y1,int y2, char c);
void drawHorizontal(char **imgdata, int x1, int x2, int y, char c);
void drawRectangle(char **imgdata,int x1,int y1, int x2, int y2,
			 char c);
void fillRegion(char **img, int x, int y, char c);
void save(char **imgdata, char *name);
void printImg(char **imgdata, int N, int M);
void push(int x, int y, selement *shead);
selement *pop(selement *head);

selement *shead;
char **img;
int N,M;

int main(){
 shead = (selement *)malloc(sizeof(struct stackElement));
 shead->x = -1;
 shead->y = -1;

char c;
char inst;
char *b ;
int x, y, x1, y1, x2, y2;
 while(1){ 
  scanf("%c",&inst);
  int isBreak = 0;
  switch(inst) {
    case 'I':
	{
	scanf("%d %d", &M, &N);
	img = initImg(img,N, M);	
	break;
	}
    case 'C':
	clear(img, N, M);
	break;
    case 'V':
  	{
	scanf("%d %d %d %c", &x, &y1, &y2, &c);
    	drawVertical(img, x, y1, y2,c);		
	break;
	}	
    case 'L':
	{
	scanf("%d %d %c",&x,&y,&c);
	img[y-1][x-1] = c;
	break;
	}
    case 'H':
	{
	scanf("%d %d %d %c", &x1, &x2, &y, &c);
	drawHorizontal(img, x1, x2, y, c);
	break;
	}
    case 'K' :
	{
	scanf("%d %d %d %d %c", &x1, &y1, &x2, &y2, &c);
	drawRectangle(img, x1, y1, x2, y2, c);
	break;
	}
    case 'F':
	{
	scanf("%d %d %c",&x, &y, &c);
	fillRegion(img, x, y, c);
	break;
	}
    case 'S':
	{
	char name[13];
	scanf("%s",name);
	printf("%s\n", name);
	printImg(img,N,M);
	break;
	} 	
    case 'P':
	printImg(img, N, M);
	break;
    case 'X':
	isBreak = 1;
	break;
 
  } 
  if (isBreak) break;
 }
 free(img);
}

void printImg(char **imgdata, int N, int M){
 int i = 0,j = 0;
 for (i = 0; i < N; i++){
    for(j = 0; j < M; j++){
  	printf("%c", imgdata[i][j]);
   }
   printf("\n");
 }

}

char **initImg(char **imgdata, int N, int M){
 imgdata = (char **) malloc(N*sizeof(char*));
 int i = 0, j = 0;
 for(i = 0; i < N; i++){
   imgdata[i] = (char *) malloc(M*sizeof(char));
   for (j = 0; j < M; j++){
	imgdata[i][j] = '0';
   }
 }
 return imgdata; 
}

void clear(char **imgdata, int N, int M){
 int i = 0, j = 0;
 for ( i = 0; i < N; i++){
   for (j = 0; j < M; j++){
	imgdata[i][j] = '0';
    }
 }
}

void coloringpexel(char **imgdata, int x, int y, char c){
  imgdata[x][y] = c;
}
void drawVertical(char **imgdata, int x, int y1, int y2, char c){
   int i = 0;
   for (i = y1; i < y2+1; i++){
	imgdata[i-1][x-1] = c;
   }
}
void drawHorizontal(char **imgdata, int x1, int x2, int y, char c){
   int i = 0;
   for (i = x1; i < x2+1; i++){
	img[y-1][i-1] = c;
   }
}
void drawRectangle(char **imgdata, int x1, int y1, int x2, int y2,
			char c){
   int i = 0, j = 0;
   for(i = x1; i < x2+1; i++){
	for (j = y1; j < y2+1; j++){
	   imgdata[j-1][i-1] = c;
	}
   }
}

void fillRegion(char **imgdata, int x1, int y1, char c1){
   char cxy = imgdata[y1-1][x1-1];
   push(x1, y1 , shead);
   int x, y;
   while(shead->next != NULL){
	selement *elem = pop(shead);
 	x = elem->x;
	 y = elem->y;
	img[y -1][x -1] = c1;
	if(y < N){
	 if(img[y][x-1] == cxy) push(x, y + 1, shead);
	}
	if(x< M){
	 if(img[y-1][x] == cxy) push(x+1, y, shead);
	}
 	if(y-1>0){
	 if(img[y-2][x-1] == cxy) push(x, y-1, shead);
	}
	if(x-1 > 0){
	 if(img[y-1][x-2] == cxy) push(x-1, y, shead);
	}
  }
}

void push(int x, int y, selement *head){ 
 selement *stop = head->next;
 selement *temp = (selement *) malloc(
			sizeof(struct stackElement));
 temp->x = x;
 temp->y = y;
 head->next = temp;
 temp->next = stop;

}

selement *pop(selement *head){
 selement *elem = shead->next;
 selement *elemnext = elem->next;
 shead->next = elemnext;
 return elem;
}
