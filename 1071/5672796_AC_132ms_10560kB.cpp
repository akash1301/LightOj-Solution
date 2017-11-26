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

int dp[205][105][105],n,m,data[105][105];


int call(int stp,int r1,int r2)
{
    int c1=stp-r1;
    int c2=stp-r2;
    if(r1>=m ||r2>=m ||c1>=n ||c2>=n)
        return -inf;
    if(r1==m-1 && c1==n-1 && r2==m-1 && c2==n-1)
        return data[r1][c1];
    if(r1==r2 && c1==c2)
        return -inf;
    int &ret=dp[stp][r1][r2];
    if(ret!=-1)
        return ret;
    ret=max(max(call(stp+1,r1+1,r2+1),call(stp+1,r1,r2)),max(call(stp+1,r1+1,r2),call(stp+1,r1,r2+1)))+data[r1][c1]+data[r2][c2];
    return ret;
}

int main()
{
	int t,cas=0;
	getint(t);
	while(t--)
    {
        sf("%d %d",&m,&n);
        loop(i,m)
        {
            loop(j,n)
            {
                cin>>data[i][j];
            }
        }
        mem(dp,-1);
        CASE(cas);
        pf("%d\n",call(1,1,0)+data[0][0]);
    }
	return  0;

}
