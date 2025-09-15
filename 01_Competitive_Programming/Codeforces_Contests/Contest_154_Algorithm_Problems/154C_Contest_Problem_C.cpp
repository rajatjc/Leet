#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int arrs=0;
        int dec=0;
        int inc=1;
        int flag=1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='+')
            {
                arrs++;
            }
            else if(s[i]=='-')

            {
                if(arrs==0)
                {
                    flag=0;
                    break;
                }
                arrs--;

            }
            else if(s[i]=='1')
            {
                if(dec==1)
                {
                    flag=0;
                    break;
                }

            }
            else{
                
                if(arrs==0)
                {
                    flag=0;
                    break;
                }
                else if(inc==1)
                {
                    flag=0;
                    break;
                }
            }
        }
    }
}