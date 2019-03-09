void Level_order(Tree T, void (*visit)(Tree ThisNode))
{
    Tree Queue[100];
    int Head = 0, Next = 0;
    if (T != NULL)
        Queue[Next++] = T;
    while (Head < Next)
        {
            if (Queue[Head]->Left)
                Queue[Next++] = Queue[Head]->Left;
            if (Queue[Head]->Right)
                Queue[Next++] = Queue[Head]->Right;
            visit(Queue[Head++]);
        }
}
