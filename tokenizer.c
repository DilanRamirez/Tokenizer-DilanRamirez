#include <stdio.h>
#include <stdlib.h>


void getSentence(char sentence[50]){
  printf("Enter Sentence:");
  fgets(sentence, 50, stdin);
}

int string_length(char* words){
  int length = 0;
  while(*words !='\0'){
    length++;
    words++;
  }
  return length;
}

char is_valid_character(char c){
  if(c == ' ' || c == '\n' || c=='\0'){
    return 0;
  }
  else{
    return 1;
  }
}

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
}

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

void print_tokens(char ** tokens){
  int pos = 0;
  printf("\n----PRINTING TOKENS-----\n");
  while(*tokens){
    printf("tokens[%d] = %s\n",pos, *tokens);
    tokens++;
    pos++;
  }
}

void free_tokens(char** tokens){
  printf("\n----FREEING TOKENS----\n");
  free(*tokens);
  *tokens = NULL;
  /*
    while(*tokens){
    free(*tokens);
    tokens++;
    }
  */
}

int main(){
  char sentence[50];
  char **tokens;
  int a = 0;
  getSentence(sentence);
  tokens = tokenize(sentence);
  print_tokens(tokens);
  return 0;
}
