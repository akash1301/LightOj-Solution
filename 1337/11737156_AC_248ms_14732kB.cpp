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
#define get2(a,b) scanf("%d %d",&a,&b)
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
 
char g[600][600];
 
int n,m,sum,vis[600][600];
 
vector<int>v1,v2;
 
int dfs(int u,int v)
{
    if(u>=n||u<0||v>=m||v<0||g[u][v]=='#'||vis[u][v]==1)
        return 0;
    vis[u][v]=1;
    v1.pb(u);
    v2.pb(v);
    if(g[u][v]=='C')
        sum++;
    dfs(u,v+1);
    dfs(u,v-1);
    dfs(u+1,v);
    dfs(u-1,v);
}
 
int main()
{
    //read();
    int t,x=0;
    getint(t);
    while(t--)
    {
        int q;
        //get2(n,m);
        scanf("%d %d %d",&n,&m,&q);
        //getchar();
        //getchar();
        loop(i,n)
        {
            getchar();
            loop(j,m)
            scanf("%c",&g[i][j]);
          //  cin>>g[i][j];
 
        }
        int crys[600][600];
        mem(vis,0);
        v1.clear();
        v2.clear();
        mem(crys,0);
        loop(i,n)
        {
            loop(j,m)
            {
                if(!vis[i][j]&&g[i][j]!='#')
                {
                    sum=0;
                    dfs(i,j);
                    for(int k=0;k<v1.size();k++)
                        crys[v1[k]][v2[k]]=sum;
                    v1.clear();
                    v2.clear();
                }
            }
        }
        pf("Case %d:\n",++x);
        while(q--)
        {
            int h,y;
            //mem(vis,0);
            scanf("%d %d",&h,&y);
            pf("%d\n",crys[h-1][y-1]);
        }
    }
    return 0;
}