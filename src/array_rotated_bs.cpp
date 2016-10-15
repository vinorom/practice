#include <bits/stdc++.h>

using namespace std;

int search(int arr[], int l, int r, int x)
{
    if (l > r) return -1;
    int mid = l + (r - l) / 2;
    if (arr[mid] == x) return mid;
    if (arr[l] <= arr[mid])
    {
        if (arr[l] <= x && x < arr[mid]) return search(arr, l, mid - 1, x);
        else return search(arr, mid + 1, r, x);
    }
    else
    {
        if (arr[mid] < x && x <= arr[r]) return search(arr, mid + 1, r, x);
        else return search(arr, l, mid - 1, x);
    }
}

void solve(int arr[], int n, int x)
{
    cout << "[";
    for (int i = 0; i < n; ++i) cout << arr[i] << ' ';
    cout << "]: x=" << x << " pos=" << search(arr, 0, n - 1, x) << '\n';
}

int main()
{
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    for (int i : arr)
    {
        solve(arr, 9, i);
    }
    return 0;
}
