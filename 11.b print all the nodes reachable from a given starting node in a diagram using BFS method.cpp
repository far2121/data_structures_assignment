#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10 // Maximum number of vertices in the graph

// Structure to represent a graph using an adjacency matrix
struct Graph {
    int numVertices;                  // Number of vertices
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
};

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    // Initialize the adjacency matrix to 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1; // Add edge from src to dest
    graph->adjMatrix[dest][src] = 1; // Add edge from dest to src
}

// Function to perform BFS traversal from a given starting node
void bfs(struct Graph* graph, int start) {
    int visited[MAX_VERTICES] = {0}; // Array to keep track of visited nodes
    int queue[MAX_VERTICES];          // Queue for BFS
    int front = 0, rear = -1;

    // Mark the starting node as visited and enqueue it
    visited[start] = 1;
    queue[++rear] = start;

    printf("Nodes reachable from node %d:\n", start);

    while (front <= rear) {
        // Dequeue a node from the front of the queue
        int currentNode = queue[front++];

        printf("%d ", currentNode); // Print the current node

        // Explore all adjacent nodes
        for (int i = 0; i < graph->numVertices; i++) {
            if (graph->adjMatrix[currentNode][i] == 1 && !visited[i]) {
                visited[i] = 1;        // Mark the node as visited
                queue[++rear] = i;     // Enqueue the adjacent node
            }
        }
    }
    printf("\n");
}

// Main function
int main() {
    int vertices = 5; // Number of vertices in the graph
    struct Graph* graph = createGraph(vertices);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    int startNode = 0; // Starting node for BFS
    bfs(graph, startNode); // Perform BFS traversal

    // Free the allocated memory for the graph
    free(graph);

    return 0;
}