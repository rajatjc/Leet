#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases

    for (int i = 0; i < t; ++i) {
        int n, m, d;
        cin >> n >> m >> d; // Read n, m, d

        vector<int> movies(n);
        for (int j = 0; j < n; ++j) {
            cin >> movies[j]; // Read entertainment values
        }

        long long totalEntertainment = 0;
        priority_queue<int> pq;

        for (int value : movies) {
            pq.push(-value);
            if (pq.size() > m) {
                pq.pop();
            }
        }

        int daysSinceLastVisit = 0;

        while (!pq.empty()) {
            int value = -pq.top();
            pq.pop();
            totalEntertainment += value - (daysSinceLastVisit * d);
            daysSinceLastVisit += 1;
        }

        cout << totalEntertainment << endl;
    }

    return 0;
}
