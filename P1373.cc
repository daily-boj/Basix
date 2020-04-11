#include <iostream>

using namespace std;

int N;
int main() {
    string bin;
    cin >> bin;
    int size = bin.size();

    if (size % 3 == 1) cout << bin[0];
    else if (size % 3 == 2) cout << ((bin[0] != '0') * 2) + (bin[1] != '0');

    for(int i = size % 3; i < size; i += 3) {
        N += (bin[i] != '0') * 4;
        N += (bin[i+1] != '0') * 2;
        N += (bin[i+2] != '0');
        cout << N;
        N = 0;
    }
}
