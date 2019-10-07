#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/*It creates the first node of the linked-list and returns it*/
List* init_history(){
  List *myList = (List*)malloc(sizeof(List)*10);
  myList->root = NULL;
  return myList;
}

/*This function adds to the linked-list all the strings typed by the user*/
void add_history(List* list, char* str){
  int pos = 1, lenght = 0, i=0;

  // It creates a new struct with the variables of Item and uses the function
  // string_length() to reserve a space of memory of that size of the string
  // and stores the string in myItem->str.
  lenght = string_length(str);
  Item *myItem = (Item*)malloc(sizeof(Item));
  myItem->str = malloc(sizeof(char)*lenght+1);

  for(i=0; i<lenght;i++){
    myItem->str[i] = str[i];
    myItem->str[lenght] = '\0';
  }

  // It add the first node only if root is NULL
  if((list)->root == NULL){
    myItem->id = 1;
    myItem->next = NULL;
    (list)->root = myItem;
    printf("--------Adding-------\n");
    return;
  }

  // If it is not NULL, a new node is appended at the end of the linked-list.
  Item *iterator = list->root;
  while(iterator->next){
    iterator = iterator->next;
    pos++;
  }
  myItem->id = pos+1;
  iterator->next = myItem;

  return;

}


/*This function returns the string by ID or "Not Found" if there is not ID*/
char* get_history(List* list, int id){
  int i=0;
  Item *iterator = list->root;

  // This for loop will leave the the pointer of the string at the position of the ID
  // to then, return it. 
  for(i=1; i<id && iterator->next!= NULL; i++){
    iterator = iterator->next;
  }

  // In case there is no ID, it will return a message "NOT FOUND"
  if(iterator->id != id) {
    printf("NOT FOUND! \n");
    return "invalid id";
  }
  printf("%d. %s", iterator->id, iterator->str);

  return iterator->str;
}

/*This function traverse the whole linked list and prints the strings stored in it
  If the list is empty, it will print "Empty List"*/
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

/*This function clean the memory reserved by the malloc used in the linked-list*/
void free_history(List* list){
  Item *iterator1 = list->root;
  Item *iterator2 = list->root;

  // It uses two pointers to free memory. One is used to clean memory, and the other to
  // move the pointer no the next node to free memory.
  if(iterator1->next == NULL)
    free(iterator1);

  // Here it will clean the memory until the last node is NULL.
  while(iterator2 != NULL){
    iterator2 = iterator2->next;
    free(iterator1);
    iterator1 = iterator2;
  }
  free(list);
  return;
}
