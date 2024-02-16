#include <bits/stdc++.h>
using namespace std;
#define ll long long


    


bool valid(vector<int>& point, vector<int>& top_left, vector<int>& bottom_right) {
    int x = point[0];
    int y = point[1];
    int x1 = top_left[0];
    int y1 = top_left[1];
    int x2 = bottom_right[0];
    int y2 = bottom_right[1];


    if (!lr(top_left, bottom_right))return false;

    if (x1 <= x && x <= x2 && y1 >= y && y >= y2)return true;
    else return false;
}

bool lr(vector<int>& top_left, vector<int>& bottom_right) {
    return top_left[0] <= bottom_right[0] && top_left[1] >= bottom_right[1];
}

    
    int numberOfPairs(vector<vector<int>>& points) {

        int ans=0;
        int n=points.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){continue;}
                
                if(lr(points[i],points[j])){
                    bool flag=true;
                    for(int k=0;k<n;k++){
                        if(k==i or k==j)continue;
                        if(valid(points[k],points[i],points[j])==1){
                            flag=false;
                            break;
                        }
                    }
                    if (flag)ans++;
                }
            }
        }
        return ans;
    }




int main(){
    // vector<vector<int>> v = {{1,1},{2,2},{3,3}};
    vector<vector<int>> v = {{6,2},{4,4},{2,6}};
    cout<<numberOfPairs(v)<<endl;
    return 0;
}