#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int p1, p2, p3;
    char str[200], ch[200];
    scanf("%d%d%d", &p1, &p2, &p3);
    scanf("%s", str);
    int len = strlen(str);
    memset(ch, 0, sizeof(ch));
    for (int i = 1; i <= len; i ++)
    {
        if (str[i] == '-' && i > 1 && i < len - 1)
        {
            if ((str[i - 1] >= 'a' && str[i - 1] <= 'z' && str[i + 1] >= 'a' && str[i + 1] <= 'z' && str[i - 1] < str[i + 1]) ||
                (str[i - 1] >= 'A' && str[i - 1] <= 'Z' && str[i + 1] >= 'A' && str[i + 1] <= 'Z' && str[i - 1] < str[i + 1]) ||
                (str[i - 1] >= '0' && str[i - 1] <= '9' && str[i + 1] >= '0' && str[i + 1] <= '9' && str[i - 1] < str[i + 1]))
            {
                if (p3 == 2)
                {
                    for (char c = str[i + 1] - 1; c > str[i - 1]; c --)
                    {
                        if (p1 == 3)
                            ch[strlen(ch)] = '*';
                        else if (p1 == 2)
                        {
                            if (c >= 'a' && c <= 'z')
                                ch[strlen(ch)] = c - 'a' + 'A';
                            else if (c >= 'A' && c <= 'Z')
                                ch[strlen(ch)] = c - 'A' + 'a';
                            else
                                ch[strlen(ch)] = c;
                        }
                        else
                        {
                            ch[strlen(ch)] = c;
                        }
                    }
                }
                else
                {
                    for (char c = str[i - 1] + 1; c < str[i + 1]; c ++)
                    {
                        if (p1 == 3)
                            ch[strlen(ch)] = '*';
                        else if (p1 == 2)
                            {
                                if (c >= 'a' && c <= 'z')
                                    ch[strlen(ch)] = c - 'a' + 'A';
                                else if (c >= 'A' && c <= 'Z')
                                    ch[strlen(ch)] = c - 'A' + 'a';
                                else
                                    ch[strlen(ch)] = c;
                            }
                            else
                            {
                                ch[strlen(ch)] = c;
                            }
                    }       
                }
            }
            else
            {
                ch[strlen(ch)] = str[i];
            }
        }
            else
            {
                ch[strlen(ch)] = str[i];
            }
        }
    printf("%s\n", ch + 1);
    return 0;
}