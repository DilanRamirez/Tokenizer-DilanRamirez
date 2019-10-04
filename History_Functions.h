#include <stdio.h>
#include <stdlib.h>
#include "History.h"


List* init_history(){
  List *myList = (List*)malloc(sizeof(List)*10);
  myList->root = NULL;
  return myList;
}


void add_history(List* list, char* str){
  int pos = 0;
  while((list+pos)->root != NULL){
    pos++;
  }

  (list+pos)->root = malloc(sizeof(Item));
  (list+pos)->root->id = pos+1;
  (list+pos)->root->str = malloc(sizeof(char)*100);
  (list+pos)->root->str = str;
  (list+pos)->root->next = (list+pos)->root;
  (list+pos)->root->next = NULL;

}


void print_history(List* list){
  int pos = 0;
  while((list+pos)->root != NULL && (list+pos)->root->next == NULL){
    printf(" %d. %s\n", (list+pos)->root->id, (list+pos)->root->str);
    pos++;
  }
}
