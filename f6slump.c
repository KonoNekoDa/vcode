#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
srand(time(NULL)); //Anropas EN gång för att sätta frö
int die1 = rand()%6+1; //blir slumptal 1-6
int die2 = rand()%6+1;
printf("du fick %d och %d",die1, die2);
return 0;
}

// staestik slumpmässiga tal!!
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// int main(void)
// {
// int freq[13]={0},diceResult,k;
// srand(time(0));
// for(k=1;k<=10000;k++)
// {
// diceResult=rand()%6+rand()%6+2;
// freq[diceResult]++;
// }
// for(k=2;k<=12;k++)
// printf("Antal %2d: %d. Andel: %.2f%%\n",k,freq[k],100*freq[k]/10000.);
// return 0;
// }