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
    int city;
    ll dist;
    node (int a,ll b)
    {
        city=a;
        dist=b;
    }
    bool operator < (const node& p) const {
    return dist>p.dist;
    }
};


int n,m,s,t;
ll dis1[mx],dis2[mx],p;
vector< pair<int,ll> >g[mx],g_rev[mx];
vector< pair<int, pair<int,ll> > >edge;


void dijkstra()
{
    loop(i,mx)
    {
        dis1[i]=inf;
    }
    priority_queue<node>pq;
    dis1[s]=0;
    pq.push(node(s,0));
    while(!pq.empty())
    {
        int u=pq.top().city;
        ll cost=pq.top().dist;
        pq.pop();
        loop(i,g[u].size())
        {
            int v=g[u][i].fr;
            int ww=g[u][i].sc;
            if(dis1[u]+ww<dis1[v])
            {
                dis1[v]=dis1[u]+ww;
                pq.push(node(v,dis1[v]));
            }
        }
    }
}


void rev_dijkstra()
{
    loop(i,mx)
    {
        dis2[i]=inf;
    }
    priority_queue<node>pq;
    dis2[t]=0;
    pq.push(node(t,0));
    while(!pq.empty())
    {
        int u=pq.top().city;
        ll cost=pq.top().dist;
        pq.pop();
        loop(i,g_rev[u].size())
        {
            int v=g_rev[u][i].fr;
            int ww=g_rev[u][i].sc;
            if(dis2[u]+ww<dis2[v])
            {
                dis2[v]=dis2[u]+ww;
                pq.push(node(v,dis2[v]));
            }
        }
    }
}



int main()
{
	int tt,cas=0;
	getint(tt);
	while(tt--)
    {
        loop(i,mx)
        {
            g[i].clear();
            g_rev[i].clear();
        }
        edge.clear();
        sf("%d %d %d %d %lld",&n,&m,&s,&t,&p);
        loop(i,m)
        {
            int a,b;
            ll c;
            sf("%d %d %lld",&a,&b,&c);
            g[a].pb(mp(b,c));
            g_rev[b].pb(mp(a,c));
            edge.pb(mp(a,mp(b,c)));
        }

        dijkstra();
        rev_dijkstra();

        ll ans=-1;

        loop(i,edge.size())
        {
            if(dis1[edge[i].fr]+dis2[edge[i].sc.fr]+edge[i].sc.sc<=p)
                ans=max(ans,edge[i].sc.sc);
        }

        CASE(cas);
        pf("%lld\n",ans);

    }
	return  0;

}
