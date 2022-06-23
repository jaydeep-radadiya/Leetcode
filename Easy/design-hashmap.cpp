// first method
class MyHashMap {
public:
    vector<int> arr;
    MyHashMap() {
        arr = vector<int>(1e6+1,-1);
    }
    
    void put(int key, int value) {
        arr[key] = value;
    }
    
    int get(int key) {
        return arr[key];
    }
    
    void remove(int key) {
        arr[key] = -1;
    }
};

// second method
class MyHashMap {
public:
    vector<list<pair<int,int>>> arr;
    int sz = 1e2+1;
    MyHashMap() {
        arr.resize(sz);
    }
    
    int hash(int key){
        return key%sz;
    }
    
    list<pair<int,int>>:: iterator search(int key){
        int idx = hash(key);
        // return find(arr[idx].begin(),arr[idx].end(),key); // this will not work
        
        auto it=arr[idx].begin();
        for(;it!=arr[idx].end();it++){
            if(it->first==key){
                return it;
            }
        }
        return it;
    }
    
    void put(int key, int value) {
        int idx = hash(key);
        remove(key);
        arr[idx].push_back({key,value});
    }
    
    int get(int key) {
        int idx = hash(key);
        auto it = search(key);
        if(it==arr[idx].end())
            return -1;
        else
            return it->second;
    }
    
    void remove(int key) {
        int idx = hash(key);
        auto it = search(key);
        if(it!=arr[idx].end()){
            arr[idx].erase(it);   
        }
    }
};