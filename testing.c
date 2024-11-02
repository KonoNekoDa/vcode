#include <stdio.h>
#include <string.h>
#define MAXTECKEN 41
#define MAXPASIENTER 1000
#define PERSONNUMMER 12

struct patientdata
{
    int nravpatienter;
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
void sokpasient(Patientdata patienter[],int nravpatient);
void bildadd(Patientdata patienter[],int nravpatient);
void sortpasient(Patientdata patienter[],int nravpatient);
void avregpasient(Patientdata patienter[]);
void printsok(Patientdata patienter[],int koll[],int nravpatienter);

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
        case 3: sokpasient(patienter,nravpatienter);
            break;
        case 4: bildadd(patienter,nravpatienter);
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



void sokpasient(Patientdata patienter[], int nravpatienter) {
    if (nravpatienter == 0) {
        printf("Databasen är tom.\n");
        return; // Gå tillbaka till huvudmenyn om databasen är tom
    }

    int choice = 0, check = 0;
    char sokstrang[MAXTECKEN];

    while (1) {
        printf("Sök på personnummer (1), namn (2), bildreferens (3), avsluta (4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: { // Sök på personnummer
                char personnummer[PERSONNUMMER];
                printf("Ange personnummer: ");
                scanf("%s", personnummer);
                
                // Hitta patienten
                int found = 0;
                for (int i = 0; i < nravpatienter; i++) 
                {
                    if (strcmp(personnummer, patienter[i].personnummer) == 0) 
                    {
                        printf("%-20s %-20s %-20s\n", "Personnummer", "Namn", "Bildreferenser");
                        printf("____________________________________________________________\n");
                        printf("%-20s %-20s ", patienter[i].personnummer, patienter[i].namn);
                        printf("[");
                        for (int j = 0; j < patienter[i].nravbild; j++) {
                            printf("%d", patienter[i].bildref[j]);
                            if (j < patienter[i].nravbild - 1) {
                                printf(", ");
                            }
                        }
                        printf("]\n");
                        found = 1;
                        break; // Avbryt loopen om patienten hittades
                    }
                }
                if (!found) {
                    printf("Personnumret saknas i databasen.\n");
                }
                break;
            }

            case 2: { // Sök på namn
                printf("Ange söksträng: ");
                scanf("%s", sokstrang);

                // Hitta patienter
                int foundCount = 0;
                int koll[MAXPASIENTER] = {0}; // För att hålla reda på hittade patienter
                for (int i = 0; i < nravpatienter; i++) {
                    if (strstr(patienter[i].namn, sokstrang) != NULL) {
                        koll[foundCount++] = i; // Spara index
                    }
                }
                if (foundCount > 0) {
                    printsok(patienter, koll, foundCount);
                } else {
                    printf("Inga patienter med denna söksträng hittades.\n");
                }
                break;
            }

            case 3: { // Sök på bildreferens
                int bildref;
                printf("Ange bildreferens: ");
                scanf("%d", &bildref);

                int found = 0;
                for (int i = 0; i < nravpatienter; i++) {
                    for (int j = 0; j < patienter[i].nravbild; j++) {
                        if (patienter[i].bildref[j] == bildref) {
                            printf("%-20s %-20s ", patienter[i].personnummer, patienter[i].namn);
                            printf("[");
                            for (int k = 0; k < patienter[i].nravbild; k++) {
                                printf("%d", patienter[i].bildref[k]);
                                if (k < patienter[i].nravbild - 1) {
                                    printf(", ");
                                }
                            }
                            printf("]\n");
                            found = 1;
                            break; // Avbryt loopen om patienten hittades
                        }
                    }
                    if (found) break; // Avbryt ytterligare loopen om patienten hittades
                }
                if (!found) {
                    printf("Ingen patient med denna bildreferens hittades.\n");
                }
                break;
            }

            case 4: // Avsluta
                printf("Avslutar sökning.\n");
                check = 1;
                break;

            default:
                printf("Ogiltigt val, försök igen.\n");
                break;
        }

        if (check) {
            break; // Gå tillbaka till huvudmenyn
        }
    }
}

void printsok(Patientdata patienter[], int koll[], int antal) {
    printf("%-20s %-20s %-20s\n", "Personnummer", "Namn", "Bildreferenser");
    printf("____________________________________________________________\n");
    
    for (int i = 0; i < antal; i++) {
        int index = koll[i];
        printf("%-20s %-20s [", patienter[index].personnummer, patienter[index].namn);
        for (int j = 0; j < patienter[index].nravbild; j++) {
            printf("%d", patienter[index].bildref[j]);
            if (j < patienter[index].nravbild - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

void bildadd(Patientdata patienter[],int nravpatienter)
{
    if(nravpatienter==0)
    {
        printf("databas tom");
        return;
    }
    
}

void sortpasient(Patientdata patienter[],int nravpatienter)
{
    printf("sortpasient");
}

void avregpasient(Patientdata patienter[])
{
    printf("sortpasient");
}