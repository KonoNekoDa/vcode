#include <stdio.h>
#include <string.h>
#define MAXTECKEN 41
#define MAXPASIENTER 1000
#define PERSONNUMMER 12

struct patientdata
{
    int nravbild;
    char namn[MAXTECKEN];
    char personnummer[PERSONNUMMER];
    int bildref[10];
};
typedef struct patientdata Patientdata;


void huvudmeny(Patientdata patienter[], int nravpatient);
void regpasientfil(Patientdata *patienter,char namn[],char personnummer[],int bildref[],int nravpatient);
void regpasient(Patientdata patienter[],int *pnravpatient);
void datafromfil(Patientdata patienter[],char txtfil[],int *pnravpatient);
void printpasient(Patientdata patienter[],int nravpatient);
int sokpasient(Patientdata patienter[],int nravpatient, int funktiondeterminant,int koll[]);
void bildadd(Patientdata patienter[],int nravpatient);
void sortpasient(Patientdata patienter[],int nravpatient);
void avregpasient(Patientdata patienter[]);
void printsok(Patientdata patienter[],int koll[],int nravpatienter);
void swap(Patientdata *patient1,Patientdata *patient2);
int sortcontroll(Patientdata patienter[], int nravpatienter);

int main()
{
    Patientdata patienter[MAXPASIENTER];
    char txtfil[MAXTECKEN]="dinmamma.txt";
    int nravpatienter=0;
    

    // temp
    // char fornamn[MAXTECKEN]="Dennis",efternamn[MAXTECKEN]="Bica",personnummer[PERSONNUMMER]="020304-2345";
    // int  bildref[10],nravbild;
    // regpasientfil(&patienter[i],fornamn,efternamn,personnummer,bildref,nravbild);

    printf("Patientjournalsystem\n");

    // printf("Vilken fil vill du anvanda: ");
    // scanf("%s",&txtfil);
    
    datafromfil(patienter,txtfil,&nravpatienter);
    // printpasient(patienter,nravpatienter);

    huvudmeny(patienter,nravpatienter);
    
}

void huvudmeny(Patientdata patienter[],int nravpatienter)
{
    int choice=0;
    int avslut=0;
    while(1)
    {
        int koll[MAXPASIENTER]={0};
        printf("Huvudmeny\n");
        printf("            1) Registrera nya patienter\n");
        printf("            2) Skriva ut alla patienter\n");
        printf("            3) Soka efter patienter\n");
        printf("            4) Lagg till bilder\n");
        printf("            5) Sortera patienter\n");
        printf("            6) Avregistrera patienter\n");
        printf("            7) Avsluta programmet\n");

        printf("Ange alternativ: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1: regpasient(patienter,&nravpatienter);
            break;
        case 2: printpasient(patienter,nravpatienter);
            break;
        case 3: int funktiondeterminant=0;
        sokpasient(patienter,nravpatienter,funktiondeterminant,koll);
            break;
        case 4: 
        bildadd(patienter,nravpatienter);
            break;
        case 5: sortpasient(patienter,nravpatienter);
            break;
        case 6: avregpasient(patienter);
            break;
        case 7: avslut=1;
        printf("Avslutar");
            break;
        default:
            break;
        }

        if(avslut==1)
        {
            break;
        }
    }
}

void datafromfil(Patientdata patienter[],char txtfil[], int *pnravpatienter)
{
    FILE *fp;
    fp=fopen(txtfil,"r");
    if(fp!=NULL)
    {   
        char fornamn[MAXTECKEN],efternamn[MAXTECKEN],personnummer[PERSONNUMMER], namn[MAXTECKEN];;
        int  bildref[10],nravbild;
        fscanf(fp,"%d",pnravpatienter);

        for(int i=0;i<(*pnravpatienter);i++)
        {
            fscanf(fp,"%d",&nravbild);
            fscanf(fp,"%s",fornamn);
            fscanf(fp,"%s",efternamn);
            strcpy(namn,fornamn);
            strcat(namn," ");
            strcat(namn,efternamn);
            fscanf(fp,"%s",personnummer);
            for (int j = 0; j < nravbild; j++)
            {
                fscanf(fp,"%d",&bildref[j]);
            }
            regpasientfil(&patienter[i],namn,personnummer,bildref,nravbild);
        }
    }
    fclose(fp);
}

