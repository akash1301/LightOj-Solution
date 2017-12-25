/////////////////////// All Is Well /////////////////////////

#include <bits/stdc++.h>

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define CIN   ios_base::sync_with_stdio(0); cin.tie(0)
#define getint(n) scanf("%d", &n)
#define getlong(n) scanf("%lld", &n)
#define pb(a) push_back(a)
#define ll long long int
#define ull unsigned long long int
#define dd double
#define SZ(a) int(a.size())
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define Unique(x)  x.erase(unique(all(x)), x.end())
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
#define mx 100005

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
        return ((ret)*(ret))%MOD;
    }
    else return ((n)*(bigMod(n,power-1,MOD)))%MOD;
}

// ll modInverse(ll n,ll MOD)
// {
//     return bigMod(n,MOD-2,MOD);
// }

ll modInverse(ll a, ll m)
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
       x1 += m0;

    return x1;
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

int k,p;
bool isPrime[mx];
vector<ll>prime;
ll dp[505][505],val[505],data[505][505];

void seive_N_logN(ll N)
{
    ///calculate prime upto N in NlogN time
    memset(isPrime,true,sizeof isPrime);
    prime.clear();

    isPrime[1]=false;
    for (ll i = 4; i<= N; i=i+2)
        isPrime[i]=false;

    for (ll i = 3; i * i<= N; i=i+2)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
    for(ll i=1; i<N; i++)
        if(isPrime[i])
            prime.push_back(i);
}

ll call(int pos,int lef)
{
    if(pos<0)
    {
        return lef==0;
    }
    if(lef<=0) return 0;
    ll &ret=dp[pos][lef];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=1;i<=lef;i++)
    {
        ll pp=(call(pos-1,lef-i)*data[pos][i-1]);
        if(pp>=mod)
            pp%=mod;
        ret+=pp;
        if(ret>=mod)
            ret-=mod;
    }
    return ret;

}

int main()
{
    seive_N_logN(mx-2);

    val[0]=prime[0]-1;
    for(int i=1;i<505;i++)
    {
        val[i]=(val[i-1] * (prime[i]-1));
        if(val[i]>=mod)
            val[i]%=mod;
    }

    loop(i,505)
    {
        loop(j,505)
        {
            data[i][j]=bigMod(prime[i],j,mod);
        }
    }

	int t,cas=0;
    getint(t);
    mem(dp,-1);
    while(t--)
    {
        sf("%d %d",&k,&p);
        p--;
        ll ans=call(p,k);
        ans=(ans * val[p]);
        if(ans>=mod)
            ans%=mod;
        CASE(cas);
        pf("%lld\n",ans);
    }
	return  0;

}
