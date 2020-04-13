#include <iostream>

using namespace std;
using ull = unsigned long long;

int T, N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T -- > 0) {
        cin >> N;
        ull sum = 0;
        for(int i = 0; i < N; i++) {
            ull a = 0;
            cin >> a;
            sum += a % N;
        }
        const char* result = sum % N == 0 ? "YES" : "NO";
        cout << result << endl;
    }
}
