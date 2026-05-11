#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct List {
    struct Node* head;
};

struct Graph {
    int vertices;
    struct List* array;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->array = (struct List*)malloc(vertices * sizeof(struct List));
    for (int i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    struct Graph* g = createGraph(n);
    int matrix[n][n];
    int degree[n];
    
    for (int i = 0; i < n; i++) {
        degree[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 1) {
                addEdge(g, i, j);
                degree[i]++;
            }
        }
    }
    
    // Output DEGREE
    for(int i=0; i<n; i++){
        printf("DEGREE %d %d\n", i, degree[i]);
    }
    
    // Output MAX_VERTEX
    int maxD = -1, maxV = 0; // Inisialisasi maxV dengan 0
    for(int i=0; i<n; i++){
        if(degree[i] > maxD){
            maxD = degree[i];
            maxV = i;
        }
    }
    printf("MAX_VERTEX %d\n", maxV);
    

    bool foundIsolated = false;
    printf("ISOLATED");
    for(int i=0; i<n; i++){
        if(degree[i] == 0){
            printf(" %d", i);
            foundIsolated = true;
        }
    }
    printf("\n");
    
    return 0;
}
