#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] - mid != arr[0]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return left + arr[0];
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Missing number is: " << findMissing(arr, n) << endl;

    return 0;
}
