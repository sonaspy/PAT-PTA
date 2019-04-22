# 1 "demo.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 332 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "demo.c" 2



extern int buf[];
int *bufp0 = &buf[0];
static int *bufp1;
void swap()
{
    int temp;
    bufp1 = &buf[1];
    temp = *bufp0;
    *bufp0 = *bufp1;
    *bufp1 = temp;
}
