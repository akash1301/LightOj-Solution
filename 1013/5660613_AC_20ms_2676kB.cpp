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

int POW(int x, int y)
{
    int res= 1;
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

int dp[50][50],sz1,sz2,ans;
ll dp2[50][50][50];
string s1,s2;

int call(int i,int j)
{
    if(i>=sz1 || j>=sz2)
        return 0;
    int &ret=dp[i][j];
    if(ret!=-1)
        return ret;
    ret=0;
    if(s1[i]==s2[j])
    {
        ret=call(i+1,j+1)+1;
    }
    else
        ret=max(call(i+1,j),call(i,j+1));
    return ret;
}

ll findans(int i,int j,int len)
{
    if(i>=sz1 || j>=sz2)
    {
        len+=(sz1-i)+(sz2-j);
        if(len==ans)
            return 1;
        return 0;

    }
    ll &ret1=dp2[i][j][len];
    if(ret1!=-1)
        return ret1;
    ret1=0;
    if(s1[i]==s2[j])
    {
        ret1=findans(i+1,j+1,len+1);
    }
    else
    {
        ret1=findans(i+1,j,len+1)+findans(i,j+1,len+1);
    }
    return ret1;

}

int main()
{
    int t,cas=0;
    getint(t);
    while(t--)
    {
        cin>>s1>>s2;
        sz1=s1.size();
        sz2=s2.size();
        mem(dp,-1);
        mem(dp2,-1);
        CASE(cas);
        ans=sz1+sz2-call(0,0);
        pf("%d %lld\n",ans,findans(0,0,0));
        s1.clear();
        s2.clear();
    }
    return  0;

}
