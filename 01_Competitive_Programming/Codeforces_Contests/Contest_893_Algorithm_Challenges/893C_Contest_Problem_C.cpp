#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, m, d;
        cin >> n >> m >> d;

        vector<int> s(m);
        for (int j = 0; j < m; ++j) {
            cin >> s[j];
        }

        int min_cookies = INT_MAX;
        int min_sellers = 0;
        int cookies_eaten = 0;
        int last_cookie_time = 0;

        for (int j = 0; j < m; ++j) {
            int time_diff = s[j] - last_cookie_time;
            if (time_diff >= d) {
                cookies_eaten++;
                last_cookie_time = s[j];
            }

            int total_cookies_removed = cookies_eaten + (m - j - 1);
            if (total_cookies_removed < min_cookies) {
                min_cookies = total_cookies_removed;
                min_sellers = 1;
            } else if (total_cookies_removed == min_cookies) {
                min_sellers++;
            }
        }

        cout << min_cookies << " " << min_sellers << endl;
    }

    return 0;
}
