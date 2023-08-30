#include <stdio.h>
int visited[7] = {0, 0, 0, 0, 0, 0, 0}; //7 vertices and no vertex has been visited
int a[7][7] =
    {
        {0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {0, 1, 1, 1, 0, 1, 0},
        {0, 1, 1, 0, 0, 1, 0},
        {0, 0, 1, 1, 0, 0, 0},
}; //adjacency matrix

int main()
{
    dfs(0);
    return 0;
}

void dfs(int i) // i -> visited node
{
    visited[i] = 1;
    printf("%d", i); //printing the visited node
    for (int j = 0; j < 7; j++)
    {
        if (a[i][j] == 1 && visited[j] == 0)
        // i : current vertex
        // j : next vertex
        // a[i][j]==1 :  EDGE EXISTS between vertex i and j
        // visited[j] == 0 : NEXT VERTEX (j) IS NOT VISITED
        {
            dfs(j);
        }
    }
}