//shitty question with lot of simulation part

class Solution {
public:
    int cal(vector<vector<int>>& image,int i,int j,int threshold){
        for(int k=0;k<3;k++){
            for(int f=0;f<2;f++){
                if(abs(image[i+k][j+f]-image[i+k][j+f+1])>threshold) return -1;
            }
        }
        for(int k=0;k<3;k++){
            for(int f=0;f<2;f++){
                if(abs(image[i+f][j+k]-image[i+f+1][j+k])>threshold) return -1;
            }
        }
        int sum=0;
        for(int k=0;k<3;k++){
            for(int f=0;f<3;f++){
                sum+=image[i+k][j+f];
            }
        }
        return sum/9;
    }
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n=image.size(),m=image[0].size();
        vector<vector<int>> res(n,vector<int>(m)); 
        vector<vector<int>> check(n,vector<int>(m,-1));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                check[i][j]=cal(image,i,j,threshold);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                for(int k=0;k<3;k++){
                    for(int f=0;f<3;f++){
                        if(i-k>=0&&j-f>=0){
                            if(check[i-k][j-f]!=-1){
                                count++;
                                res[i][j]+=check[i-k][j-f];
                            }
                        }
                    }
                }
                if(count!=0) res[i][j]=res[i][j]/count;
                else  res[i][j]=image[i][j];
            }
        }
        return res;
    }
};
