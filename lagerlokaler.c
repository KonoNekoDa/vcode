#include <stdio.h>
#define MAXFORRAD 20


struct lagerlokaler
{
    int lagringsvolym[MAXFORRAD];
    int nrlagringsvolym;
};
typedef struct lagerlokaler Lagerlokaler;

void printvarohus(Lagerlokaler v);
void concentreravarohus(Lagerlokaler *pvarohus1,Lagerlokaler *pvarohus2);

int main()
{
    Lagerlokaler varohus1 ={{8,12,10},3};
    Lagerlokaler varohus2 ={{20,30},2};

    printvarohus(varohus1);
    printvarohus(varohus2);
    concentreravarohus(&varohus1,&varohus2);
    printvarohus(varohus1);
    printvarohus(varohus2);
}

void printvarohus(Lagerlokaler v)
{
    printf("varohus: ");
    for (int i = 0; i < v.nrlagringsvolym ; i++)
    {
        printf("%d m3, ",v.lagringsvolym[i]);
    }
    printf("\n");
    
}

void concentreravarohus(Lagerlokaler *pvarohus1,Lagerlokaler *pvarohus2)
{

    int tmp1 = (pvarohus1->nrlagringsvolym);
    int tmp2 = (pvarohus1->nrlagringsvolym)+(pvarohus2->nrlagringsvolym);

    for (int i = tmp1; i < tmp2; i++)
    {
        (pvarohus1->lagringsvolym[i])=(pvarohus2->lagringsvolym[i-tmp1]);
        (pvarohus1->nrlagringsvolym)++;
        (pvarohus2->nrlagringsvolym)--;

    }
    
}