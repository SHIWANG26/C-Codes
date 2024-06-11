#include <iostream>
using namespace std;

void setIithBit(int n, int i){
    int mask = 1<<i;
    int ans = n|mask;
    cout<<"After setting : "<<ans<<endl;
}

void clearIthBit(int& n, int i){
    int mask = ~(1<< i);
    int ans = n&mask;
    cout<<"After clearing: "<<ans<<endl;
}

bool checkPower2(int n, int i){
    if ((n&(n-1))==0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    
}

int countSEtBits(int n, int i){
    int cnt = 0;
    while (n--)
    {
        n = (n & (n-1));
        cnt++;
    }
    return cnt;
    
}

void updateBit(int& n, int i, int target){
    clearIthBit(n,i);
    int mask = target<<i;
    n = n|mask;
    cout<<"After updating : "<<n<<endl;
}

void clearLastBit(int& n, int i){
    int mask = (-1<<i);
    n = n&mask;
    cout<<"After clearing last ith bits, we get: "<<n<<endl;
}

void clearBitsInRange(int n, int i, int j){
    int a = (-1<<(i+1));
    int b = (1<<j)-1;
    int mask = a|b;
    cout<<"Ans after clearing th erange is: "
}
void getSubSequence(string& str){
    vector<string> ans;
    int ans = str.length();
    int temp = "";
    for (int num = 0; num < (1<<n); num++)
    {
        for (int i = 0; i < n; i++)
        {
            /* code */
        }
        
    }
    
}
int main()
{
    int n, i;
    cin>>n>>i;
    updateBit(n,0,1);
    clearLastBit(n, i);    
    cout<<"Power of 2 ans: "<<checkPower2(n)<<endl;
    cout<<"Number of setBits: "<<countSEtBits(n,i)<<endl;
    clearBitsInRange(15,3,1);
return 0;
}
