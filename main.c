#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int visited[MAX];
void DFS_iter(int graph[MAX][MAX], int start, int n) {
    int stack[MAX];
    int top = -1; 
    stack[++top] = start;
    visited[start] = 1;
    while (top != -1) {
        int vertex = stack[top--];
        printf("%d ", vertex);
        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                stack[++top] = i;
                visited[i] = 1; 
            }
        }
    }
}
void dfs_recur(int graph[MAX][MAX], int visited[MAX], int node) {
    visited[node] = 1;
    printf("%d ", node);
    for (int i = 0; i < MAX; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs_recur(graph, visited, i);
        }
    }
}
void BFS(int graph[MAX][MAX], int start, int n) {
    int queue[MAX], front = -1, rear = -1;
    visited[start] = 1;
    printf("%d ", start);
    queue[++rear] = start;
    if (front == -1) front = 0;
    while (front <= rear) {
        int current = queue[front++];
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                printf("%d ", i);
                queue[++rear] = i;
            }
        }
    }
}