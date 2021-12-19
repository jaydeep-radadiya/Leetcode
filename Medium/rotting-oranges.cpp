// tc : r*c + r*c*4
// sc : r*c

// first
class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) {
        int r = arr.size();
        int c = arr[0].size();
        
        int noz = 0;
        int cnt = 0; // element go into q 
        queue<pair<int,pair<int,int>>> q; // time x y
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j]==0){
                    noz++;
                }
                else if(arr[i][j]==2){
                    q.push({0,{i,j}});
                    cnt++;
                }
            }
        }
        
        int ans = 0;
        while(not q.empty()){
            int time = q.front().first;
            int curr_x = q.front().second.first;
            int curr_y = q.front().second.second;
            ans = time;
            q.pop();
            
            if(curr_x+1<r && arr[curr_x+1][curr_y]==1){
                q.push({time+1,{curr_x+1,curr_y}});
                arr[curr_x+1][curr_y] = 2;
                cnt++;
            }
            if(curr_x-1>=0 && arr[curr_x-1][curr_y]==1){
                q.push({time+1,{curr_x-1,curr_y}});
                arr[curr_x-1][curr_y] = 2;
                cnt++;
            }
            if(curr_y+1<c && arr[curr_x][curr_y+1]==1){
                q.push({time+1,{curr_x,curr_y+1}});
                arr[curr_x][curr_y+1] = 2;
                cnt++;
            }
            if(curr_y-1>=0 && arr[curr_x][curr_y-1]==1){
                q.push({time+1,{curr_x,curr_y-1}});
                arr[curr_x][curr_y-1] = 2;
                cnt++;
            }
        }
        if(r*c-noz==cnt) return ans;
        else return -1;
    }
};

// second
struct node {
    int x, y, time;
    node(int _x,int _y,int _time){
        x = _x;
        y = _y;
        time = _time;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) {
        int r = arr.size();
        int c = arr[0].size();
        
        int oranges = 0; // cnt oranges
        queue<node> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j]==2)
                    q.push(node(i,j,0));
                if(arr[i][j]!=0)
                    oranges++;
            }
        }
        
        int ans = 0;
        int cnt = 0;
        while(not q.empty()){
            int x = q.front().x;
            int y = q.front().y;
            int time = q.front().time;
            q.pop();
            cnt++;
            
            ans = max(ans,time);
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int new_x = x+dx[i];
                int new_y = y+dy[i];
                if(new_x>=0 && new_x<r && new_y>=0 && new_y<c && arr[new_x][new_y]==1){
                    q.push(node(new_x,new_y,time+1));
                    arr[new_x][new_y] = 2;
                }
            }
        }
        if(oranges==cnt) return ans;
        else return -1;
    }
};