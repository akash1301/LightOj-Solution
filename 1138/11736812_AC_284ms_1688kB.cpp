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

int zero(int n)
{
    int cnt=0;
    int x=5;
    while(x<=n)
    {
        cnt+=n/x;
        x*=5;
    }
    return cnt;
}

int main()
{
    int t,cas=0;
    getint(t);
    while(t--)
    {
        int n;
        cin>>n;
        int mx=410000000;
        int mn=0;
        int mid=(mx+mn)/2;
        CASE(cas);
        int ans=0;
        while(mn<=mx)
        {
            int x=zero(mid);
            if(n>x)
                mn=mid+1;
            else if(n<x)
                mx=mid-1;
            else
            {
                ans=mid;
                mx=mid-1;
            }
            mid=(mn+mx)/2;
        }
        if(ans==0)
            pf("impossible\n");
        else
            pf("%d\n",ans);
    }
    return 0;
}
