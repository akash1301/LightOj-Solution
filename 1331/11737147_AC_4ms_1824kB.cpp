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
#define CASE(n) printf("Case %d: ",++n)
#define inf 1000000000
#define EPS 1e-9

using namespace std;

int fx[]={0,0,1,-1,1,1,-1,-1};
int fy[]={1,-1,0,0,1,-1,1,-1};

dd thita (dd a,dd b,dd c)
{
    return acos((b*b+c*c-a*a)/(2*b*c));
}

int main()
{
   // read();
    int t,cas=0;
    double r1,r2,r3;
    cin>>t;
    while(t--)
    {
        scanf("%lf %lf %lf",&r1,&r2,&r3);
        dd a=r1+r2;
        dd b=r2+r3;
        dd c=r3+r1;
        dd s=(a+b+c)/2.0;
        dd area=sqrt(s*(s-a)*(s-b)*(s-c));
        area -= thita(a,b,c)/2.0*r3*r3;
        area -= thita(b,a,c)/2.0*r1*r1;
        area -= thita(c,a,b)/2.0*r2*r2;
        CASE(cas);
        pf("%.8lf\n",area+EPS);
    }
    return 0;
}
