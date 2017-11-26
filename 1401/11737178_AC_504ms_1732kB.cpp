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
#define mx 100005

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

string ss;
int n,dp[105][5][5];

int Grundy(int len,int samne,int pichone)
{
    if(len==0) return 0;
    int &ret=dp[len][samne][pichone];
    if(ret!=-1) return ret;
    set<int>sata;
    for(int i=1;i<=len;i++)
    {
        for(int j=1;j<=2;j++)
        {
            if(i==1 && samne==j) continue;
            if(i==len && pichone==j) continue;
            int tmp=Grundy(i-1,samne,j) ^ Grundy(len-i,pichone,j);
            sata.insert(tmp);
        }
    }
    int mn=0;
    while(sata.find(mn) != sata.end())
        mn++;
    return ret=mn;
}

int main()
{
	int t,cas=0;
	getint(t);
	mem(dp,-1);
	while(t--)
    {
        ss.clear();
        cin>>ss;
        n=ss.size();
        int last=0,samne=0,pichone=0,ans=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            if(ss[i]=='X')
                pichone=1;
            if(ss[i]=='O')
                pichone=2;
            if(ss[i]!='.')
            {
                ans ^=Grundy(i-last,samne,pichone);
                last=i+1;
                samne=pichone;
                cnt++;
            }
        }
        ans ^=Grundy(n-last,samne,0);
        if(cnt & 1)
        {
            if(ans)
                ans=0;
            else
                ans=1;
        }
        CASE(cas);
        if(ans)
            pf("Yes\n");
        else
            pf("No\n");
    }
	return  0;

}
