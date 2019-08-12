#include <stdio.h>

typedef FILE *file_p;
int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    int b[10];
    file_p fp = fopen("demo.dat", "wb+");
    fwrite(a, sizeof(int), 10, fp);
    fclose(fp);

    fp = fopen("demo.dat", "rb+");
    fread(b, sizeof(int), 10, fp);
    for (int i = 0; i < 10; i++)
        printf("%d ", b[i]);
    fclose(fp);

    return 0;
}

