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

int data[20],val[20];

ll dp[20][5][5];
int len;


ll call(int i,int small,int pore)
{
    if(i==(len+1)/2)
    {
        if(pore) return small;
        return 1;
    }
    ll &ret=dp[i][small][pore];
    if(ret!=-1) return ret;
    ret=0;
    if(small)
    {
        ret+=10*call(i+1,1,0);
        return ret;
    }
    ret=0;
    int j , s = ( i==0 && len>1) ? 1 : 0;
    for(j=s;j<data[i];j++)
    {
        ret+=call(i+1,1,0);
    }

    if(j<data[len-i-1])
        ret+=call(i+1,0,0);
    else if(j==data[len-i-1])
        ret+=call(i+1,0,pore);
    else
        ret+=call(i+1,0,1);

    return ret;
}


ll solve(ll p)
{
    if(p==0) return 1;
    if(p<10) return p+1;
    int cnt=0;
    while(p)
    {
        val[cnt++]=p%10;
        p/=10;
    }
    reverse(val,val+cnt);
    ll ans=0;
    loop(i,cnt-1)
    {
        data[i]=9;
        len=i+1;
        mem(dp,-1);
        ans+=call(0,0,0);
    }
    loop(i,cnt)
        data[i]=val[i];
    mem(dp,-1);
    len=cnt;
    ans+=call(0,0,0);
    return ans;

}


int main()
{
//    data[0]=9;
//    data[1]=9;
//    data[2]=9;
//    mem(dp,-1);
//    len=3;
//    cout<<call(0,0,0)<<endl;
	int t,cas=0;
	getint(t);
	while(t--)
    {
        ll a,b;
        sf("%lld %lld",&a,&b);
        CASE(cas);
        if(b<a) swap(a,b);
        pf("%lld\n",solve(b)-solve(a-1));
    }
	return  0;

}
