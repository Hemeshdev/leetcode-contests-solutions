class Solution {
public:
    void sieve(vector<bool>&prime){
        prime[0]= false;
        prime[1] = false;
        for(int i=2;i<10000;i++){
            if(prime[i]==true){
                for(int j=i*i;j<10000;j+=i){
                    prime[j] = false;
                }
            }
        }
    }
    int minOperations(int n, int m) {
        vector<bool>prime(10000,true);
        sieve(prime);
        if(prime[n] || prime[m]) return -1;
        vector<int>temp(10000,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        temp[n] = n;
        pq.push({n,n});
        while(pq.size()){
            auto top = pq.top();
            pq.pop();
            int minimum = top.first;
            int current = top.second;
            if(current ==m) return minimum;
            string str = to_string(current);
            for(int i=0;i<str.size();i++){
                char c = str[i];
                if(c>'0'){
                    str[i] = c+1;
                    int aga = stoi(str);
                    if(prime[aga]==false && minimum+aga<temp[aga]){
                        pq.push({minimum+aga,aga});
                        temp[aga] = minimum+aga;
                    }
                }
                if(c<'0'){
                        str[i] = c-1;
                        int aga = stoi(str);
                        if(prime[aga]==false && minimum+aga<temp[aga]){
                            pq.push({minimum+aga,aga});
                            temp[aga] = minimum+aga;
                        }
                    }
                }
                str[i] = c;
            }
        }   
        return -1;
    }
};
