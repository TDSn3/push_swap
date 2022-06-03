#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define N 0
#define R 1
#define X 0
#define Z 1
#define M 3


int main(int ac, char **av)
{
    int a[2] = {0, 0};
    int i[2] = {1, 0};

    if (ac ^ 3)
        return (1);

c:
    if (*(av[i[X]]))
    {
        if ((*(av[i[X]]) ^ '0') < 10)
        {
            a[i[Z]] *= 10;
            a[i[Z]] += (*(av[i[X]]) - '0');
        }
        ++(av[i[X]]);
        goto c;
    }
    if (i[X]++ == 1 && !i[Z]++)
        goto c;

    int *s = malloc(sizeof(int) * a[N]);

    srand(time((void *)0));

    if (a[N] > ((a[R] << 1) + 1))
        return (1);
    i[X] = 0;

generate:
    if (i[X] < a[N])
    {
        i[Z] = 0;
        s[i[X]] = (rand() % (a[R] + 1));
        if (!(rand() % (M)))
            s[i[X]] *= -1;
    t:
        if (i[Z] < i[X])
        {
            if (s[i[X]] == s[i[Z]])
                goto generate;
            i[Z]++;
            goto t;
        }
        i[X]++;
        goto generate;
    }
    i[X] = 0;

print:
    if(i[X] < a[N])
    {
        printf("%d",s[i[X]]);
        if (i[X] ^ (a[N] - 1))
            printf(" ");
        i[X]++;
        goto print;
    }
    if (s)
        free(s);
    printf("\n");
    return (0);
}
