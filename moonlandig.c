#include <stdio.h>

int main()
{
    float f = 0, height=250, velocity=-25, time=0;
    printf("Lunar decent challenge!\n");
    printf("You will pilot a lunar decent the last 250m.\n");
    printf("Each turn represent 1-second decent time.\n");
    printf("Set the throttle for each turn (0-100)\n");
    printf("Time Height Velocity Throttle?\n");
    
    
    while(height>=0)
    {
        printf("%.1f     %.1f     %.1f     ",time,height,velocity);
        scanf("%f",&f);
        if (f<0 || f>100)
        {
            printf("throttle setting out off range!!\n");
            break;
        }
        
        height=height+velocity+(0.1*f-1.5)/2;
        velocity=velocity+(0.1*f-1.5);

        time++;   
    }

    if(height > 0)
    {
        printf("system malfunction, restart system!\n");
        return 0;
    }

    if (velocity >= -2)
    {
        printf("\nYou hav landed succesfully!!!");
    }
    else
    {
        printf("\nFailed!! crashed at %.1fm/s",velocity);
    }
    return 0;
}