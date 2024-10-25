class Solution {
public:
    string oddString(vector<string>& words) {
        map<string,long long> mp;
        long long r = 3;
        for(long long j = 0;j<words.size();j++){
            string x;
            for(long long i = 0;i<words[j].size()-1;i++){
                x.push_back(words[j][i+1]-words[j][i]);
            }
            mp[x]+= r++;
            if(mp.size()==2 and j>2){
                return words[min(begin(mp)->second,next(begin(mp))->second)-3];
            }

        }
        return words[min(begin(mp)->second,next(begin(mp))->second)-3];
    }
}; 