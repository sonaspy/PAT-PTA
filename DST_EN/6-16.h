void ShortestDist(MGraph Graph, int dist[], int count[], Vertex S)
{
    int vis[MaxVertexNum];
    for (int i = 0; i < MaxVertexNum; i++)
        dist[i] = INFINITY, vis[i] = count[i] = 0;
    dist[S] = 0, count[S] = 1;
    while (1)
    {
        int mi = INFINITY;
        S = -1;
        for (int i = 0; i < Graph->Nv; i++)
            if (!vis[i] && mi > dist[i])
                mi = dist[i], S = i;
        if (S == -1)
            break;
        vis[S] = 1;
        for (int i = 0; i < Graph->Nv; i++)
        {
            if (!vis[i] && mi + Graph->G[S][i] < dist[i])
                dist[i] = mi + Graph->G[S][i], count[i] = count[S];
            else if (!vis[i] && mi + Graph->G[S][i] == dist[i])
                count[i] += count[S];
        }
    }
    for (int i = 0; i < MaxVertexNum; i++)
        if (dist[i] == INFINITY)
            dist[i] = -1, count[i] = 0;
}