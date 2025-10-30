// Prims Implementations
#include<stdio.h>
#include<stdlib.h> 

#define MAX 1000
//weights should be less then MAX

int main() {
    FILE *fp = fopen("Inputs/input_Prims.txt", "r"); // relative path is Inputs/input_Prims.txt
    if (fp == NULL) {
        printf("Error opening input_Prims.txt\n");
        return 1;
    }

    int V;
    fscanf(fp, "%d", &V);

    // Allocate adjacency matrix
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
    }

    // Read adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            fscanf(fp, "%d", &graph[i][j]);
        }
    }
    fclose(fp);

    FILE *out = fopen("Outputs/Prims.txt", "w");
    if (out == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = MAX;
        mstSet[i] = 0;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int min = MAX, min_index;

        for (int v = 0; v < V; v++) {
            if (mstSet[v] == 0 && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }

        int u = min_index;
        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Output MST edges and total weight
    int total_weight = 0;
    fprintf(out, "MST Edges:\n");
    printf("MST Edges:\n");
    for (int i = 1; i < V; i++) {
        fprintf(out, "%d - %d : %d\n", parent[i], i, graph[i][parent[i]]);
        printf("%d - %d : %d\n", parent[i], i, graph[i][parent[i]]);
        total_weight += graph[i][parent[i]];
    }
    fprintf(out, "Total MST Weight: %d\n", total_weight);
    printf("Total MST Weight: %d\n", total_weight);

    // Free memory
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    fclose(out);

    return 0;
}
