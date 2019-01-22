void PercolateUp(int p, PriorityQueue H)
{
    int i = H->Size;
    int X = H->Elements[p];
    for (; H->Elements[i / 2] > X; i /= 2)
        H->Elements[i] = H->Elements[i / 2];
    H->Elements[i] = X;
}

void PercolateDown(int p, PriorityQueue H)
{
    int X = H->Elements[1];
    int Parent, Child;
    for (Parent = 1; Parent * 2 <= H->Size; Parent = Child)
    {
        Child = Parent * 2;
        if (Child != H->Size && H->Elements[Child] > H->Elements[Child + 1])
        {
            Child++;
        }
        if (X <= H->Elements[Child])
            break;
        else
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = X;
}