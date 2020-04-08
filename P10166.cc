#include <iostream>
#include <vector>
#include <array>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int D1, D2;
array<bool, 2001> check({ false });

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);

    cin >> D1 >> D2;

    int sum = 0;
    for(int i = D1; i <= D2; i++) {
        vector<int> tmp;
        for(int j = 1; j < i; j++) {
            int x = i / gcd(i, j); // j / i의 분모 (기약분수)
            if(check.at(x)) continue;
            else {
                sum++;
                tmp.push_back(x);
            }
        }
        for(int i: tmp) check[i] = true;
    }

    cout << sum+1 << endl;
}
