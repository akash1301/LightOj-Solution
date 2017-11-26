/****************************************
*  MD. Al Mamun Akash                   *
*  uVa id: Pointer***                   *
*  Codeforces: Akash.KUET               *
*  LOJ: 19025				*
*  Spoj:akash_kuet                      *
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
#define EPS 1e-9

using namespace std;

int fx[]={0,0,1,-1,1,1,-1,-1};
int fy[]={1,-1,0,0,1,-1,1,-1};
ll dp[10005];
ll a,b,c,d,e,f;

ll fun(ll n)
{
    if(n==0)
        return a;
    if(n==1)
        return b;
    if(n==2)
        return c;
    if(n==3)
        return d;
    if(n==4)
        return e;
    if(n==5)
        return f;
    if(dp[n]!=-1)
        return dp[n];
    dp[n]=(fun(n-1)+fun(n-2)+fun(n-3)+fun(n-4)+fun(n-5)+fun(n-6))%10000007;
    return dp[n];
}

int main()
{
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        ll n;
        mem(dp,-1);
        cin>>a>>b>>c>>d>>e>>f>>n;
        CASE(cas);
        cout<<fun(n)%10000007<<endl;
    }
    return 0;
}
