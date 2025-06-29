class Solution {
  public:
   bool check(int mid, vector<int>& arr, int k) {
    int sum = 0;
    int count = 1;  // Start with 1 partition

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > mid) return false;  // Can't fit this element
        if (sum + arr[i] > mid) {
            count++;
            sum = arr[i];  // Start new partition
        } else {
            sum += arr[i];
        }
    }

    return count <= k;
}
    int splitArray(vector<int>& arr, int k) {
        // code here
        int l=*max_element(arr.begin(),arr.end());
        int h=accumulate(arr.begin(),arr.end(),0);
        int result=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(check(mid,arr,k)){
                result=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
};