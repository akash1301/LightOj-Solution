#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
 
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
vector<int>v[20010];
int vis[20010];
 
int bfs(int x)
{
    queue<int>q;
    q.push(x);
    vis[x]=1;
    int num=0,tot=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(vis[u]==1)
            num++;
        tot++;
        if(v[u].size()==0)
            return 1;
        for(int j=0;j<v[u].size();j++)
        {
            int d=v[u][j];
            if(!vis[d])
            {
                vis[d]=3-vis[u];
                q.push(d);
            }
        }
    }
    return max(num,tot-num);
}
 
 
int main()
{
    //read();
    int t,n,x=0;
    getint(t);
 
    while(t--)
    {
 
        getint(n);
        int m=0;
         mem(vis,10);
        for(int i=0;i<n;i++)
        {
            int a,b;
            sf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
            vis[b]=0;
            vis[a]=0;
            if(max(a,b)>m)
                m=max(a,b);
        }
        int sum=0;
        for(int i=1;i<=m;i++)
        {
            if(vis[i]==0)
            {
                sum+=bfs(i);
            }
        }
        pf("Case %d: %d\n",++x,sum);
        loop(i,20010)
        v[i].clear();
    }
    return 0;
}