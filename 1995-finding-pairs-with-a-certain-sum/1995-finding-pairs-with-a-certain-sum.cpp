class FindSumPairs {

    private :
    unordered_map<int,int> mp;
    // map<int,int> mp;
    int n;
    vector<int>nums1;
    vector<int> nums2;
    int m; //length of nums1,nums2
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this-> n=nums1.size(); 
        this->nums1=nums1;
        this->nums2=nums2;
        this->m=nums2.size();

        for(int i=0;i<m;i++)
        {
            mp[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {

        mp[nums2[index]]-=1;
        nums2[index]+=val;
        mp[nums2[index]]++;
        return ;
    }
    
    int count(int target) {
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int num2=target-nums1[i];
            if(mp.find(num2)!=mp.end())
            {
                cnt+=mp[num2];
            }
        }


        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */