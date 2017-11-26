/****************************************
*  MD. Al Mamun Akash                   *
*  uVa id: Pointer***                   *
*  Codeforces: Akash.KUET               *
*  LOJ: 19025               *
*  Spoj:akash_kuet                      *
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
#define getlong scanf("%lld",&n)
#define CASE(n) printf("Case %d: ",++n)
#define inf 2147483647
#define EPS 1e-9
 
using namespace std;
 
int fx[]={0,0,1,-1,1,1,-1,-1};
int fy[]={1,-1,0,0,1,-1,1,-1};
 
int cost_joe[205][205],cost_fire[205][205],r,c;
char data[205][205];
 
struct state
{
    int x,y,c;
    state(int p,int q,int w)
    {
        x=p;
        y=q;
        c=w;
    };
};
 
int bfs_joe(int u,int v)
{
    queue<state>qu;
    qu.push(state(u,v,0));
    cost_joe[u][v]=0;
    while(!qu.empty())
    {
        state d=qu.front();
        qu.pop();
        for(int i=0;i<4;i++){
        int nx=d.x+fx[i];
        int ny=d.y+fy[i];
       // cout<<inf<<endl;
 
        if(nx>=0&&nx<r&&ny>=0&&ny<c&&data[nx][ny]!='#'&&cost_joe[nx][ny]==inf)
        {
            cost_joe[nx][ny]=d.c+1;
            //cout<<cost_joe[nx][ny]<<endl;
            //cout<<cost_joe[d.x][d.y]<<endl;
            qu.push(state(nx,ny,cost_joe[nx][ny]));
        }
        }
    }
}
 
 
int bfs_fire()
{
    queue<state>qu;
    loop(i,r)
    {
        loop(j,c)
        {
            if(data[i][j]=='F')
            {
                qu.push(state(i,j,0));
                cost_fire[i][j]=0;
            }
        }
    }
    while(!qu.empty())
    {
        state d=qu.front();
        qu.pop();
        for(int i=0;i<4;i++){
        int nx=d.x+fx[i];
        int ny=d.y+fy[i];
        if(nx>=0&&nx<r&&ny>=0&&ny<c&&data[nx][ny]!='#'&&cost_fire[nx][ny]>d.c+1)
        {
            cost_fire[nx][ny]=d.c+1;
            qu.push(state(nx,ny,cost_fire[nx][ny]));
        }
        }
    }
}
 
 
int main()
{
    int t,x,y,cas=0;
    getint(t);
    while(t--)
    {
        getint(r);
        getint(c);
        loop(i,r)
        {
            scanf("%s",data[i]);
        }
        loop(i,r)
        {
            loop(j,c)
            {
                if(data[i][j]=='J')
                {
                    x=i;
                    y=j;
                    i=r;
                    j=c;
                }
            }
        }
        loop(i,205)
        {
            loop(j,205)
            cost_joe[i][j]=cost_fire[i][j]=inf;
        }
        bfs_joe(x,y);
        bfs_fire();
        int ans=inf;
        for(int i=0;i<r;i++)
        {
            if(cost_fire[i][0]>cost_joe[i][0])
            {
               // cout<<cost_joe[i][0]<<endl;
                ans=min(ans,cost_joe[i][0]);
            }
            if(cost_fire[i][c-1]>cost_joe[i][c-1])
            {
               // cout<<cost_joe[i][c-1]<<endl;
                ans=min(ans,cost_joe[i][c-1]);
            }
        }
        for(int i=0;i<c;i++)
        {
            if(cost_fire[0][i]>cost_joe[0][i])
            {
               // cout<<cost_joe[0][i]<<endl;
                ans=min(ans,cost_joe[0][i]);
            }
            if(cost_fire[r-1][i]>cost_joe[r-1][i])
            {
               // cout<<cost_joe[r-1][i]<<endl;
                ans=min(ans,cost_joe[r-1][i]);
            }
        }
        CASE(cas);
        if(ans==inf)
            pf("IMPOSSIBLE\n");
        else
            pf("%d\n",ans+1);
    }
    return 0;
}