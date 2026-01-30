void bubbleSort()
This function is the Bubble Sort algorithm, which sorts an array by comparing and swapping elements in sequence,
but stops early if no changes occur in a pass, avoiding unnecessary comparisons.

void getArrayValues()
This function reads a line for each array element using fgets, 
extracts only the valid integer at the beginning of the line using sscanf, assigns it to the array, 
and requests re-entry for invalid inputs.

example:
Element 1: 5 ✅ Accepted
Element 2: abc ❌ Rejected
Element 2: 12a ❌ Rejected
Element 2: 7 ✅ Accepted
