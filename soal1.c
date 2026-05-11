//** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
//* Modul : 05 - Foundation of Algorithm
//* Hari dan Tanggal : Senin, 11 May 2026
//* Nama (NIM) : Hasan Al Mutawakkil (13224080)
//* Nama File : TP_5_PMP.c
//* Deskripsi : Mencari Leluhur (Analisis Graph Degree)

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

// ... (Fungsi DFS dan DFSTraversal tidak digunakan di main() saat ini, 
//      tapi dibiarkan sesuai kode asli)

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

    // Cari Max Degree
    int maxD = -1, maxV = -1;
    for(int i=0; i<n; i++){
        if(degree[i] > maxD){
            maxD = degree[i];
            maxV = i;
        }
    }
    // Tambahkan \n agar MAX_VERTEX tidak menempel dengan ISOLATED
    printf("MAX_VERTEX %d\n", maxV);

    // Cari Isolated
    bool foundIsolated = false;
    for(int i=0; i<n; i++){
        if(degree[i] == 0){
            if (!foundIsolated) {
                printf("ISOLATED");
                foundIsolated = true;
            }
            printf(" %d", i);
        }
    }

    if(!foundIsolated){
        printf("ISOLATED NONE");
    }
    printf("\n");

    return 0;
}
