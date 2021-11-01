// first method
class MyHashSet {
public:
    vector<bool> arr;
    MyHashSet() {
        arr = vector<bool>(1e6+1,false);
    }
    
    void add(int key) {
        arr[key] = true;
    }
    
    void remove(int key) {
        arr[key] = false;
    }
    
    bool contains(int key) {
        return arr[key];
    }
};

// second method
class MyHashSet {
public:
    vector<list<int>> arr;
    int sz = 1e2+1; // we take any size
    MyHashSet() {
        arr.resize(sz);
    }
    
    int hash(int key){
        return key%sz;
    }
    
    list<int>:: iterator search(int key){
        int idx = hash(key);
        return find(arr[idx].begin(),arr[idx].end(),key);
    }
    
    void add(int key) {
        if(contains(key)==true){
            return;
        }
        else{
            int idx = hash(key);
            arr[idx].push_back(key);   
        }
    }
    
    void remove(int key) {
        if(contains(key)==false){
            return;
        }
        else{
            int idx = hash(key);
            arr[idx].erase(search(key));   
        }
    }
    
    bool contains(int key) {
        int idx = hash(key);
        if(search(key)!=arr[idx].end()) return true;
        else return false;
    }
};