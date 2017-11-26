#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
 
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
 
using namespace std;
 
int main()
{
    int t,x=0;
    cin>>t;
    char a[28];
 
    while(t--)
    {
        for(int i=0;i<26;i++)
    {
        a[i]=i+65;
    }
        int n,k,s=0;
        cin>>n>>k;
        pf("Case %d:\n",++x);
        do
        {
            for(int i=0;i<n;i++)
                cout<<a[i];
            cout<<endl;
            s++;
            if(s==k)
                break;
        }while(next_permutation(a,a+n));
 
    }
    return 0;
}