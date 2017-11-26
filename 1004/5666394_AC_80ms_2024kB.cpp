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

ll data[205][105],dp[205][105];
int n;


ll call(int i,int j)
{
    if(i>=2*n-1 || j<0 || j>=n || data[i][j]==-1)
        return 0;
    ll &ret=dp[i][j];
    if(ret!=-1)
        return ret;
    ret=0;
    ret=call(i+1,j)+data[i][j];
    if(i<n-1)
    {
        ret=max(ret,call(i+1,j+1)+data[i][j]);
    }
    else
    {
        ret=max(ret,call(i+1,j-1)+data[i][j]);
    }
    return ret;
}


int main()
{
	int t,cas=0;
	getint(t);
	while(t--)
	{
	    getint(n);
	    mem(data,-1);
	    for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                sf("%lld",&data[i][j]);
            }
        }
        for(int i=n;i<2*n-1;i++)
        {
            for(int j=0;j<2*n-i-1;j++)
            {
                sf("%lld",&data[i][j]);
            }
        }
        mem(dp,-1);
        CASE(cas);
        pf("%lld\n",call(0,0));

	}
	return  0;

}
