#include <stdio.h>

int main()
{
    int bredd,hojd;

    printf("Ange bredd: ");
    scanf("%d",&bredd);
    printf("Ange hojd: ");
    scanf("%d",&hojd);
    for( int k = 1; k <= hojd; k++ ) 
    {
        if(k == hojd || k==1)
        {
            for(int i = 1; i <= bredd; i++ )
            {
                printf("*");
            }
        }
        else
        {
            for(int i = 1; i <= bredd; i++ ) 
            {
                if(i < bredd && i > 1)
                {
                    printf(" ");
                }
                else{
                    printf("*") ;
                }
            }
        }
      printf("\n");
    }
    return 0;
}