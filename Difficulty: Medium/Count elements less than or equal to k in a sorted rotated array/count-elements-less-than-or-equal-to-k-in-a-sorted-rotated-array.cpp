class Solution {
public:
    int upperBound(vector<int>& arr, int l, int h, int x) {
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (arr[mid] > x)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }

    int countLessEqual(vector<int>& arr, int x) {
        int n = arr.size();
        int l = 0, h = n - 1;
        int pivot = 0;
        while (l <= h) {
            if (arr[l] <= arr[h]) {
                pivot = l;
                break;
            }
            int mid = l + (h - l) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;

            if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) {
                pivot = mid;
                break;
            }
            if (arr[mid] >= arr[l])
                l = mid + 1;
            else
                h = mid - 1;
        }

        int count = 0;
        if (pivot > 0) {
            int idx = upperBound(arr, 0, pivot - 1, x);
            count += idx; 
        }
        int idx = upperBound(arr, pivot, n - 1, x);
        count += (idx - pivot);

        return count;
    }
};
