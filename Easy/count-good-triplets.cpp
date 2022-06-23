// bruteforce
class Solution {
    bool is_good(int first,int second,int third,int a,int b,int c){
        return (abs(first-second)<=a && abs(second-third)<=b && abs(first-third)<=c);
    }

public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(is_good(arr[i],arr[j],arr[k],a,b,c)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};

// little optimization
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(abs(arr[i]-arr[j])<=a){
                    for(int k=j+1;k<n;k++){
                        if(abs(arr[j]-arr[k])<=b && abs(arr[i]-arr[k])<=c){
                            cnt++;
                        }
                    }   
                }
            }
        }
        return cnt;
    }
};