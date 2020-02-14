// #include <limits.h> 
// #include <stdio.h>
#define COLS 5
#define ROWS 5

int main() {
  int matrix[ROWS][COLS] = {
    {0, 5, 13, 11, 0},
    {5, 0, 7, 0, 3},
    {13, 7, 0, 1, 4},
    {11, 0, 1, 0, 4},
    {0, 3, 4, 2, 0}
  };

  // setup tables
  int visited[ROWS] = {0, 0, 0, 0, 0};
  int previous[ROWS] = {-1, -1, -1, -1, -1};
  int cost[ROWS] = {1000000, 1000000, 1000000, 1000000, 1000000};
  // int cost[ROWS] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX};

  int r, c;
  cost[0] = 0;
  for (r = 0; r < ROWS; r++) {
    for (c = 0; c < COLS; c++) {
      // Do we update our chart?
      if(visited[c] == 0 && matrix[r][c] > 0 && (cost[r] + matrix[r][c] < cost[c])) {
        // YES! :)
        cost[c] = matrix[r][c] + cost[r]; // update cost
        previous[c] = r; // previous becomes our current row
      }
      // NO :(
    } // loop over columns
    visited[r] = 1;

  } // loop over rows
  int i;
  for (i = 0; i < ROWS; i++) {
    printf("\n");
    printf("%d ", cost[i]);
    printf("%d ", previous[i]);
    printf("\n");
  }
  return 1;
}