#include<stdio.h>
#include<stdlib.h>

struct String_struct {
 char *value;
 char* (*get)(const void *self);
 void (*set)(const void *self, char* val); 
};

typedef struct String_struct String;
char *getStr(const void *self);
void setStr(const void *self, char *val);
String *newString();

int main(){

 String *a = newString();
 a->set(a, "dafdafd");
 printf("the value is %s\n", a->get(a));
}
String *newString() {
 String *a = (String *) malloc(sizeof(struct String_struct));
 a->value = "";
 a->get = &getStr;
 a->set = &setStr;
 return a;
}
char *getStr(const void *self){
  return ((String *)self)->value;
 
}
void setStr(const void *self, char* val){
 ((String *)self)->value = val;
}
