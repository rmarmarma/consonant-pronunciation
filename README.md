# consonant-pronunciation

This project is a programming assignment from the Introduction to Computer Systems course taught at Trinity College 
in Hartford Connecticut.

## Program description
Write a program that takes a list of “words” and ranks them from easiest- to
hardest-to-pronounce. You may assume that no word is more than 25 characters,
each appears on a separate line in the input file, and there are no more than 1000
words to be ranked. Treat ‘y’ as a consonant. For instance, the list grosy, beotoo,
and rabso should be ranked:

- rabso
- grosy
- beotoo

because the fraction of consonants in each word is 0.6, 0.8, and 0.33 respectively.
Your program should read the word list from a file, sort them according to the
scoring system described above, and output the sorted list in increasing order of
difficulty to pronounce. Implement the algorithm Sort below as a function,
which also requires implementing the function Compare. Please note: you must
use the sorting/compare algorithm provided; failure to do so will cost you the full
amount of the credit for implementing the sort (see rubric below).

### Algorithm: 

Sort (A,n) // Sorts array A of size n; indexed from 0

For j = 1 to n-1

key = A[j]

// Now shift A[j] to where it belongs in

// the sorted sequence A[1]..A[j-1]

k = j-1

while k >= 0 and Compare(A[k],key)

A[k+1] = A[k]

k = k – 1

A[k+1] = key



Compare (x, y) // Returns T if x > y, otherwise F

Implement your comparison function here

### Compile with gcc and redirect input.in as input.
