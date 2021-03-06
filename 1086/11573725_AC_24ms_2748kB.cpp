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
#define Harmonic(n) (0.577215664901532+log(n)+(1/(2*n)))     ///Use Only for large n

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

int n,m,deg[20],sz;
vector<int>oddnode;
ll dp[(1<<17)+1],dis[20][20];


ll call(int mask)
{
    if(mask==((1<<sz)-1))
       return 0;
    ll &ret=dp[mask];
    if(ret!=-1) return ret;
    ret=inf;
    loop(i,sz)
    {
        if(CHECK(mask,i)) continue;
        mask=SET(mask,i);
        loop(j,sz)
        {
            if(CHECK(mask,j)) continue;
            ret=min(ret,dis[oddnode[i]][oddnode[j]]+call(SET(mask,j)));
        }
        break;
    }
    return ret;
}

void clr()
{
    loop(i,20)
    {
        loop(j,20)
        {
            dis[i][j]=inf;
        }
        dis[i][i]=0;
        deg[i]=0;
    }
    oddnode.clear();
}

int main()
{
	int t,cas=0;
	getint(t);
	while(t--)
    {
        clr();
        sf("%d %d",&n,&m);
        ll tot=0;
        loop(i,m)
        {
            int a,b;
            ll c;
            sf("%d %d %lld",&a,&b,&c);
            dis[a][b]=dis[b][a]=min(dis[a][b],c);
            deg[a]++;
            deg[b]++;
            tot+=c;
        }

        for(int i=1;i<=n;i++)
        {
            if(deg[i] & 1)
            {
                oddnode.pb(i);
            }
        }

        CASE(cas);

        if(oddnode.size()==0)
        {
            pf("%lld\n",tot);
            continue;
        }

        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }

        mem(dp,-1);
        sz=oddnode.size();

        ll ans=call(0);
        pf("%lld\n",tot+ans);

    }

	return  0;

}
