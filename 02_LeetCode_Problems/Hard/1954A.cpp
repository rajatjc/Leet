#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        if(n-ceil(n*1.0/m)>k)cout<<"YES\n";
        else
        cout<<"NO\n";
    }
    return 0;
}