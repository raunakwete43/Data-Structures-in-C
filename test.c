#include <stdio.h>
#include <string.h>

void rabinkarp(char text[], char pattern[], int q)
{
    int n = strlen(text);
    int m = strlen(pattern);
    int i, j;
    int d = 10;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < m - 1; i++)
    {
        h = (d * h) % q;
    }

    printf("Hash Value => %d\n", h);

    for (i = 0; i < m; i++)
    {
        t = (d * t + text[i]) % q;
        p = (d * p + pattern[i]) % q;
    }

    printf("Hash Value => %d\n", t);
    printf("Hash Value => %d\n", p);

    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (pattern[j] != text[i + j])
                    break;
            }
            if (j == m)
            {
                printf("Match Found at %d\n", i+1);
            }
        }


        if (i < n - m)
        {
            t = (d * (t - (h * text[i])) + text[i + m]) % q;
            if (t < 0)
                t = t + q;
        }
    }
}

int main()
{
    char text[] = "abcacbcad";
    char pat[] = "bca";

    rabinkarp(text, pat, 13);
    return 0;
}
