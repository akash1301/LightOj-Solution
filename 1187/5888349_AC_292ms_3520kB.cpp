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

int left(int n)
{
    return 2*n;
}

int right(int n)
{
    return (2*n)+1;
}

const int mx=100005;

int tree[4*mx];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=1;
        return ;
    }
    int mid=(b+e)/2;
    init(left(node),b,mid);
    init(right(node),mid+1,e);
    tree[node]=tree[left(node)]+tree[right(node)];
}

int query(int node,int b,int e,int val)
{
    if(b==e)
    {
        tree[node]=0;
        return b;
    }
    int mid=(b+e)/2;
    int p=0;
    if(tree[left(node)]>=val)
        p=query(left(node),b,mid,val);
    else
        p=query(right(node),mid+1,e,val-tree[left(node)]);
    tree[node]=tree[left(node)]+tree[right(node)];
    return p;
}


int main()
{
	int t,cas=0;
	getint(t);
	while(t--)
    {
        mem(tree,0);
        int n;
        getint(n);
        int data[n+10];
        for(int i=1;i<=n;i++)
        {
            getint(data[i]);
        }
        int ans;
        init(1,1,n);
        for(int i=n;i>=1;i--)
        {
            ans=query(1,1,n,i-data[i]);
        }
        CASE(cas);
        pf("%d\n",ans);
    }
	return  0;

}
