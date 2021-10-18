// first method
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int mx_area = 0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // area = width*height
                int area = (j-i)*min(height[j],height[i]);
                mx_area = max(mx_area,area);
            }
        }
        return mx_area;
    }
};

// second method
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int mx_area = 0;
        int left = 0;
        int right = n-1;
        
        while(left<right){
            int area = (right-left)*min(height[left],height[right]);
            mx_area = max(mx_area,area);
            
            if(height[left]<height[right])
                left++;
            else
                right--;
        }
        return mx_area;
    }
};