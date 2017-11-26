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
int CHECK(ll n,ll pos){ return (bool) (n & (1LL<<pos));}


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

ll mod=100000007;
ll fact[1000005];

ll nCr(ll n,ll r)
{
    ll xx=(fact[n]%mod)*modInverse(fact[r],mod)%mod;
    xx%=mod;
    xx=xx%mod*modInverse(fact[n-r],mod)%mod;
    xx%=mod;
    return xx;
}


int main()
{
    fact[0]=1;
    for(ll i=1;i<=1000000;i++)
    {
        fact[i]=fact[i-1]%mod*i%mod;
        fact[i]%=mod;
    }
	int t,cas=0;
	getint(t);
	while(t--)
    {
        ll k,n;
        vector< pall >vv;
        sf("%lld %lld",&k,&n);
        loop(i,k)
        {
            ll p,q;
            sf("%lld %lld",&p,&q);
            vv.pb(mp(p,q));
        }
        ll mask=(1<<k)-1;
        ll ans=0;
        for(ll i=0;i<=mask;i++)
        {
            ll tot=n,cnt=0;
            for(ll j=0;j<k;j++)
            {
                if(CHECK(i,j))
                {
                    tot-=vv[j].sc+1;
                    cnt++;
                }
                else
                {
                    tot-=vv[j].fr;
                }
            }

            if(tot<0)
                continue;

            if(cnt%2==1)
            {
                ans=ans%mod-nCr(tot+k-1,k-1)%mod;
                ans=MOD(ans,mod);
            }
            else
            {
                ans=ans%mod+nCr(tot+k-1,k-1)%mod;
                ans%=mod;
            }
        }

        CASE(cas);
        pf("%lld\n",ans%mod);
    }

	return  0;

}
