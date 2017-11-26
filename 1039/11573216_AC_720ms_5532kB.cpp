/****************************************
*  MD. Al Mamun Akash                   *
*  uVa id: Pointer***                   *
*  Codeforces: Akash.KUET               *
*  LOJ: 19025				*
*  Spoj:akash_kuet                      *
*  Khulna,Bangladesh.                   *
*****************************************/

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

int nP2(int n)
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

map<string,bool>vis,block;

struct node
{
    string ss;
    int d=0;
    node(string x,int y)
    {
        ss=x;
        d=y;
    }
};

int bfs(string start,string des)
{
    vis.clear();
    queue<node>qu;
    qu.push(node(start,0));
    vis[start]=1;
    while(!qu.empty())
    {
        node tp=qu.front();
        qu.pop();
        if(block[tp.ss]==1)
            continue;
        if(tp.ss==des)
            return tp.d;
        for(int i=0;i<3;i++)
        {
            string st=tp.ss;
            st[i]++;
            if(st[i]=='z'+1)
                st[i]='a';
            if(vis[st]==0)
            {
                vis[st]=1;
                qu.push(node(st,tp.d+1));
            }
            string sx=tp.ss;
            sx[i]--;
            if(sx[i]=='a'-1)
                sx[i]='z';
            if(vis[sx]==0)
            {
                vis[sx]=1;
                qu.push(node(sx,tp.d+1));
            }
        }
    }
    return -1;
}



int main()
{
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        string ss1,ss2;
        cin>>ss1>>ss2;
        int n;
        cin>>n;
//        if(!n)
//        {
//            CASE(cas);
//            cout<<0<<endl;
//            continue;
//        }
        while(n--)
        {
            string s1,s2,s3;
            cin>>s1>>s2>>s3;
            for(int i=0;i<s1.size();i++)
            {
                string ss;
                ss+=s1[i];
                for(int j=0;j<s2.size();j++)
                {
                    ss+=s2[j];
                    for(int k=0;k<s3.size();k++)
                    {
                        ss+=s3[k];
                        block[ss]=1;
                        ss.erase(ss.end()-1,ss.end());
                    }
                    ss.erase(ss.end()-1,ss.end());
                }
                ss.erase(ss.end()-1,ss.end());
            }
        }
        CASE(cas);
        cout<<bfs(ss1,ss2)<<endl;
        block.clear();
    }
    return 0;
}
