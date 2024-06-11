#include <iostream>
using namespace std;

void printrowiseSum(int arr[][3],int row,int column){
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < column; j++)
        {
            sum += arr[i][j];
        }
        cout<<"The sum is : \n"<<sum<<endl;
    }
    
}

int main()
{
int arr[3][3], row, column, i, j;
cout<<"Enter number of row and column\n";
cin>>row>>column;
for ( i = 0; i < row; i++)
{
    for ( j = 0; j < column; j++)
    {
        cin>>arr[i][j];
    }
    
}
for ( i = 0; i < row ; i++)
{
    for ( j = 0; j < column; j++)
    {
        cout<<arr[i][j];
    }
    cout<<endl;
}
printrowiseSum(arr, row, column);
return 0;
}
