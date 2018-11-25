// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<stdio.h>

using namespace std;
void Print_Factorial( int N);
    int main(int argc, char const *argv[])
{
    /* code */
    Print_Factorial(4);
    return 0;
}

void Print_Factorial( int N)
{
  int fact[2568] = {0};
  fact[0] = 1;
  int n = 0, digits = 1; // n 为进的数，digits 为当前结果的总位数

  for (int i = 2; i <= N; i++)
  {
    for (int j = 0; j < digits; j++)
    {
      int temp = i * fact[j] + n;
      fact[j] = temp % 10;
      n = temp / 10;
      if (n && j == digits - 1)
      {
        digits++;
      } // 当有进位且已经处理到最前位时才开拓目标数组的下一位
    }
  }

  for (int i = digits - 1; i >= 0; i--)
  {
    if (N >= 0)
    {
      printf("%d", fact[i]);
    }
    else
    {
      printf("Invalid input");
    }
  }
  printf("\n");
}
