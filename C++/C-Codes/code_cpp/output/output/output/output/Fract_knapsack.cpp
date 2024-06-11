#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    double r1 = (1.0)*a.first/a.second;
    double r2 = (1.0)*b.first/b.second;
    return r1>r2;
}

int main()
{
int profit[] = {60, 100, 120};
int wt[] = {10,20,30};
int n = 3; 
vector<pair<int,int>> data;
int W = 50;
for (int i = 0; i < n; i++)
{
   data.push_back({profit[i], wt[i]});
}
sort(data.begin(), data.end(), cmp);
for(auto i:  data){
    cout<<i.first<<","<<i.second<<endl;
}
cout<<endl;
int TotalValue = 0;
for (int i = 0; i < data.size(); i++)
{
    pair<int,int> item = data[i];
    int itemVal = item.first;
    int itemWt = item.second;
    if (itemWt<=W)
    {
        TotalValue += itemVal;
        W-=itemWt;
    }
    else
    {   
        double ratio = (1.0)*itemVal/itemWt;
        double valToAdd = ratio*W;
        TotalValue += (int)valToAdd;

        W = 0;
    }
    
    
}

return 0;
}
