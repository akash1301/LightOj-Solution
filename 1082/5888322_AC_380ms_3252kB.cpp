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
#define mx 100005
using namespace std;

int a[mx],ara[mx*3];

void init(int node,int b,int e)
{
    if(b==e)
    {
        ara[node]=a[b];
        return ;
    }
    int mid=(b+e)/2;
    int left=node*2;
    int right=node*2+1;
    init(left,b,mid);
    init(right,mid+1,e);
    ara[node]=min(ara[left],ara[right]);
}

int query(int node,int b,int e,int i,int j)
{
    if(i>e||j<b)
        return mx;
    if(b>=i&&e<=j)
        return ara[node];
    int mid=(b+e)/2;
    int right=node*2+1;
    int left=node*2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return min(p1,p2);
}

int main()
{
    //read();
    int t,x=0;
    getint(t);
    while(t--)
    {
        int n,q;
        getint(n);
        getint(q);
        for(int i=1;i<=n;i++)
        getint(a[i]);
        init(1,1,n);
        pf("Case %d:\n",++x);
        loop(i,q)
        {
            int x,y;
            getint(x);
            getint(y);
            pf("%d\n",query(1,1,n,x,y));
        }
    }
    return 0;
}
