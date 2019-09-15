#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define test() freopen("in", "r", stdin)

typedef struct node *Node;
struct node
{
    char *name;
    bool isDir;
    Node subFile;
    Node subDir;
    Node Next;
} Head;
void Print(Node, int);
void Read();
Node New(char *);
Node insertDir(Node, char *);
Node InsertFile(Node, char *);
int main()
{
    //test();
    int n;
    scanf("%d", &n);
    Head.name = (char *)malloc(sizeof(char) * 5);
    strcpy(Head.name, "root");
    Head.subFile = NULL;
    Head.subDir = NULL;
    Head.Next = NULL;
    Head.isDir = true;
    for (int i = 0; i < n; i++)
        {
            getchar();
            Read();
        }
    Print(&Head, 0);
    return 0;
}

void Read()
{
    char FileName[266];
    Node temp = &Head; // root
    scanf("%s", FileName);
    char words[266];
    int j, L = 0;
    for (int i = 0; i < strlen(FileName); i++)
        {
            if (FileName[i] == '\\')
                {
                    for (j = L; j < i; j++)
                        words[j - L] = FileName[j];
                    words[j - L] = '\0';
                    temp->subDir = insertDir(temp->subDir, words);
                    temp = temp->subDir;
                    while (strcmp(temp->name, words))
                        temp = temp->Next;
                    L = i + 1;
                }
        }
    if (L < strlen(FileName))
        {
            for (int j = L; j <= strlen(FileName); j++)
                words[j - L] = FileName[j];
            temp->subFile = InsertFile(temp->subFile, words);
        }
}
Node insertDir(Node H, char *k)
{
    if (!H || strcmp(H->name, k) > 0)
        {
            Node temp = New(k);
            temp->Next = H;
            return temp;
        }
    if (strcmp(H->name, k) == 0)
        return H;
    H->Next = insertDir(H->Next, k);
    return H;
}
Node InsertFile(Node H, char *k)
{
    if (!H || strcmp(H->name, k) > 0)
        {
            Node temp = New(k);
            temp->isDir = false;
            temp->Next = H;
            return temp;
        }
    H->Next = InsertFile(H->Next, k);
    return H;
}
Node New(char *k)
{
    Node temp = (Node)malloc(sizeof(struct node));
    temp->name = (char *)malloc(sizeof(char) * (strlen(k) + 1));
    strcpy(temp->name, k);
    temp->Next = NULL;
    temp->subFile = NULL;
    temp->subDir = NULL;
    temp->isDir = true;
    return temp;
}
void Print(Node H, int space)
{
    if (H)
        {
            for (int i = 0; i < space; i++)
                printf(" ");
            printf("%s\n", H->name);
            if (H->isDir == true)
                Print(H->subDir, space + 2);
            Print(H->subFile, space + 2);
            Print(H->Next, space);
        }
}
