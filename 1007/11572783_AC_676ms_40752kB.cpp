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
#define getlong(n) scanf("%lld",&n)
#define CASE(n) printf("Case %d: ",++n)
#define inf 1000000000
#define EPS 1e-9

using namespace std;

int fx[]={0,0,1,-1,1,1,-1,-1};
int fy[]={1,-1,0,0,1,-1,1,-1};


unsigned long long phi[5000010];

int main()
{
    ll t,cas=0;
    ll big=5000002;
    sf("%lld",&t);
    for(ll i=2;i<big;i++)
    {
        if(phi[i]==0)
        {
            phi[i]=i;
            for(ll j=i;j<big;j+=i)
            {
                if(phi[j]==0)
                    phi[j]=j;
                phi[j]-=phi[j]/i;
            }
        }
    }
    for(int i=2;i<big;i++)
    {
        phi[i]=phi[i]*phi[i]+phi[i-1];
    }

    while(t--)
    {
        ll a,b;
        getlong(a);
        getlong(b);
        ll ans=0;
        CASE(cas);
        pf("%llu\n",phi[b]-phi[a-1]);
    }
    return 0;
}
