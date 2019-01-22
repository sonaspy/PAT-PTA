
void ShortestDist(MGraph Graph, int dist[], Vertex S)
{
    int visited[MaxVertexNum];
    int i, j, k;
    for (j = 0; j < Graph->Nv; j++)
    {
        visited[j] = 0;
        dist[j] = Graph->G[S][j];
    }
    visited[S] = 1;
    dist[S] = 0;
    for (j = 0; j < Graph->Nv - 1; j++)
    {
        int min = INFINITY;
        int u = -1;
        for (k = 0; k < Graph->Nv; k++)
        {
            if (visited[k] == 0 && dist[k] < min)
            {
                min = dist[k];
                u = k;
            }
        }
        if (u == -1)
            break;
        visited[u] = 1;
        for (k = 0; k < Graph->Nv; k++)
        {
            if (!visited[k] && dist[k] > dist[u] + Graph->G[u][k])
            {
                dist[k] = dist[u] + Graph->G[u][k];
            }
        }
    }
    for (i = 0; i < Graph->Nv; i++)
    {
        if (dist[i] == INFINITY)
            dist[i] = -1;
    }
}
