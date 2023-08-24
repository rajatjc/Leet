#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    vector<int> arr;
    stack<pair<int, int>> history; // Store history of changes: operation type and value
    unordered_map<int, int> elementCount;

    while (q--) {
        char op;
        cin >> op;

        if (op == '+') {
            int x;
            cin >> x;
            arr.push_back(x);
            history.push({1, x});
            elementCount[x]++;
        } else if (op == '-') {
            int k;
            cin >> k;
            while (k--) {
                int removed = arr.back();
                arr.pop_back();
                history.push({2, removed});
                elementCount[removed]--;
                if (elementCount[removed] == 0) {
                    elementCount.erase(removed);
                }
            }
        } else if (op == '!') {
            while (!history.empty()) {
                int opType = history.top().first;
                int value = history.top().second;
                history.pop();
                
                if (opType == 1) {
                    arr.pop_back();
                    elementCount[value]--;
                    if (elementCount[value] == 0) {
                        elementCount.erase(value);
                    }
                } else if (opType == 2) {
                    arr.push_back(value);
                    elementCount[value]++;
                }
                if (opType != 3) // Stop when encountering a rollback
                    break;
            }
        } else if (op == '?') {
            cout << elementCount.size() << "\n";
        }
    }

    return 0;
}