void regpasientfil(Patientdata *patienter,char namn[],char personnummer[],int bildref[],int nravbild)
{
    strcpy(patienter->namn,namn);
    strcpy(patienter->personnummer,personnummer);
    (patienter->nravbild)=nravbild;
    for (int i = 0; i < nravbild; i++)
    {
        (patienter->bildref[i])=bildref[i];
    }   
}

void regpasient(Patientdata patienter[],int *pnravpatienter)
{
    char fornamn[MAXTECKEN],efternamn[MAXTECKEN],personnummer[PERSONNUMMER],namn[MAXTECKEN];
    int  bildref[10],nravbild=0,check=0,index=0;;

    while(1)
    {
        while(1)
        {
            printf("Ange Personnummer (q for att avsluta): ");
            scanf("%s",personnummer);
            int koll=0;

            if(!strcmp(personnummer,"q"))
            {
                break;
            }

            for (int i = 0; i <*pnravpatienter; i++)
            {
                if(!strcmp(personnummer,patienter[i].personnummer))
                {
                    printf("redan registrerat.\n");
                    koll=1;
                    break;
                }
            }

            if(koll==0)
            {
                strcpy(patienter[*pnravpatienter].personnummer,personnummer);
                break;
            }
        }

        if(!strcmp(personnummer,"q"))
            {
                printf("Avslutar registrering\n");
                break;
            }

        printf("Ange Namn: ");
        scanf("%s %s",fornamn,efternamn);

        strcpy(namn,fornamn);
        strcat(namn," ");
        strcat(namn,efternamn);

        strcpy(patienter[*pnravpatienter].namn,namn);

        while(1)
        {
            check=0;
            printf("Ange bildreferens (eller 0 for att avsluta): ");
            scanf("%d",&bildref[nravbild]);

            if(bildref[nravbild]==0)
            {
                printf("Avslutar registrering\n");
                (*pnravpatienter)++;
                break;
            }

            for (int i = 0; i < *pnravpatienter; i++)
            {
                for (int j = 0; j < patienter[i].nravbild; j++)
                {
                    if(bildref[nravbild]==patienter[i].bildref[j])
                    {
                        printf("referensen finns redan!\n");
                        check=1;
                        break;
                    }
                }
            }
            if(check==0)
            {
                (patienter[*pnravpatienter].bildref[nravbild])=bildref[nravbild];
                (patienter[*pnravpatienter].nravbild)++;
                nravbild++;
            }
            

        }
    }
}

