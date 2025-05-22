ll n;
    cin>> n;
    ll k=1;
    while(1)
    {
        ll x= 1<<k;
        if(x<=n)
        {
            k++;
        }else
        break;
    }
    cout<< k<< endl;
