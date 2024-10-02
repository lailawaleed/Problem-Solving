class Solution{
public:
    vector<int> arrayRankTransform(vector<int>& arr)
    {
        vector<pair<int,int>>vp(arr.size());
        for(int i=0;i<arr.size();i++){
            vp[i]={arr[i],i+1};
        }
        sort(vp.begin(),vp.end());
        vector<int>ans(vp.size());
        int it=1;
        // 10 20 30 40 40
        for(int i=0;i<vp.size();i++){
            //cout<<vp[i].first<<" "<<vp[i].second<<"\n";
            if(i>0 && vp[i].first!=vp[i-1].first)
            {
                it++;
                ans[vp[i].second-1]=it;
            }
            else
            {
                ans[vp[i].second - 1] = it;
            }
        }
        return ans;
    }
};
