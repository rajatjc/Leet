#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        int a[m];
        
        for (int j = 0; j < m; j++)
        {
            cin >> a[j];
        }
        
        unordered_map<int, int> elementCount;
        for (int j = 0; j < m; j++)
        {
            elementCount[a[j]]++;
        }
        
        if (elementCount.size() == 1)
        {
            cout << -1 << endl;
            continue;
        }
        
        sort(a, a + m); // Corrected line to sort the array 'a'
        
        vector<int> b, c;
        
        for (int i : a)
        {
            if (i == a[0])
                b.push_back(i); // Corrected 'psuhbac' to 'push_back'
            else
                c.push_back(i); // Corrected 'elsec' to 'else' and 'pushback' to 'push_back'
        }
        
        cout << b.size() << " "<<c.size()<<endl;;
        for (int val : b)
        {
            cout << val << " ";
        }
        
        cout << endl;
        
        for (int val : c)
        {
            cout << val << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}
