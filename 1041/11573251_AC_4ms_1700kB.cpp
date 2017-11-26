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

struct node
{
    int p,q,w;
};

bool comp(node x,node y)
{
    return x.w<y.w;
}

vector<node>graph;
int n,pr[200];
int find(int r)
{
    if(pr[r]==r)
        return r;
    return find(pr[r]);
}

int mst()
{
    int ans=0,cnt=0;
    for(int i=0;i<graph.size();i++)
    {
        int u=find(graph[i].p);
        int v=find(graph[i].q);
        if(u!=v)
        {
            pr[u]=v;
            ans+=graph[i].w;
            cnt++;
            if(cnt==n-1)
                break;
        }
    }
    if(cnt<n-1)
        return -1;
    return ans;
}



int main()
{
	int t,cas=0;
	getint(t);

	while(t--)
    {
        int e;
        cin>>e;
        n=1;
        map<string,int>mapa;
        loop(i,e)
        {
            string s1,s2;
            int p;
            cin>>s1>>s2>>p;
            if(!mapa[s1])
            {
                mapa[s1]=n;
                n++;
            }
            if(!mapa[s2])
            {
                mapa[s2]=n;
                n++;
            }
            node edge;
            edge.p=mapa[s1];
            edge.q=mapa[s2];
            edge.w=p;
            graph.pb(edge);
        }
        n--;
        sort(all(graph),comp);
        loop(i,200)
        {
            pr[i]=i;
        }
        CASE(cas);
        int x=mst();
        if(x==-1)
            pf("Impossible\n");
        else
            pf("%d\n",x);
        graph.clear();
    }

	return  0;

}
