#include <stdio.h>
#include <string.h>
#define MAXTECKEN 41
#define MAXPASIENTER 1000
#define MAXBILDREF 10

struct patientdata
{
    int nravpatienter;
    char fornamn[MAXTECKEN];
    char efternamn[MAXTECKEN];
    int personnummer[10];
    int bildref[MAXBILDREF];
};
typedef struct patientdata Patientdata;


void huvudmeny(Patientdata *ppatienter[]);
void regpasient(Patientdata *ppatienter[]);
void datafromfil(Patientdata *ppatienter[],char txtfil);

int main()
{
    Patientdata patienter[MAXPASIENTER];
    FILE *fp;
    char txtfil[MAXTECKEN];
    
    printf("Patientjournalsystem\n");
    printf("Vilken fil vill du anvanda: ");
    printf("%s",&txtfil);
    
    datafromfil(&patienter,txtfil);
    huvudmeny(&patienter);
    
}

void huvudmeny(Patientdata *ppatienter[])
{
    int choice=0;
    while(1)
    {
        printf("Huvudmeny\n");
        printf("            1) Registrera nya patienter\n");
        printf("            2) Skriva ut alla patienter\n");
        printf("            3) Soka efter patienter\n");
        printf("            4) Lagg till bilder\n");
        printf("            5) Sortera patienter\n");
        printf("            6) Avregistrera patienter\n");
        printf("            7) Avsluta programmet\n");

        printf("Ange alternativ: ");
        scanf("%d",choice);

        switch(choice)
        {
        case 1: regpasient();
            break;
        case 2: printpasient();
            break;
        case 3: sokpasient();
            break;
        case 4: bildadd();
            break;
        case 5: sortpasient();
            break;
        case 6: avregpasient();
            break;
        case 7:
            break;
        default:
            break;
        }
    }
}

void datafromfil(Patientdata *ppatienter[],int txtfil)
{
    FILE *fp;
    fp=fopen(txtfil,"r");
    if(fp!=NULL)
    {
        char fornamn[MAXTECKEN],efternamn[MAXTECKEN];
        int nravpatienter, personnummer[10], bildref[MAXBILDREF];
        fscanf(fp,"%d",nravpatienter);
        for(int i=0;i<(nravpatienter);i++)
        {
            fscanf(fp,"%s",&fornamn);
            fscanf(fp,"%s",&efternamn);
            fscanf(fp,"%s",&personnummer);
            
        }
        *ppatienter[i]=regpasient(fornamn,efternamn,personnummer,bildref);
        fclose(fp);
    }
    else
    {
        int nravpatienter=0;
    }
}

void regpasient(Patientdata *ppatienter[])
{

}