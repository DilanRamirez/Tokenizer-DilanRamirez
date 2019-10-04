#include <stdio.h>
#include "Tokenizer.h"
#include "History_Functions.h"


void interface(int answer, char *str){
  char sentence[50];
  char **tokens;
  int id = 0;
  List *list = init_history();

  switch(answer){
    case 1:{
       getSentence(sentence);
    break;
    }

    case 2:{
      getSentence(sentence);
       tokens = tokenize(str);
       print_tokens(tokens);
       free_tokens(tokens);
       printf("\n");
    break;
    }
    
    case 3:{
       add_history(list, str);
       print_history(list);
    break;
    }
      
    case 4:{
       printf("BYE\n");
    break;
    }
  }
}


int main(){
  int answer = 0;
  char sentence[50];
  printf("---------WELCOME-------\n");

  do{
    getSentence(sentence);
    printf("\nChoose and Option from Below:\n");
    printf("1.Enter a new string\n");
    printf("2.Tokenize a String\n");
    printf("3.Print History\n");
    printf("4.Exit\n");
    do{
      printf("\nYour Option: ");
      scanf("%d", &answer);
      if(answer<1 || answer >4)
          printf("Incorrect, choose a valid option\n");
          interface(answer, sentence);
    }while(answer<0 || answer>4);
  }while(answer!=4);

  return 0;
}
