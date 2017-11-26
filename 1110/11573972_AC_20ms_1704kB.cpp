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
//
//string s1,s2;
//
//int len1,len2,dp[105][105];



int main()
{
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        //getchar();
        string s1,s2;
        int len1,len2,dp[105][105];
        cin>>s1>>s2;
        len1=s1.size();
        len2=s2.size();
        string ans[len1+10][len2+10];
       // mem(dp,0);
        for(int i=0;i<=len1;i++)
        {
            dp[i][0]=0;
            ans[i][0]="";
        }
        for(int j=0;j<=len2;j++)
        {
            dp[0][j]=0;
            ans[0][j]="";
        }
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                    ans[i][j]=ans[i-1][j-1]+s1[i-1];
                }
                else if(dp[i-1][j]>dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                    ans[i][j]=ans[i-1][j];
                }
                else if(dp[i][j-1]>dp[i-1][j])
                {
                    dp[i][j]=dp[i][j-1];
                    ans[i][j]=ans[i][j-1];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                    ans[i][j]=min(ans[i-1][j],ans[i][j-1]);
                }
            }
        }
        CASE(cas);
        if(dp[len1][len2]==0)
            cout<<":("<<endl;
        else
            cout<<ans[len1][len2]<<endl;
    }
    return 0;
}
