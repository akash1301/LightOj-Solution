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
 
int main()
{
    //read();
    ll t,cas=0;
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        ll a,strt;
        cin>>s;
        cin>>a;
        if(s[0]=='-')
            strt=1;
        else
            strt=0;
        a=fabs(a);
        ll x=0;
        for(int i=strt;i<s.size();i++)
        {
            x=10*x+(s[i]-'0');
            if(x>=a)
            {
                x=x%a;
            }
        }
        if(x==0)
        {
            CASE(cas);
            cout<<"divisible"<<endl;
        }
        else
        {
            CASE(cas);
            cout<<"not divisible"<<endl;
        }
    }
    return 0;
}