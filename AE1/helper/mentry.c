/*
  Helper files by Kon. Come ask me for any clarifications ONLY AFTER YOU GOOGLE AND/OR TRY YOURSELF.
*/

// TODO: Include your .h file.
  // Other header files already specified in your .h file do not need to be included again.

// TODO: DEFINE a variable to store the length of a standard string (char array)
  // Doesn't have to be a big number, one MEntry->full_address is roughly 100 chars at most.

/* me_get returns the next file entry, or NULL if end of file*/
MEntry *me_get(FILE *fd) {
  // TODO: Create a new MEntry object.

  // TODO: Initialize 3 strings to store the 3 lines in one entry.
    // 1. Name
    // 2. Address
    // 3. Postal Code

  // TODO: Use the fgets() function to read the next line of input from [fd] and assign them to the 3 strings.
    // The cursor remembers its position and will return NULL if there are no more lines, so use that to check for EOF.
    // Google the function la walao

  // TODO: Get the MEntry->surname attribute
    // Loop through the first string until you reach the [,] character.
    // Assign those characters to MEntry->surname, in a SINGLE CASE.
      // Google the toupper()/tolower() functions thx

  // TODO: Get the MEntry->house_number attribute
    // Use the second string.
    // The atoi() function takes a string and gets the integers up to the first whitespace. Google for more thx

  // TODO: Get the MEntry->postcode attribute
    // Use the third string. The pdf asks you to remove any non-alphanumeric characters.
    // Tada isalnum(). Also try to make it all single-case too.

  // TODO: Get the MEntry->full_address attribute
    // Use strcpy() and strcat() functions to combine all 3 original strings into MEntry->full_address.
    // This is used mainly for printing output. It's the exact entry as given in input.

  // TODO: return your MEntry object.
}

/* me_hash computes a hash of the MEntry, mod size */
unsigned long me_hash(MEntry *me, unsigned long size) {
  // NOTE: Use me->surname, me->postcode, & me->house_number as the key.
        // Google hashing functions. There are many examples on github and stack overflow of how to convert a string into a hashable int.
  // TODO: For the string attributes, convert each character into its integer value and operate on those.
  // TODO: Add the hash of the 2 string attributes to me->house_number (already an int)

  // TODO: return sum % size.
    // In this function, [size] represents the number of buckets in your MList.
    // If you take # of buckets to be, for example, 4, any number mod 4 will only give you [0, 1, 2, 3].
    // This result corresponds with the index number of the bucket in the MList.
    // MEntry with the same 3 attributes will have the same hash.
}

/* me_print prints the full address on fd */
void me_print(MEntry *me, FILE *fd) {
  // TODO: fprintf(). * * * * * G O O G L E * * * * * <3
    // Use me->full_address.
}

/* me_compare compares two mail entries, returning <0, 0, >0 if
 * me1<me2, me1==me2, me1>me2
 */
int me_compare(MEntry *me1, MEntry *me2) {
  // NOTE: Remember how I said "MEntry with the same 3 attributes will have the same hash"?
        // Ya other entries may also have the same hash so DON'T USE THAT TO COMPARE.

  // TODO: strcmp() compares two strings.
    // Concatenate the surname, house number and postal code attributes for each of the two MEntry then compare those.

  // TODO: Return the result.
}

/* me_destroy destroys the mail entry
 */
void me_destroy(MEntry *me) {
  // TODO: free() everything in [me].
}

/*
You're done!!!!! Now make sure you malloc'ed and freed everything
properly with proper checking of the return value, otherwise go
have fun with all your Segmentation Fault (Core Dumped) when you
run the files (:

Checking individual files:
Add this just before all your other functions and use
`gcc [-w -Wall] -o [output file] [mlist.c | mentry.c]`, then `./[output file]`
int main() {
  FILE *fPtr = fopen("S.txt", "r");
  MEntry *m;
  while ( (m = me_get(fPtr)) != NULL) {
    me_print(m, fPtr); // or whatever functions you wanna test
  }
}
*/
