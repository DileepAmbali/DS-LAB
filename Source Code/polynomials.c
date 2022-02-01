#include <stdio.h>
#define MAX_TERM 100
typedef struct
{
    float coeff;
    int expon;
} polynomial;

polynomial term[MAX_TERM];
int avail = 0;

void attach(float coeff, int exp)
{
    if (avail >= MAX_TERM)
    {
        fprintf(stderr, "Too many terms!");
        exit();
    }
    term[avail].coeff = coeff;
    term[avail].expon = exp;
}

int main()
{
    return 0;
}