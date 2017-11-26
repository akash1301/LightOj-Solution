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

int dp[55][5][7],sz;
string ss;

bool isvowel(char c)
{
    if(c=='A' || c=='E' ||c=='I' ||c=='O'||c=='U')
        return 1;
    return 0;
}

int call(int i,int v,int c)
{
    if(i>=sz)
    {
        if(v>=3 || c>=5)
            return 1;
        return 2;
    }
    if(v>=3 ||c>=5)
        return 1;
    int &ret=dp[i][v][c];
    if(ret!=-1)
        return ret;
    if(ss[i]=='?')
    {
        int ret1,ret2;
        ret1=call(i+1,v+1,0);
        ret2=call(i+1,0,c+1);
        if(ret1==1 && ret2==1)
            ret=1;
        else if(ret1==2 && ret2==2)
        {
            ret=2;
        }
        else
            ret=ret1+ret2;
    }
    else
    {
        int x,y;
        if(isvowel(ss[i]))
        {
            x=v+1;
            y=0;
        }
        else
        {
            y=c+1;
            x=0;
        }
        ret=call(i+1,x,y);
    }
    return ret;
}

int main()
{
	int t,cas=0;
	getint(t);
	getchar();
	while(t--)
    {
        cin>>ss;
//        cout<<ss<<endl;
        sz=ss.size();
        mem(dp,-1);
        int x=call(0,0,0);
        CASE(cas);
        if(x==1)
        {
            pf("BAD\n");
        }
        else if(x==2)
        {
            pf("GOOD\n");
        }
        else
        {
            pf("MIXED\n");
        }
        ss.clear();
    }
	return  0;

}
