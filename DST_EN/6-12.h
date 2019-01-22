int CountConnectedComponents(LGraph Graph)
{
    int Count = 0, Front = 0, Rear = 0;
    Vertex Visit[MaxVertexNum] = {0};
    Vertex Queue[MaxVertexNum] = {0};
    Vertex V;
    for (int i = 0; i < Graph->Nv; i++)
        if (!Visit[i])
        {
            Queue[Front] = i;
            Visit[i] = 1;
            while (Front <= Rear)
            {
                PtrToAdjVNode Ptr = Graph->G[Queue[Front]].FirstEdge;
                for (; Ptr != NULL; Ptr = Ptr->Next)
                    if (!Visit[Ptr->AdjV])
                    {
                        Queue[++Rear] = Ptr->AdjV;
                        Visit[Ptr->AdjV] = 1;
                    }
                Front++;
            }
            Count++;
            Rear = Front;
        }
    return Count;
}