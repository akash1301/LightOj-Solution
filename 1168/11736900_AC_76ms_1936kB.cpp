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
#define mx 1005

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

int str2int(string s) {
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}

string int2str(int a) {
	stringstream ss;
	ss << a;
	string str = ss.str();
	return str;
}

string char2str(char a) {
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

ll MOD(ll n,ll mod)
{
    if(n>=0)
        return n%mod;
    else if(-n==mod)
        return 0;
    else
        return mod+(n%mod);
}

int n,mapa[mx],vis[mx],scc_num[mx],scc,node,tot;
vector<int>g[mx],finish,graph_scc[mx],rev_g[mx];

int dfs1(int u)
{
    vis[u]=1;
    loop(i,g[u].size())
    {
        int v=g[u][i];
        if(!vis[v])
            dfs1(v);
    }
    finish.pb(u);
}


int dfs2(int u)
{
    vis[u]=2;
    scc_num[u]=scc;
    loop(i,rev_g[u].size())
    {
        int v=rev_g[u][i];
        if(vis[v]==1)
            dfs2(v);
    }
}

int dfs3(int u)
{
    vis[u]=1;
    tot++;
    if(graph_scc[u].size()>1)
        node=1;
    loop(i,graph_scc[u].size())
    {
        int v=graph_scc[u][i];
        if(!vis[v])
            dfs3(v);
    }
}

void clr()
{
    loop(i,mx)
    {
        g[i].clear();
        rev_g[i].clear();
        graph_scc[i].clear();
    }
    finish.clear();
    mem(mapa,0);
    mem(vis,0);
    mem(scc_num,0);
}

int main()
{
	int t,cas=0;
	getint(t);
	while(t--)
    {
        clr();
        getint(n);
        int cnt=2;
        mapa[0]=1;
        loop(i,n)
        {
            int x;
            getint(x);
            loop(j,x)
            {
                int a,b;
                sf("%d %d",&a,&b);
                if(!mapa[a])
                    mapa[a]=cnt++;
                if(!mapa[b])
                    mapa[b]=cnt++;
                g[mapa[a]].pb(mapa[b]);
                rev_g[mapa[b]].pb(mapa[a]);
            }
        }

        for(int i=1;i<cnt;i++)
        {
            if(!vis[i])
            {
                dfs1(i);
            }
        }
        scc=1;
        for(int i=finish.size()-1;i>=0;i--)
        {
            int u=finish[i];
            if(vis[u]==1)
            {
                dfs2(u);
                scc++;
            }
        }

//        cout<<scc-1<<endl;

        for(int i=1;i<cnt;i++)
        {
            loop(j,g[i].size())
            {
                int u=g[i][j];
                if(scc_num[i]!=scc_num[u])
                    graph_scc[scc_num[i]].pb(scc_num[u]);
            }
        }

        mem(vis,0);

        node=0;
        tot=1;
        CASE(cas);
        dfs3(scc_num[1]);
        //cout<<node<<" "<<tot<<endl;
        if(!node && tot==scc)
            pf("YES\n");
        else
            pf("NO\n");
    }
	return  0;

}
