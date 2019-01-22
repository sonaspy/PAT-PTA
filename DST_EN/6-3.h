Polynomial Add(Polynomial a, Polynomial b)
{
    Polynomial c = (Polynomial)malloc(sizeof(struct Node));
    c->Next = NULL;      
    Polynomial tail = c; 
    Polynomial pa, pb;
    pa = a->Next;
    pb = b->Next; 
    while (pa != NULL && pb != NULL)
    { 
        if (pa->Exponent > pb->Exponent)
        {                                                                 
            Polynomial newnode = (Polynomial)malloc(sizeof(struct Node)); 
            newnode->Coefficient = pa->Coefficient;
            newnode->Exponent = pa->Exponent;
            newnode->Next = NULL;
            tail->Next = newnode;
            tail = newnode; 
            pa = pa->Next;  
        }
        else if (pa->Exponent < pb->Exponent)
        {
            Polynomial newnode = (Polynomial)malloc(sizeof(struct Node)); 
            newnode->Coefficient = pb->Coefficient;
            newnode->Exponent = pb->Exponent;
            newnode->Next = NULL;
            tail->Next = newnode;
            tail = newnode; 
            pb = pb->Next;  
        }
        else
        { 
            if ((pa->Coefficient + pb->Coefficient) != 0)
            {                                                                 
                Polynomial newnode = (Polynomial)malloc(sizeof(struct Node)); 
                newnode->Coefficient = pa->Coefficient + pb->Coefficient;
                newnode->Exponent = pa->Exponent;
                newnode->Next = NULL;
                tail->Next = newnode;
                tail = newnode; 
            }
            pa = pa->Next;
            pb = pb->Next; 
        }
    }
    
    if (pb == NULL)
    {
        while (pa != NULL)
        {                                                                 
            Polynomial newnode = (Polynomial)malloc(sizeof(struct Node)); 
            newnode->Coefficient = pa->Coefficient;
            newnode->Exponent = pa->Exponent;
            newnode->Next = NULL;
            tail->Next = newnode;
            tail = newnode; 
            pa = pa->Next;  
        }
    }
    else
    {
        while (pb != NULL)
        {
            Polynomial newnode = (Polynomial)malloc(sizeof(struct Node)); 
            newnode->Coefficient = pb->Coefficient;
            newnode->Exponent = pb->Exponent;
            newnode->Next = NULL;
            tail->Next = newnode;
            tail = newnode; 
            pb = pb->Next;  
        }
    }
    return c;
}
