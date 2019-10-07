#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* getSentence() gets a char pointer as paramter 
   to write a string.*/
void getSentence(char* sentence){   
  printf("Enter Sentence: ");
  fgets(sentence, 50, stdin);
  return;
}

/* string_length() uses a char pointer to traverse the whole sentence
   and count the number of characters it containsn and returns the length
   of the string */
int string_length(char* words){
  int length = 0;
  while(*words !='\0'){
    length++;
    words++;
  }
  return length;
}

/*This function reaad character by character of the stirng and returns 0 
  if the charaters is a invalid character or 1 if it is a valid character.*/
char is_valid_character(char c){
  if(c == ' ' || c == '\0' || c == '%' || c == '#' || c == '&' || c == '!' || c == '@' || c == ';' || c == '$' || c == '^' || c == '*'){
    return 0;
  }
  else{
    return 1;
  }
}

/*This function traverse the string to keep track the number of words
  and returns the number of words in the string*/
int count_words(char* str){
  int count = 0, space = 0, noSpace = 1;
  int state = space;
  while(*str != '\0'){
    if(*str == ' '){
      state = space;
    }
    else if(state == space){
      state = noSpace;
      count++;
    }
    str++;
  }
  
  return count;
}

/* This function uses a char pointer as parameter to traverse the string
   character by character. It uses is_valid_character() to identify when it
   it is a valid word to start the tokenizer. */
char* find_word_start(char* str){
  char *value = str;
  int valid = 0;
  while(*value){
    valid = is_valid_character(*value);
    if(valid == 1){
      return value;
    }
    value++;
  }
  return value;
}

/* This function uses a char pointer as parameter to traverse the string
   character by character. It uses is_valid_character() to identify when the first word finished
   to then, use it whith the tokenizer.*/
char* find_word_end(char* str){
  char *value = str;
  int valid = 1;
  while(valid != 0){
    valid = is_valid_character(*value);
    if(valid == 0) break;
    value++;
  }
  return value;
}

/*This function just uses two pointers to copy the address of a pointer to another
  and copy the value of that pointer.*/
void copy_word(char* str, char* copy){
  while(*str != '\0'){
    if(*str == ' '){
      copy = str;
    }
    str++;
  }
  while(*copy != '\0'){
    if(*copy == ' ')
      copy++;
    copy++;
  }
  return;
}

/*This function separes a piece of memory to store the fisrt word of the string using malloc.*/
char* tokenCopy(char* str){
  int length = 0;
  char *copy = str;
  while(*str != '\0' && *str != ' ' && *str != '\n'){
    length++;
    str++;
  }

  char *string = (char *)malloc(sizeof(char)*(length + 1));
  char *ret = string;

  while(*copy!= '\0' && *copy != ' ' && *copy != '\n'){
    *string = *copy;
    string++;
    copy++;
  }
    return ret;
}

/*Tokenizer implements count_word(), find_word_start(), find_word_end(), and tokenCopy()
  to traverse the whole string and split it by toknes/words and return a pointer to a malloc
  that cointains the pointers of the tokens and returns a pointer to the pointers*/
char** tokenize(char* str){
  int numWords=0;
  char *copy, *start;
  
  numWords = count_words(str);
  char **tokens = (char **)malloc(sizeof(char*)*(numWords+1));
  start = str;
  char** outTokens = tokens;
  start = find_word_start(start);  
  while(*start){
    *outTokens = tokenCopy(start);
    start = find_word_end(start);
    start = find_word_start(start);
    outTokens++;
  }
  *outTokens = NULL;
  return tokens;
}

/*Print all the tokens/word of the string that are in memory*/
void print_tokens(char ** tokens){
  int pos = 0;
  printf("\n----PRINTING TOKENS-----\n");
  while(*tokens){
    printf("tokens[%d] = %s\n",pos, *tokens);
    tokens++;
    pos++;
  }
}
/*This function clean the memory used to store all the pointers
  in malloc*/
void free_tokens(char** tokens){
  printf("\n----FREEING TOKENS----\n");
  free(*tokens);
  *tokens = NULL;
}
