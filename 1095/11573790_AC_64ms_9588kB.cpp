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

ll mod=1000000007;

ll dp[1005][1005],dp2[1005];


ll nCr(ll n,ll r)
{
    if(r==1)
        return n;
    if(n==r || r==0)
        return 1;
    ll &ret=dp[n][r];
    if(ret!=-1)
        return ret;
    ret=(nCr(n-1,r-1)%mod+nCr(n-1,r)%mod)%mod;
    return ret;
}

ll call(ll n)
{
    if(n==2 || n==0)
        return 1;
    if(n==1)
        return 0;
    ll &ret=dp2[n];
    if(ret!=-1)
        return ret;
    ret=(n-1)%mod*(call(n-1)%mod+call(n-2)%mod)%mod;
    ret%=mod;
    return ret;
}

int main()
{
	int t,cas=0;
	getint(t);
	mem(dp,-1);
	mem(dp2,-1);
	while(t--)
    {
        ll n,m,k;
        sf("%lld %lld %lld",&n,&m,&k);
        ll ans=0;
        for(ll i=0;i<=n-m;i++)
        {
            ans+=(nCr(n-m,i)%mod*call(n-k-i)%mod)%mod;
//            cout<<ans<<" "<<nCr(n-m,i)<<" "<<call(n-k-i)<<endl;
        }
        ans=(ans%mod*nCr(m,k)%mod)%mod;
        CASE(cas);
        pf("%lld\n",ans);
    }
	return  0;

}
