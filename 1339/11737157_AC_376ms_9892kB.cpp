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
    int max_cnt,left_val,left_cnt,right_val,right_cnt;
}tree[4*mx];

int data[mx];


type pushup(type left,type right)
{
//    if(right.left_val==0)
//        return left;
//    if(left.left_val==0)
//        return right;
    type tmp;
    tmp.left_val=left.left_val;
    tmp.right_val=right.right_val;
    if(left.left_val==right.left_val)
    {
        tmp.left_cnt=left.left_cnt+right.left_cnt;
    }
    else
        tmp.left_cnt=left.left_cnt;
    if(left.right_val==right.right_val)
    {
        tmp.right_cnt=left.right_cnt+right.right_cnt;
    }
    else
        tmp.right_cnt=right.right_cnt;
    tmp.max_cnt=max(left.max_cnt,right.max_cnt);
    if(left.right_val==right.left_val)
        tmp.max_cnt=max(tmp.max_cnt,left.right_cnt+right.left_cnt);
    return tmp;

}

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].max_cnt=1;
        tree[node].left_val=data[b];
        tree[node].left_cnt=1;
        tree[node].right_val=data[b];
        tree[node].right_cnt=1;
        return ;
    }
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    init(l,b,mid);
    init(r,mid+1,e);
    tree[node]=pushup(tree[l],tree[r]);
//    cout<<node<<" "<<tree[node].max_val<<" "<<tree[node].max_cnt<<" "<<tree[node].left_val<<" "<<tree[node].left_cnt<<" "<<tree[node].right_val<<" "<<tree[node].right_cnt<<endl;
}

type query(int node,int b,int e,int i,int j)
{
//    if(i>e || j<b)
//    {
//        type tmp;
//        tmp.max_cnt=0;
//        tmp.left_val=0;
//        tmp.left_cnt=0;
//        tmp.right_val=0;
//        tmp.right_cnt=0;
//        return tmp;
//    }
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    if(j<=mid)
    {
        return query(l,b,mid,i,j);
    }
    else if(i>mid)
    {
        return query(r,mid+1,e,i,j);
    }
    else
    {
        type left=query(l,b,mid,i,j);
        type right=query(r,mid+1,e,i,j);
        return pushup(left,right);
    }
}

int main()
{
	int t,cas=0;
	getint(t);
	while(t--)
    {
        int n,c,q;
        sf("%d %d %d",&n,&c,&q);
        for(int i=1;i<=n;i++)
        {
            getint(data[i]);
        }
        mem(tree,0);
        init(1,1,n);
//        cout<<tree[1].max_cnt<<" "<<tree[1].max_val<<endl;
        CASE(cas);
        while(q--)
        {
            int x,y;
            sf("%d %d",&x,&y);
            type xx=query(1,1,n,x,y);
            pf("%d\n",xx.max_cnt);
        }
    }
	return  0;

}
