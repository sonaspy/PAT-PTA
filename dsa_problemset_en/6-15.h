void merge_pass(ElementType list[], ElementType sorted[], int N, int length)
{
    int Ptr3 = 0;
    int i;
    for (i = 0; i <= N - 2 * length; i = i + 2 * length)
        {
            int Ptr1 = i, Ptr2 = i + length;
            while (Ptr1 < i + length && Ptr2 < i + 2 * length)
                {
                    if (list[Ptr1] < list[Ptr2])
                        sorted[Ptr3++] = list[Ptr1++];
                    else
                        sorted[Ptr3++] = list[Ptr2++];
                }
            if (Ptr1 == i + length && Ptr2 != i + 2 * length)
                while (Ptr2 < i + 2 * length)
                    sorted[Ptr3++] = list[Ptr2++];
            if (Ptr2 == i + 2 * length && Ptr1 != i + length)
                while (Ptr1 < i + length)
                    sorted[Ptr3++] = list[Ptr1++];
        }
    if (i + length < N)
        {
            int Ptr1 = i, Ptr2 = i + length;
            while (Ptr1 < i + length && Ptr2 < N)
                {
                    if (list[Ptr1] < list[Ptr2])
                        sorted[Ptr3++] = list[Ptr1++];
                    else
                        sorted[Ptr3++] = list[Ptr2++];
                }
            if (Ptr1 == i + length && Ptr2 != N)
                while (Ptr2 < i + 2 * length)
                    sorted[Ptr3++] = list[Ptr2++];
            if (Ptr2 == N && Ptr1 != i + length)
                while (Ptr1 < i + length)
                    sorted[Ptr3++] = list[Ptr1++];
        }
    else
        for (int j = i; j < N; j++)
            sorted[j] = list[j];
}