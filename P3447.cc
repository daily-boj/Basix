#include <iostream>
#include <vector>

using namespace std;

int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;

    vector<unsigned long long> D {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };
    while(T --> 0) {
        unsigned int N = 0;
        cin >> N;
        if(N >= D.size()) for(int i = D.size(); i <= N; i++) D.push_back(D[i - 1] + D[i - 5]);
        cout << D[N] << endl;
    }
}
