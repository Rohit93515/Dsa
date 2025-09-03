#include <iostream>
#include <algorithm>
using namespace std;

int countDistinct(int arr[], int n) {
    sort(arr, arr + n); 
    int count = 1;     
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[] = {10, 20, 10, 30, 40, 20, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Total distinct elements: " << countDistinct(arr, n) << endl;
    return 0;
}
