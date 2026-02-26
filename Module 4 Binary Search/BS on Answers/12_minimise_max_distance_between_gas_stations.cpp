#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>

using namespace std;

double minDistanceBrute(vector<int> &stations,int k){   //only comments were added by chatGPT
    vector<int> makeDiv(stations.size()-1,0); 
    // makeDiv[i] = number of extra stations inserted between stations[i] and stations[i+1]

    for(int i=1;i<=k;i++){
        int maxDistance=-1,maxDistIndex=-1;

        // Find the segment that currently has the maximum section length
        for(int j=0;j<stations.size()-1;j++){
            int dist=stations[j+1]-stations[j];    
            double sectionLength=(double)dist/(makeDiv[j]+1);  
            // Effective max distance in this segment after current divisions

            if(sectionLength>maxDistance){
                maxDistance=sectionLength;
                maxDistIndex=j;   // Track the most critical segment
            }
        }
        makeDiv[maxDistIndex]++;  
        // Place one station in the segment with maximum current gap
    }

    double maxLength=-1;
    // Compute the final maximum section length after placing all k stations
    for(int i=0;i<stations.size()-1;i++){
        double sectionLength=(double)(stations[i+1]-stations[i])/(makeDiv[i]+1);
        if(sectionLength>maxLength){
            maxLength=sectionLength;
        }
    }
    return maxLength;  // Minimum possible maximum distance
}

double minDistancePriorityQueue(vector<int> &stations,int k){
    priority_queue<pair<double,int>> pq;
    vector<int> howMany(stations.size()-1,0);
    for(int i=0;i<stations.size()-1;i++){
        double dist=stations[i+1]-stations[i];
        pq.push({dist,i});
    }

    for(int i=1;i<=k;i++){
        pair<double,int> maxDist=pq.top();
        pq.pop();
        int index=maxDist.second;
        howMany[index]++;
        double initialDist=stations[index+1]-stations[index];
        double newSectionLength=(double)initialDist/(howMany[index]+1);
        pq.push({newSectionLength,index});
    }
    return pq.top().first;
}

bool isPossible(vector<int> &stations, int k, double mid){
    int gasCount=0;
    for(int i=0;i<stations.size()-1;i++){
        int numOfGas=(stations[i+1]-stations[i]) /mid;   //number of gas stations inbetween
        if((stations[i+1]-stations[i])/mid==numOfGas*mid){   //if remainder was 0 or not
            numOfGas--;
        }
        gasCount+=numOfGas;
        if(gasCount>k) return false;  //avoid extra checks
    }
    return gasCount<=k;
}

double minDistanceBS(vector<int> &stations,int k){
    double low=0;
    double high=0;
    for(int i=0;i<stations.size()-1;i++){    //high is the max difference
        double dist=stations[i+1]-stations[i];
        if(dist>high){
            high=dist;
        }
    }
    while(high-low>1e-6){
        double mid=(high+low)/2;
        if(isPossible(stations,k,mid)) high=mid;
        else low=mid;
    }
    return high;
}

int main(){
    vector<int> stations={1,13,17,23};
    int k=5;
    cout<<minDistanceBrute(stations,k)<<endl;
    cout<<minDistancePriorityQueue(stations,k)<<endl;
    cout<<minDistanceBS(stations,k);
    return 0;
}