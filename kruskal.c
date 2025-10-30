//kruskal implementation
#include<stdio.h>
#include<stdlib.h>

// Structure for Edge
typedef struct {
    int u, v, w;
} Edge;

// Union_Find structure
int parent[100];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void union_sets(int x, int y) {
    int px = find(x), py = find(y);
    if (px != py) {
        parent[px] = py;
    }
}



int main() {
    FILE *fp = fopen("Inputs/input_kruskal.txt", "r"); // relative path is Inputs/input_kruskal.txt
    if (fp == NULL) {
        printf("Error opening input_kruskal.txt\n");
        return 1;
    }

    int V, E;
    fscanf(fp, "%d %d", &V, &E);
    Edge edges[E];
    for (int i = 0; i < E; i++) {
        fscanf(fp, "%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    fclose(fp);
    //qsort(edges, E, sizeof(Edge), compare) which is inbuild function for the sorting edges :-)

    // Write edge weights to input.txt for merge_sorting
    FILE *input_fp = fopen("Inputs/input.txt", "w");
    if (input_fp == NULL) {
        printf("Error opening input.txt for writing\n");
        return 1;
    }
    for (int i = 0; i < E; i++) {
        fprintf(input_fp, "%d\n", edges[i].w);
    }
    fclose(input_fp);

    // Call merge_sorting.out to sort the weights
    system("./merge_sorting.out");

    // Read sorted weights from MergeOutput.txt
    FILE *output_fp = fopen("Outputs/MergeOutput.txt", "r");
    if (output_fp == NULL) {
        printf("Error opening MergeOutput.txt\n");
        return 1;
    }
    int sorted_weights[E];
    for (int i = 0; i < E; i++) {
        fscanf(output_fp, "%d", &sorted_weights[i]);
    }
    fclose(output_fp);

    // Reorder edges based on sorted weights
    Edge sorted_edges[E];
    int used[E];
    for (int i = 0; i < E; i++) {
        used[i] = 0;
    }
    for (int i = 0; i < E; i++) {
        for (int j = 0; j < E; j++) {
            if (!used[j] && edges[j].w == sorted_weights[i]) {
                sorted_edges[i] = edges[j];
                used[j] = 1;
                break;
            }
        }
    }
    // Copy sorted edges back
    for (int i = 0; i < E; i++) {
        edges[i] = sorted_edges[i];
    }
    // Initialize Union-Find
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    FILE *out = fopen("Outputs/kruskal.txt", "w");
    if (out == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    int mst_weight = 0;
    printf("MST Edges:\n");
    fprintf(out, "MST Edges:\n");
    for (int i = 0; i < E; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u) != find(v)) {
            union_sets(u, v);
            mst_weight += w;
            printf("%d - %d : %d\n", u, v, w);
            fprintf(out, "%d - %d : %d\n", u, v, w);
        }
    }
    printf("Total MST Weight: %d\n", mst_weight);
    fprintf(out, "Total MST Weight: %d\n", mst_weight);
    fclose(out);

    return 0;
}
