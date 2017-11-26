#include <stdio.h>
int main()
{
    int t[125][2],i,a;
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%d %d",&t[i][0],&t[i][1]);
        if(t[i][0]<=10 & t[i][1]<=10)
        {
            printf("Case %d: %d\n",i+1,t[i][0]+t[i][1]);
        }
    }
    return 0;
}
