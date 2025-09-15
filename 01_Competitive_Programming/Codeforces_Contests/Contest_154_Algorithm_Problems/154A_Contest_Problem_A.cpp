#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string digits;
        cin >> digits;

        int flag=0;
        // Find a digit that makes the sum of the remaining digits prime
        for (char digit : digits) {
            if(digit=='3')
            {
                flag=1;
                break;
            }
            else if(digit=='7')
            {
                flag=2;
                break;
            }
        }
        if(flag==1)
        cout<<37<<endl;
        else if(flag==2)
        {
            cout<<73<<endl;
        }
        // else
        // cout<<flag<<endl;
    }

    return 0;
}
