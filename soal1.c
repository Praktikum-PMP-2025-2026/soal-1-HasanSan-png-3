//** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
//** Modul : 05 - Foundation of Algorithm
//** Hari dan Tanggal : Senin, 11 May 2026
//** Nama (NIM) : Hasan Al Mutawakkil (13224080)
//** Nama File : TP_5_PMP.c
//** Deskripsi : Mencari Leluhur (Analisis Graph)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struktur Node untuk Adjacency List
struct Node {
    int data;
    struct Node* next;
};

// Struktur List (Head pointer)
struct List {
    struct Node* head;
};

// Struktur Graph
struct Graph {
    int vertices;
    struct List* array;
};

// Fungsi membuat Node baru
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fungsi membuat Graph baru
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->array = (struct List*)malloc(vertices * sizeof(struct List));
    for (int i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Fungsi menambahkan Edge (Directed Graph)
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
    int V;

    if (scanf("%d", &V) != 1) return 0;
    
    struct Graph* g = createGraph(V);
    int matrix[V][V];
    int degree[V];
    
    // Inisialisasi degree 0
    for(int i=0; i<V; i++) degree[i] = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 1) {
                addEdge(g, i, j);
                degree[i]++; // Asumsi directed, degree = out-degree
            }
        }
    }

    // 1. Output DEGREE
    for(int i=0; i<V; i++){
        printf("DEGREE %d %d\n", i, degree[i]);
    }

    int maxDegree = -1;
    int maxVertex = -1;
    for(int i=0; i<V; i++){
        if(degree[i] > maxDegree){
            maxDegree = degree[i];
            maxVertex = i;
        }
    }
    printf("MAX_VERTEX %d\n", maxVertex);

    // 3. Mencari ISOLATED Vertex (Degree 0)
    int isolated = -1;
    for(int i=0; i<V; i++){
        if(degree[i] == 0){
            isolated = i;
            break; // Ambil yang pertama jika ada banyak
        }
    }
    printf("ISOLATED %d\n", isolated);

    return 0;
}
