#include <iostream>
#include <vector>
#include <string>

using namespace std;

int T, W, H;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while(T -- > 0) {
        cin >> H >> W;
        vector<string> box(H);
        for(string& c: box) cin >> c;
        int candies = 0;
        for(int i = 0; i < H; i++) for(int j = 0; j < W; j++) if(box[i][j] == 'o') {
            if(j > 0 && j < W - 1 && box[i][j-1] == '>' && box[i][j+1] == '<') candies++;
            if(i > 0 && i < H - 1 && box[i-1][j] == 'v' && box[i+1][j] == '^') candies++;
        }
        cout << candies << endl;
    }
}
