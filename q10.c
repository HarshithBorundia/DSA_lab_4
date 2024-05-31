#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char board[n][m];

    // Input board configuration
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &board[i][j]);  // Use a space before %c to skip newline characters
        }
    }

    // Falling process
    for (int i = 0; i < m; i++) {
        int j = n - 1;
        int empty[n];
        int k = n - 1;
        for (int l = 0; l < n; l++) {
            empty[l] = 0;
        }
        while (j >= 0) {
            if (board[j][i] == 'o') {
                k = j;
                empty[k] = -1;
                k--;
                j--;
            } else if (board[j][i] == '*') {
                if (empty[k] == -1) {
                    j--;  // You missed this decrement statement
                } else {
                    board[j][i] = '.';
                    board[k][i] = '*';
                    empty[j] = 0;
                    k--;
                    j--;
                }
            } else {
                empty[j] = 0;
                j--;  // You missed this decrement statement
            }
        }
    }

    // Output final board configuration
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}

