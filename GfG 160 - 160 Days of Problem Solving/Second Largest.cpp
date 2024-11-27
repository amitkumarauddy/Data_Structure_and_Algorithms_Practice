/**
 * The given C++ program finds and returns the second largest element in a vector of integers.
 * 
 * The code defines a class `Solution` with a method `getSecondLargest` that takes a vector of
 * integers as input and returns the second largest element in the vector. The main function prompts
 * the user to enter the number of test cases, then for each test case, it prompts the user to enter an
 * array of integers. It then calculates and displays the second largest element in each array.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function returns the second largest element
    int getSecondLargest(vector<int> &arr) {
        if (arr.size() < 2) return -1; // If less than 2 elements, second largest doesn't exist

        int first = INT_MIN, second = INT_MIN;
        for (int num : arr) {
            if (num > first) {
                second = first;
                first = num;
            } else if (num > second && num < first) {
                second = num;
            }
        }
        return (second == INT_MIN) ? -1 : second;
    }
};

int main() {
    int t;
    cout << "Enter Test Cases: ";
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        cout << "Enter Array Elements: ";
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);

        cout << "Second Largest Element: ";
        if (ans != -1) {
            cout << ans << endl;
        } else {
            cout << "Not Found" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
