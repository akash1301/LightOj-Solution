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

map<string,int>mapa;
vector<int>graph[55];
int match[700],vis[700],n,m;

void add(string s,int p)
{
    for(int i=0;i<n;i+=6)
    {
        int x=mapa[s]+m+i;
//        cout<<x<<endl;
        graph[p].pb(x);
    }
}

bool matching(int u)
{
    for(int i=0,j=graph[u].size();i<j;i++)
    {
        int v=graph[u][i];
        if(vis[v])
            continue;
        vis[v]=1;
        if(match[v]==-1 || matching(match[v]))
        {
            match[v]=u;
            return true;
        }
    }
    return false;
}

int main()
{
	int t,cas=0;
	mapa["XXL"]=0;
	mapa["XL"]=1;
	mapa["L"]=2;
	mapa["M"]=3;
	mapa["S"]=4;
	mapa["XS"]=5;
	getint(t);
	while(t--)
    {
        sf("%d %d",&n,&m);
        n*=6;

        loop(i,m)
        {
            string s1,s2;
            cin>>s1>>s2;
            add(s1,i);
            add(s2,i);
        }
        mem(match,-1);
        int cnt=0;
        loop(i,m)
        {
            mem(vis,0);
            if(matching(i))
            {
                cnt++;
            }
        }
        CASE(cas);
        if(cnt==m)
        {
            pf("YES\n");
        }
        else
            pf("NO\n");
        loop(i,55)
        graph[i].clear();
    }
	return  0;

}
