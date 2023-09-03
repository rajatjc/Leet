#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, H, X;
    cin >> N >> H >> X;

    vector<int> potions(N);
    for (int i = 0; i < N; ++i) {
        cin >> potions[i];
    }

    int least_effective_potion = -1;
    for (int i = 0; i < N; ++i) {
        if (H + potions[i] >= X) {
            least_effective_potion = i + 1;
            break;
        }
    }

    cout << least_effective_potion << endl;

    return 0;
}
