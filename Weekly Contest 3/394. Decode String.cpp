//recursion solution
class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return helper(pos, s);
    }
    
    string helper(int& pos, string s) {
        int num=0;
        string word = "";
        for(;pos<s.size(); pos++) {
            char cur = s[pos];
            if(cur == '[') {
                string curStr = helper(++pos, s);
                for(;num>0;num--) word += curStr;
            } else if (cur >= '0' && cur <='9') {
                num = num*10 + cur - '0';
            } else if (cur == ']') {
                return word;
            } else {    
                word += cur;
            }
        }
        return word;
    }
};


// my solution
// class Solution {
// public:
//     string decodeString(string s) {
//         stack<string> st;
//         int i = 0;
//         while (i < s.size()) {
//             if (s[i] == ']') {
//                 string temp = "";
//                 while (st.top() != "[") {
//                     string c = st.top();
//                     st.pop();
//                     temp += c;
//                 }
//                 st.pop(); 
                
//                 string num = "";
//                 while (!st.empty() && isdigit(st.top()[0])) { 
//                     string c = st.top();
//                     st.pop();
//                     num = c + num; 
//                 }
//                 int tot = stoi(num);
//                 reverse(temp.begin(), temp.end());
//                 string tempans = "";
//                 for (int j = 0; j < tot; ++j) {
//                     tempans += temp; 
//                 }
//                 st.push(tempans);
//             } else {
//                 st.push(string(1, s[i]));
//             }
//             i++;
//         }
//         string ans="";
//         while (!st.empty()) {
//             ans = st.top() + ans; 
//             st.pop();
//         }
//         return ans;
//     }
// };
