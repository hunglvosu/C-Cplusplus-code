#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char **initImg(char **imgdata,int N, int M);
void clear(char **imgdata, int N, int M);
void coloringpixel(char **imgdata,int x, int y, char c);
void drawVertical(char **imgdata, int x, int y1,int y2, char c);
void drawHorizontal(char **imgdata, int x1, int x2, int y, char c);
void drawRectangle(char **imgdata,int x1,int y1, int x2, int y2,
			 char c);
void fillRegion(char **img, int x, int y, char c);
void fillPixels(char **img, int x, int y, char c1, char c2);
void save(char **imgdata, char *name);
void printImg(char **imgdata, int N, int M);
char **img;
int N,M;

int main(){
char c;
char inst;
char *b ;
//scanf("%s",b);
//printf("input is %s", b);
int x, y, x1, y1, x2, y2;
 while(1){ 
  scanf("%c",&inst);
  int isBreak = 0;
 // printf("your input char is %c\n",c);
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
	//printImg(img,N,M); 
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
//	gets(name);
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
 //printImg(imgdata, N,M);
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

void fillRegion(char **imgdata, int x, int y, char c){
   char cxy = imgdata[y-1][x-1];
   fillPixels(imgdata, x, y, cxy, c);

}
void fillPixels(char **img, int x, int y, char c1, char c2){
  if(img[y-1][x-1] == c1){
    img[y-1][x-1] = c2;
  } else return;
 if (y < N) if( img[y][x-1] == c1){
   fillPixels(img, x,  y + 1, c1, c2);
 } 
 if(x < M ) if( img[y-1][x] == c1){
   fillPixels(img, x + 1, y, c1, c2);
  }
 if ( y - 1 > 0) if( img[y-2][x-1] == c1){
   fillPixels(img, x, y -1, c1, c2);
 }
 if(x-1 > 0 )if( img[y-1][x-2] == c1){
   fillPixels(img, x-1, y, c1, c2);
}
 
}
