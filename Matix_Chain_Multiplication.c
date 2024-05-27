*/Time Complexity: O(M ^ V), Since these are the total number of color combinations.
Auxiliary Space: O(V), Recursive stack.*/
#include <stdio.h>
#include <limits.h>

int n;
void print_optimal(int i, int j, int s[n][n]);

int main() {
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the %d element: ", i);
        scanf("%d", &arr[i]);
    }
    
    int s[n][n];
    int m[n][n];

    // Initialize matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s[i][j] = 0;
            m[i][j] = 0;
        }
    }

    int j, min, q;
    for (int d = 1; d < n - 1; d++) { // used to find the diagonal elements
        for (int i = 1; i < n - d; i++) {
            min = INT_MAX;
            j = i + d;
            for (int k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < min) {
                    min = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d  ", m[i][j]);
        }
        printf("\n");
    }

    printf("Optimal Parenthesization: ");
    print_optimal(1, n - 1, s);
    printf("\n");

    return 0;
}

void print_optimal(int i, int j, int s[n][n]) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        print_optimal(i, s[i][j], s);
        print_optimal(s[i][j] + 1, j, s);
        printf(")");
    }
}
