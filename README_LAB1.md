Lab Project 1: Building a Tokenizer and Linked-Lists
----------------------------------------------------
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
