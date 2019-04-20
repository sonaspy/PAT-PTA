// author - newguo@sonaspy.cn
// coding - utf_8

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    /* code */
    double x[10],y[10],k;
    double center_x = 1, center_y = -0.5, r = 5;
    int i;
    for (i = 0; i < 10; i++)
    {
        double dis = pow(abs(x[i] - center_x), 2) + pow(abs(y[i] - center_y), 2);
        dis = sqrt(dis);
        if(dis < r) k++;
    }

    return 0;
}