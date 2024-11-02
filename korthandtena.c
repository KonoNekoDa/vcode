#include <stdio.h>
#define MAXCARDS 52
#define CARDVALUE 13

struct kort
{
    char type;
    int kort;
};
typedef struct kort Kort;

struct korthand
{
    Kort kort[MAXCARDS];
    int nrOfcards;
};
typedef struct korthand Korthand;

void printHand(Korthand hand);

int main()
{
    Korthand myHand={{{'s',3},{'h',12},{'r',3},{'r',8}},4};
    Korthand yourHand={{{'k',3},{'k',4},{'k',5},{'k',6},{'k',7}},5};
    
    printHand(myHand);
    printHand(yourHand);
}

void printHand(Korthand hand)
{
    
    for (int  i = 0; i < hand.nrOfcards; i++)
    {
        printf("%c %d, ",hand.kort[i].type,hand.kort[i].kort);
    }
    printf("\n");
}