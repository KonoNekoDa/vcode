#include <stdio.h>
#include <limits.h>
int main(void)
{
int max,min,k,number;
min=INT_MAX;
max=INT_MIN;
for(k=1;k<=5;k++)
{
printf("Tal nr %d: ",k);
scanf("%d",&number);
if (number<min)
{
min=number;
}
if (number>max)
{
max=number;
}
}
printf("%d %d\n",max,min);
return 0;
}

max tal exempel
#include <stdio.h>
int max(int v[],int n)
{
int i,max=v[0];
for(i=1;i<n;i++)
{
if(max<v[i])
{
max = v[i];
}
}
return max;
}
int main(void)
{
int a[] = {1,3,6,2,8,1};
printf("Storsta vardet ar %d",max(a,6));
return 0;
}



compute