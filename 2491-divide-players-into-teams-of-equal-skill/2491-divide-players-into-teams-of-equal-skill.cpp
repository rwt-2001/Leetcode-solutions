class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int prevValue = skill[0] + skill[n-1];
        long long chem = skill[0] * skill[n-1];
        
        for(int i = 1;i<skill.size()/2;i++){
            int curSkill = skill[i] + skill[n-1-i];
            if(curSkill != prevValue) return -1;
            chem += (skill[i] * skill[n-1-i]);
            // cout<<(skill[i] * skill[n-1-i])<<endl;
        }
        return chem;
    }
};