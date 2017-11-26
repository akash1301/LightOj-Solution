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
#define inf  100000007
#define EPS 1e-9

using namespace std;

int fx[]={0,0,1,-1,1,1,-1,-1};
int fy[]={1,-1,0,0,1,-1,1,-1};


int main()
{
    int t,cas=0;
    cin>>t;
    ll n,tk;
    while(t--)
    {
        cin>>n>>tk;
        ll dp[tk+10],coin[n+10];
        loop(i,n)
        cin>>coin[i];
        mem(dp,0);
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=coin[i];j<=tk;j++)
            {
                dp[j]+=dp[j-coin[i]]%inf;
            }
        }
        CASE(cas);
        cout<<dp[tk]%inf<<endl;
    }
    return 0;
}
