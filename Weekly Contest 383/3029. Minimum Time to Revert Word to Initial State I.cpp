// this has less constraints so we can use the below method, when it comes to greater constraints we have to use kmp algorithm

class Solution {
public:
    bool comp(string temp,string word){
        int n = word.size();
        for(int i=0;i<n;i++){
            if(temp[i]!=word[i] && temp[i]!='*') return false;
        }
        return true;
    }
    int minimumTimeToInitialState(string word, int k) {
        string temp = word;
        int count =0;
        do{
            temp.erase(0,k);
            temp+=string(k,'*');
            count++;
        }while(!comp(temp,word));
        return count;
    }
};

