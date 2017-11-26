/****************************************
*  MD. Al Mamun Akash                   *
*  uVa id: Pointer***                   *
*  Codeforces: Akash.KUET               *
*  LOJ: 19025               *
*  Codechef: akash_                     *
*  Khulna,Bangladesh.                   *
*****************************************/
 
 
 
#include <bits/stdc++.h>
 
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long int
#define dd double
#define SZ(a) int(a.size())
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define pi acos(-1.0)
#define pf printf
#define sf scanf
#define mp make_pair
#define paii pair<int, int>
#define padd pair<dd, dd>
#define pall pair<ll, ll>
#define fr first
#define sc second
#define getlong scanf("%lld",&n)
#define CASE(n) printf("Case %d: ",++n)
#define inf 1000000000
 
using namespace std;
 
/*int pd(int s)
{
    int d=1;
    for(int j=1;j<=s;j++)
        d*=2;
    return d;
}*/
 
int main()
{
    //read();
    int t,cas=0;
    cin>>t;
    getchar();
    while(t--)
    {
        //getchar();
        string s1,s2;
        s1.clear();
        s2.clear();
        getline(cin,s1);
        getline(cin,s2);
        int p=0,a[10];
        //mem(a,0);
        a[0]=0;
        //cout<<s1<<endl;
        //cout<<s2<<endl;
        s2=s2+'.';
        s1=s1+'.';
        //cout<<s2<<endl;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]=='.')
            {
                p++;
                a[p]=0;
                continue;
            }
            a[p]=10*a[p]+(s1[i]-'0');
        }
        //for(int i=0;i<p;i++)
          //  cout<<a[i]<<endl;
        p=0;
        int k=0,x=0,power=7;
        for(int i=0;i<s2.size();i++)
        {
            if(s2[i]=='.')
            {
                if(x!=a[p])
                {
                    k=1;
                    break;
                }
                x=0;
                power=7;
                p++;
            }
            else{
            x+=(s2[i]-'0')*pow(2.00,power);
            power--;
            }
        }
        if(k==1)
        {
            CASE(cas);
            cout<<"No"<<endl;
        }
        else
        {
            CASE(cas);
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}