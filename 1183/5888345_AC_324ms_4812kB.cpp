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

const int mx=100005;

struct type
{
    int sum,prop;
}tree[mx*4];

void pushdown(int node,int b,int e)
{
    if(tree[node].prop!=-1)
    {
        int mid=(b+e)/2;
        int xx=tree[node].prop;
        tree[2*node].sum=(mid-b+1)*xx;
        tree[2*node].prop=xx;
        tree[(2*node)+1].sum=(e-mid)*xx;
        tree[(2*node)+1].prop=xx;
        tree[node].prop=-1;
    }
}

void update(int node,int b,int e,int i,int j,int val)
{
    if(b>=i && e<=j)
    {
        tree[node].sum=(e-b+1)*val;
        tree[node].prop=val;
        return ;
    }
    pushdown(node,b,e);
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    if(j<=mid)
    {
        update(l,b,mid,i,j,val);
    }
    else if(i>mid)
    {
        update(r,mid+1,e,i,j,val);
    }
    else
    {
        update(l,b,mid,i,j,val);
        update(r,mid+1,e,i,j,val);
    }
    tree[node].sum=tree[l].sum+tree[r].sum;
}

int query(int node,int b,int e,int i,int j)
{
    if(b>=i && e<=j)
    {
        return tree[node].sum;
    }
    pushdown(node,b,e);
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    int p=0;
    if(j<=mid)
    {
        p=query(l,b,mid,i,j);
    }
    else if(i>mid)
    {
        p=query(r,mid+1,e,i,j);
    }
    else
    {
        p=query(l,b,mid,i,j)+query(r,mid+1,e,i,j);
    }
//    tree[node].sum=tree[l].sum+tree[r].sum;
    return p;
}


int main()
{
	int t,cas=0;
	getint(t);
	while(t--)
    {
        loop(i,mx*4)
        {
            tree[i].sum=0;
            tree[i].prop=-1;
        }
        int n,q;
        sf("%d %d",&n,&q);
        CASE(cas);
        while(q--)
        {
            int ch,x,y,v;
            getint(ch);
            if(ch==1)
            {
                sf("%d %d %d",&x,&y,&v);
                update(1,0,n-1,x,y,v);
            }
            else
            {
                sf("%d %d",&x,&y);
                int xx=query(1,0,n-1,x,y);
                int len=y-x+1;
                int gg=gcd(xx,len);
                xx/=gg;
                len/=gg;
                if(len==1)
                {
                    pf("%d\n",xx);
                }
                else
                {
                    pf("%d/%d\n",xx,len);
                }
            }
        }
    }
	return  0;

}
