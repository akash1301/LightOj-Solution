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

int n,mask_value[20],dp[(1<<15)+1][20],match[20][20];
vector<string>data;
string ans;

int call(int mask,int pre)
{
    if(mask>=(1<<n)-1)
    {
        dp[mask][pre]=0;
        return 0;
    }
    int &ret=dp[mask][pre];
    if(ret!=-1) return ret;
    ret=inf;
    if(mask==0)
    {
        loop(i,n)
        {
            ret=min(ret,call(mask | mask_value[i],i)+(int)data[i].size());
        }
    }
    else
    {
        loop(i,n)
        {
            if(CHECK(mask,i)) continue;
            int len=data[i].size()-match[pre][i];
            ret=min(ret,call(mask | mask_value[i],i)+len);
        }
    }
    return ret;
}


void printSol(int mask,int pre,string str)
{
    if(mask>=(1<<n)-1)
    {
        ans=str;
        return;
    }
    if(mask==0)
    {
        int ret=inf,id;
        string mmm="Z";
        loop(i,n)
        {
            int p=dp[mask | mask_value[i]][i]+data[i].size();
            if(p<ret)
            {
                ret=p;
                id=i;
                mmm=data[i];
            }
            else if(p==ret && data[i]<mmm)
            {
                ret=p;
                id=i;
                mmm=data[i];
            }
        }
        printSol(mask | mask_value[id],id,str+data[id]);
    }
    else
    {
        int ret=inf,id,xx;
        string mmm="Z";
        loop(i,n)
        {
            if(CHECK(mask,i)) continue;
            int len=data[i].size()-match[pre][i];
            int p=dp[mask | mask_value[i]][i]+len;
            string ppp=data[i].substr(match[pre][i],len);
            if(p<ret)
            {
                ret=p;
                id=i;
                mmm=ppp;
            }
            else if(p==ret && ppp<mmm)
            {
                ret=p;
                id=i;
                mmm=ppp;
            }
        }
        printSol(mask | mask_value[id],id,str+mmm);
    }
}


int main()
{
    int t,cas=0;
//    write();
    getint(t);
    while(t--)
    {
        ans.clear();
        data.clear();
        mem(mask_value,0);
        mem(match,0);
        getint(n);
        loop(i,n)
        {
            string ss;
            cin>>ss;
            data.pb(ss);
        }
        sort(all(data));
        loop(i,data.size())
        {
            mask_value[i]=0;
            loop(j,data.size())
            {
                if(data[j].size()>data[i].size()) continue;
                int ssz=data[j].size();
                for(int k=0; k<data[i].size(); k++)
                {
                    if(k+ssz>data[i].size()) break;
                    string sub=data[i].substr(k,ssz);
                    if(sub==data[j])
                    {
                        mask_value[i]=SET(mask_value[i],j);
                        break;
                    }
                }
            }
//            cout<<mask_value[i]<<endl;
        }


        loop(i,n)
        {
            loop(j,n)
            {
                if(i==j) continue;
                string tmp="";
                for(int k=0;k<data[j].size();k++)
                {
                    tmp+=data[j][k];
                    if(tmp.size()>data[i].size()) break;
                    int sz=tmp.size();
                    int xx=data[i].size()-sz;
                    string sub=data[i].substr(xx,sz);
                    if(sub==tmp)
                        match[i][j]=sz;
                }
            }
        }


        mem(dp,-1);
//        cout<<call(0,0)<<endl;

        call(0,0);

        printSol(0,0,"");

        CASE(cas);
        cout<<ans<<endl;

    }
    return  0;

}
