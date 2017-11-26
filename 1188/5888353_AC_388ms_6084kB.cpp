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

int pos[mx],data[mx],tree[4*mx];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=1;
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
    if(b==i && e==i)
    {
        tree[node]=0;
        return ;
    }
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    if(mid>=i)
        update(l,b,mid,i);
    else if(i>mid)
        update(r,mid+1,e,i);
    else
    {
        update(l,b,mid,i);
        update(r,mid+1,e,i);
    }
    tree[node]=tree[l]+tree[r];
}

int query(int node,int b,int e,int i,int j)
{
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    if(mid>=j)
    {
        return query(l,b,mid,i,j);
    }
    else if(i>mid)
    {
        return query(r,mid+1,e,i,j);
    }
    else
    {
        return query(l,b,mid,i,j)+query(r,mid+1,e,i,j);
    }
}

int main()
{
	int t,cas=0;
	getint(t);
	while(t--)
    {
        mem(tree,0);
        vector<pair<int, pair<int,int> > >vv;
        vector< paii >ans;
        int n,q;
        sf("%d %d",&n,&q);
        for(int i=1;i<=n;i++)
        {
            getint(data[i]);
            pos[data[i]]=0;
        }
        loop(i,q)
        {
            int x,y;
            sf("%d %d",&x,&y);
            vv.pb(mp(y,mp(x,i)));
        }
        sort(all(vv));
        init(1,1,n);
        int ind=0;
        for(int i=1;i<=n;i++)
        {
            if(pos[data[i]])
            {
                update(1,1,n,pos[data[i]]);
            }
            pos[data[i]]=i;
            while(i==vv[ind].fr)
            {
                int xx=query(1,1,n,vv[ind].sc.fr,vv[ind].fr);
                ans.pb(mp(vv[ind].sc.sc,xx));
                ind++;
            }
        }
        sort(all(ans));
        CASE(cas);
        int sz=ans.size();
        loop(i,q)
        {
            pf("%d\n",ans[i].sc);
        }


    }
	return  0;

}
