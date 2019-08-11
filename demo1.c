#include <stdio.h>

struct stu
{
    char *ss;
    int i;
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    struct stu a, *p = &a;
    a.ss = "123";
    char *z;
    z = p->ss++;
    printf("%s", p->ss);
    return 0;
}