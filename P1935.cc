#include <iostream>
#include <iomanip>
#include <array>
#include <stack>

using namespace std;
array<double, 26> names{};

double process(stack<char>& program) {
    char top = program.top();
    program.pop();

    if (top >= 'A' && top <= 'Z') {
        return names[top - 'A'];
    }

    auto B = process(program);
    auto A = process(program);

    switch(top) {
        case '+':
            return A + B;
        case '-':
            return A - B;
        case '/':
            return A / B;
        case '*':
            return A * B;
        default:
            exit(-1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    stack<char> program;
    int many = 0;

    cin >> many;

    cin.ignore();
    string raw_program;
    getline(cin, raw_program);
    for (auto a: raw_program) program.push(a);
    raw_program.clear(); // put expression to stack

    for(int i = 0; i < many; i++) cin >> names[i];

    cout << fixed << setprecision(2);
    cout << process(program);
}
