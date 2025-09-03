    #include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string str) {
    stack<char> s;
    for (char c : str) {
        s.push(c);
    }

    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    return reversed;
}

int main() {
    string input = "DataStructure";

    cout << "Original String: " << input << endl;
    cout << "Reversed String: " << reverseString(input) << endl;

    return 0;
}
