class RandomizedSet {
    unordered_map<int,int> mp;
    vector<int> vec;
    int index = 1;
public:
    RandomizedSet() {
        vec.push_back(0);
    }
    
    bool insert(int val) {
        
        if(!mp[val] || mp[val] == -1)
        {
        
            vec.push_back(val);
            mp[val] = vec.size() - 1;
            // cout<<"0---"<<mp[val]<<" "<<val<<endl;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp[val] == -1 || !mp[val]) return false;
        // cout<<mp[val]<<" "<<val<<endl;
        vec[mp[val]] = vec[vec.size() - 1];
        mp[vec[vec.size() - 1]] = mp[val];
        vec.pop_back();
        mp[val] = -1;
        return true;
    }
    
    int getRandom() {
        
        return vec[(rand() % (vec.size() - 1)) + 1];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */