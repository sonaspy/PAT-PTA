#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 10
int main(int argc, char const *argv[])
{
    /* code */
    static int a[N][N], i, j;
    int left = 0, right = N - 1, up = 0, down = N - 1;
    int x = 1, row = right, col = down, d = 1, done;
    while (x <= N * N)
    {
        a[row][col] = x;
        x++;
        done = 0;
        do
        {
            if (d == 1)
            {

                col--;
                if (col < left)
                {
                    col = left;
                    d = 2;
                    continue;
                }
                else
                {
                    done = 1;
                    break;
                }
            }
            else if (d == 2)
            {
                row--;
                if (row < up)
                {
                    row = up;
                    d = 3;
                    continue;
                }
                else
                {
                    done = 1;
                    break;
                }
            }
            else if (d == 3)
            {
                col++;
                if (col > right)
                {
                    col = right;
                    d = 4;
                    continue;
                }
                else
                {
                    done = 1;
                    break;
                }
            }
            else if (d == 4)
            {
                row++;
                if (row == down)
                {
                    down--;
                    left++;
                    up++;
                    right--;
                    row = down;
                    d = 1;
                    continue;
                }
                else
                {
                    done = 1;
                    break;
                }
            }
        } while (!done);
    }
    return 0;
}