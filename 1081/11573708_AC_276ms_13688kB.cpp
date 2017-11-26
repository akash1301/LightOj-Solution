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
#define CASE(n) printf("Case %d:\n",++n)
#define CASE_COUT cout<<"Case "<<++cas<<": "
#define inf 1000000000
#define EPS 1e-9
#define Harmonic(n) (0.577215664901532+log(n)+(1/(2*n)))     ///Use Only for large n
#define mx 100005

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

int str2int(string s)
{
    stringstream ss(s);
    int x;
    ss >> x;
    return x;
}

string int2str(int a)
{
    stringstream ss;
    ss << a;
    string str = ss.str();
    return str;
}

string char2str(char a)
{
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

ll MOD(ll n,ll mod)
{
    if(n>=0)
        return n%mod;
    else if(-n==mod)
        return 0;
    else
        return mod+(n%mod);
}

int n,q,table[505][505][11],data[505][505];

void init()
{
    loop(i,n)
        loop(j,n)
    table[i][j][0]=data[i][j];

    for(int k=1; (1<<k)<=n; k++)
    {
        for(int i=0; i+(1<<k)-1<n; i++)
        {
            for(int j=0; j+(1<<k)-1<n; j++)
            {
                int p=1<<(k-1);
                table[i][j][k]=max(max(table[i][j][k-1],table[i+p][j][k-1]),max(table[i][j+p][k-1],table[i+p][j+p][k-1]));
            }
        }
    }
}


int main()
{
    int t,cas=0;
    getint(t);
    while(t--)
    {
        sf("%d %d",&n,&q);
        loop(i,n)
        {
            loop(j,n)
                getint(data[i][j]);
        }
        mem(table,0);
        init();
        CASE(cas);
        while(q--)
        {
            int a,b,s;
            sf("%d %d %d",&a,&b,&s);
            int p=log2(s);
            int pp=1<<p;
            a--;
            b--;
            int ans=max(max(table[a][b][p],table[a+s-pp][b][p]),max(table[a][b+s-pp][p],table[a+s-pp][b+s-pp][p]));
            pf("%d\n",ans);
        }
    }
    return  0;

}
