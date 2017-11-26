#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
 
int main()
{
    long long int t,a,b,p=0,sum;
    cin>>t;
    while(t--)
    {
       
        sum=0;
        cin>>a;
        for(b=1;b<=a;b++)
        {
            long long int c;
            cin>>c;
            if(c>0)
            sum+=c;
        }
        printf("Case %lld: %lld\n",++p,sum);
    }
    return 0;
}