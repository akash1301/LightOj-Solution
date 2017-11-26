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
#define CASE(n) printf("Case %d:\n",++n)
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

struct type
{
    ll sum,prop;
}tree[300005];

void update(int node,int b,int e,int i,int j,ll val)
{
    if(i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
        tree[node].sum+=((e-b+1)*val);
        tree[node].prop+=val;
        return ;
    }
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    if(j<=mid)
    update(l,b,mid,i,j,val);
    else if(i>mid)
    update(r,mid+1,e,i,j,val);
    else
    {
        update(l,b,mid,i,j,val);
        update(r,mid+1,e,i,j,val);
    }
    tree[node].sum=tree[l].sum+tree[r].sum+(e-b+1)*tree[node].prop;
}

ll query(int node,int b,int e,int i,int j,ll carry)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
    {
        return tree[node].sum+(e-b+1)*carry;
    }
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    if(j<=mid)
        return query(l,b,mid,i,j,carry+tree[node].prop);
    else if(i>mid)
        return query(r,mid+1,e,i,j,carry+tree[node].prop);
    else{
    ll pp=query(l,b,mid,i,j,carry+tree[node].prop);
    ll qq=query(r,mid+1,e,i,j,carry+tree[node].prop);
    return pp+qq;
    }
}


int main()
{
	int t,cas=0;
	getint(t);
	while(t--)
    {
        loop(i,300005)
        {
            tree[i].sum=0;
            tree[i].prop=0;
        }
        int n,q;
        sf("%d %d",&n,&q);
        CASE(cas);
        while(q--)
        {
            int x,y,z;
            sf("%d %d %d",&x,&y,&z);
            if(!x)
            {
                ll pp;
                sf("%lld",&pp);
                update(1,1,n,y+1,z+1,pp);
            }
            else
            {
                pf("%lld\n",query(1,1,n,y+1,z+1,0));
            }
        }

    }
	return  0;

}