void printpasient(Patientdata patienter[],int nravpatienter)
{   
    printf("%-20s %-20s %-20s\n","Personnummer","Namn","Bildreferenser");
    printf("_________________________________________________________\n");
    for (int i = 0; i < nravpatienter; i++)
    {   
        printf("%-20s %-20s [",patienter[i].personnummer,patienter[i].namn);
        for (int j = 0; j < patienter[i].nravbild; j++)
        {
            printf("%d",patienter[i].bildref[j]);
            if(j<patienter[i].nravbild-1)
            {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

int sokpasient(Patientdata patienter[],int nravpatienter,int funktiondeterminant,int koll[])
{
    int choice=0,check=0,finns=0;
    char soknamn[MAXTECKEN],soknamn2[MAXTECKEN],personnummer[PERSONNUMMER];

    if(nravpatienter==0)
    {
        printf("databas tom");
        return 0;
    }

    while(1)
    {
        printf("Sok pa personnummer(1), namn(2), bildreferens(3), avsluta(4):");
        scanf("%d",&choice);
        int koll[MAXPASIENTER] = {0};

        switch(choice)
        {
            case 1: printf("Ange personnummer: ");
            scanf("%s",personnummer);
            finns = 0;
            for (int i = 0; i < nravpatienter; i++)
            {
                if(strcmp(patienter[i].personnummer,personnummer)==0)
                {
                    koll[finns++]=i;
                }
            }
            if(finns>0)
            {
                printsok(patienter,koll,finns);
                break;
            }
            else 
            {
                printf("liknande namn saknas i databasen\n");
            }
            break;

            case 2: printf("ange sokning: ");
            finns = 0;
            scanf("%s",soknamn);
            for (int i = 0; i < nravpatienter; i++)
            {
                if(strstr(patienter[i].namn,soknamn)!=NULL)
                {
                    koll[finns++]=i;
                }
            }

            if(finns>0)
            {
                printsok(patienter,koll,finns);
                break;
            }
            else 
            {
                printf("liknande namn saknas i databasen\n");
            }
            break;

            case 3: printf("Ange Bildreference: ");
            int bild;
            finns=0;
            scanf("%d",&bild);
            for (int i = 0; i < nravpatienter; i++)
            {
                for (int j = 0; j < nravpatienter; j++)
                {
                    if(patienter[i].bildref[j]==bild)
                    {
                        koll[finns++]=i;
                    }
                }
                
            }
            if(finns>0)
            {
                printsok(patienter,koll,finns);
                break;
            }
            else 
            {
                printf("liknande namn saknas i databasen\n");
            }
            break;

            case 4:
                printf("avslutar sokning\n");
                check=1;
                break;
        }

        if(funktiondeterminant==-1 && finns==1)
        {
            int returning =koll[finns];
            return returning;
        }
        if(funktiondeterminant==-1)
        {
            printf("du fick inte exakt en traff\n");
        }
        if(check==1)
        {
            break;
        }
    }
}

void printsok(Patientdata patienter[],int koll[],int nravpatienter)
{    
    printf("%-20s %-20s %-20s\n","Personnummer","Namn","Bildreferenser");
    printf("_________________________________________________________\n");
    for (int i = 0; i < nravpatienter; i++)
    {   
        int f = koll[i];
        printf("%-20s %-20s [",patienter[f].personnummer,patienter[f].namn);
        for (int j = 0; j < patienter[f].nravbild; j++)
        {
            printf("%d",patienter[f].bildref[j]);
            if(j<patienter[f].nravbild-1)
            {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

void bildadd(Patientdata patienter[],int nravpatienter)
{
    int  bildref[10],nravbild=0,check=0,funktiondeterminant=-1, koll[MAXPASIENTER]={0};

    if(nravpatienter==0)
    {
        printf("databas tom");
        return;
    }
    
    int index=sokpasient(patienter,nravpatienter,funktiondeterminant,koll);

    printf("%d",index);

    while(1)
        {
            check=0;
            printf("Ange bildreferens (eller 0 for att avsluta): ");
            scanf("%d",&bildref[nravbild]);

            if(bildref[nravbild]==0 || nravbild==10)
            {
                printf("Avslutar lagga till bilder\n");
                break;
            }

            for (int j = 0; j < patienter[index].nravbild; j++)
            {
                if(bildref[nravbild]==patienter[index].bildref[j])
                {
                    printf("referensen finns redan!\n");
                    check=1;
                    break;
                }
            }
            
            if(check==0)
            {
                (patienter[nravpatienter].bildref[nravbild])=bildref[nravbild];
                (patienter[nravpatienter].nravbild)++;
                nravbild++;
            }
        }
}

void sortpasient(Patientdata patienter[],int nravpatienter)
{
    int choice=0;
    if(nravpatienter==0)
    {
        printf("databas tom");
        return;
    }

    printf("Sortera pa personnummer (1), Namn(2): ");
    scanf("%d",&choice);

    if(choice==1)
    {
        while(1)
        {
            for (int i = 0; i < nravpatienter; i++)
            {
                for (int j = 0; j < PERSONNUMMER; j++)
                {
                    if(patienter[i].personnummer[j]<(patienter[i+1].personnummer[j]))
                    {
                        swap(&patienter[i],&patienter[i+1]);
                        break;
                    }
                }
            }
            if(sortcontroll(patienter,nravpatienter)==1)
            {
                break;
            }
        }
    }
    else
    {
        while(1)
        {
            for (int i = 0; i < nravpatienter; i++)
            {
                for (int j = 0; j < PERSONNUMMER; j++)
                {
                    if(patienter[i].namn[j]<(patienter[i+1].namn[j]))
                    {
                        swap(&patienter[i],&patienter[i+1]);
                        break;
                    }
                }
            }
            if(sortcontroll(patienter,nravpatienter)==1)
            {
                break;
            }
        }   
    }
}

void avregpasient(Patientdata patienter[])
{
    printf("sortpasient");
}

void swap(Patientdata *patient1,Patientdata *patient2)
{   
    Patientdata temp = *patient1;
    *patient1=*patient2;
    *patient1=temp;
}

int sortcontroll(Patientdata patienter[], int nravpatienter)
{
    int check=0;
    for (int i = 0; i < nravpatienter; i++)
    {
        for (int j = 0; j < PERSONNUMMER; j++)
        {
            if(patienter[i].personnummer[j]>(patienter[i+1].personnummer[j]))
            {
                check++;
            }
        }
    }

    if(check==PERSONNUMMER)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}