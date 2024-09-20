#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        int min1=n+1;
        for(int i=0;i<n;i++)
        {
            int ctr=0;
            while(a[i]==a[0])
            {
                ctr++;
                i++;
            }
            // cout<<ctr<<"ctr"<<endl;
            if(ctr<min1)
            min1=ctr;
        }
        if(min1==n)
        cout<<-1<<endl;
    else
    cout<<min1<<endl;
    }
    return 0;
}