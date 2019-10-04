#include <stdio.h>

typedef struct s_Item {
  int id;
  char* str;
  struct s_Item* next;
} Item;


typedef struct s_List {
  struct s_Item* root;
} List;
