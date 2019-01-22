Deque CreateDeque()
{
    PtrToNode Node = (PtrToNode)malloc(sizeof(struct Node)); // 1
    Deque D = (Deque)malloc(sizeof(struct DequeRecord));     // 2
    Node->Next = Node->Last = NULL;
    D->Rear = D->Front = Node;

    return D;
}
int Push(ElementType X, Deque D)
{
    PtrToNode a = (PtrToNode)malloc(sizeof(struct Node));
    if (a)
    {
        a->Element = X;
        a->Last = D->Front;
        a->Next = D->Front->Next;
        if (D->Front->Next)
            D->Front->Next->Last = a;
        else
            D->Rear = a;
        D->Front->Next = a;
        return 1;
    }
    else
        return 0;
}
ElementType Pop(Deque D)
{
    ElementType val;
    PtrToNode a = D->Front->Next;
    if (a)
    {
        val = a->Element;
        if (a == D->Rear)
        {
            D->Front->Next = NULL;
            D->Rear = D->Front;
        }
        else
        {
            D->Front->Next->Next->Last = D->Front;
            D->Front->Next = D->Front->Next->Next;
        }
        free(a);
        return val;
    }
    else
        return ERROR;
}
int Inject(ElementType X, Deque D)
{
    PtrToNode a = (PtrToNode)malloc(sizeof(struct Node));
    if (a)
    {
        a->Element = X;
        a->Next = NULL;
        if (D->Front == D->Rear)
        {
            D->Front->Next = a;
            a->Last = D->Front;
        }
        else
        {
            D->Rear->Next = a;
            a->Last = D->Rear;
        }
        D->Rear = a;
        return 1;
    }
    else
        return 0;
}
ElementType Eject(Deque D)
{
    ElementType val;
    if (D->Front == D->Rear)
        return ERROR;
    else
    {
        val = D->Rear->Element;
        if (D->Front->Next == D->Rear)
        {
            free(D->Rear);
            D->Front->Next = NULL;
            D->Rear = D->Front;
        }
        else
        {
            D->Rear = D->Rear->Last;
            free(D->Rear->Next);
            D->Rear->Next = NULL;
        }
        return val;
    }
}
