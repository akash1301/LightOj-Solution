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

int r,c,mask_val[10],dp[9][(1<<8)+1][(1<<8)+1];


int call(int i,int prev_mask,int mask)
{
    if(i>=r)
    {
        if(prev_mask==((1<<c)-1)) return 0;
        return  inf;
    }
    int &ret=dp[i][prev_mask][mask];
    if(ret!=-1) return ret;
    ret=inf;
    for(int j=0;j<(1<<c);j++)
    {
        int val[3]={prev_mask,mask,mask_val[i+1]};
        int step=0;
        loop(k,c)
        {
            if(!CHECK(j,k)) continue;
            step++;
            loop(o,3)
                val[o] ^=(1<<k);
            if(k+1<c)
            {
                loop(o,3)
                    val[o] ^=(1<<(k+1));
            }
            if(k-1>=0)
            {
                loop(o,3)
                    val[o] ^=(1<<(k-1));
            }
        }
        if(i==0)
            ret=min(ret,call(i+1,val[1],val[2])+step);
        else if(val[0]==((1<<c)-1))
            ret=min(ret,call(i+1,val[1],val[2])+step);
    }
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
            getchar();
            int mask=0;
            loop(j,c)
            {
                char c;
                sf("%c",&c);
                if(c=='*')
                    mask|=(1<<j);
            }
            mask_val[i]=mask;
        }
        mem(dp,-1);
        CASE(cas);
        int xx=call(0,0,mask_val[0]);
        if(xx>=inf)
            pf("impossible\n");
        else
            pf("%d\n",xx);

    }
	return  0;

}
