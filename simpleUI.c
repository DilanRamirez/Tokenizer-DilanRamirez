#include <stdio.h>
#include "history.h"
#include "tokenizer.h"



int main(){

  int answer = 0, id = 0, option = 0;
  char sentence[50];
  char **tokens, *str, *ansAux;
  List *list = init_history();

  printf("---------WELCOME-------\n");

  do{
    fflush(stdin);
    getSentence(sentence);
    printf("\nChoose and Option from Below:\n");
    printf("1. Tokenize a String\n");
    printf("2. History Options\n");
    printf("3. Exit\n");
    printf("\nYour Option: ");
    fflush(stdin);
    scanf(" %d", &answer);
    printf("You selected: %d \n", answer);

    switch(answer){
      case 1:
        add_history(list, sentence);
        tokens = tokenize(sentence);
        print_tokens(tokens);
        free_tokens(tokens);
        printf("\n");
      break;

      case 2:
        fflush(stdin);
        printf("Choose an Option: \n");
        printf("1. Print History\n");
        printf("2. Recall an Item by ID\n");
        printf("3. Clean History\n");
        add_history(list, sentence);
        scanf(" %d", &option);

        switch(option){
          case 1:
	     print_history(list);
	     fflush(stdin);
             break;
          case 2:
	     printf("Number of ID: ");
	     scanf("%d", &id);
	     get_history(list, id);
             break;

          case 3:
	     free_history(list);
             break; 
	break;
      }
      
      default:
      break;
    }
  }while(answer!=3);
  
  return 0;
}
