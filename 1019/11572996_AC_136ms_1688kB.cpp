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
#define inf 1000000
using namespace std;
 
int main()
{
    int n,m,t,p=0;
    cin>>t;
    while(t--)
    {
       
        cin>>n>>m;
        int g[n+1][n+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
                {
                    if(i==j)
                    g[i][j]=0;
                    else
                    g[i][j]=inf;
                }
        }
        for(int i=1;i<=m;i++)
        {
            int p,q,w;
            cin>>p>>q>>w;
            if(g[p][q]>w||g[p][q]==0)
            g[p][q]=w;
            if(g[q][p]>w||g[q][p]==0)
            g[q][p]=w;
        }
        for(int i=1;i<=n;i++)
        {
            for(int k=1;k<=n;k++)
            {
                for(int j=1;j<=n;j++)
                {
                    g[i][j]=min(g[i][k]+g[k][j],g[i][j]);
                    g[j][i]=min(g[j][k]+g[k][i],g[j][i]);
                }
            }
        }
        cout<<"Case "<<++p<<": ";
        if(g[1][n]==inf)
            cout<<"Impossible"<<endl;
        else
            cout<<g[1][n]<<endl;
    }
    return 0;
}