

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
#define getlong(n) scanf("%lld",&n)
#define CASE(n) printf("Case %d: ",++n)
#define inf 100000000
#define EPS 1e-9

using namespace std;

//8 way moves
//int fx[]={0,0,1,-1,1,1,-1,-1};
//int fy[]={1,-1,0,0,1,-1,1,-1};

//knight moves
int fx[]={-2,-2,-1,-1,1,1,2,2};
int fy[]={-1,1,-2,2,-2,2,-1,1};

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
    int x,y;
    node(int p,int q)
    {
        x=p;
        y=q;
    }
};

vector<paii >point;
int row,col;
char graph[15][15];


int bfs(int i,int j,int disx,int disy)
{
    ll dis[15][15];
    mem(dis,63);
    queue<node>qu;
    qu.push(node(i,j));
    dis[i][j]=0;
    while(!qu.empty())
    {
        node tp=qu.front();
        qu.pop();
        int x=tp.x;
        int y=tp.y;
        if(x==disx && y==disy)
            return dis[x][y];
        loop(i,8)
        {
            int xx=x+fx[i];
            int yy=y+fy[i];
            if(xx>=0 && xx<row && yy>=0 && yy<col && dis[xx][yy]>dis[x][y]+1)
            {
                dis[xx][yy]=dis[x][y]+1;
                qu.push(node(xx,yy));
            }
        }
    }
    return -1;
}


int main()
{
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        cin>>row>>col;
        loop(i,row)
        {
            loop(j,col)
            {
                cin>>graph[i][j];
                if(graph[i][j]!='.')
                {
                    point.pb(mp(i,j));
                }
            }
        }
        int sz=point.size();
        int ans=inf;
        loop(i,row)
        {
            loop(j,col)
            {
                bool flag=true;
                int sum=0;
                loop(k,sz)
                {
                    int d=bfs(i,j,point[k].fr,point[k].sc);
                    if(d==-1)
                    {
                        flag=false;
                        break;
                    }
                    int x=graph[point[k].fr][point[k].sc]-'0';
                    int p=d/x;
                    if(d%x!=0)
                        p++;
                    sum+=p;
                }
                if(flag && sum<ans)
                    ans=sum;
            }
        }
        CASE(cas);
        if(ans==inf)
            pf("-1\n");
        else
        pf("%d\n",ans);
        point.clear();

    }
    return 0;
}
