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

const int mx=150005;

int tree[4*mx];

void update(int node,int b,int e,int i,int val)
{
    if(b==i && e==i)
    {
        tree[node]+=val;
        return ;
    }
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    if(i<=mid)
    {
        update(l,b,mid,i,val);
    }
    else
    {
        update(r,mid+1,e,i,val);
    }
    tree[node]=tree[l]+tree[r];
}

int query(int node,int b,int e,int pos)
{
    tree[node]--;
    if(b==e)
    {
        return b;
    }
    int l=2*node;
    int r=l+1;
    int mid=(b+e)/2;
    if(pos<=tree[l])
    {
        return query(l,b,mid,pos);
    }
    else
        return query(r,mid+1,e,pos-tree[l]);
}

int main()
{
    int t,cas=0;
    getint(t);
    while(t--)
    {
        vector<int>data;
        mem(tree,0);
        int n,q;
        sf("%d %d",&n,&q);
        int tot=n+q;
        loop(i,n)
        {
            int p;
            getint(p);
            data.pb(p);
            update(1,0,tot-1,i,1);
        }
        int cnt=n,tmp=n;
        CASE(cas);
        if(n==0)
            getchar();
        while(q--)
        {
            char ss;
            int x;
            getchar();
            sf("%c %d",&ss,&x);
//            cout<<ss<<endl;
            if(ss=='c')
            {
                if(x>cnt)
                {
                    pf("none\n");
                }
                else
                {
                    int pp=query(1,0,tot-1,x);
                    pf("%d\n",data[pp]);
                    cnt--;
                }
            }
            else
            {
                cnt++;
                data.pb(x);
                update(1,0,tot-1,tmp,1);
                tmp++;
            }
        }
    }
    return  0;

}
