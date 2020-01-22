#include <stdio.h> 
 
 int main() { 
 int i,j,t;
  unsigned long long int sum, n[300];
   scanf("%d",&t);
   for(i=0;i<t;i++)
   {
     scanf("%llu",&n[i]);
   }
   for(i=0;i<t;i++)
   {
     sum=1;
     for(j=2;j<=(int)sqrt(n[i]);j++)
     {
       if(n[i]%j==0)
       {
         if(j*j!=n[i])
         {
           sum=sum+j+(n[i]/j);
         }
         else
           sum=sum+j;
       }
     }
     if(sum==n[i])
     {
       printf("YES\n");
     }
     else
     {
       printf("NO\n");
     }
   }
   return 0;
 }
   
