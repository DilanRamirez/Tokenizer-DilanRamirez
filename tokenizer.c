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
  if((c >= 'a' &&  c <= 'z') || (c >= 'A' &&  c <= 'Z') || (c == '-') || (c != ' ')){
    return 1;
  }
  
  else{
    return 0;
  }
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
  int valid = 0;
  while(*value){
    valid = is_valid_character(*value);
    if(valid == 0){
      return value;
    }
    value++;
  }

  return value;
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


void copy_word(char* str, char* copy){
  while(*str != '\0'){
    if(*str == ' '){
      copy = str;
    }
    str++;
  }
}


char* tokenCopy(char* str){
  int length=0, i;
  char *copy = str;
  while(*str != '\0' && *str != ' '){
    length++;
    str++;
  }

  char *string = (char *)malloc(sizeof(char)*(length + 1));
  char *ret = string;

  if(*string != NULL)
    printf("TOKEN_COPY\n");
  
  while(*copy!= '\0' && *copy != ' '){
    *string = *copy;
    string++;
    copy++;

  }
  printf("\n");
  return ret;
  
}


char** tokenize(char* str){
  int numWords=0;
  char *copy, *stringPointer, *start, *end, *newStart, *NS;
  numWords = count_words(str);
  char **tokens = (char **)malloc(sizeof(char*)*(numWords + 1));
  tokenCopy(str);
  newStart = str;

  while(*str != '\0'){
    start = find_word_start(str);
    end = find_word_end(str);
    str++;
    if(*end == ' ' && *start != ' '){
      NS = start;
    }
    
    start++;
    end++;
  }
  
  tokenCopy(NS);
  NS++;
}


int main(){
  char word[50], c;
  getSentence(word);
  printf("%s", word);
  tokenize(word);
  return 0;

}
