#include <stdio.h>

void create(int poly[], int degree)
{
    int i = 0;

    printf("Enter the coeffecients for:\n");
    for (i = degree; i >= 0; i--)
    {
        printf("Exp_%d: ", i);
        scanf("%d", &poly[i]);
    }
}
void display(int poly[], int degree)
{
    int i;
    for (i = degree; i >= 0; i--)
    {

        if (i != degree && poly[i] >= 0)
        {
            printf(" + ");
        }
        printf("%dx^%d", poly[i], i);
    }
}
void main()
{
    int poly1[100] = {
        0},
        degree1, poly2[100] = {0}, degree2, degreeresult, polyresult[100], i = 0;

    printf("Enter the degree of first polynomial");
    scanf("%d", &degree1);
    create(poly1, degree1);
    printf("Enter the degree of second polynomial");
    scanf("%d", &degree2);
    create(poly2, degree2);
    if (degree1 > degree2)
    {
        degreeresult = degree1;
    }
    else
    {
        degreeresult = degree2;
    }
    for (i = 0; i <= degreeresult; i++)
    {
        polyresult[i] = poly1[i] + poly2[i];
    }
    printf("The first polynomial is:\n");
    display(poly1, degree1);
    printf("\nThe second polynomial is:\n");
    display(poly2, degree2);
    printf("\nThe sum of 2 polynomials is:\n");
    display(polyresult, degreeresult);
}