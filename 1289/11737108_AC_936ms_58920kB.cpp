/////////////////////// All Is Well /////////////////////////

#include <bits/stdc++.h>

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
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
#define getlong(n) scanf("%lld",&n)
#define CASE(n) printf("Case %d: ",++n)
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
//int SET(ll n,int pos){ return n=n | (1LL<<pos);}
//int RESET(ll n,int pos){ return n=n & ~(1LL<<pos);}
//int CHECK(ll n,int pos){ return (bool) (n & (1LL<<pos));}


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

int nP2(int n)
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

const int mx=1e8;

ll prime[(mx/64)+5];
int primeList[5761455+5],sz;
unsigned int dp[5761455+5];

void BitSeive()
{
    ll sq=sqrt(mx);
    for(ll i=3;i<=sq;i+=2)
    {
        if(!(prime[i/64] & (1LL<<(i%64))))
        {
            for(ll j=i*i;j<=mx;j+=i)
                prime[j/64] |=(1LL<<(j%64));
        }
    }
    primeList[sz++]=2;
    for(ll i=3;i<=mx;i+=2)
        if(!(prime[i/64] & (1LL<<(i%64))))
            primeList[sz++]=i;
}

unsigned int fun(int x)
{
    int sq=sqrt(x);
    unsigned int ret=1;
    for(int i=0;primeList[i]<=sq && i<5761455;i++)
    {
        int xx=x/primeList[i];
        unsigned int cnt=1;
        while(xx>=primeList[i])
        {
            xx/=primeList[i];
            cnt*=primeList[i];
        }
        ret*=cnt;
    }
    return ret;
}


int main()
{
    BitSeive();
    int t,cas=0;
    getint(t);
    dp[0]=2;
    for(int i=1;i<sz;i++)
    {
        dp[i]=dp[i-1]*primeList[i];
    }
    while(t--)
    {
        int inp;
        getint(inp);
        unsigned int ans=fun(inp);
        unsigned int p=dp[upper_bound(primeList,primeList+sz,inp)-primeList-1];
        CASE(cas);
        pf("%u\n",ans*p);
    }
    return 0;
}
