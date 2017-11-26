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
 
ll POW(ll x, ll y)
{
    ll res= 1;
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
 
ll mx=10000000000;
vector<ll>data;
int sz;
ll mod=100000007;
 
 
int BS(ll x)
{
    int lo=0,hi=sz-1;
    int mid=(lo+hi)/2;
    int ans;
    while(lo<=hi)
    {
        if(data[mid]>x)
        {
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
            ans=mid;
        }
        mid=(hi+lo)/2;
    }
    return ans;
}
 
ll dp[102750];
 
ll catalan(int n)
{
    if(n<=1)
        return 1;
    ll &ret=dp[n];
    if(ret!=-1)
        return ret;
    ret=0;
    for(int i=0; i<n; i++)
    {
        ret=ret%mod + (catalan(i)%mod*catalan(n-i-1)%mod)%mod;
        ret%=mod;
    }
    return ret;
}
map<ll,int>mapa;
 
int main()
{
//    for(int i=3;i<=20;i+=3)
//        vv.pb(i);
//    cout<<BS(13)<<endl;
    for(ll i=2;; i++)
    {
        for(ll j=2;; j++)
        {
            ll x=POW(i,j);
            if(x>mx)
                break;
            if(!mapa[x])
            {
                data.pb(x);
                mapa[x]=1;
            }
        }
        if(POW(i,2)>mx)
            break;
    }
    sort(all(data));
    sz=data.size();
//    cout<<data[sz-1]<<endl;
    int t,cas=0;
    getint(t);
    mem(dp,-1);
    while(t--)
    {
        ll a,b;
        sf("%lld %lld",&a,&b);
        int xx;
        if(a<4|| a>data[sz-1])
        {
            if(a<4)
                xx=0;
            else
                xx=sz-1;
        }
        else
            xx=BS(a);
        if(data[xx]<a)
            xx++;
        int yy;
        if(b<4 || b>data[sz-1])
        {
            if(b<4)
                yy=-1;
            else
                yy=sz-1;
        }
        else
            yy=BS(b);
//        cout<<xx<<" "<<yy<<endl;
        CASE(cas);
        if(xx>yy)
        {
            pf("0\n");
            continue;
        }
        ll ans=catalan(yy-xx+1);
        pf("%lld\n",ans%mod);
    }
    return  0;
 
}