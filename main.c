#include <stdlib.h>
#include <stdio.h>

void c3_p6()
{
    int x = 10;
    int y = 1;
    while (0 < x)
    {
        y *= x;
        x -= 1;
    }
}

void c4_p4() {
    int x = 10;
    int y = 1;
    int z;
    if (x < y) {
        z = x;
    } else {
        z = y;
    }
    printf("%d\n", z);
}

void c4_p14() {
    int sum = 0;
    int i = 1;
    while (i < 11) {
        sum += i;
        i++;
    }
    printf("%d\n%d\n", sum, i);
}

void c5_p2()
{
    char buf[10];
    int i = 0;
    while (i < 20)
    {
        buf[i] = i;
        i = i + 1;
    }
}

void c5_p3()
{
    char *strings[] = {"One", "Two", "Three"};
    char *s = NULL;
    int i;
    for (i = 0; i < 3; i++)
    {
        s = strings[i];
        printf("%s\n", s);
    }
    printf("%d\n", i);
}

void c5_p15()
{
    int a, b, *p;
    p = NULL;
    if (rand())
        p = &a;
    if (p)
        *p = 42;
}

void c6_p2() {
    int A[4][8] = {8};
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            sum += A[i][j];
        }
    }
    printf("%d\n", sum);
}

int main()
{
    c3_p6();

    return 0;
}
