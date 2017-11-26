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
#define mx 505

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

int n,m,shop[20],dis[18][18],dokan[mx],s,dt[mx];
bool vis[17][(1<<17)+1];
vector< paii >g[mx];
paii dp[17][(1<<17)+1];


struct node
{
    int city,dist;
    node (int a,int b)
    {
        city=a;
        dist=b;
    }
    bool operator < (const node& p) const {
        return dist>p.dist;
    }
};

int dijkstra(int src,int des)
{
    loop(i,mx)
    {
        dt[i]=inf;
    }
    priority_queue<node>q;
    q.push(node(src,0));
    dt[src]=0;
    while(!q.empty())
    {
        node t=q.top();
        q.pop();
        int u=t.city;
        if(u==des) return dt[u];
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i].fr;
            int cc=g[u][i].sc;
            if(cc+dt[u]<dt[v])
            {
                dt[v]=cc+dt[u];
                q.push(node(v,dt[v]));
            }
        }
    }
    return dt[des];

}

void clr()
{
    loop(i,mx)
    {
        g[i].clear();
        dokan[i]=0;
    }
    loop(i,18)
    {
        loop(j,18)
            dis[i][j]=inf;
        shop[i]=0;
    }
}


paii call(int i,int mask)
{
    if(shop[i]==n-1)
    {
        return mp(0,0);
    }
    paii &ret=dp[i][mask];
    if(vis[i][mask]) return ret;
    ret=mp(-inf,inf);
    vis[i][mask]=1;
    loop(j,s+2)
    {
        if(CHECK(mask,j)) continue;
        if(dis[i][j]>=inf) continue;
        paii tmp=call(j,SET(mask,j));
        tmp.fr+=dokan[shop[j]];
        tmp.sc+=dis[i][j];
        if(tmp.fr>ret.fr)
        {
            ret=tmp;
        }
        else if(tmp.fr==ret.fr && tmp.sc<ret.sc)
        {
            ret=tmp;
        }
    }

    return ret;

}


int main()
{
	int t,cas=0;
	getint(t);
	while(t--)
    {
        clr();
        sf("%d %d %d",&n,&m,&s);
        loop(i,s)
        {
            int a;
            getint(shop[i+1]);
            dokan[shop[i+1]]++;
        }
        shop[s+1]=n-1;
        loop(i,m)
        {
            int a,b,c;
            sf("%d %d %d",&a,&b,&c);
            g[a].pb(mp(b,c));
        }

        for(int i=0;i<=s+1;i++)
        {
            for(int j=0;j<=s+1;j++)
            {
                dis[i][j]=dijkstra(shop[i],shop[j]);
            }
        }

        mem(vis,0);

        paii ans=call(0,1);
        CASE(cas);
        if(ans.fr<0)
        {
            pf("Impossible\n");
        }
        else
            pf("%d %d\n",ans.fr,ans.sc);

    }
	return  0;

}
