Lab Project 1: Building a Tokenizer and Linked-Lists
----------------------------------------------------
##Overview
The objective of this lab is to build a tokenizer that
maintains a history. Tokenizing is the process of dividing a string into
tokens by some delimeter (e.g. the string library split() function).
Consider tokenizing the string "The cake is a lie!" using space
character. this would result in: \["The", "cake", "is", "a","lie!"\].

Tokenizer will mantain a histor like the following:
1. The cake is a lie!
2. But it was delicious.
3. True.

It will be able to view and recall a certain history item by using a comand
similar to '!2'. This would then use the string "But it was delicious." as
input and tokenize.

The second milestone of my project is to define several of the
functions contained in the tokenizer.h file:

1. `int string_length(char*);`
   - Counts the number of characters in the string argument.

2. `char is_valid_character(char c);`
   - Evaluates if the character c is an acceptable character for
     token. Acceptable characters include any alphanumeric or
     special character. Unacceptable characters include any
     whitespace or control characters.
     Returns 0 if not, 1 if yes.

3. `int find_word_start(char*);`
   - Finds the next word in the string. 
     For example, given an input of "  my cake" the function
     should return "my cake".
   
4. `int find_word_end(char*);`
   - Finds the end of current word.
     For example, given an input of "my cake" the function
     should return " cake".
   
5. `int count_words(char*);`
   - Counts the number of words in the string argument.
   
The third milestone of my project will require you to allocate and
free memory. Going back to the **tokenizer.h** file, you are now going
to define the following functions:

1. `void print_tokens(char**);`
   - Tokenizes the string argument into an array of tokens.
     For example, "hello world string" would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" */

2. `void free_tokens(char**);`
   - Prints all tokens.


Finally,  putting it All Together:

1.  `char** tokenize(char*);`
   - Frees all tokens and the array containing the tokens.


The final milestone of my project is to build the history component.
The history can be represented as a linked list data structure, with
each node containing:

1.  an id based on its place in the list,
2.  the string entered by user,
3.  and, a pointer to the next node.

1. init_history()
  - Initialize the linked list to keep the history.

2. void add_history(List* list, char* str)
  - Add a history item to the end of the list.
    List* list - the linked list
    char* str - the string to store

3. char* get_history(List* list, int id)
  - Retrieve the string stored in the node where Item->id == id.
    List* list - the linked list
    int id - the id of the Item to find

4. void print_history(List* list)
   - Print the entire contents of the list.

5. void free_history(List* list)
   - Free all Items and the List.








