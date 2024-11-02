#include <stdio.h>
#include <math.h>

struct expfunk
{
    float c,k;
};
typedef struct expfunk Expfunk;

void printExp(Expfunk e);
void value(Expfunk myExp, float val);
void multiply(Expfunk *pmyExp, float dec);

int main()
{
    Expfunk myExp={20,0.3};

    printExp(myExp);
    value(myExp,5.1);
    multiply(&myExp,2.1);
    printf("\n");
    printExp(myExp);
}

void printExp(Expfunk e)
{
    printf("y(x)= %.2fe^(%.2fx)",e.c,e.k);
}

void value(Expfunk myexp, float val)
{
    float newval= myexp.c*exp(myexp.k*val);

    printf("\n%.2f",newval);
}

void multiply(Expfunk *pmyExp, float dec)
{
    (pmyExp->c)=(pmyExp->c)*dec;
}