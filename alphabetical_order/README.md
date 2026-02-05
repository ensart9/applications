#Dynamic Word Sorting

This project is a C programme that dynamically sorts words received from the user into alphabetical order, ignoring case sensitivity. 

#  Project Objective

- Obtain words from the user without knowing the word count beforehand  
- Manage memory dynamically (malloc, realloc, free)  
- Perform alphabetical sorting ignoring case sensitivity
- Write a sorting algorithm without using ready-made string comparison functions such as `strcmp()`  

# How Does the Programme Work?

1. Words are taken from the user one by one  
2. The array is enlarged with `realloc` for each new word  
3. When the user enters `0`, the word collection process ends  
4. Words are sorted alphabetically by comparing them character by character  
   - `tolower()` is used during comparison  
   - Case sensitivity is ignored  
5. The sorted words are printed to the screen  
6. At the end of the programme, all memory areas are freed using `free`
