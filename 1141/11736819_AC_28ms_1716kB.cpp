/****************************************
*  MD. Al Mamun Akash                   *
*  uVa id: Pointer***                   *
*  Codeforces: Akash.KUET               *
*  LOJ: 19025				*
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
#define inf 100000
#define EPS 1e-9

using namespace std;

int fx[]={0,0,1,-1,1,1,-1,-1};
int fy[]={1,-1,0,0,1,-1,1,-1};

bool prime[1010];

void seive()
{
    mem(prime,true);
    for(int i=4;i<=1005;i+=2)
        prime[i]=false;
    for(int i=3;i<=sqrt(1005);i+=2)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=1005;j+=i)
                prime[j]=false;
        }
    }
}
vector<int>factor[1010];

void prime_factor()
{
    for(int i=2;i<=1005;i++)
    {
        if(prime[i])
        {
            for(int j=i*2;j<=1005;j+=i)
            {
                factor[j].pb(i);
            }
        }
    }
}

int dis[1005];

int bfs(int start,int lst)
{
    loop(i,1005)
    dis[i]=inf;
    queue<int>q;
    q.push(start);
    dis[start]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(u==lst)
            return dis[u];
        if(u>lst)
           return -1;
        int p=u;
        for(int i=0;i<factor[p].size();i++)
        {
            int v=factor[p][i];
            if(p+v<=lst){
            if(dis[p+v]>dis[p]+1)
            {
                dis[p+v]=dis[p]+1;
                q.push(p+v);
            }
            }
        }
    }
    return -1;
}


int main()
{
    int t,cas=0;
    seive();
    prime_factor();
    cin>>t;
    while(t--)
    {
        int s,x;
        cin>>s>>x;
        CASE(cas);
        cout<<bfs(s,x)<<endl;
    }
    return 0;
}
