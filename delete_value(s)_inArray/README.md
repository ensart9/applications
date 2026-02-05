This programme creates a dynamic array based on the size entered by the user and fills this array with random numbers within a specified range (MIN–MAX).
(The user can easily change the MIN-MAX values.) The created array is printed to the screen.

The user then enters the values they wish to delete from the array in sequence. 
Each entered value is searched for in the array; if found, the first occurrence is deleted, the array elements are shifted to the left,
and the memory is reduced using 'realloc'. If the entered value is not found in the array, an error message is displayed.

The user ends the deletion process by entering a letter. Once all deletions are complete, the final updated state of the array is printed to the screen.
