#include <stdio.h>
#define N 5

void bfs(int adj[N][N], int start)
{
    int visited[N] = {0}, q[N], f = 0, r = 0;
    int i, node;

    q[r++] = start;
    visited[start] = 1;

    printf("BFS traversal starting from node %c:\n", start + 65);

    while (f < r)
    {
        node = q[f++];
        printf("%c\t", node + 65);

        for (i = 0; i < N; i++)
        {
            if (adj[node][i] == 1 && visited[i] == 0)
            {
                q[r++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main()
{
    int adj[N][N];
    int i, j;
    int start;

    printf("Enter the %dx%d adjacency matrix (0 or 1):\n", N, N);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting node (0 for A, 1 for B, ..., %d for %c): ", N - 1, N - 1 + 65);
    scanf("%d", &start);

    bfs(adj, start);

    return 0;
}

