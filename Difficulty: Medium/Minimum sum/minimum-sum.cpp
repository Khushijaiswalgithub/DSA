class Solution {
  public:
    string addStrings(string num1, string num2) {
    string result = "";
    int carry = 0;
    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int n1 = i >= 0 ? num1[i--] - '0' : 0;
        int n2 = j >= 0 ? num2[j--] - '0' : 0;
        int sum = n1 + n2 + carry;
        result += (sum % 10) + '0';
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());

    // Remove leading zeros
    int start = 0;
    while (start < result.size() - 1 && result[start] == '0') {
        start++;
    }

    return result.substr(start);
}
    string minSum(vector<int> &arr) {
        // code here
        string s1,s2;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n;i+=2){
            s1+=(to_string(arr[i]));
            if(i+1<n){
            s2+=(to_string(arr[i+1]));
            }
        }
        string s=addStrings(s1,s2);
        return s;
    }
};