#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int n) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = n;

    graph->adjLists = malloc(n* sizeof(struct Node*));

    int i;
    for (i = 0; i < n; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

int outdegree(struct Graph* graph, int vertex) {
    struct Node* temp = graph->adjLists[vertex];
    int count = 0;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int indegree(struct Graph* graph, int vertex) {
    int i, count = 0;
    for (i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            if (temp->vertex == vertex)
                count++;
            temp = temp->next;
        }
    }
    return count;
}

int main() {
    int n = 4; 
    struct Graph* graph = createGraph(n);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);

    int i;
    for (i = 0; i < n; i++) {
        printf("Vertex %d - Outdegree: %d, Indegree: %d\n", i, outdegree(graph, i), indegree(graph, i));
    }

    return 0;
}



   