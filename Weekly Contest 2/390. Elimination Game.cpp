//first approach
// f(n, left) = 2 * f(n/2, right)

// Then, Second iteration (right to left elimination) is done on elements 2 * (1, 2, ... n/2)

// So, f(n, left) = 2 * f(n/2, right)

// let f((1,2,...,n), left) = f((n), left) = k
// now replace each value 1, 2, ... with (n + 1 - oldValue)

// f((n, n-1, ..., 1), left) = n+1 - k
// f(n, right) = n + 1 - f(n, left) (from second observation)
// f(n, left) + f(n, right) = n+1
// Using the above equations,

// f(n, left) = 2 * f(n/2, right)
// f(n, left) = 2 * (n/2 + 1 - f(n/2, left))

class Solution {
public:
    int lastRemaining(int n) {
        if(n==1) return 1;
        return 2*(n/2 +1-lastRemaining(n/2));
    }
};



// 2nd approach
// remain starts as n, divide by 2 each row, stop the loop when remain=1.
// Integer jump caches the distance the start might need to move, starts as 1, multiply by 2 each row.
// direction starts as ->, turn around each row.
// when direction is ->, the head move forward;
// when direction is <-, the head move forward if remain is odd, else does nothing.


class Solution {
public:
    int lastRemaining(int n) {
        int start = 1;
        int jump =1;
        bool flag = true;
        while(n>1){
            if(flag){
                start+=jump;
            }
            else{
                start+=n%2==0?0:jump;
            }
            jump*=2;
            n/=2;
            flag = !flag;
        }
        return start;
    }
};
