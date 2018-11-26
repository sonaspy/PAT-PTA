// data structure problem solutions for CN fuctions part.
#ifndef PTA_DST_FUNCTIONS___
#define PTA_DST_FUNCTIONS___



// 6-1
List Reverse(List L)
{ 
  List b = NULL;
  List a = L;
  if (!L)
    return L;
  while (L->Next)
  {
    a = L->Next;
    L->Next = b;
    b = L;
    L = a;
  }
  a->Next = b;
  return a;
}
/**======================================================= */




// 6-2

List MakeEmpty(){
  List p;
  p = (List)malloc(sizeof(struct LNode));
  p->Last = -1;
  return p;
}
Position Find( List L, ElementType X ){
   int i;
    for(i = 0; i <= L->Last; i++){
        if(X==L->Data[i]){
            return i;
        }
    }
    return ERROR;
}
bool Insert( List L, ElementType X, Position P ){
  if(L->Last == MAXSIZE-1){
    printf("FULL");
    return false;
  }
  if(P<0||P>L->Last+1){
     printf("ILLEGAL POSITION");
        return false;
  int i;
    for(i = L->Last+1; i > P; i--){
        L->Data[i] = L->Data[i-1];
    }
    L->Data[P] = X;
    L->Last++;
    return true;
}
bool Delete( List L, Position P ){
    int i;
    if(P<0||P>L->Last){
        printf("POSITION %d EMPTY",P);
        return false;
    }
    for(i = P; i < L->Last; i++){
        L->Data[i] = L->Data[i+1];
    }
    L->Last--;
    return true;
}
/**======================================================= */


// 6-3
int Length( List L ){
  int cnt = 0;
  while(L!=NULL){
    cnt++;
    L = L->Next;
  }
  return cnt;
}
/**======================================================= */


// 6-4
ElementType FindKth( List L, int K ){
    if(L==NULL) return ERROR;   
    while(--K){                       
        if(L->Next==NULL) return ERROR;
        else L=L->Next;
    }
    return L->Data;          
}
/**======================================================= */


// 6-5

Position Find( List L, ElementType X ){
    while(L){
        if(L->Data == X){
            return L;
        }
        L = L->Next;
    }
    return ERROR;
}
List Insert( List L, ElementType X, Position P ){
    List head = L;
    List p = (List)malloc(sizeof(struct LNode));
    p->Data = X;    
    p->Next = NULL;
    if(P==L){
        p->Next = L;
        return p;
    }
    while(L){
        if(P==L->Next){
            List temp = L->Next;
            L->Next = p;
            p->Next = temp;
            return head;
        }
        L = L->Next;
    }
    printf("Wrong Position for Insertion\n");
    return ERROR;
}
List Delete( List L, Position P ){
    if(L == P){
        L = L->Next;
        return L;
    }
    List head = L;

    while(L){
        if(L->Next==P){
            List temp = P->Next;
            L->Next = temp;
            return head;
        }
        L = L->Next;
    }
    printf("Wrong Position for Deletion\n");
    return ERROR;
}
/**======================================================= */


// 6-6

List MakeEmpty()
{
    List L = (List)malloc(sizeof(List));
    L->Next = NULL;
    return L;
}
Position Find(List L, ElementType X)
{
    L = L->Next;
    while (L)
    {
        if (L->Data == X)
        {
            return L;
        }
        L = L->Next;
    }
    return ERROR;
}

bool Insert(List L, ElementType X, Position P)
{
    List p = (List)malloc(sizeof(List));
    p->Data = X;
    p->Next = NULL;
    List k = L;
    while (k)
    {
        if (k->Next == P)
        {
            p->Next = P;
            k->Next = p;
            return true;
        }
        k = k->Next;
    }
    printf("Wrong Position for Insertion\n");
    return false;
}

bool Delete(List L, Position P)
{
    if (L == P)
    {
        L = L->Next;
        return true;
    }
    while (L)
    {
        if (L->Next == P)
        {
            L->Next = P->Next;
            return true;
        }
        L = L->Next;
    }
    printf("Wrong Position for Deletion\n");
    return false;
}

/**======================================================= */


// 6-7

Stack CreateStack(int MaxSize)
{
    Stack stack = (Stack)malloc(sizeof(struct SNode));
    stack->Data = (int *)malloc(sizeof(ElementType) * MaxSize);
    stack->Top1 = -1;
    stack->Top2 = MaxSize;
    stack->MaxSize = MaxSize;
    return stack;
}
bool Push(Stack S, ElementType X, int Tag)
{
    if (S == NULL)
        return false;
    if (S->Top1 + 1 == S->Top2)
    {
        printf("Stack Full\n");
        return false;
    }

    if (Tag == 1)
        S->Data[++S->Top1] = X;
    else
        S->Data[--S->Top2] = X;
    return true;
}
ElementType Pop(Stack S, int Tag)
{
    if (S == NULL)
        return ERROR;
    if (Tag == 1)
    {
        if (S->Top1 == -1)
        {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
        return S->Data[S->Top1--];
    }

    if (S->Top2 == S->MaxSize)
    {
        printf("Stack %d Empty\n", Tag);
        return ERROR;
    }
    return S->Data[S->Top2++];
}

/**======================================================= */

//6-8

#endif