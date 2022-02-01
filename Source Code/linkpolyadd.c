#include <stdio.h>
#include <stdlib.h>

struct polyNode
{
    float coeff;
    int exp;
    struct polyNode *link;
};

struct polyNode *A = NULL, *B = NULL, *C = NULL;

struct polyNode *create(float coeff, int exp)
{
    struct polyNode *node;
    node = (struct polyNode *)malloc(sizeof(struct polyNode));
    node->coeff = coeff;
    node->exp = exp;
    node->link = NULL;
    return node;
}

int isEmpty(struct polyNode *X)
{
    if (X == NULL)
        return 1;
    return 0;
}

void addNodeA(float coeff, int exp)
{
    struct polyNode *node = create(coeff, exp);
    struct polyNode *temp = A;
    if (isEmpty(A) == 1)
    {
        A = node;
        return;
    }

    while (temp->link)
    {
        temp = temp->link;
    }
    temp->link = node;
}

void addNodeB(float coeff, int exp)
{
    struct polyNode *node = create(coeff, exp);
    struct polyNode *temp = B;
    if (isEmpty(B) == 1)
    {
        B = node;
        return;
    }

    while (temp->link)
    {
        temp = temp->link;
    }
    temp->link = node;
}

int compare(int e1, int e2)
{
    if (e1 > e2)
        return -1;
    else if (e1 == e2)
        return 0;
    else
        return 1;
}

void addPoly()
{
    struct polyNode *tempA = A;
    struct polyNode *tempB = B;
    struct polyNode *tempC = C;
    struct polyNode *node;

    while (tempA != NULL && tempB != NULL)
    {

        switch (compare(tempA->exp, tempB->exp))
        {
        case -1:
            node = create(tempA->coeff, tempA->exp);
            if (isEmpty(tempC) == 1)
            {
                C = node;
                tempC = C;
                tempA = tempA->link;
            }
            else
            {
                tempC->link = node;
                tempC = tempC->link;
                tempA = tempA->link;
            }
            break;
        case 0:
            node = create((tempA->coeff + tempB->coeff), tempA->exp);
            if (isEmpty(tempC) == 1)
            {
                C = node;
                tempC = C;
                tempA = tempA->link;
                tempB = tempB->link;
            }
            else
            {
                tempC->link = node;
                tempC = tempC->link;
                tempA = tempA->link;
                tempB = tempB->link;
            }
            break;
        case 1:
            node = create(tempB->coeff, tempB->exp);
            if (isEmpty(tempC) == 1)
            {
                C = node;
                tempC = C;
                tempB = tempB->link;
            }
            else
            {
                tempC->link = node;
                tempC = tempC->link;
                tempB = tempB->link;
            }
            break;
        default:
            break;
        }
    }
    while (tempA != NULL)
    {
        node = create(tempA->coeff, tempA->exp);
        tempC->link = node;
        tempC = tempC->link;
        tempA = tempA->link;
    }

    while (tempB != NULL)
    {
        node = create(tempB->coeff, tempB->exp);
        tempC->link = node;
        tempC = tempC->link;
        tempB = tempB->link;
    }
}

void display(struct polyNode *temp)
{
    while (temp != NULL)
    {
        printf("%.1fx^%d ---> ", temp->coeff, temp->exp);
        temp = temp->link;
    }
    printf("NULL\n");
}

void main()
{
    int num;
    int exp;
    float coeff;
    int ch;

    do
    {
        printf("\n\n 1. Create Polynomials \n 2. Add Polynomials \n 3. Display Polynomials \n 4. Exit  ");
        printf("\n    -> ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the number of terms in the first polynomial: ");
            scanf("%d", &num);
            for (int i = 0; i < num; i++)
            {
                printf("Enter the coefficient of term %d: ", i + 1);
                scanf("%f", &coeff);
                printf("Enter the exponent of term %d: ", i + 1);
                scanf("%d", &exp);
                addNodeA(coeff, exp);
            }
            printf("\nThe first polynomial CREATED!\n");
            printf("\nEnter the number of terms in the second polynomial: ");
            scanf("%d", &num);
            for (int i = 0; i < num; i++)
            {
                printf("Enter the coefficient of term %d: ", i + 1);
                scanf("%f", &coeff);
                printf("Enter the exponent of term %d: ", i + 1);
                scanf("%d", &exp);
                addNodeB(coeff, exp);
            }
            printf("\nThe second polynomial CREATED!\n");
            break;
        case 2:
            addPoly();
            printf("\n    SUM Polynomial C : ");
            display(C);
            break;
        case 3:
            printf("\n    Polynomial A : ");
            display(A);
            printf("\n    Polynomial B : ");
            display(B);
            printf("\n    SUM Polynomial C : ");
            display(C);
            break;
        case 4:
            exit(0);
        default:
            printf("\n    Invalid Option !!!");
        }
    } while (1);
}