int Isomorphic(Tree T1, Tree T2)
{
    int flag = 1, flag1 = 1, flag2 = 1, flag3 = 1, flag4 = 1;
    if (T1 != NULL && T2 != NULL)
        {
            if (T1->Element != T2->Element)
                flag = 0;
            else
                {
                    flag1 = Isomorphic(T1->Left, T2->Left);
                    flag2 = Isomorphic(T1->Left, T2->Right);
                    flag3 = Isomorphic(T1->Right, T2->Left);
                    flag4 = Isomorphic(T1->Right, T2->Right);
                    flag = (flag1 && flag4) || (flag2 && flag3);
                }
        }
    else if (T1 == NULL && T2 != NULL)
        flag = 0;
    else if (T1 != NULL && T2 == NULL)
        flag = 0;
    return flag;
}