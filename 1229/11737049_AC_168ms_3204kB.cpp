/////////////////////// All Is Well /////////////////////////

#include <bits/stdc++.h>

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define CIN   ios_base::sync_with_stdio(0); cin.tie(0)
#define getint(n) scanf("%d", &n)
#define getlong(n) scanf("%lld", &n)
#define pb(a) push_back(a)
#define ll long long int
#define ull unsigned long long int
#define dd double
#define SZ(a) int(a.size())
#define read() freopen("input.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define Unique(x)  x.erase(unique(all(x)), x.end())
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

// ll modInverse(ll n,ll MOD)
// {
//     return bigMod(n,MOD-2,MOD);
// }

ll modInverse(ll a, ll m)
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;

    if (m == 1)
      return 0;

    while (a > 1)
    {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
       x1 += m0;

    return x1;
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

int dp[205][205][3][3],lefnxt[205],rtnxt[205],vis[205];
vector<int>data;

string ss;

int Grundy(int lef,int rt,int l,int r)
{
    if(lef>rt) return 0;
    int &ret=dp[lef][rt][l][r];
    if(ret!=-1) return ret;
    int x=lef,y=rt;
    if(l)
        x+=2;
    if(r)
        y-=2;
    set<int>sata;
    for(int i=x;i<=y;i++)
    {
        int tmp=Grundy(lef,i-1,l,1) ^ Grundy(i+1,rt,1,r);
        sata.insert(tmp);
    }
    int mn=0;
    while(sata.find(mn)!=sata.end())
        mn++;
    return ret=mn;
}

bool check()
{
    int sz=ss.size();
    for(int i=0;i<ss.size();i++)
    {
        if(ss[i]=='X') continue;
        if(i-1>=0 && i+1<sz && ss[i+1]=='X' && ss[i-1]=='X')
            return 1;
        if(i+2<sz && i+1<sz && ss[i+1]=='X' && ss[i+2]=='X')
            return 1;
        if(i-2>=0 && i-1>=0 && ss[i-1]=='X' && ss[i-2]=='X')
            return 1;
    }
    return 0;
}


void critical()
{
    int sz=ss.size();
    for(int i=0;i<ss.size();i++)
    {
        if(ss[i]=='X') continue;
        if(i-1>=0 && i+1<sz && ss[i+1]=='X' && ss[i-1]=='X'){
            data.pb(i+1);
        }
        else if(i+2<sz && i+1<sz && ss[i+1]=='X' && ss[i+2]=='X'){
            data.pb(i+1);
        }
        else if(i-2>=0 && i-1>=0 && ss[i-1]=='X' && ss[i-2]=='X'){
            data.pb(i+1);
        }
    }
}


int solve()
{
    if(check()) return 0;
    int pos=-1,ans=0;
    for(int i=0;i<ss.size();i++)
    {
        if(ss[i]=='X')
        {
            int l=1;
            if(pos==-1)
                l=0;
            ans^=Grundy(pos+1,i-1,l,1);
            pos=i;
        }
    }
    if(pos<ss.size()-1)
    {
        int l=1;
        if(pos==-1)
            l=0;
        ans^=Grundy(pos+1,(int)ss.size()-1,l,0);
    }
    return ans==0;
}

int main()
{
//    read();
//    write();
	int t,cas=0;
	getint(t);
	mem(dp,-1);
	while(t--)
    {
        data.clear();
        ss.clear();
        cin>>ss;

        CASE(cas);

        if(check())
        {
            critical();
            loop(i,data.size())
            {
                pf("%d",data[i]);
                if(i<data.size()-1)
                    pf(" ");
            }
            pf("\n");
            continue;
        }

        loop(i,ss.size())
        {
            if(ss[i]=='X') continue;

            ss[i]='X';
            if(solve())
                data.pb(i+1);
            ss[i]='.';
        }

        if(data.size()==0)
        {
            pf("0\n");
            continue;
        }

        loop(i,data.size())
        {
            pf("%d",data[i]);
            if(i<data.size()-1)
                pf(" ");
        }
        pf("\n");



    }
	return  0;

}
