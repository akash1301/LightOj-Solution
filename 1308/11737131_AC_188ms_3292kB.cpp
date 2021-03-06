/////////////////////// All Is Well /////////////////////////

#include <bits/stdc++.h>

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define CIN   ios_base::sync_with_stdio(0); cin.tie(0)
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
#define CASE(n) printf("Case %d: ",++n)
#define CASE_COUT cout<<"Case "<<++cas<<": "
#define inf 1000000000
#define EPS 1e-9
#define Harmonic(n) (0.577215664901532+log(n)+(1/(2*n)))     ///Use Only for large n
#define mx 10005

using namespace std;

//8 way moves
//int fx[]={0,0,1,-1,1,1,-1,-1};
//int fy[]={1,-1,0,0,1,-1,1,-1};

//knight moves
//int fx[]={-2,-2,-1,-1,1,1,2,2};
//int fy[]={-1,1,-2,2,-2,2,-1,1};

//Bit operation
int SET(int n,int pos)
{
    return n=n | (1<<pos);
}
int RESET(int n,int pos)
{
    return n=n & ~(1<<pos);
}
int CHECK(int n,int pos)
{
    return (bool) (n & (1<<pos));
}

int str2int(string s)
{
    stringstream ss(s);
    int x;
    ss >> x;
    return x;
}

string int2str(int a)
{
    stringstream ss;
    ss << a;
    string str = ss.str();
    return str;
}

string char2str(char a)
{
    stringstream ss;
    ss << a;
    string str = ss.str();
    return str;
}

ll bigMod(ll n,ll power,ll MOD)
{
    if(power==0)
        return 1;
    if(power%2==0)
    {
        ll ret=bigMod(n,power/2,MOD);
        return ((ret%MOD)*(ret%MOD))%MOD;
    }
    else return ((n%MOD)*(bigMod(n,power-1,MOD)%MOD))%MOD;
}

ll modInverse(ll n,ll MOD)
{
    return bigMod(n,MOD-2,MOD);
}

int POW(int x, int y)
{
    int res= 1;
    for ( ; y ; )
    {
        if ( (y&1) )
        {
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

ull nC2(ull n)
{
    return n*(n-1)/2;
}

ll MOD(ll n,ll mod)
{
    if(n>=0)
        return n%mod;
    else if(-n==mod)
        return 0;
    else
        return mod+(n%mod);
}

int n,m,point;
ull cnt;
vector<int>g[mx];
int vis[mx],artpoint[mx],used[mx],low[mx],degroot,dfstime,comp_point[mx],comp;

void findart(int u, int par)
{
    int i, v, child = 0;
    used[u] = 1;
    vis[u] = low[u] = ++dfstime;
    for(i = 0; i < g[u].size(); i++)
    {
        v = g[u][i];
        if(v == par) continue;
        if(used[v]) low[u] = min(low[u], vis[v]);
        else
        {
            child++;
            findart(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= vis[u]) artpoint[u] = 1;
        }
    }
    if(par == -1) artpoint[u] = (child > 1);
}

int dfs(int u)
{
    vis[u]=1;
    cnt++;
    loop(i,g[u].size())
    {
        int v=g[u][i];
        if(!vis[v] && !artpoint[v])
            dfs(v);
        if(artpoint[v] && comp_point[v]!=comp)
        {
            point++;
            comp_point[v]=comp;
        }
    }
}


void clr()
{
    loop(i,mx)
    {
        g[i].clear();
    }
    mem(artpoint,0);
    mem(vis,0);
    mem(used,0);
    mem(low,0);
    mem(comp_point,0);
}


int main()
{
    int t,cas=0;
    getint(t);
    while(t--)
    {
        clr();
        sf("%d %d",&n,&m);
        loop(i,m)
        {
            int a,b;
            sf("%d %d",&a,&b);
            g[a].pb(b);
            g[b].pb(a);
        }
        degroot=0;
        dfstime=0;
        findart(0,-1);

//        loop(i,n)
//        cout<<artpoint[i]<<endl;

        mem(vis,0);
        comp=1;
        int shaft=0;
        ull way=1;
        loop(i,n)
        {
            if(!vis[i] && !artpoint[i])
            {
                point=0;
                cnt=0;
                dfs(i);
                if(point==1)
                {
                    shaft++;
                    way*=cnt;
                }
                comp++;
            }
        }

        if(shaft==0)
        {
            shaft=2;
            way=nC2((ull)n);
        }
        CASE(cas);
        pf("%d %llu\n",shaft,way);

    }
    return  0;

}
