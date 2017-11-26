#include <stdio.h>
int main()
{
    int t[25][1],a,i,b,c;
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%d",&t[i][0]);
        if(t[i][0]>=0 && t[i][0]<=20)
        {
            b=t[i][0]/2;
            c=t[i][0]-b;
            if(b<=10 && c<=10)
            {
                printf("%d %d\n",b,c);
            }
        }
    }
    return 0;
}