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
const int mx=150005;

struct type
{
    int sum,prop;
}tree[mx*4];

vector< paii >v;
vector<int>val,qq;
map<int,int>mapa;

void update(int node,int b,int e,int i,int j,int prop)
{
    if(b>=i && e<=j)
    {
        tree[node].sum+=(e-b+1)*prop;
        tree[node].prop+=prop;
        return ;
    }
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    if(j<=mid)
    {
        update(l,b,mid,i,j,prop);
    }
    else if(i>mid)
    {
        update(r,mid+1,e,i,j,prop);
    }
    else
    {
        update(l,b,mid,i,j,prop);
        update(r,mid+1,e,i,j,prop);
    }
    tree[node].sum=tree[l].sum+tree[r].sum+(e-b+1)*tree[node].prop;
}
int query(int node,int b,int e,int i,int carry)
{
    if(b==i && e==i)
    {
        return tree[node].sum+(e-b+1)*carry;
    }
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    if(i<=mid)
    {
        return query(l,b,mid,i,carry+tree[node].prop);
    }
    else
    {
        return query(r,mid+1,e,i,carry+tree[node].prop);
    }
}

int main()
{
	int t,cas=0;
	getint(t);
	while(t--)
    {
        mem(tree,0);
        int n,q;
        sf("%d %d",&n,&q);
        loop(i,n)
        {
            int p,qu;
            sf("%d %d",&p,&qu);
            v.pb(mp(p,qu));
            val.pb(p);
            val.pb(qu);
        }

        loop(i,q)
        {
            int p;
            getint(p);
            val.pb(p);
            qq.pb(p);
        }

        sort(all(val));
        int sz=val.size();
        int cnt=0;
        loop(i,sz)
        {
            if(i>0 && val[i]==val[i-1])
                mapa[val[i]]=mapa[val[i-1]];
            else
                mapa[val[i]]=++cnt;
        }
        cnt+=2;

//        loop(i,sz)
//        {
//            cout<<val[i]<<" "<<mapa[val[i]]<<endl;
//        }

        loop(i,n)
        {
            int xx=v[i].fr;
            int yy=v[i].sc;
//            cout<<mapa[xx]<<" "<<mapa[yy]<<endl;
            update(1,1,cnt,mapa[xx],mapa[yy],1);
        }
        CASE(cas);
        loop(i,q)
        {
            pf("%d\n",query(1,1,cnt,mapa[qq[i]],0));
        }
        v.clear();
        val.clear();
        qq.clear();
        mapa.clear();
    }
	return  0;

}
