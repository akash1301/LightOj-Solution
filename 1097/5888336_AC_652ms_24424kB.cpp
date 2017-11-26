/////////////////////// All Is Well /////////////////////////

#include <bits/stdc++.h>

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define CIN   ios_base::sync_with_stdio(0); cin.tie(0)
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
#define CASE(n) printf("Case %d: ",++n)
#define CASE_COUT cout<<"Case "<<++cas<<": "
#define inf 1000000000
#define EPS 1e-9

using namespace std;

//8 way moves
//int fx[]={0,0,1,-1,1,1,-1,-1};
//int fy[]={1,-1,0,0,1,-1,1,-1};

//knight moves
//int fx[]={-2,-2,-1,-1,1,1,2,2};
//int fy[]={-1,1,-2,2,-2,2,-1,1};

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

const int mx=1430005;

int tree[4*mx],ans[100005];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]= b & 1;
        return ;
    }
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    init(l,b,mid);
    init(r,mid+1,e);
    tree[node]=tree[l]+tree[r];
}

void update(int node,int b,int e,int i)
{
    if(b==e)
    {
        tree[node]=0;
        return ;
    }
    int l=2*node;
    int r=1+l;
    int mid=(b+e)/2;
    if(i<=tree[l])
    {
        update(l,b,mid,i);
    }
    else
    {
        update(r,mid+1,e,i-tree[l]);
    }
    tree[node]=tree[l]+tree[r];
}

int query(int node,int b,int e,int pos)
{
    if(b==e)
    {
        return b;
    }
    int l=2*node;
    int r=1+l;
    int mid=(b+e)/2;
    if(pos<=tree[l])
    {
        return query(l,b,mid,pos);
    }
    else
    {
        return query(r,mid+1,e,pos-tree[l]);
    }
}

int main()
{
    mem(tree,0);
    init(1,1,mx);
    ans[1]=1;
    for(int i=2;i<=100000;i++)
    {
        int val=query(1,1,mx,i);
        ans[i]=val;
        int xx=(mx/val)*val;
//        cout<<val<<endl;
        for(int j=xx;j>=val;j-=val)
        {
            update(1,1,mx,j);
        }
    }

	int t,cas=0;
	getint(t);
	while(t--)
    {
        int n;
        getint(n);
        CASE(cas);
        pf("%d\n",ans[n]);
    }
	return  0;

}
