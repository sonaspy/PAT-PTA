void ShortestDist(LGraph Graph, int dist[], Vertex S)
{
    int front = 0, rear = 0;
    PtrToAdjVNode p = NULL;
    Vertex que[MaxVertexNum];
    for (int i = 0; i < MaxVertexNum; i++)
        que[i] = dist[i] = -1;
    dist[S] = 0;
    que[0] = S;

    while (front <= rear)
    {
        Vertex s = que[front++];
        p = Graph->G[s].FirstEdge;
        while (p)
        {
            Vertex v = p->AdjV;
            if (dist[v] == -1)
            {
                dist[v] = 1 + dist[s];
                que[++rear] = v;
            }
            p = p->Next;
        }
    }
}
