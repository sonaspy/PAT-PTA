#include <stdio.h>

struct node
{
    struct node *next;
    int d;
};
typedef struct aa
{
    int n;
    double m;
} ABC;
struct student
{
    int num;
    char name[30];
    float score;
} stud1;
int main(int argc, char **argv)
{
    int x = '\2';
    double b = 1e-1;
    long int c;

    printf("%lu", sizeof stud1);
    return 0;
}