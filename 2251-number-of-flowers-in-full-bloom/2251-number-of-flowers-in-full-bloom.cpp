class Solution {
public:
    int findStart(vector<vector<int>> &flowers, int target)
    {
        int index = 0;
        int l = 0, r = flowers.size()-1;
        while(l <= r)
        {
            
            int mid = l + (r - l)/2;
            // cout<<mid<<" ";
            if(flowers[mid][0] <= target)
            {
                
                l = mid + 1;
                index = l;
            }else{
                r = mid - 1;
            }
        }
    
        if(index < flowers.size() && flowers[index][0]==target) index++;
        return index;
    }
    int findEnd(vector<vector<int>> &flowers, int target)
    {
        int index = 0;
        int l = 0, r = flowers.size()-1;
        while(l <= r)
        {
            
            int mid = l + (r - l)/2;
           
            
            if(flowers[mid][1] <= target)
            {
                
                l = mid + 1;
                index = l;
            }else{
                r = mid - 1;
            }
        }
        
        if(index < flowers.size() && flowers[index][1]==target) index++;
      
        return index;
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        sort(flowers.begin(), flowers.end());
        vector<vector<int>> flowerEnd = flowers;
        sort(flowerEnd.begin(), flowerEnd.end(),[](auto a, auto b)
             {
                 return a[1] < b[1];
             });
        vector<int> ans;
        // for(auto flower: flowers)
        // {
        //     cout<<flower[0]<< " "<<flower[1]<<" | ";
        // }
        // cout<<endl;
        for(auto time : people)
        {
            int s = findStart(flowers, time);
            int e = findEnd(flowerEnd, time - 1) ;
            
            ans.push_back(s-(e < 0 ? 0 : e));
            
        }
        
        return ans;

    }
};