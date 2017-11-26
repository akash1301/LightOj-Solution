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
#define inf 10000000
#define EPS 1e-9

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

vector<int>g[205];
int vis[205],par[205],flow[205][205],dis[205][205],f,strt,des,e,n,val,cap[205][205];

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
                if(!vis[v] && flow[u][v]>0 && dis[u][v]<=val)
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
        mem(dis,0);
        int d;
        vector< pair<int,char> > vv;
        cin>>n>>d;
        loop(i,n)
        {
            getchar();
            char x;
            int y;
            sf("%c-%d",&x,&y);
            vv.pb(mp(y,x));
        }
        strt=1;
        des=2*(n+1);
        loop(i,vv.size())
        {
            int xx=vv[i].fr;
            char yy=vv[i].sc;
//            cout<<xx<<" "<<yy<<endl;
            int tmp;
            if(yy=='S')
                tmp=2*(i+1)+1;
            else
                tmp=2*(i+1);
            for(int j=i+1; j<vv.size(); j++)
            {
                dis[tmp][2*(j+1)]=vv[j].fr-xx;
                g[tmp].pb(2*(j+1));
                g[2*(j+1)].pb(tmp);
                cap[tmp][2*(j+1)]=2;
            }

            if(yy=='S')
            {
                dis[tmp-1][tmp]=1;
                g[tmp].pb(tmp-1);
                g[tmp-1].pb(tmp);
                cap[tmp-1][tmp]=1;
            }
            dis[tmp][des]=d-xx;
            g[tmp].pb(des);
            g[des].pb(tmp);
            cap[tmp][des]=2;
        }
        loop(i,vv.size())
        {
            dis[strt][2*(i+1)]=vv[i].fr;
            g[strt].pb(2*(i+1));
            g[2*(i+1)].pb(strt);
            cap[strt][2*(i+1)]=2;
        }
        dis[strt][des]=d;
        g[strt].pb(des);
        g[des].pb(strt);
        cap[strt][des]=2;
        int hi=d;
        int lo=1;
        int mid=(hi+lo)/2;
        int ans=0;
        while(lo<=hi)
        {
            for(int i=0;i<205;i++)
            {
                for(int j=0;j<205;j++)
                {
                    flow[i][j]=cap[i][j];
                }
            }
            val=mid;
            int dx=max_flow();
//            cout<<val<<" "<<dx<<endl;
            if(dx<2)
            {
                lo=mid+1;
            }
            else
            {
                hi=mid-1;
                ans=mid;
            }
            mid=(hi+lo)/2;
        }
        CASE(cas);
        pf("%d\n",ans);
        loop(i,205)
        g[i].clear();
    }

    return  0;

}
