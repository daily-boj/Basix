#include <iostream>
#include <vector>

using namespace std;

int N, K;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    vector<int> coins(N);
    for(auto& n: coins) cin >> n;

    int sum = 0;
    for(auto it = coins.crbegin(); it != coins.crend(); it++) sum += K / *it, K = K % *it;
    cout << sum;
}
