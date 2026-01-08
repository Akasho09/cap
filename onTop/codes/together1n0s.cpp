// Arrange 0’s and 1’s using two pointers by swapping misplaced elements in linear time.
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 0, 1, 0, 0, 1};
    int n = 6;

    int left = 0, right = n - 1;

    while (left < right) {
        while (arr[left] == 0 && left < right) left++;
        while (arr[right] == 1 && left < right) right--;

        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// 🔹 Efficient Approach (Two Pointers)
    // Use two pointers: left and right

    // left moves from start, right from end

    // Swap misplaced 1 on left with 0 on right

    // Continue until pointers meet

    // No extra space used

