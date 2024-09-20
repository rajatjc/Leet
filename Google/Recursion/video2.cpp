// #include <iostream>
// using namespace std;

// // Function to print the name N times
// void printName(int i, int n) {
//     if (i > n) {
//         return; // Base case: stop recursion
//     }
//     cout << "Raj" << endl;
//     printName(i + 1, n); // Recursive call
// }

// int main() {
//     int n=4;
//     cout << "Enter the number of times to print the name: ";
//     // cin >> n;
//     printName(1, n); // Start recursion with i = 1
//     return 0;
// }


// #include <iostream>
// using namespace std;

// // Function to print numbers from 1 to N
// void printNumbers(int i, int n) {
//     if (i > n) {
//         return; // Base case: stop recursion
//     }
//     cout << i << " ";
//     printNumbers(i + 1, n); // Recursive call
// }

// int main() {
//     int n;
//     cout << "Enter the value of N: ";
//     cin >> n;
//     printNumbers(1, n); // Start recursion with i = 1
//     return 0;
// }


// #include <iostream>
// using namespace std;

// // Function to print numbers from N to 1
// void printNumbersReverse(int i, int n) {
//     if (i < 1) {
//         return; // Base case: stop recursion
//     }
//     cout << i << " ";
//     printNumbersReverse(i - 1, n); // Recursive call
// }

// int main() {
//     int n;
//     cout << "Enter the value of N: ";
//     cin >> n;
//     printNumbersReverse(n, n); // Start recursion with i = N
//     return 0;
// }


// #include <iostream>
// using namespace std;

// // Function to print numbers from 1 to N using backtracking
// void printNumbersBacktrack(int i, int n) {
//     if (i < 1) {
//         return; // Base case: stop recursion
//     }
//     printNumbersBacktrack(i - 1, n); // Recursive call before printing
//     cout << i << " ";
// }

// int main() {
//     int n;
//     cout << "Enter the value of N: ";
//     cin >> n;
//     printNumbersBacktrack(n, n); // Start recursion with i = N
//     return 0;
// }


#include <iostream>
using namespace std;

// Helper function to print numbers from N to 1
void printNumbersHelper(int i, int n) {
    if (i > n) {
        return; // Base case: stop recursion
    }
    printNumbersHelper(i + 1, n); // Recursive call
    cout << i << " "; // Print after recursion
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    printNumbersHelper(1, n); // Start recursion with i = N
    return 0;
}
