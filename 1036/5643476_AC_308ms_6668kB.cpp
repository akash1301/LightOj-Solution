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

int rad[505][505],ura[505][505],rad_cum[505][505],ura_cum[505][505],dp[505][505],r,c;

int call(int i,int j)
{
    if(i<0 || j<0)
        return 0;
    int &ret=dp[i][j];
    if(ret!=-1)
        return ret;
    ret=call(i,j-1)+rad_cum[i][j];
    ret=max(ret,call(i-1,j)+ura_cum[i][j]);
    return ret;
}


int main()
{
	int t,cas=0;
	getint(t);
	while(t--)
    {
        sf("%d %d",&r,&c);
        loop(i,r)
        {
            loop(j,c)
            {
                getint(ura[i][j]);
            }
        }
        loop(i,r)
        {
            loop(j,c)
            {
                getint(rad[i][j]);
            }
        }
        loop(i,r)
        {
            ura_cum[i][0]=ura[i][0];
            for(int j=1;j<c;j++)
            {
                ura_cum[i][j]=ura[i][j]+ura_cum[i][j-1];
            }
        }
        loop(i,c)
        {
            rad_cum[0][i]=rad[0][i];
            for(int j=1;j<r;j++)
            {
                rad_cum[j][i]=rad[j][i]+rad_cum[j-1][i];
            }
        }

        mem(dp,-1);
        CASE(cas);
        pf("%d\n",call(r-1,c-1));

    }
	return  0;

}
