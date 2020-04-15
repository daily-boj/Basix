#include <iostream>
#include <vector>

using namespace std;
using ull = unsigned long long;

int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    vector<int> D { 1, 2 };
    for(int i = 2; i < N; i++) D.push_back((D[i-1] + D[i-2]) % 15746);
    cout << D[N-1] % 15746;
}
