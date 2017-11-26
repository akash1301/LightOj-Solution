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

vector<long long>data,data2;

long long  mx=1000000000000;

void init()
{
    data.pb(4);
    data.pb(7);
    int i=0;
    for(;;i++)
    {
        ll pp=10*data[i]+4;
        ll qq=10*data[i]+7;
        if(pp>mx)
            break;
        data.pb(pp);
        if(qq>mx)
            break;
        data.pb(qq);
    }
}

bool check(ll xx)
{
    while(xx)
    {
        int x=xx%10;
        if(x!=4 && x!=7)
            return 1;
        xx/=10;
    }
    return 0;
}


int call(int i,long long gun)
{
    if(gun>1)
    {
        data2.pb(gun);
    }
    for(int j=i;j<data.size();j++)
    {
        if(gun<=mx/data[j])
            call(j,gun*data[j]);
        else
            break;
    }
}


int main()
{
    init();
    call(0,1);
    int sz=data2.size();
    loop(i,sz)
    {
        data.pb(data2[i]);
    }
    sort(all(data));
    data.erase(unique(all(data)),data.end());
	int t,cas=0;
    getint(t);
    while(t--)
    {
        ll a,b;
        sf("%lld %lld",&a,&b);
        int hi=upper_bound(all(data),b)-data.begin();
        int lo=lower_bound(all(data),a)-data.begin();
        CASE(cas);
        pf("%d\n",hi-lo);
    }
	return  0;

}
