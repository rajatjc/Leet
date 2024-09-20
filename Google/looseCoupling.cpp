#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start, end;
};

bool compareStart(const Interval& a, const Interval& b) {
    return a.start < b.start;
}

bool compareEnd(const Interval& a, const Interval& b) {
    return a.end < b.end;
}

int countIntervals(vector<Interval>& intervals, int number) {
    sort(intervals.begin(), intervals.end(), compareStart);
    
    auto left = lower_bound(intervals.begin(), intervals.end(), Interval{number, 0}, [](const Interval& a, const Interval& b) {
        return a.end < b.start;
    });

    auto right = upper_bound(intervals.begin(), intervals.end(), Interval{0, number}, [](const Interval& a, const Interval& b) {
        return a.start > b.end;
    });

    int count = 0;
    for (auto it = left; it != right; ++it) {
        if (it->start <= number && it->end >= number) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<Interval> intervals = {{0, 1}, {0, 5}, {0, 7}, {3, 4}, {3, 7}, {4, 4}, {5, 6}, {5, 7}, {7, 7}};
    int number = 5;
    cout << "Number " << number << " is present in " << countIntervals(intervals, number) << " intervals." << endl;
}
