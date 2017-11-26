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
 
char g[30][30];
 
int vis[30][30],r,c,sum,dis[30][30];
int fx[]={0,0,1,-1};
int fy[]={1,-1,0,0};
 
struct node
{
    int x,y;
    node(int data1,int data2)
    {
        x=data1;
        y=data2;
    }
};
 
int bfs(int u,int v)
{
    queue<node>q;
    q.push(node(u,v));
    vis[u][v]=1;
    dis[u][v]=0;
    while(!q.empty())
    {
        node tp=q.front();
        q.pop();
        int x4=tp.x;
        int y4=tp.y;
        if(g[x4][y4]=='h')
            return dis[x4][y4];
        for(int i=0;i<4;i++)
        {
            int x5=x4+fx[i];
            int y5=y4+fy[i];
            if(x5<r&&x5>=0&&y5<c&&y5>=0&&g[x5][y5]!='#'&&vis[x5][y5]==0&&g[x5][y5]!='m')
            {
                vis[x5][y5]=1;
                dis[x5][y5]=dis[x4][y4]+1;
                q.push(node(x5,y5));
            }
        }
    }
}
 
int main()
{
    //read();
    int t,x1,x2,y1,y2,z1,z2,h=0;
    cin>>t;
    while(t--)
    {
        cin>>r>>c;
        loop(i,r)
        {
            //getchar();
            loop(j,c){
                //getchar();
            cin>>g[i][j];
            if(g[i][j]=='c')
            {
                x1=i;
                x2=j;
            }
            if(g[i][j]=='a')
            {
                y1=i;
                y2=j;
            }
            if(g[i][j]=='b')
            {
                z1=i;
                z2=j;
            }
        }
        }
        int ans=0;
        int ds;
        mem(vis,0);
        ds=bfs(x1,x2);
        if(ds>ans)
            ans=ds;
        //sum=0;
        mem(vis,0);
        ds=bfs(y1,y2);
        if(ds>ans)
            ans=ds;
        mem(vis,0);
        ds=bfs(z1,z2);
        if(ds>ans)
            ans=ds;
        pf("Case %d: %d\n",++h,ans);
    }
    return 0;
}