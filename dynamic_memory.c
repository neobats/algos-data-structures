// Guy Batton
// this is a program to make a queue that dynamically allocates and handles memory.

// #include <stdlib.h> 
// #include <limits.h> 
// #include <stdio.h>
// #include <time.h>
#define COUNT 100
#define CHARS 1000

struct LLnode {
  char *str;
  struct LLnode *next;
};

// adds item to end of queue.
// returns 1 if the empty list is now not empty
// returns 2 if adds to a non-empty list
// returns 0 if adding fails.
int enqueue (char *data, struct LLnode **hd, struct LLnode **tl) {
  struct LLnode *temp;
  temp = (struct LLnode*)malloc(sizeof(struct LLnode));
  (*temp).str = data;
  (*temp).next = NULL;
  // (*temp).next = 0; // why the heck won't the linter let me assign to NULL?
  if(!(*hd)) {
    (*hd) = temp;
    (*tl) = (*hd);
    return 1;
  } else if (*hd) {
    (**tl).next = temp;
    (*tl) = temp;
    return 2;
  } else {
    return 0;
  }
}

// removes the item from the front of the queue.
// returns a pointer to a character
char* dequeue (struct LLnode **hd, struct LLnode **tl) {
  if ((*hd) == (*tl)) { // all the things
    char* data = (**hd).str;
    free(*hd); // empty the list
    (*hd) = NULL;
    (*tl) = NULL;
    return data;
  } else if ((*hd)) { // one thing
    struct LLnode *temp;
    temp = &hd;
    char* data = (*temp).str;
    (*hd) = (*temp).next;
    free(temp); // remove the current front of queue
    return data;
  } else { // no thing
    return NULL;
  }
} 

int main() {
  struct LLnode *head;
  struct LLnode *tail;

  head = (struct LLnode*)malloc(sizeof(struct LLnode));
  tail = head;

  // srand(time(NULL));
  srand(1);
  int newChar = (rand() % 26) + 65;

  for (int i = 0; i < COUNT; i++) {
    
  }
  


  return 0;
}