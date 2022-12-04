class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        map<char, int> mp;
        
        char arr[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        for(int i = 0;i<n/2;i++)
            mp[s[i]]++;
        for(int i = n/2;i<n;i++)
            mp[s[i]]--;
        int sum = 0;
        for(auto &c : arr){
            sum += mp[c];
        }
        
        return sum==0;
    }
};