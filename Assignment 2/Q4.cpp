#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1 = "Hello ";
    string str2 = "World!";
    string result = str1 + str2;  

    cout << "Concatenated String: " << result << endl;

     string str = "OpenAI";
    reverse(str.begin(), str.end());  
    cout << "Reversed String: " << str << endl;

    string str = "Hello World";
    string result = "";

    for (char c : str) {
        if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
              c=='A'||c=='E'||c=='I'||c=='O'||c=='U')) {
            result += c;
        }
    }

    cout << "String without vowels: " << result << endl;

      string arr[] = {"banana", "apple", "cherry", "date"};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort(arr, arr + n);  

    cout << "Strings in alphabetical order: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    char c = 'A';
    char lower = tolower(c);

    cout << "Lowercase character: " << lower << endl;
    return 0;
}
