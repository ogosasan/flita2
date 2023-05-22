#include "graph.h"



int main(int argc, char *argv[]) {
    struct graph graph = {0};
    if(argc != 2){
        puts("Error input! Enter path to file.");
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error. Unable to open file.\n");
        return 1;
    }
    read_graph(file, &graph);
    fclose(file);
    file = fopen("graph.dot", "w");
    if (file == NULL) {
        fprintf(stderr, "Error. Unable to open file.\n");
        return 1;
    }
    write_dot(file, &graph);
    fclose(file);
    system("dot -Tpng graph.dot -o graph.png");
    return 0;
}