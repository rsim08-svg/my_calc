#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<stdbool.h>
#include "main.h"

int stoi(char* str)
{
    int a = 0, slen = strlen(str);
    for(int i = 0; i < slen; i++) a += (str[i]-48)*((int)pow(10, slen-i-1));
    return a;
}

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

int main(int argc, char* argv[])
{
        char* ans = (char*)malloc(sizeof(int)*((argc-1)/3));
        for (int i = 1; i < argc; i++)
	{
            if (strcmp(argv[i], "-k") == false)
	    {
                if (i+2 != argc)
		{
                    printf("Не найден аргумент для флага -k\n");
                    return 0;
                }
                break;
            }
            if (i % 3 == 2)
	    {
                if (((int)argv[i][0] == ((int)('+'))
                    || (int)argv[i][0] == ((int)('-'))
                    || (int)argv[i][0] == ((int)('*'))
                    || (int)argv[i][0] == ((int)('%'))) == false)
                    {
                        printf("Ошибка в выражении.\n");
                        return 0;
                    }
            } 
	    
	    else 
	    {
                if (((int)argv[i][0] - 48 < 0) || ((int)argv[i][0] - 48 > 9))
		{
                    printf("Ошибка в числе.\n");
                    return 0;
                }
            }
        }
        if (argc%3 != 0) 
	{
            printf("Неверное кол-во аргументов / и / или не найдено -k\n");
            return 0;
        }

        for (int i = 1; i < argc; i++)
	{
            if (strcmp(argv[i], "-k") == false)
	    {
                result(ans, ((argc-1)/3), stoi(argv[i+1]));
                printf("Результирующая строка: %s\n", ans);
                return 0;
            }

            if (i % 3 == 2)
	    {
                int c = calc(stoi(argv[i-1]), stoi(argv[i+1]), argv[i][0]);
                printf("Ответ №%d: %d\n", ((i+1)/3), c);
                ans[((i+1)/3) - 1] = c;
            }
        }
}
