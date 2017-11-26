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
#define mx 105

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


struct node
{
    int city,g,cost;
    node (int a,int b,int c)
    {
        city=a;
        g=b;
        cost=c;
    }
    bool operator < (const node& p) const {
    return cost>p.cost;
    }
};

int n,m,gas[mx],dis[mx][mx];
vector< paii >g[mx];


int dijkstra(int src,int des,int cap)
{
    loop(i,mx)
    {
        loop(j,mx)
            dis[i][j]=inf;
    }
    priority_queue<node>pq;
    pq.push(node(src,0,0));
    dis[src][0]=0;
    while(!pq.empty())
    {
        int u=pq.top().city;
        int gg=pq.top().g;
        int cc=pq.top().cost;
        pq.pop();
        if(u==des) return cc;
        if(cap>=gg+1 && dis[u][gg+1]>dis[u][gg]+gas[u])
        {
            dis[u][gg+1]=dis[u][gg]+gas[u];
            pq.push(node(u,gg+1,dis[u][gg+1]));
        }
        loop(i,g[u].size())
        {
            int v=g[u][i].fr;
            int ccc=g[u][i].sc;
            if(gg<ccc) continue;
            if(dis[v][gg-ccc]>dis[u][gg])
            {
                dis[v][gg-ccc]=dis[u][gg];
                pq.push(node(v,gg-ccc,dis[v][gg-ccc]));
            }
        }
    }
    return -1;
}


int main()
{
	int t,cas=0;
	getint(t);
	while(t--)
    {
        loop(i,mx)
        {
            g[i].clear();
        }
        sf("%d %d",&n,&m);
        loop(i,n)
        {
            getint(gas[i]);
        }
        loop(i,m)
        {
            int a,b,c;
            sf("%d %d %d",&a,&b,&c);
            g[a].pb(mp(b,c));
            g[b].pb(mp(a,c));
        }

        int q;
        getint(q);
        CASE(cas);
        while(q--)
        {
            int c,s,tt;
            sf("%d %d %d",&c,&s,&tt);
            int ans=dijkstra(s,tt,c);
            if(ans==-1)
                pf("impossible\n");
            else
                pf("%d\n",ans);
        }

    }
	return  0;

}
