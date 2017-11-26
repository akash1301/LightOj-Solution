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
#define CASE(n) printf("Case %d:\n",++n)
#define CASE_COUT cout<<"Case "<<++cas<<": "
#define inf 1000000000
#define EPS 1e-9
#define Harmonic(n) (0.577215664901532+log(n)+(1/(2*n)))     ///Use Only for large n
#define mx 50005

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

int n,m,pr[mx],level[mx],parent[mx],dis[mx];
paii table[mx][16];
vector< paii >g[mx];
vector< pair< int , paii > >edge;

int findd(int u)
{
    if(pr[u]==u) return u;
    return pr[u]=findd(pr[u]);
}

void MST()
{
    loop(i,mx)
        pr[i]=i;
    sort(all(edge));
    int cnt=0;
    loop(i,edge.size())
    {
        int aa=findd(edge[i].sc.fr);
        int bb=findd(edge[i].sc.sc);
        if(aa!=bb)
        {
            pr[aa]=bb;
            cnt++;
            g[edge[i].sc.fr].pb(mp(edge[i].sc.sc,edge[i].fr));
            g[edge[i].sc.sc].pb(mp(edge[i].sc.fr,edge[i].fr));
            if(cnt==n-1) break;
        }
    }
}


int dfs(int u,int par,int lev)
{
    level[u]=lev;
    parent[u]=par;
    loop(i,g[u].size())
    {
        int v=g[u][i].fr;
        if(par==v) continue;
        dis[v]=g[u][i].sc;
        dfs(v,u,lev+1);
    }
}


void lca_init()
{
    mem(table,-1);
    for(int i=1; i<=n; i++){
        table[i][0].fr=parent[i];
        table[i][0].sc=dis[i];
    }
    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(table[i][j-1].fr!=-1){
                table[i][j].fr=table[table[i][j-1].fr][j-1].fr;
                table[i][j].sc=max(table[i][j-1].sc,table[table[i][j-1].fr][j-1].sc);
            }
        }
    }
}


int lca_query(int p,int q)
{
    if(level[p]<level[q])
        swap(p,q);
    int log=1;
    while(1)
    {
        int aaa=log+1;
        if((1<<aaa)>level[p]) break;
        log++;
    }
    for(int i=log; i>=0; i--)
    {
        if(level[p]-(1<<i)>=level[q])
            p=table[p][i].fr;
    }
    if(p==q) return p;
    for(int i=log; i>=0; i--)
    {
        if(table[p][i].fr!=-1 && table[p][i].fr!=table[q][i].fr)
        {
            p=table[p][i].fr;
            q=table[q][i].fr;
        }
    }
    return parent[p];
}


int func(int node,int l)
{
    int log=1;
    int ans=0;
    while(1)
    {
        int aaa=log+1;
        if((1<<aaa)>level[node]) break;
        log++;
    }
    for(int i=log; i>=0; i--)
    {
        if(level[node]-(1<<i)>=l){
            ans=max(ans,table[node][i].sc);
            node=table[node][i].fr;
        }
    }
    return ans;
}


int main()
{
	int t,cas=0;
	getint(t);
	while(t--)
    {
        edge.clear();
        loop(i,mx)
            g[i].clear();
        sf("%d %d",&n,&m);
        loop(i,m)
        {
            int a,b,c;
            sf("%d %d %d",&a,&b,&c);
            edge.pb(mp(c,mp(a,b)));
        }
        MST();
        dis[1]=0;
        dfs(1,0,0);
        lca_init();
        int q;
        getint(q);
        CASE(cas);
        while(q--)
        {
            int a,b;
            sf("%d %d",&a,&b);
            int lca=lca_query(a,b);
            pf("%d\n",max(func(a,level[lca]),func(b,level[lca])));
        }
    }
	return  0;

}
