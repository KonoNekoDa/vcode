#include <stdio.h>
#define LENGTH 5
int main(void)
{
int a[LENGTH];
int i;
for(i=0;i<LENGTH;i++)
{
scanf("%d",&a[i]);
}
int sum=0;
for(i=0;i<LENGTH;i++)
{
sum = sum+a[i];
}
printf("Summan blir: %d \n",sum);
return 0;
}
