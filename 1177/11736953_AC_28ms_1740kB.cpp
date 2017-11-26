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

vector<int>g[105];
int vis[105],par[105],flow[105][105],f,strt,des,e,n;

void augmentPath(int u,int len)
{
    if(u==strt)
    {
        f=len;
        return;
    }
    else if(vis[u])
    {
        augmentPath(par[u],min(len,flow[par[u]][u]));
        flow[u][par[u]]+=f;
        flow[par[u]][u]-=f;
    }
}


int max_flow()
{
    int ans=0;
    while(1)
    {
        mem(vis,0);
        queue<int>q;
        q.push(strt);
        mem(par,0);
        bool flag=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            if(u==des){
                flag=1;
                break;
            }
            for(int i=0,j=g[u].size(); i<j; i++)
            {
                int v=g[u][i];
                if(!vis[v] && flow[u][v]>0)
                {
                    vis[v]=1;
                    par[v]=u;
                    q.push(v);
                }
            }
        }
        augmentPath(des,inf);
        if(f==0 || !flag)
        {
            break;
        }
        ans+=f;
    }
    return ans;
}

int main()
{
	int t,cas=0;

	cin>>t;
	while(t--)
    {
        mem(flow,0);
        cin>>n>>e;
        for(int i=2;i<n;i++)
        {
            int p;
            cin>>p;
            g[i].pb(i+n);
            g[i+n].pb(i);
            flow[i][i+n]=p;
//            flow[i+n][i]=p;
        }

        loop(i,e)
        {
            int p,q,w;
            cin>>p>>q>>w;
            if(p==1 || p==n)
            {
                g[p].pb(q);
                g[q].pb(p);
                flow[p][q]=w;
//                flow[q][p]=w;
            }
            else
            {
                g[p+n].pb(q);
                g[q].pb(p+n);
                flow[p+n][q]=w;
//                flow[q][p+n]=w;
            }
            if(q==1 || q==n)
            {
                g[q].pb(p);
                g[p].pb(q);
                flow[q][p]=w;
//                flow[p][q]=n;
            }
            else
            {
                g[q+n].pb(p);
                g[p].pb(q+n);
                flow[q+n][p]=w;
//                flow[p][q+n]=w;
            }

        }
        strt=1;
        des=n;
        CASE(cas);
        cout<<max_flow()<<endl;
        loop(i,105)
        g[i].clear();
    }
	return  0;

}
