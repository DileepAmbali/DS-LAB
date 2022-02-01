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

void polyMul()
{
    C = NULL;
    free(C);
    struct polyNode *tempA = A;
    struct polyNode *tempB = B;
    struct polyNode *tempC = C;
    struct polyNode *node;

    for (; tempA != NULL; tempA = tempA->link)
    {
        for (tempB = B; tempB != NULL; tempB = tempB->link)
        {
            tempC = C;
            node = create(tempA->coeff * tempB->coeff, tempA->exp + tempB->exp);
            if (isEmpty(tempC) == 1)
            {
                C = node;
            }
            else
            {
                while (tempC->exp != node->exp && tempC->link != NULL)
                {
                    tempC = tempC->link;
                }
                if (tempC->exp == node->exp)
                {
                    tempC->coeff = tempC->coeff + node->coeff;
                    free(node);
                }
                else if (tempC->link == NULL)
                {
                    tempC->link = node;
                }
            }
        }
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
        printf("\n\n 1. Create Polynomials \n 2. Multiply Polynomials \n 3. Display Polynomials \n 4. Exit  ");
        printf("\n    -> ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            A = NULL;
            B = NULL;
            free(A);
            free(B);
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
            polyMul();
            printf("\n    PRODUCT Polynomial C : ");
            display(C);
            break;
        case 3:
            printf("\n    Polynomial A : ");
            display(A);
            printf("\n    Polynomial B : ");
            display(B);
            printf("\n    PRODUCT Polynomial C : ");
            display(C);
            break;
        case 4:
            exit(0);
        default:
            printf("\n    Invalid Option !!!");
        }
    } while (1);
}