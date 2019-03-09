void MySort(ElementType A[], int N)
{
    int i = 0;
    int Front = 0;
    int Rear = N - 1;
    ElementType *B = (ElementType *)malloc(N * sizeof(ElementType));
    for (i = 0; i < N; i++)
        {
            if (A[i] == false)
                B[Front++] = A[i];
            if (A[i] == true)
                B[Rear--] = A[i];
        }
    for (i = Front; i <= Rear; i++)
        B[i] = maybe;
    for (i = 0; i < N; i++)
        A[i] = B[i];
    free(B);
}