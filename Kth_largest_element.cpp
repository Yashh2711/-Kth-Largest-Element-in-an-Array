#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (nums[j] <= pivot) {
            ++i;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[right]);
    return i + 1;
}

int quickSelect(vector<int>& nums, int left, int right, int k) {
    if (left == right) return nums[left];
    int pivotIndex = partition(nums, left, right);
    int position = pivotIndex - left + 1;
    if (k == position) return nums[pivotIndex];
    else if (k < position) return quickSelect(nums, left, pivotIndex - 1, k);
    else return quickSelect(nums, pivotIndex + 1, right, k - position);
}

int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    return quickSelect(nums, 0, n - 1, n - k + 1);
}

int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "Kth largest element is: " << findKthLargest(nums, k) << endl;
    return 0;
}
