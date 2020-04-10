#include <iostream>
#include <vector>

using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    vector<vector<bool>> ban(N+1, vector<bool>(N+1, false));
    while(M --> 0) {
        int a, b;
        cin >> a >> b;
        if(a > b) ban[a][b] = true;
        else ban[b][a] = true;
    }

    int count = 0;
    for(int a = 1; a <= N; a++) {
        for(int b = 1; b < a; b++) {
            if(ban[a][b]) break;
            for(int c = 1; c < b; c++) if(!ban[a][c] && !ban[b][c]) count++;
        }
    }

    cout << count;
}
