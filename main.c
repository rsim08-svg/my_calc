#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<stdbool.h>
#include "main.h"


//Функция калькулятора, которая определяет какую операцию использовать
int calc(int i1, int i2, char op)
{
    if (op == ((int)('+'))) return i1 + i2;
    if (op == ((int)('-'))) return i1 - i2;
    if (op == ((int)('*'))) return i1 * i2;
    if (op == ((int)('%'))) return i1 % i2;
    return 0;
}

void result(char* arr, int len, int k)
{
    for(int j = 0; j < len; j++) arr[j] -= k;
}
