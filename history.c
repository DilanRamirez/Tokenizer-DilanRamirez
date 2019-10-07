#include <stdio.h>
#include <stdlib.h>
#include "History.h"

List* init_history(){
  List *myList = (List*)malloc(sizeof(List)*10);
  myList->root = NULL;
  return myList;
}

void add_history(List* list, char* str){
  int pos = 1, lenght = 0, i=0;

  lenght = string_length(str);
  Item *myItem = (Item*)malloc(sizeof(Item));
  myItem->str = malloc(sizeof(char)*lenght+1);

  for(i=0; i<lenght;i++){
    myItem->str[i] = str[i];
    myItem->str[lenght] = '\0';
  }

  if((list)->root == NULL){
    myItem->id = 1;
    myItem->next = NULL;
    (list)->root = myItem;
    printf("--------Adding-------\n");
    return;
  }

  Item *iterator = list->root;
  while(iterator->next){
    iterator = iterator->next;
    pos++;
  }
  myItem->id = pos+1;
  iterator->next = myItem;

  return;

}

char* get_history(List* list, int id){
  int i=0;
  Item *iterator = list->root;

  for(i=1; i<id && iterator->next!= NULL; i++){
    iterator = iterator->next;
  }
  if(iterator->id != id) {
    printf("not found! \n");
    return "invalid id";
  }
  printf("%d. %s", iterator->id, iterator->str);

  return iterator->str;
}

void print_history(List* list){
  if(list == NULL) {
    printf("Empty list \n");
    return;
  }
  Item *temp = list->root;

  while(temp != NULL){
    printf(" %d. %s\n", temp->id, temp->str);
    temp = temp->next;
  }

  return;
}

void free_history(List* list){
  Item *iterator1 = list->root;
  Item *iterator2 = list->root;

  if(iterator1->next == NULL)
    free(iterator1);


  while(iterator2 != NULL){
    iterator2 = iterator2->next;
    free(iterator1);
    iterator1 = iterator2;
  }
  free(list);
  return;
}

