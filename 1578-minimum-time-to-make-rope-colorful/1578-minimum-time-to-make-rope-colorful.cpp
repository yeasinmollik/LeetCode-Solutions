class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        char currColor = colors[0];
        int maxTime = neededTime[0], totTime = neededTime[0];
        int minC = 0;
        
        neededTime.push_back(-1);
        colors.push_back('#');
        for(int i = 1; i < colors.size(); i++){
            if(colors[i] == colors[i-1]){
                totTime += neededTime[i];
                maxTime = max(maxTime, neededTime[i]);
            }
            else{
                minC += (totTime - maxTime);
                maxTime = neededTime[i];
                totTime = neededTime[i];
            }
        }
        return minC;
    }
};