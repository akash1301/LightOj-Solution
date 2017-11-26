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
using namespace std;
 
int main()
{
    char a[21][21];
    int t,c,r,visited[21][21],x,y,p=0;
    cin>>t;
    while(t--)
    {
        cin>>c>>r;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {cin>>a[i][j];
            if(a[i][j]=='@')
            {x=i;
            y=j;}
            visited[i][j]=0;
            }
        }
 
        queue<int>q1,q2;
        q1.push(x);
        q2.push(y);
        visited[x][y]=1;
        int sum=1;
        while(!q1.empty()&&!q2.empty())
        {
            int u1=q1.front();
            int u2=q2.front();
            q1.pop();
            q2.pop();
            if(a[u1-1][u2]=='.'&&visited[u1-1][u2]==0&&(u1-1)<r&&u2<c)
            {
                sum++;
                visited[u1-1][u2]=1;
                q1.push(u1-1);
                q2.push(u2);
            }
            if(a[u1][u2-1]=='.'&&visited[u1][u2-1]==0&&u1<r&&(u2-1)<c)
            {
                sum++;
                visited[u1][u2-1]=1;
                q1.push(u1);
                q2.push(u2-1);
            }
            if(a[u1+1][u2]=='.'&&visited[u1+1][u2]==0&&(u1+1)<r&&u2<c)
            {
                sum++;
                visited[u1+1][u2]=1;
                q1.push(u1+1);
                q2.push(u2);
            }
            if(a[u1][u2+1]=='.'&&visited[u1][u2+1]==0&&u1<r&&(u2+1)<c)
            {
                sum++;
                visited[u1][u2+1]=1;
                q1.push(u1);
                q2.push(u2+1);
            }
 
        }
        cout<<"Case "<<++p<<": "<<sum<<endl;
    }
    return 0;
}