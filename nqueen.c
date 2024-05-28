#include <stdio.h>
#include <stdbool.h>

int n;
int arr[100][100];
int solutionCount = 0;

bool issafe(int arr[100][100], int x, int y, int n) {
    for (int row = 0; row < x; row++) { // checking for the rows only which are upward--so x changes y remains constant
        if (arr[row][y] == 1) return false;
    }
    int row = x, col = y;
    while (col >= 0 && row >= 0) { // checking for the left upper diagonal
        if (arr[row][col] == 1) {
            return false;
        }
        row--; col--;
    }
    row = x; col = y;
    while (col < n && row >= 0) { // checking for the right upper diagonal
        if (arr[row][col] == 1) {
            return false;
        }
        row--; col++;
    }
    return true;
}

void nqueen(int arr[100][100], int x, int n) { // y is not needed here, we don't need to check forward we need to check downwards
    if (x >= n) { // base case if x exceeds the grid then it is able to place all the queens properly
        solutionCount++;
        printf("Solution %d:\n", solutionCount);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
    for (int col = 0; col < n; col++) {
        if (issafe(arr, x, col, n)) {
            arr[x][col] = 1;
            nqueen(arr, x + 1, n); // if possible to place then calling for the next row by x++
            arr[x][col] = 0; // backtracking
        }
    }
}

int main() {
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }
    nqueen(arr, 0, n);
    if (solutionCount == 0) {
        printf("No solution exists\n");
    } else {
        printf("Total solutions: %d\n", solutionCount);
    }
    return 0;
}
