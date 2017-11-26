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
#define Harmonic(n) (0.577215664901532+log(n)+(1/(2*n)))     ///Use Only for large n
#define mx 1005

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

ll mod=1000000007;

ll nCr[mx][mx],dp[mx][55];

int m,n,k;

void init()
{
    loop(i,mx)
        nCr[i][0]=1;
    for(int i=1;i<mx;i++)
    {
        for(int j=1;j<=i;j++)
            nCr[i][j]=(nCr[i-1][j-1] + nCr[i-1][j])%mod;
    }
}

ll call(int cell,int color)
{
    if(color>cell) return 0;
    if(color==1) return 1;
    ll &ret=dp[cell][color];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=1;i<=cell;i++)
    {
        ll pp=(call(cell-i,color-1) * nCr[cell][i])%mod;
        ret=(ret + pp)%mod;
    }
    return ret;
}

int main()
{
    init();
    mem(dp,-1);
	int t,cas=0;
	getint(t);
	while(t--)
    {
        sf("%d %d %d",&m,&n,&k);
        m++;
        n++;
        CASE(cas);
        if(n==1 && m==1)
        {
            pf("%d\n",k);
            continue;
        }

        int one=(n*m)/2;
        int two=(n*m)-one;

        ll ans=0;

        for(int i=1;i<k;i++)
        {
            ll tmp=(call(one,i) * bigMod((ll)(k-i),(ll)two,mod) )%mod;
            tmp=(tmp * nCr[k][i])%mod;
            ans=(ans + tmp)%mod;
        }

        pf("%lld\n",ans);


    }
	return  0;

}
