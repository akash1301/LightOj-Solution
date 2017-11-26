

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

const int mx=1e6;

bool prime[mx+10];
ll primeList[mx+10],sz,siz,ans,lo,hi;


void seive()
{
    primeList[sz++]=2;
    int sq=sqrt(mx);
    for(int i=3;i<=sq;i+=2)
    {
        if(!prime[i])
        {
            for(int j=i*i;j<=mx;j+=i)
                prime[j]=true;
        }
    }
    for(int i=3;i<=mx;i+=2)
        if(!prime[i])
            primeList[sz++]=i;
}

vector<pair<ll,ll> >divisor;


void divcount(ll a)
{
    ll sq=sqrt(a);
    ll tmp=a;
    ll sum=0;
    for(ll  i=0;i<sz && primeList[i]*primeList[i]<=tmp;i++)
    {
        if(tmp%primeList[i]==0)
        {
            ll cnt=0;
            while(tmp%primeList[i]==0)
            {

                tmp/=primeList[i];
                cnt++;
            }
            divisor.pb(mp(primeList[i],cnt));
        }
    }
    if(tmp>1)
        divisor.pb(mp(tmp,1));
    siz=divisor.size();
}


void call(ll i,ll w)
{
    if(i>=siz)
    {
        if(w>=lo && w<=hi){
            ans++;
        }
        return ;
    }
    ll x=divisor[i].fr;
    ll y=divisor[i].sc;
    for(int j=0;j<=y;j++)
    {
        call(i+1,w);
        w*=x;
    }
}




int main()
{
    seive();
    int t,cas=0;
    getint(t);
    while(t--)
    {
        divisor.clear();
        ll x,y;
        sf("%lld %lld",&x,&y);
        lo=y;
        hi=x/y;
        if(x%y)
            hi++;

        CASE(cas);
        divcount(x);
        ans=0;
        call(0,1);
        pf("%lld\n",ans/2);
    }
    return 0;
}
