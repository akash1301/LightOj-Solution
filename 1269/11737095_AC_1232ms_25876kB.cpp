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

int str2int(string s) {
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}

string int2str(int a) {
	stringstream ss;
	ss << a;
	string str = ss.str();
	return str;
}

string char2str(char a) {
	stringstream ss;
	ss << a;
	string str = ss.str();
	return str;
}

ll bigMod(ll n,ll power,ll MOD)
{
    if(power==0)
        return 1;
    if(power%2==0)
    {
        ll ret=bigMod(n,power/2,MOD);
        return ((ret%MOD)*(ret%MOD))%MOD;
    }
    else return ((n%MOD)*(bigMod(n,power-1,MOD)%MOD))%MOD;
}

ll modInverse(ll n,ll MOD)
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

ll MOD(ll n,ll mod)
{
    if(n>=0)
        return n%mod;
    else if(-n==mod)
        return 0;
    else
        return mod+(n%mod);
}

struct node
{
    node *next[2];
    node()
    {
        loop(i,2)
            next[i]=NULL;
    }
}*root;

void Insert(int val)
{
    node *cur=root;
    for(int i=31;i>=0;i--)
    {
        int pp=CHECK(val,i);
        if(cur->next[pp]==NULL)
            cur->next[pp]=new node();
        cur=cur->next[pp];
    }
}

int query_max(int val)
{
    node *cur=root;
    int ans=0;
    for(int i=31;i>=0;i--)
    {
        int pp=CHECK(val,i);
        int ulta= pp^1;
        if(cur->next[ulta])
        {
            ans=SET(ans,i);
            cur=cur->next[ulta];
        }
        else
        {
            cur=cur->next[pp];
        }
    }
    return ans;
}


int query_min(int val)
{
    node *cur=root;
    int ans=0;
    for(int i=31;i>=0;i--)
    {
        int pp=CHECK(val,i);
        int ulta= pp^1;
        if(cur->next[pp])
        {
            cur=cur->next[pp];
        }
        else
        {
            cur=cur->next[ulta];
            ans=SET(ans,i);
        }
    }
    return ans;
}

void del(node *cur)
{
    loop(i,2)
    {
        if(cur->next[i])
            del(cur->next[i]);
    }
    delete(cur);
}

int main()
{
	int t,cas=0;
	getint(t);
	while(t--)
    {
        root=new node();
        Insert(0);
        int n,tot=0,mn=INT_MAX,mx=0;
        getint(n);
        loop(i,n)
        {
            int p;
            getint(p);
            tot ^=p;
            mn=min(mn,query_min(tot));
            Insert(tot);
            mx=max(mx,query_max(tot));
        }

        CASE(cas);
        pf("%d %d\n",mx,mn);
        del(root);
    }
	return  0;

}
