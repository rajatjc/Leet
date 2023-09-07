#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> traps;
        for (int i = 0; i < n; i++) {
            int d, s;
            cin >> d >> s;
            traps.push_back({d, s});
        }

        sort(traps.begin(), traps.end());

        int max_k = 2e8;
        int time = 0;
        for (int i = 0; i < n; i++) {
            int d = traps[i].first;
            int s = traps[i].second;
            int ans=d+ceil(s/2.0)-1;
            if(ans<max_k)
            max_k=ans;
            
        }

        cout << max_k << endl;
    }

    return 0;
}
