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

ll divisor(ll x,ll y)
{
    ll cnt=0;
    while(x%y==0)
    {
        cnt++;
        x/=y;
    }
    return cnt;
}

ll cont(ll x,ll y)
{
    ll cnt=0;
    ll ret=y;
    while(ret<=x)
    {
        cnt+=x/ret;
        ret*=y;
    }
    return cnt;
}


int main()
{
    int t,cas=0;
    getint(t);
    while(t--)
    {
        ll n,r,p,q;
        sf("%lld %lld %lld %lld",&n,&r,&p,&q);
        CASE(cas);
        pf("%lld\n",min(cont(n,2)-cont(r,2)-cont(n-r,2)+divisor(p,2)*q,cont(n,5)-cont(r,5)-cont(n-r,5)+divisor(p,5)*q));
    }
    return 0;
}
