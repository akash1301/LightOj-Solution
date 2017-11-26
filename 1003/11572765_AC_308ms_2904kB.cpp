/****************************************
*  MD. Al Mamun Akash                   *
*  uVa id: Pointer***                   *
*  Codeforces: Akash.KUET               *
*  LOJ: 19025                           *
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
#define inf 1000000000
 
using namespace std;
 
int fx[]={0,0,1,-1,1,1,-1,-1};
int fy[]={1,-1,0,0,1,-1,1,-1};
 
map<string,int>ind;
vector<int>g[20005];
int vis[20005],val;
 
int dfs(int u)
{
    if(val==1)
        return 0;
    vis[u]=1;
    for(int i=0,j=g[u].size();i<j;i++)
    {
        int v=g[u][i];
        if(!vis[v])
            dfs(v);
        else{
            val=1;
            return 0;
        }
    }
    //top.pb(u);
}
 
/*int dfs2(int u)
{
    vis[u]=1;
    loop(i,g[u].size())
    {
        int v=g[u][i];
        if(!vis[v])
            dfs2(v);
    }
    //top.pb(u);
}*/
 
 
int main()
{
    //read();
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        int e;
        cin>>e;
        int in=1;
        loop(i,e)
        {
            string s1,s2;
            cin>>s1>>s2;
            if(!ind[s1])
            {
                ind[s1]=in;
                in++;
            }
            if(!ind[s2])
            {
                ind[s2]=in;
                in++;
            }
            g[ind[s1]].pb(ind[s2]);
            //g2[ind[s2]].pb(ind[s1]);
        }
        //mem(vis,0);
        val=0;
        for(int i=1;i<in;i++)
        {
            //if(!vis[i])
            mem(vis,0);
                dfs(i);
        }
        //int ans=0,val=1;
        /*mem(vis,0);
        for(int i=top.size()-1;i>=0;i--)
        {
            if(!vis[top[i]])
            {
                dfs2(top[i]);
                ans++;
                if(ans>1){
                    val=0;
                    break;
                }
            }
        }*/
        CASE(cas);
        if(val==0)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        loop(i,in){
        g[i].clear();
//        g2[i].clear();
        }
        //top.clear();
        ind.clear();
 
    }
    return 0;
}