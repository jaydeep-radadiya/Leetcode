class BrowserHistory {
private:
    list<string> history;
    list<string> :: iterator it;
    
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        it = history.begin();
    }
    
    void visit(string url) {
        auto temp = it;
        temp++;
        history.erase(temp,history.end());
        history.push_back(url);
        it++;
    }
    
    string back(int steps) {
        while(it!=history.begin() && steps--){
            it--;
        }
        return *it;
    }
    
    string forward(int steps) {
        while(it!=--history.end() && steps--){
            it++;
        }
        return *it;
    }
};