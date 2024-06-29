class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        int i=n-1,j=m-1;
        int carry =0;
        string ans ="";
        while(i>=0 && j>=0){
            int sum = (num1[i]-'0')+(num2[j]-'0')+carry;
            carry = sum/10;
            ans+=to_string(sum%10);
            i--;
            j--;           
        }
        while(i>=0){
            int sum = (num1[i]-'0')+carry;
            carry = sum/10;
            ans+=to_string(sum%10);
            i--;
        }
        while(j>=0){
            int sum = (num2[j]-'0')+carry;
            carry = sum/10;
            ans+=to_string(sum%10);
            j--;
        }
        while(carry){
            int sum =carry;
            carry = sum/10;
            ans+=to_string(sum%10);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
