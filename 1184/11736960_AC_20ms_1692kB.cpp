

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

int man[55][4],woman[55][4],matching[55],vis[55],m,w;


bool Bmatching(int u)
{
    for(int i=0;i<w;i++)
    {
        if(abs(man[u][0]-woman[i][0])<=12 && abs(man[u][1]-woman[i][1])<=5 && man[u][2]==woman[i][2])
        {
            if(vis[i])
                continue;
            vis[i]=1;
            if(matching[i]==-1 || Bmatching(matching[i]))
            {
//                cout<<u<<" "<<i<<endl;
                matching[i]=u;
                return true;
            }
        }
    }
    return false;
}


int main()
{
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        cin>>m>>w;
        loop(i,m)
        {
            cin>>man[i][0]>>man[i][1]>>man[i][2];
        }
        loop(i,w)
        {
            cin>>woman[i][0]>>woman[i][1]>>woman[i][2];
        }
        mem(matching,-1);
        int ans=0;
        loop(i,m)
        {
            mem(vis,0);
            if(Bmatching(i))
            {
                ans++;
            }
        }
        CASE(cas);
        cout<<ans<<endl;
    }
    return 0;
}
