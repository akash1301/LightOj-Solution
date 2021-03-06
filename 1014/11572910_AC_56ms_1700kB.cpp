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
#define getlong scanf("%lld",&n)
#define CASE(n) printf("Case %d:",++n)
#define inf 1000000000
#define EPS 1e-9

using namespace std;

int fx[]={0,0,1,-1,1,1,-1,-1};
int fy[]={1,-1,0,0,1,-1,1,-1};

int main()
{
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        int n,a;
        cin>>n>>a;
        int x=a+1;
        CASE(cas);
        n-=a;
        vector<int>ans;
        int sq=sqrt(n);
        for(int i=1;i<=sq;i++)
        {
            if(n%i==0){
                if(i>a)
                ans.pb(i);
                if(i!=(n/i)&&(n/i)>a)
                    ans.pb(n/i);
            }
        }
        if(!ans.size()){
            cout<<" impossible"<<endl;
            continue;
        }
        int sz=ans.size();
        sort(all(ans));
        loop(i,sz)
        cout<<" "<<ans[i];
        cout<<endl;

    }
    return 0;
}
