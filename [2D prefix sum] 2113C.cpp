#include <bits/stdc++.h>
#define ll long long
#define test int t; cin >> t; while (t--)
#define F first
#define S second
using namespace std;
 
int pref[1000][1000];
 
pair< ll, ll> fix(ll a, ll b, ll n, ll m)
{
    if(a<0) a=0;
    if(a>n) a=n;
    if(b<0) b=0;
    if(b>m) b=m;
 
    return {a,b};
}// fixing so that adding or subtracting doesnt get out of limit
 
int main()
{
 
  test
  {
    int n, m, k;
    int cnt=0;
    cin>> n>> m>>k;
    char a[n+1][m+1];
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='g')
                cnt++;
        }
    }
 
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            pref[i][j]=pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]+(a[i][j]=='g');// count the prefix count of 'g'
        }
    }
 
    ll mn=INT_MAX;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]!='.')continue;
 
            pair< ll ,ll> p= fix(i+k-1, j+k-1, n, m);
            pair< ll, ll> q= fix(i-k, j-k, n, m);
            ll x=pref[p.F][p.S]-pref[p.F][q.S]-pref[q.F][p.S]+pref[q.F][q.S];//counting without k-1 squared boxes
            mn=min(mn,x);
        }
    }
    cout<< cnt-mn<< endl;
}
 
}
