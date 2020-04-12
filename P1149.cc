#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    vector<array<int, 3>> price(N);
    for(auto& item: price) cin >> item[0] >> item[1] >> item[2];

    vector<array<int, 3>> D(N);
    D[0] = price[0];
    for(int i = 1; i < N; i++) {
        D[i][0] = min(D[i-1][1], D[i-1][2]) + price[i][0];
        D[i][1] = min(D[i-1][0], D[i-1][2]) + price[i][1];
        D[i][2] = min(D[i-1][0], D[i-1][1]) + price[i][2];
    }
    cout << *min_element(D[N-1].cbegin(), D[N-1].cend()) << endl;
}
