// ekhane mainly array take vangle 3 ta array pabo , tarpor hoyto eta ager tar shathe change korbe noyto porer tar shathe , karon duitar shathe change korle she majhkhanei theke jabe , evabe 3 ta sum pabo

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define test int t; cin >> t; while (t--)
#define srt(v) sort(v.begin(), v.end());
#define rvs(v) reverse(v.begin(), v.end());
using namespace std;
int main()
{
  test
  {  
    int n, l, r;
    cin>> n>> l>> r;
    int v[n+1];
    for(int i=1 ; i<=n; i++) cin>> v[i];
    vector< int > a, b, c;
    for(int i=1 ; i<l; i++)
    {
        a.push_back(v[i]);
    }
    for(int i=l ; i<=r; i++)
    {
        b.push_back(v[i]);
    }
    for(int i=r+1; i<=n; i++)
    {
        c.push_back(v[i]);
    }

    srt(a);
    srt(b);
    srt(c);
    vector< int > k;
    rvs(b);
    k=b;
    ll sum1= accumulate(b.begin(), b.end(), 0ll);
    for(int i=0; i<min(k.size(),a.size()); i++)
    {
        if(a[i]<k[i])
        {
            k[i]=a[i];
        }
    }
    ll sum2=accumulate(k.begin(), k.end(), 0ll);
    k=b;
    for(int i=0; i<min(k.size(),c.size()); i++)
    {
        if(c[i]<k[i])
        {
            k[i]=c[i];
        }
    }
    ll sum3=accumulate(k.begin(), k.end(), 0ll);
    cout<< min(sum1, min(sum2, sum3))<< endl;
  }

}



