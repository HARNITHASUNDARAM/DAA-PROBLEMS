#include <stdio.h>
#include <string.h>

// Function to find the Longest Common Subsequence
int LCS(char* X, char* Y, int m, int n) {
    // Create a 2D table to store the lengths of LCS
    int L[m + 1][n + 1];

    // Build the table in a bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    // Return the length of the longest common subsequence
    return L[m][n];
}

// Function to print the Longest Common Subsequence
void printLCS(char* X, char* Y, int m, int n) {
    // Create a table for storing LCS lengths
    int L[m + 1][n + 1];

    // Build the table in a bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    // Reconstruct the LCS from the table
    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    printf("Longest Common Subsequence: %s\n", lcs);
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    // Finding the length of LCS
    printf("Length of Longest Common Subsequence: %d\n", LCS(X, Y, m, n));

    // Printing the LCS
    printLCS(X, Y, m, n);

    return 0;
}
