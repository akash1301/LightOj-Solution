/****************************************
*  MD. Al Mamun Akash                   *
*  uVa id: Pointer***                   *
*  Codeforces: Akash.KUET               *
*  LOJ: 19025                           *
*  Codechef: akash_                     *
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
#define CASE(n) printf("Case %d: ",++n)
#define inf 1000000000
 
using namespace std;
 
int main()
{
    //read();
    ll t;
    cin>>t;
    for(ll i=0;i<t;)
    {
        ll n;
        cin>>n;
        if(n%2==1)
        {
            CASE(i);
            cout<<"Impossible"<<endl;
            continue;
        }
        ll d=sqrt(n);
        ll x1=0,x2=0;
        for(ll j=2;j<=n/2;j+=j)
        {
            if(n%j==0&&(n/j)%2==1)
            {
                x1=n/j;
                x2=j;
                break;
            }
            //else if(n%j==0&&(n/j)%2==0)
            //{
//CASE(i);
            //    cout<<j<<" "<<n/j<<endl;
            //}
        }
        CASE(i);
            cout<<x1<<" "<<x2<<endl;
    }
    return 0;
}
