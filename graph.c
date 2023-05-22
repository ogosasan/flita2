#include "graph.h"

void read_graph(FILE* file, struct graph* graph) {
    char line[256];
    int row = 0;

    while (fgets(line, sizeof(line), file)) {
        int col = 0;
        char* token = strtok(line, " ");
        while (token) {
            int value = atoi(token);
            graph->nodes[row][col++] = value;
            if (col-1 <= row) {
                graph->nodes[col-1][row] = value;
            }
            token = strtok(NULL, " ");
        }
        row++;
    }

    graph->num_nodes = row;
}

void write_dot(FILE* file, struct graph* g) {
    fprintf(file, "digraph G {\n");
    for (int i = 0; i < g->num_nodes; i++) {
        fprintf(file, "  %d;\n", i);
    }
    for (int i = 0; i < g->num_nodes; i++) {
        for (int j = i; j < g->num_nodes; j++) {
            if (g->nodes[i][j]) {
                fprintf(file, "  %d -> %d [dir=none, label=%d];\n", i, j, g->nodes[i][j]);
            }
        }
    }
    fprintf(file, "}\n");
}
