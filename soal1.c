//** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
//* Modul : 05 - Foundation of Algorithm
//* Hari dan Tanggal : Senin, 11 May 2026
//* Nama (NIM) : Hasan Al Mutawakkil (13224080)
//* Nama File : TP_5_PMP.c
//* Deskripsi : Mencari Leluhur


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

void DFS(struct Graph* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);
    struct Node* currentNode = graph->array[vertex].head;
    while (currentNode) {
        int adjacentVertex = currentNode->data;
        if (!visited[adjacentVertex]) {
            DFS(graph, adjacentVertex, visited);
        }
        currentNode = currentNode->next;
    }
}

void DFSTraversal(struct Graph* graph, int* order, int orderSize) {
    bool* visited = (bool*)malloc(graph->vertices * sizeof(bool));
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < orderSize; i++) {
        if (!visited[order[i]]) {
            DFS(graph, order[i], visited);
        }
    }
    free(visited);
}

int main() {
    int n;
    int arr[99]; 
    scanf("%d", &n);


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
    
    for(int i=0; i<n; i++){
        printf("DEGREE %d %d\n", i, degree[i]);
    }

    

    int c = -1;
    for(int i=0; i<n; i++){
        if(degree[i] == 0){
            c = i;
            break; 
        }
    }
    printf("ISOLATED %d\n", c);

    int maxD = -1, maxV =-1;
    for(int i=0; i<n; i++){
        if(degree[i] > maxD){
            maxD = degree[i];
            maxV = i;
        }
    }
    printf("MAX_VERTEX %d", maxV);
    printf("\n");


   return 0;
}
