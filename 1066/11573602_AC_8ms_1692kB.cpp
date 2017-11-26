/****************************************
*  MD. Al Mamun Akash                   *
*  uVa id: Pointer***                   *
*  Codeforces: Akash.KUET               *
*  LOJ: Al Mamun Akash                  *
*  Khulna,Bangladesh.                   *
*****************************************/
 
 
 
#include <bits/stdc++.h>
 
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define getint(n) scanf("%d", &n)
#define pb(a) push_back(a)
#define ll long long int
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
 
using namespace std;
 
char g[15][15],c;
int vis[15][15],n,des1,des2,dis[15][15];
 
int fx[]={0,0,1,-1};
int fy[]={1,-1,0,0};
 
struct node
{
    int city1,city2;
    node(int a,int b)
    {
        city1=a;
        city2=b;
    }
};
 
bool valid(int g,int h)
{
    return g>=0&&h>=0&&g<n&&h<n;
}
 
int bfs(int u,int v)
{
    queue<node>q;
    q.push(node(u,v));
    mem(dis,0);
    mem(vis,0);
    vis[u][v]=1;
    dis[u][v]=0;
    while(!q.empty())
    {
        node tp=q.front();
        q.pop();
        int x1=tp.city1;
        int y1=tp.city2;
        if(g[x1][y1]==1+c){
            des1=x1;
            des2=y1;
            return dis[x1][y1];
        }
        for(int i=0;i<4;i++)
        {
            int x2=x1+fx[i];
            int y2=y1+fy[i];
            if(valid(x2,y2) && !vis[x2][y2] && (g[x2][y2]=='.'||g[x2][y2]==c+1))
            {
                vis[x2][y2]=1;
                dis[x2][y2]=dis[x1][y1]+1;
                q.push(node(x2,y2));
            }
        }
    }
    return -1;
}
 
int main()
{
   //read();
    int t,x,y,k=0;
    cin>>t;
    while(t--)
    {
 
        int alpha=0;
        cin>>n;
        getchar();
        loop(i,n)
        {
            loop(j,n)
            {
                cin>>g[i][j];
                if(g[i][j]>='A'&&g[i][j]<='Z')
                    alpha++;
                if(g[i][j]=='A')
                {
                    x=i;
                    y=j;
                }
            }
        }
        int sum=1,ans=0,d=1;
        while(1)
        {
            if(sum==alpha)
                break;
            c=g[x][y];
            g[x][y]='.';
            d=bfs(x,y);
            if(d==-1)
                break;
            ans+=d;
            sum++;
            x=des1;
            y=des2;
 
        }
        if(d==-1)
            pf("Case %d: Impossible\n",++k);
        else
            pf("Case %d: %d\n",++k,ans);
    }
    return 0;
}
 