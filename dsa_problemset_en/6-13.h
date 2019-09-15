bool TopSort(LGraph Graph, Vertex TopOrder[])
{
    Vertex Degree[MaxVertexNum] = {0};
    PtrToAdjVNode Ptr;
    Vertex Queue[MaxVertexNum] = {0};
    int Front = 0, Rear = 0;
    for (int i = 0; i < Graph->Nv; i++)
        {
            Ptr = Graph->G[i].FirstEdge;
            for (; Ptr != NULL; Ptr = Ptr->Next)
                Degree[Ptr->AdjV]++;
        }
    for (int i = 0; i < Graph->Nv; i++)
        if (Degree[i] == 0)
            Queue[Rear++] = i;
    while (Front < Rear)
        {
            Vertex V = Queue[Front++];
            TopOrder[Front - 1] = V;
            Ptr = Graph->G[V].FirstEdge;
            for (; Ptr != NULL; Ptr = Ptr->Next)
                {
                    Degree[Ptr->AdjV]--;
                    if (Degree[Ptr->AdjV] == 0)
                        Queue[Rear++] = Ptr->AdjV;
                }
        }
    if (Front < Graph->Nv)
        return false;
    return true;
}