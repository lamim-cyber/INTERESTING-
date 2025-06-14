#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll power(ll a, ll b)
{
    if(b==0) return 1;
    if(b%2==0)
    {
        ll p=power(a,b/2);
        return (p*p)%mod;
    }else 
    {
        ll p=power(a,b/2);
        return ((p*p)%mod)*a%mod;
    }
}
int main()
{
    
    ll n, x;
    cin>> n>> x;
    vector< ll > v(n);
    ll sum=0;
    for(int i=0; i<n; i++)
    {
        cin>> v[i];
        sum+=v[i];// as the problem state the power of x
    }
    map< ll, ll>m;
    for(int i=0; i<n; i++)
    {
        m[sum-v[i]]++;//count in a map
    } 
    ll k= sum-v[n-1];
    while(m[k]%x==0)
    {
        m[k+1]+=m[k]/x;
        m[k]=0;
        k++;
    }
    cout<< power(x,min(sum,k))<< nl;//the ans will alawys the min power that can be taken common
  
} 
