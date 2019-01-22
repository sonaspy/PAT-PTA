
void ShortestDist(MGraph Graph, int dist[], Vertex S)
{
    int book[MaxVertexNum];
    int i, j, k;
    for (j = 0; j < Graph->Nv; j++)
    {
        book[j] = 0;
        dist[j] = Graph->G[S][j];
    }
    book[S] = 1;
    dist[S] = 0;
    for (j = 0; j < Graph->Nv - 1; j++)
    {
        int min = INFINITY;
        int u = -1;
        for (k = 0; k < Graph->Nv; k++)
        {
            if (book[k] == 0 && dist[k] < min)
            {
                min = dist[k];
                u = k;
            }
        }
        if (u == -1)
            break;
        book[u] = 1;
        for (k = 0; k < Graph->Nv; k++)
        {
            if (!book[k] && dist[k] > dist[u] + Graph->G[u][k])
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
