

/////////////////////// All Is Well /////////////////////////

#include <bits/stdc++.h>

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long int
#define ull unsigned long long int
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

//8 way moves
//int fx[]={0,0,1,-1,1,1,-1,-1};
//int fy[]={1,-1,0,0,1,-1,1,-1};

//knight moves
//int fx[]={-2,-2,-1,-1,1,1,2,2};
//int fy[]={-1,1,-2,2,-2,2,-1,1};

//Bit operation
int SET(int n,int pos){ return n=n | (1<<pos);}
int RESET(int n,int pos){ return n=n & ~(1<<pos);}
int CHECK(int n,int pos){ return (bool) (n & (1<<pos));}


int bigMod(int n,int power,int MOD)
{
    if(power==0)
        return 1;
    if(power%2==0)
    {
        int ret=bigMod(n,power/2,MOD);
        return ((ret%MOD)*(ret%MOD))%MOD;
    }
    else return ((n%MOD)*(bigMod(n,power-1,MOD)%MOD))%MOD;
}

int modInverse(int n,int MOD)
{
    return bigMod(n,MOD-2,MOD);
}

int POW(int x, int y)
{
    int res= 1;
    for ( ; y ; ) {
        if ( (y&1) ) {
            res*= x;
        }
        x*=x;
        y>>=1;
    }
    return res;
}

int inverse(int x)
{
    dd p=((dd)1.0)/x;
    return (p)+EPS;
}

int gcd(int a, int b)
{
    while(b) b^=a^=b^=a%=b;
    return a;
}

int nC2(int n)
{
    return n*(n-1)/2;
}

int MOD(int n,int mod)
{
    if(n>=0)
        return n%mod;
    else if(-n==mod)
        return 0;
    else
        return mod+(n%mod);
}

vector<int>g[1005];
int vis[1005],n,m,tmp,cnt,data[1005];


int dfs(int u)
{
    vis[u]=1;
    cnt++;
    tmp+=data[u-1];
    for(int i=0,j=g[u].size();i<j;i++)
    {
        int v=g[u][i];
        if(!vis[v])
            dfs(v);
    }
}


int main()
{
    int t,cas=0;
    getint(t);
    while(t--)
    {
        sf("%d %d",&n,&m);
        int sum=0;
        loop(i,n)
        {
            getint(data[i]);
            sum+=data[i];
        }
        loop(i,m)
        {
            int p,q;
            sf("%d %d",&p,&q);
            g[p].pb(q);
            g[q].pb(p);
        }
        CASE(cas);
        mem(vis,0);
        if(sum%n!=0)
        {
            pf("No\n");
            continue;
        }
        sum/=n;
        bool flag=true;
        loop(i,n)
        {
            if(!vis[i+1])
            {
                tmp=0;
                cnt=0;
                dfs(i+1);
                if(tmp%cnt!=0){
                    flag=false;
                    break;
                }
                if(tmp/cnt!=sum)
                {
                    flag=false;
                    break;
                }

            }
        }
        if(!flag)
            pf("No\n");
        else
            pf("Yes\n");
        loop(i,1000)
        g[i].clear();

    }
    return 0;
}
