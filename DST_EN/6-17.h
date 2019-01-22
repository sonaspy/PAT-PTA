void ShortestDist(MGraph Graph, int dist[], int path[], Vertex S)
{
    int vis[MaxVertexNum], count[MaxVertexNum];
    for (int i = 0; i < Graph->Nv; i++)
        count[i] = vis[i] = 0, dist[i] = INFINITY, path[i] = -1;
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
            if (!vis[i] && Graph->G[S][i] + mi < dist[i])
            {
                dist[i] = Graph->G[S][i] + mi;
                count[i] = count[S];
                path[i] = S;
            }
            else if (!vis[i] && Graph->G[S][i] + mi == dist[i] && count[i] > count[S] + 1)
            {
                count[i] = count[S] + 1;
                path[i] = S;
            }
        }
    }
    for (int i = 0; i < MaxVertexNum; i++)
        if (INFINITY == dist[i])
            dist[i] = -1;
}
