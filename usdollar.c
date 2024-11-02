#include <stdio.h>

int main(void)
{
    int amount, tjugo=20, tio=10, fem=5, ett=1, pay, odd, rest;
    printf("how much moola you got g:");
    scanf("%d",&amount);

    if (amount<0)
    {
        printf("du kan inte ha negativt med moola");
        return 0;
    }

    // 20$
    printf("this how you pay back!:\n");
    pay=amount/tjugo;
    printf("20$:%d\n",pay);
    odd=(pay*tjugo);
    rest=amount-odd;
    if(rest==0)
    {
        return 0;
    }

    // 10$
    pay=rest/tio;
    printf("10$:%d\n",pay);
    odd=(pay*tio);
    rest=rest-odd;

    if(rest==0)
    {
        return 0;
    }
  
    // 5$
    pay=rest/fem;
    printf("5$:%d\n",pay);
    odd=(pay*fem);
    rest=rest-odd;

    if(rest==0)
    {
        return 0;
    }

    // 1$
    pay=rest/ett;
    printf("1$:%d\n",pay);
    odd=(pay*ett);
    rest=rest-odd;

    if(rest==0)
    {
        return 0;
    }

    return 0;
  

}