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

bool prime[1000007];

vector<int>store;

int seive()
{
    mem(prime,true);
    int sq=sqrt(1000005);
    for(int i=3;i<=sq;i+=2)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=1000005;j+=i)
                prime[j]=false;
        }
    }
    store.pb(2);
    for(int i=3;i<=1000005;i+=2)
        if(prime[i])
        store.pb(i);

}

int main()
{
    seive();
    int t,cas=0;
    getint(t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        int sq=sqrt(n);
        int sz=store.size();
        int ans=1;
        for(int i=0;i<sz&&store[i]*store[i]<=n;i++)
        {
            int cnt=1;
            while(n%store[i]==0)
            {
                //cout<<store[i]<<endl;
                cnt++;
                n/=store[i];
            }
            ans*=cnt;
        }
        if(n>1)
            ans*=2;
        CASE(cas);
        pf("%d\n",ans-1);
    }
    return 0;
}
