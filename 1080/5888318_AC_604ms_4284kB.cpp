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
#define CASE_COUT cout<<"Case "<<++cas<<":"<<endl
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
    int sum,prop;
}tree[300005];

int sz;
string ss;

void update(int node,int b,int e,int i,int j,int val)
{
    if(b>j || e<i)
        return;
    if(b>=i && e<=j)
    {
        tree[node].sum+=(e-b+1)*val;
        tree[node].prop+=val;
        return;
    }
    int left=2*node;
    int right=left+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*val;
}

int query(int node,int b,int e,int i,int j,int carry)
{
    if(b>j || e<i)
        return 0;
    if(b>=i && e<=j)
    {
        return tree[node].sum+(e-b+1)*carry;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j,carry+tree[node].prop);
    int p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p1 + p2;
}


int main()
{
//    CIN;
	int t,cas=0;
	getint(t);
	while(t--)
    {
        mem(tree,0);
        ss.clear();
        getchar();
        getline(cin,ss);
        sz=ss.size();
        loop(i,sz)
        {
            if(ss[i]=='1')
            {
                update(1,1,sz,i+1,i+1,1);
            }
        }
        int q;
        getint(q);
        CASE(cas);
        while(q--)
        {
            char x;
            int  a,b;
            getchar();
            sf("%c",&x);
            if(x=='I')
            {
                sf("%d %d",&a,&b);
                update(1,1,sz,a,b,1);
            }
            else
            {
                getint(a);
                int xx=query(1,1,sz,a,a,0);
                if(xx & 1)
                    pf("1\n");
                else
                    pf("0\n");
            }
        }
    }
	return  0;

}
