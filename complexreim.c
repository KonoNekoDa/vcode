#include <stdio.h>

struct complex
{
    float re,im;
};
typedef struct complex Complex;

Complex skapacomplex(float re, float im);
void printComplex(Complex c);
void multicomplex(Complex *pComplex, float k);


int main()
{
    Complex c1, c2;
    c1=skapacomplex(3,2);
    c2=skapacomplex(2,-3);
    multicomplex(&c1,-2.5);
    multicomplex(&c2,-1);
    printComplex(c1);
    printComplex(c2);
}

Complex skapacomplex(float re, float im)
{
    Complex c;
    c.re = re;
    c.im = im;
    return c;
}

void printComplex(Complex c)
{
    if(c.im>=0)
    {
        printf("%.4f + %.4fi\n",c.re,c.im);
    }
    else 
    {
        printf("%.4f - %.4fi\n",c.re,c.im);
    }
}

void multicomplex(Complex *pComplex, float inmatvar)
{
    (pComplex->re) *= inmatvar;
    (pComplex->im) *= inmatvar;
}