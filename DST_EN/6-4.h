
List Reverse(List L)
{
    if (!L || !(L->Next) || !(L->Next->Next))
        return L;
    PtrToNode nd, p = L->Next->Next, nx = L->Next;
    nx->Next = NULL;
    while (p)
    {
        nd = p->Next;
        p->Next = nx;
        nx = p;
        p = nd;
    }
    L->Next = nx;

    return L;
}
