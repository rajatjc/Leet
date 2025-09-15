#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string n,m;
        cin>>n>>m;
        int flag=0;
        for(int i=0;i<n.length();i++)
        {
            int n1=n[i]-'0';
            int m1=m[i]-'0';
            if(flag==1)
            {
                
                int lar=n1>m1?n1:m1;
                int sma=n1+m1-lar;
                n[i]=sma+'0';
                m[i]=lar+'0';
            }
            if(n1!=m1&&flag==0)
            {
                flag=1;
                int lar=n1>m1?n1:m1;
                int sma=n1+m1-lar;
                n[i]=lar+'0';
                m[i]=sma+'0';
            }
        }
        cout<<n<<endl<<m<<endl;
    }
    return 0;
}