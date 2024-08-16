#include <stdio.h>
#define infinity 999
int prime(int cost[10][10], int source, int n)
{
    int i, j, sum = 0, visited[10], cmp[10], vertex[10];
    int min, v, u;
    for (int i = 1; i <= n; i++)
    {
        vertex[i] = source;
        visited[i] = 0;
        cmp[i] = cost[source][i];
    }
    for (int i = 1; i <= n; i++)
    {
        min = infinity;
        for (int j = 1; j <= n; j++)
            if (!visited[j] && cmp[j] < min)
            {
                min = cmp[j];
                u = j;
            }
        visited[u] = 1;
        sum = sum + cmp[u];
        printf("\n %d->%d sum=%d\n", vertex[u], u, cmp[u]);
        for (v = 1; v <= n; v++)
            if (!visited[v] && cost[u][v] < cmp[v])
            {
                cmp[v] = cost[u][v];
                vertex[v] = u;
            }
    }
    return sum;
}

void main()
{
    int a[10][10], n, i, j, m, source;
    printf("\n Enter gthe number of vertices");
    scanf("%d", &n);
    printf("\n Enter the cost matrix:0 self loop & 999 no edge\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] != a[j][i] || (a[i][i] != 0))
            {
                printf("\n Invalid entry \n Cost matrix should be symmetrical & the diagonal elements are zero");
                return;
            }
    printf("\n Enter the source: ");
    scanf("%d", &source);
    m = prime(a, source, n);
    printf("\n \n Total cost=%d", m);
}
