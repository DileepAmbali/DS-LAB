#include <stdio.h>

#include <stdlib.h>
struct node
{
    int coeff, exp;
    struct node *link;
} *A = NULL, *B = NULL, *S = NULL;

struct node *create()
{
    struct node *TP = NULL, *temp = NULL, *LTP = NULL;
    int n, coeff, exp, i;
    printf("\n Enter no of Terms of Poly  : ");
    scanf("%d", &n);
    printf("\n Enter Coefficint and Exponent of Poly in order(k1x^n+k2x^n-1..+knx^0  : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &coeff, &exp);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->coeff = coeff;
        temp->exp = exp;
        temp->link = NULL;
        if (TP == NULL)
        {
            TP = temp;
            LTP = temp;
        }
        else
        {
            LTP->link = temp;
            LTP = temp;
        }
    }
    return TP;
}
void display(struct node *temp)
{
    while (temp != NULL)
    {
        printf("%dx^%d ---> ", temp->coeff, temp->exp);
        temp = temp->link;
    }
    printf("NULL\n");
}
struct node *polyadd(struct node *P1, struct node *P2)
{
    struct node *P3 = NULL, *lastP3 = NULL, *temp = NULL;
    if (P1 == NULL)
        P3 = P2;
    else if (P2 == NULL)
        P3 = P1;
    else
    {
        while (P1 != NULL && P2 != NULL)
        {

            if (P2->exp > P1->exp)
            {
                temp = (struct node *)malloc(sizeof(struct node));
                temp->coeff = P2->coeff;
                temp->exp = P2->exp;
                temp->link = NULL;

                if (P3 == NULL)
                {
                    P3 = temp;
                    lastP3 = temp;
                }
                else
                {
                    lastP3->link = temp;
                    lastP3 = temp;
                }
                P2 = P2->link;
            }
            else if (P2->exp < P1->exp)
            {
                temp = (struct node *)malloc(sizeof(struct node));
                temp->coeff = P1->coeff;
                temp->exp = P1->exp;
                temp->link = NULL;
                if (P3 == NULL)
                {
                    P3 = temp;
                    lastP3 = temp;
                }
                else
                {
                    lastP3->link = temp;
                    lastP3 = temp;
                }
                P1 = P1->link;
            }
            else
            {
                temp = (struct node *)malloc(sizeof(struct node));
                temp->coeff = P1->coeff + P2->coeff;
                temp->exp = P1->exp;
                temp->link = NULL;
                if (P3 == NULL)
                {
                    P3 = temp;
                    lastP3 = temp;
                }
                else
                {
                    lastP3->link = temp;
                    lastP3 = temp;
                }
                P1 = P1->link;
                P2 = P2->link;
            }
        }
        while (P1 != NULL)
        {
            lastP3->link = P1;
            lastP3 = P1;
            P1 = P1->link;
        }
        while (P2 != NULL)
        {
            lastP3->link = P2;
            lastP3 = P2;
            P2 = P2->link;
        }
    }
    return P3;
}

void main()
{
    int ch;

    do
    {
        printf("\n\n 1. Create Poly \n 2. Add Poly \n 3. Display Poly \n 4. Exit  ");
        printf("\n    Enter Option : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            A = create();
            B = create();
            break;
        case 2:

            S = polyadd(A, B);
            display(S);
            break;
        case 3:
            printf("\n    Polynomial A : ");
            display(A);
            printf("\n    Polynomial B : ");
            display(B);
            break;
        case 4:
            exit(0);
        default:
            printf("\n    Invalid Option !!!");
        }
    } while (1);
}