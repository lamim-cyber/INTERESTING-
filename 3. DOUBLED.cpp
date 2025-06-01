#include <bits/stdc++.h>
#define ll long long 
int main()
{
    ll n;
    cin>> n;
    for(int i=1; ; i++)
    {
        if(stoll(to_string(i)+to_string(i))> n)// stoll converts the string to ll
            //to_string make a string
            // addition is not happening in like int, ll , it is just concade two str
        {
            cout<< i-1<< endl;
            return 0;
        }
    }

}
