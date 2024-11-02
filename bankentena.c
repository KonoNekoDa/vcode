#include <stdio.h>
#include <string.h>

#define MAXLENGHT 41
#define MAXCUSTOMER 10

void printcustomer(char customer[][MAXLENGHT], int nrCustomer);
int adminlogin(int *pacces);
void adminmenu(char customer[][MAXLENGHT],int *pnrCustomer,int bankacc[]);
void registercustomer(char customer[][MAXLENGHT],int *pnrCustomer);
void deposit(char customer[][MAXLENGHT],int nrCustomer, int bankacc[]);



int main()
{
    char customer[MAXCUSTOMER][MAXLENGHT];
    int nrCustomer=0,choice, access=0, customerchoice;
    int bankacc[10]={0};

    for (int i = 0; i < MAXCUSTOMER; i++)
    {
        bankacc[i]=0;
    }
    


    printf("Banken\n");
    while(1)
    {
        printf("1. Admin, 2. Kundsaldo, 3. Avsluta: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1 : 
            adminlogin(&access);
            if(access==1)
            {
                adminmenu(customer,&nrCustomer,bankacc);
            }
            break;
        
        case 2 :
            printcustomer(customer,nrCustomer);
            printf("ange kundnummer: ");
            scanf("%d",&customerchoice);
            printf("%s, %d kr\n",customer[customerchoice-1],bankacc[customerchoice]);
            break;

        case 3 :
            printf("avslutar program");
            break;

        default:
            printf("Felaktigt val\n"); 
            break;
        }

        if(choice==3)
        {
            break;
        }
    }
}

void printcustomer(char customer[][MAXLENGHT], int nrCustomer)
{
    if(nrCustomer==0)
    {
        printf("saknas kunder\n");
        return;
    }

    for (int i = 0; i < nrCustomer; i++)
    {
        printf("%d. %s\n",i+1, customer[i]);
    }

    
}

int adminlogin(int *paccess)
{
    if(*paccess==1)
    {
        printf("alredy loged in");
    }
    char password[5];
    char truelock[]={"abcd"};

    printf("Enter Password: ");
    scanf("%s",password);

    int check=strcmp(password,truelock);
    if(check==0)
    {
        *paccess=1;
    }
    else
    {
        printf("wrong password\n");
        return 0;
    }
    
}

void adminmenu(char customer[][MAXLENGHT],int *pnrCustomer, int bankacc[])
{
    
    int choice2;
    do{

        printf("1. Registrera kund, 2. Insattning, 3. Startmenyn: ");
        scanf("%d",&choice2);

        switch (choice2)
        {
        case 1:
            registercustomer(customer,&*pnrCustomer);
            break;

        case 2:
            deposit(customer,*pnrCustomer,bankacc);
            break;

        case 3:
            break;
        
        default:

            break;
        }

    }while(choice2!=3);
}

void registercustomer(char customer[][MAXLENGHT],int *pnrCustomer)
{
    int n=*pnrCustomer;
    char input[MAXLENGHT];

    while(1)
    {
        printf("Ange kund (q avslutar) : ");

        scanf(" %[^\n]s",input);
        char re[]={"q"};
        int check=strcmp(input,re);
        if(check==0)
        {
            break;
        }
        else 
        {
            strncpy(customer[n],input,MAXLENGHT-1);
            (customer[n][MAXLENGHT])=input[MAXLENGHT];
            n++;
        }
    }
    *pnrCustomer=n;
}

void deposit(char customer[][MAXLENGHT],int nrCustomer, int bankacc[])
{
    printcustomer(customer,nrCustomer);

    int customerchoice=0,value;

    do{
        printf("Vem vill gora en insattning: ");
        scanf("%d",&customerchoice);
    }while(customerchoice<!nrCustomer&&customerchoice>!0);

    printf("Insettning: ");
    scanf("%d", &value);

    bankacc[customerchoice]=+value;

    printf("Nytt saldo: %d\n",bankacc[customerchoice]);
}