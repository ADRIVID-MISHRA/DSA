#include<iostream>
#include<vector>

using namespace std;

int ninjaTrainingRecursion(int day,int lastTask,vector<vector<int>>& points) {
    if(day==0){
        int maxPoints=INT_MIN;
        for(int i=0;i<3;i++){
            if(i!=lastTask) maxPoints=max(maxPoints,points[day][i]);
        }
        return maxPoints;
    }

    int maxPoints=INT_MIN;
    for(int i=0;i<3;i++){ //Try doing all the tasks except lastTask
        if(i!=lastTask) maxPoints=max(maxPoints,points[day][i]+ninjaTrainingRecursion(day-1,i,points));
    }
    return maxPoints;
}
 
int ninjaTrainingMemoization(int day,int lastTask,vector<vector<int>>& points,vector<vector<int>>& dp) {
    if(day==0){
        int maxPoints=INT_MIN;
        for(int i=0;i<3;i++){
            if(i!=lastTask) maxPoints=max(maxPoints,points[day][i]);
        }
        return maxPoints;
    }

    if(dp[day][lastTask]!=-1) return dp[day][lastTask];

    int maxPoints=INT_MIN;
    for(int i=0;i<3;i++){ //Try doing all the tasks except lastTask
        if(i!=lastTask) maxPoints=max(maxPoints,points[day][i]+ninjaTrainingMemoization(day-1,i,points,dp));
    }
    return dp[day][lastTask]=maxPoints;
}

int ninjaTrainingTabulation(vector<vector<int>> &points){
    int n=points.size();
    vector<vector<int>> dp(n,vector<int>(4,-1));

    for(int i=0;i<=3;i++){   
        int maxPoints=INT_MIN;
        for(int j=0;j<=2;j++){
            if(j!=i) maxPoints=max(maxPoints,points[0][j]);
        }
        dp[0][i]=maxPoints;
    }

    for(int day=1;day<n;day++){
        for(int last=0;last<=3;last++){
            int maxPoints=INT_MIN;
            for(int task=0;task<=2;task++){
                if(task!=last) maxPoints=max(maxPoints,points[day][task]+dp[day-1][task]); 
            }
            dp[day][last]=maxPoints;
        }
    }
    return dp[n-1][3];
}

int ninjaTrainingSpaceOptimized(vector<vector<int>> &points){
    int n=points.size();
    vector<int> dp(4,-1);

    for(int last=0;last<=3;last++){   
        int maxPoints=INT_MIN;
        for(int j=0;j<=2;j++){
            if(j!=last) maxPoints=max(maxPoints,points[0][j]);
        }
        dp[last]=maxPoints;
    }

    for(int day=1;day<n;day++){
        vector<int> temp(4,-1);
        for(int last=0;last<=3;last++){
            int maxPoints=INT_MIN;
            for(int task=0;task<=2;task++){
                if(task!=last) maxPoints=max(maxPoints,points[day][task]+dp[task]); 
            }
            temp[last]=maxPoints;
        }
        dp=temp;
    }
    return dp[3];
}

int main() {
    vector<vector<int>> points={
        {1,2,5}, 
        {3,1,1}, 
        {3,3,3}
    };

    int n=points.size();
    cout<<ninjaTrainingRecursion(n-1,3,points)<<endl;

    vector<vector<int>> dp(n,vector<int>(4,-1)); //initialize 2D dp array with -1
    cout<<ninjaTrainingMemoization(n-1,3,points,dp)<<endl;

    cout<<ninjaTrainingTabulation(points)<<endl;

    cout<<ninjaTrainingSpaceOptimized(points);
    return 0;
}