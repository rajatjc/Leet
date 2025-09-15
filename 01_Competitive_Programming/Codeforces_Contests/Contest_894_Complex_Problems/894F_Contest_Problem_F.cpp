#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int w, f;
        cin >> w >> f;

        int n;
        cin >> n;

        vector<int> strengths(n);
        for (int i = 0; i < n; ++i) {
            cin >> strengths[i];
        }

        sort(strengths.begin(), strengths.end(), greater<int>());

        long long time = 0;
        int max_strength = max(w, f);
        int q = 1;
        int w1 = q * w;
        int f1 = q * f;
        int ans=0;
        while (strengths.size() != 0) {
            bool removed = true;
            while (removed == true ) {
                if(strengths.size()==0)
                break;
                if (f1 > w1 && f1 >= strengths[0]) {
                    f1 -= strengths[0];
                    strengths.erase(strengths.begin());
                    removed = true;
                } else if (w1 >= f1 && w1 >= strengths[0]) {
                    w1 -= strengths[0];
                    strengths.erase(strengths.begin());
                    removed = true;
                } else {
                    removed = false;
                }
            }
               if(strengths.size()==0)
                break;

            q = strengths[0] / max_strength;
            if (strengths[0] % max_strength != 0) {
                q++;
            }
            w1 = q * w;
            f1 = q * f;
            ans+=q;
            
        }
        if(ans==0)
        ans++;
        cout << ans << endl;
    }

    return 0;
}
