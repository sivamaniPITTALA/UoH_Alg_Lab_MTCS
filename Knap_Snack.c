// Knap_Sack.c - 0/1 Knapsack Problem Solver
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n+1][W+1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    return K[n][W];
}

int main() {
    FILE *fp = fopen("Inputs/input_knap.txt", "r");
    if (fp == NULL) {
        printf("Error opening input.txt\n");
        return 1;
    }

    int W, n;
    fscanf(fp, "%d", &W);
    fscanf(fp, "%d", &n);

    int wt[100], val[100];
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d %d", &wt[i], &val[i]);
    }
    fclose(fp);

    printf("Knapsack Capacity: %d\n", W);
    printf("Number of items: %d\n", n);
    printf("Items (weight, value):\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", wt[i], val[i]);
    }
    printf("\n");

    int max_value = knapSack(W, wt, val, n);

    printf("Maximum value: %d\n", max_value);

    FILE *out = fopen("Outputs/KnapSnackOutput.txt", "w");
    if (out == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    fprintf(out, "%d\n", max_value);
    fclose(out);

    return 0;
}

