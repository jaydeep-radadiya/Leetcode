class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int r = image.size();
        int c = image[0].size();
        
        // rotate row
        for(int i=0;i<r;i++){
            int left = 0;
            int right = image[i].size()-1;
            while(left<right){
                swap(image[i][left++],image[i][right--]);
            }
        }
        
        // flip the value
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(image[i][j]==1)
                    image[i][j] = 0;
                else
                    image[i][j] = 1;
            }
        }
        return image;
    }
};

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto &row : image){
            reverse(row.begin(),row.end());
            for(int &ele : row) ele = ele^1;
        }
        return image;
    }
};