#include <stdio.h>

void dfs(int N, int adj[N][N], int start) {
    int visited[N];
    int stack[N];
    int top = -1;
    int i;
    for (i = 0; i < N; i++)
        visited[i] = 0;
    stack[++top] = start;
    while (top != -1) {
        int node = stack[top--];
        if (!visited[node]) {
            visited[node] = 1;
            printf("%c\t", node + 65);
            for (i = N - 1; i >= 0; i--)
                if (adj[node][i] == 1 && !visited[i])
                    stack[++top] = i;
        }
    }
}
int main() {
    int N;
    printf("Enter no.of nodes : ");
    scanf("%d", &N);
    int adj[N][N];
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%d", &adj[i][j]);
    char startChar;
    scanf(" %c", &startChar);
    int startNode = startChar - 'A';
    if (startNode < 0 || startNode >= N)
        return 1;
    dfs(N, adj, startNode);
    return 0;
}

