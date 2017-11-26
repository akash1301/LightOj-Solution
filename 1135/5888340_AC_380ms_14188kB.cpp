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
int SET(int n,int pos)
{
    return n=n | (1<<pos);
}
int RESET(int n,int pos)
{
    return n=n & ~(1<<pos);
}
int CHECK(int n,int pos)
{
    return (bool) (n & (1<<pos));
}


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
    for ( ; y ; )
    {
        if ( (y&1) )
        {
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
    ll prop,one,two,zero;
} tree[4*mx];

void pushdown(int node)
{
    if(tree[node].prop>0)
    {
        ll v=tree[node].prop%3;
        int l=2*node;
        int r=l+1;
        if(v==1)
        {
            ll tmp=tree[l].zero;
            ll tmp2=tree[l].one;
            tree[l].zero=tree[l].two;
            tree[l].one=tmp;
            tree[l].two=tmp2;

            tmp=tree[r].zero;
            tmp2=tree[r].one;
            tree[r].zero=tree[r].two;
            tree[r].one=tmp;
            tree[r].two=tmp2;
        }
        else if(v==2)
        {
            ll tmp=tree[l].zero;
            ll tmp2=tree[l].one;
            tree[l].one=tree[l].two;
            tree[l].two=tmp;
            tree[l].zero=tmp2;

            tmp=tree[r].zero;
            tmp2=tree[r].one;
            tree[r].one=tree[r].two;
            tree[r].two=tmp;
            tree[r].zero=tmp2;
        }
        tree[l].prop+=tree[node].prop;
        tree[r].prop+=tree[node].prop;
        tree[node].prop=0;
    }
}

void pushup(int node)
{
    int l=2*node;
    int r=l+1;
    tree[node].zero=tree[l].zero+tree[r].zero;
    tree[node].one=tree[l].one+tree[r].one;
    tree[node].two=tree[l].two+tree[r].two;
}

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].zero=1;
        return ;
    }
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    init(l,b,mid);
    init(r,mid+1,e);
    tree[node].zero=tree[l].zero+tree[r].zero;
}

void update(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
        tree[node].prop++;
        ll tmp=tree[node].zero;
        ll tmp2=tree[node].one;
        tree[node].zero=tree[node].two;
        tree[node].one=tmp;
        tree[node].two=tmp2;
        return ;
    }
    pushdown(node);
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    update(l,b,mid,i,j);
    update(r,mid+1,e,i,j);
    pushup(node);
}

ll query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
    {
        return tree[node].zero;
    }
    pushdown(node);
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    ll xx=query(l,b,mid,i,j);
    ll yy=query(r,mid+1,e,i,j);
    pushup(node);
    return xx+yy;
}

int main()
{
    int t,cas=0;
    getint(t);
    while(t--)
    {
        loop(i,4*mx)
        {
            tree[i].prop=0;
            tree[i].one=0;
            tree[i].two=0;
            tree[i].zero=0;
        }
        int n,q;
        sf("%d %d",&n,&q);
        CASE(cas);
        init(1,0,n-1);
        while(q--)
        {
            int p,x,y;
            sf("%d %d %d",&p,&x,&y);
            if(!p)
            {
                update(1,0,n-1,x,y);
//                pf("%lld\n",query(1,0,n-1,x,y));
            }
            else
            {
                pf("%lld\n",query(1,0,n-1,x,y));
            }
        }
    }
    return  0;

}
