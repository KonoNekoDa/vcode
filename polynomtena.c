#include <stdio.h>

struct pol{
    float a, b ,c;
};
typedef struct pol Pol;

Pol createPol(float a,float b,float c);
int value(Pol p, float *pval);
void printPol(Pol p);
void differenciate(Pol *ppol, Pol p);

int main()
{
    Pol p1;
    float val;
    p1 = createPol(2,-1,-3);
    printPol(p1);
    value(p1,&val);
    printf("\n%.3f\n",val);
    differenciate(&p1,p1);
    printPol(p1);
}

Pol createPol(float a,float b,float c)
{
    Pol p;
    p.a=a;
    p.b=b;
    p.c=c;
    return p;
}

int value(Pol p,float *pval)
{
    float valor=0.5;
    float val = (p.a)*(valor*valor) + (p.b)*valor + (p.c);
    *pval=val;
    return *pval;
}

void printPol(Pol p)
{
    printf("(%.3f)x^2 + (%.3f)x + (%.3f)",p.a,p.b,p.c);
}

void differenciate(Pol *ppol, Pol p)
{
    (ppol->a) = 0;
    (ppol->b) = (p.a + p.a);
    (ppol->c) = p.b;
}