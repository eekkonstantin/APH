/*
  Helper files by Kon. Come ask me for any clarifications or help ONLY AFTER YOU GOOGLE AND/OR TRY YOURSELF.
*/

// TODO: Include your .h file.
  // Other header files already specified in your .h file do not need to be included again.

// TODO: DEFINE a variable to store the capacity of your bucket.
  // The pdf says 20, but for testing purposes you should use a smaller number first.

typedef struct bucket_s {
  // TODO: Declare what the bucket holds.
    // 1. An int to store the current # of elements in the bucket because C is a lil bitch when it comes to counting array elements
    // 2. An array of MEntry pointers. Yay more asterisks.

    // NOTE: if you don't mind manually counting how many stupid MEntry are in your bucket every time, you can skip this struct and make your [MList]->2 be the MEntry pointer array.
} Bucket;

struct mlist { // No need for [typedef] keyword because it's already in your .h, here you only need to tell the program what's INSIDE MList.
  // TODO: Declare what makes up your MList.
    // 1. Number of buckets currently in your MList
    // 2. An array of pointers to your [Bucket]s.
};

int ml_verbose = 0;		/* if true, prints diagnostics on stderr */ // This is copied from the given mlistLL.c
  // Refer to mlistLL.c to see where (and how) you should put your verbosity statements.

// The following variables are for when you need to re-sort your MList, as you'll see later.
// TODO: Create a global variable to keep track of how many buckets you have.
// TODO: Create a globally accessible MList object.


/* ml_create  - creates a new mailing list
              - returns pointer to start of mailing list*/
MList *ml_create(void) {
  // TODO: Initialize an empty MList and allocate memory for all its attributes.
  // TODO: Set your number of buckets in this MList using the global variable.

  // TODO: Return the nicely allocated MList.
}

/* ml_add - adds a new MEntry to the list;
 * returns 1 if successful, 0 if error (malloc)
 * returns 1 if it is a duplicate */
int ml_add(MList **ml, MEntry *me) {
  // TODO: Make a MList *variable.
    // Dereference **ml because wtf idk why they give double pointer.
    // e.g.
  MList *wtf = *ml;

  // TODO: Use the ml_lookup() function to check whether any record in the MList is a potential duplicate.
    // End this function if there is already a duplicate.

  // TODO: Find the bucket number of [me] with its hash value.
  // TODO: Add [me] to its bucket and increment [Bucket X]->1 if necessary.

  // TODO: Check if the size of Bucket X has exceeded your defined bucket size.
    // If it has,   TODO: Increment the global variable # of buckets.
                 // TODO: Create a NEW MList object with the ml_create() function.
                 // TODO: Pull everything out of their buckets and add them to the new MList.
                    // Using ml_add() will automatically sort them using the new hash number since the number of buckets in the new MList is different.

  // TODO: return 1 if no problems.
}

/* ml_lookup - looks for MEntry in the list, returns pointer to matching entry or NULL */
MEntry *ml_lookup(MList *ml, MEntry *me) {
  // TODO: Get the Bucket holding [me]
    // If the bucket is empty, just finish the function.

  // TODO: Loop through the bucket and use me_compare() to check if a matching entry exists.
    // Break when you find a match.

  // TODO: return NULL || the matching MEntry*.
}

/* ml_destroy - destroy the mailing list */
void ml_destroy(MList *ml) {
  // TODO: Go through your MList and free() everything.
    // Use me_destroy() for MEntry items.
  // TODO: Free your MList.
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
