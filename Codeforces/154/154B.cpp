#include<bits/stdc++.h>
using namespace std;
int main(){


    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        int seen0=-1,seen1=-1,diff=0,index1=-1,index0=-1;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]==s2[i])
            {
                if(s1[i]=='0')
                {
                    seen0=1;
                    index0=i;
                }
                else
                {
                    seen1=1;
                    index1=i;
                    if(diff==0)
                    {
                        break;

                    }
                }
            }
            else
            {
                diff=1;
                
                while(s1[i]!=s2[i])
                {

                    i++;
                }
                if(s1[i]=='0'&&seen0==1)
                {
                    diff=0;
                    if(index1>index0&&index1<i)
                    {
                        index1=-1;
                        seen1=0;
                    }
                }
                else if(s1[i]=='1'&&seen1==1)
                {
                    diff=0;
                    if(index0>index1&&index0<i)
                    {
                        index0=-1;
                        seen0=0;
                    }
                }
            }
        }
        if(diff==1)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
    }
    return 0;
}