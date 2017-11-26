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
 
dd ax,ay,az,bx,by,bz,x,y,z;
 
dd sq(dd xx)
{
    return (xx)*(xx);
}
 
 
dd dis3d(dd x1,dd y1,dd z1,dd x2,dd y2,dd z2)
{
    return sqrt(sq(x1-x2)+sq(y1-y2)+sq(z1-z2));
}
 
dd func(dd r)
{
    dd x1=ax+(bx-ax)*r;
    dd y1=ay+(by-ay)*r;
    dd z1=az+(bz-az)*r;
    return dis3d(x1,y1,z1,x,y,z);
}
 
dd BS(dd left,dd right)
{
    loop(i,500)
    {
        dd l=(2*left+right)/3.0;
        dd r=(2*right+left)/3.0;
        if(func(l)<func(r))
            right=r;
        else
            left=l;
    }
    return left;
}
 
int main()
{
    int t,cas=0;
    getint(t);
    while(t--)
    {
        sf("%lf %lf %lf %lf %lf %lf %lf %lf %lf",&ax,&ay,&az,&bx,&by,&bz,&x,&y,&z);
        CASE(cas);
        dd ans=BS(0.0,1.0);
        pf("%.10lf\n",func(ans));
    }
    return  0;
 
}