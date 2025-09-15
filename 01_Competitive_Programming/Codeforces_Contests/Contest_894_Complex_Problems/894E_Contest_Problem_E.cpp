#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, d;
        cin >> n >> m >> d;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int ans = 0;
        int maxVal = -1;
        int index = -1;

        for (int i = 0; i < n; ++i) {
            int localMax = a[i] - d * i;
            cout<<localMax<<" ";
            if (localMax > maxVal) {
                maxVal = localMax;
                index = i;
            }
        }

cout<<endl;
        int li = 0;

        for (int i = index; i < n; ++i) {
            if(m==0)
            break;
            int diff = i+1 - li;
            int sum = a[i] - d * diff;
            if (sum > 0) {
                ans += sum;
                li = i+1;
                m--;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
