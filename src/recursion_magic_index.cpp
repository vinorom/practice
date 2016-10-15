#include <bits/stdc++.h>

using namespace std;

int find_magic_index_distinct(int arr[], int left, int right) // assume all values are distinct
{
    if (left > right) return -1;

    int mid= (left+right) / 2;
    if (arr[mid] == mid) return mid;
    if (arr[mid] > mid) return find_magic_index_distinct(arr, left, mid - 1);
    else return find_magic_index_distinct(arr, mid + 1, right);
}

int find_magic_index(int arr[], int left, int right) // assume values are not distinct
{
    if (left > right) return -1;

    int mid= (left+right) / 2;
    if (arr[mid] == mid) return mid;

    auto left_idx = min(mid - 1, arr[mid]);
    auto res = find_magic_index(arr, left, left_idx);
    if (res != -1) return res;

    auto right_idx = max(mid + 1, arr[mid]);
    res = find_magic_index(arr, right_idx, right);
    return res;
}

void solve(int arr[], int n, int (*func)(int[], int, int))
{
    cout << '[';
    for (int i = 0; i < n; ++i) cout << arr[i] << ' ';
    cout << "]: " << func(arr, 0, n - 1) << '\n';
}

int main()
{
    int arr1[] = {-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13};
    solve(arr1, sizeof(arr1) / sizeof(arr1[0]), find_magic_index_distinct);

    int arr2[] = {-10, -5, 2, 2, 2, 3, 4, 8, 9, 12, 13};
    solve(arr2, sizeof(arr2) / sizeof(arr2[0]), find_magic_index);

    return 0;
}
