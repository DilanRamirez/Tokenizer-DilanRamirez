#include <stdio.h>


void getSentence(char sentence[50]){

  printf("Enter Sentence:");
  scanf("%[^\n]s", sentence);

}


int string_length(char* words){

  int length = 0;
  while(*words !='\0'){
    length++;
    words++;
  }

  printf("Length: %d",length);
  return length;

}


char is_valid_character(char c){

  int value = 0;
  printf("\nEnter a Character: ");
  scanf(" %c",&c);

  if((c >= 'a' &&  c <= 'z') || (c >= 'A' &&  c <= 'Z') || (c >= '1' &&  c <= '1000000') || (c == '-') || (c != ' ')){
    value++;
    printf("Acceptable Character: %d\n", value);
    return value;
  }

  else{
    printf("Unacceptable Character: %d\n", value);
    return value;
  }

}


char* find_word_start(char* str){

  char *value = str;
  while(*value != ' '){
    value++;
  }

  value++;
  printf("Sentence after the first word:%s\n", value);
  return value;

}


char* find_word_end(char* str){

  char *value = str;
  while(*value != '\0'){
    value++;
  }

  while(*value != ' '){
    value--;
  }
  
  value++;
  printf("Last word: %s\n", value);
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

  printf("Number of Words: %d\n",count);
  return count;

}



int main(){
  char word[50], c;
  getSentence(word);
  string_length(word);
  is_valid_character(c);
  find_word_start(word);
  find_word_end(word);
  count_words(word);
  return 0;
}

