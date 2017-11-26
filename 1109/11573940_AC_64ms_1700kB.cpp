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


struct xxx
{
    int ind,div;
};

bool compare(xxx a,xxx b)
{
        if(a.div==b.div)
            return a.ind>b.ind;
        return a.div<b.div;
}

int divisor(int n)
{
    int sq=sqrt(n);
    int ans=0;
    for(int i=1;i*i<=n;i++)
    {
        if(i*i==n)
            ans++;
        else if(n%i==0)
            ans+=2;
    }
    return ans;
}


int main()
{
    xxx data[1005];
    for(int i=1;i<=1000;i++)
    {
        data[i].ind=i;
        data[i].div=divisor(i);
    }
    sort(data+2,data+1001,compare);
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        int g;
        cin>>g;
        CASE(cas);
        pf("%d\n",data[g].ind);
    }
    return 0;
}
