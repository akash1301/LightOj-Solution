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

ll gc;

pall ExtendedEuclid(ll a, ll b)  /// returns x, y | ax + by = gcd(a,b)
{
    if(b == 0)
    {
        gc=a;
        return mp(1, 0);
    }
    else
    {
        pall d = ExtendedEuclid(b, a % b);
        return mp(d.second, d.first - d.second * (a / b));
    }
}


int main()
{
	int t,cas=0;
	getint(t);
	while(t--)
    {
        ll a,b,c,x1,x2,y1,y2;

        sf("%lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&x1,&x2,&y1,&y2);

        c=-c;
        if(a<0)
        {
            a=-a;
            ll tmp=x1;
            x1=-x2;
            x2=-tmp;
        }

        if(b<0)
        {
            b=-b;
            ll tmp=y1;
            y1=-y2;
            y2=-tmp;
        }
        CASE(cas);

        pall ans=ExtendedEuclid(a,b);

        if(gc && c%gc!=0)
        {
            pf("0\n");
            continue;
        }

        if(a==0 && b==0)
        {
            if(c==0)
            {
                pf("%lld\n",(x2-x1+1)*(y2-y1+1));
            }
            else
                pf("0\n");
            continue;
        }

        if(a==0)
        {
            if(c/b>=y1 && c/b<=y2)
            {
                pf("%lld\n",(x2-x1+1));
            }
            else
                pf("0\n");
            continue;
        }

        if(b==0)
        {
            if(c/a>=x1 && c/a<=x2)
            {
                pf("%lld\n",(y2-y1+1));
            }
            else
                pf("0\n");
            continue;
        }

        ans.fr*=(c/gc);
        ans.sc*=(c/gc);

        ll x=ans.fr;
        ll y=ans.sc;

        a/=gc;
        b/=gc;

        ll t1=ceil((dd)(x1-x)/(dd)b);
        ll t11=floor((dd)(y-y1)/(dd)a);
        ll t2=ceil((dd)(y-y2)/(dd)a);
        ll t22=floor((dd)(x2-x)/(dd)b);

        ll mn=max(t1,t2);
        ll mx=min(t11,t22);

        if(mn>mx)
        {
            pf("0\n");
            continue;
        }

        pf("%lld\n",mx-mn+1);

    }
	return  0;

}
