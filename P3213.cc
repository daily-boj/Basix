#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    vector<string> edibles(N);
    for(string& item: edibles) cin >> item;

    int half = 0;
    int quarters = 0;
    int t_quarters = 0;
    int count = 0;

    for(auto item: edibles) {
        if(item == "1/4") quarters++;
        else if(item == "1/2") half++;
        else if(item == "3/4") t_quarters++;
        else exit(-1);
    }

    while(quarters > 0 && t_quarters > 0) count++, quarters--, t_quarters--;
    while(half >= 2) count++, half -= 2;
    while(half > 0 && quarters > 0) count++, quarters -= 2, half--;
    while(quarters > 0) count++, quarters -= 4;

    count += half + t_quarters;

    cout << count;
}
