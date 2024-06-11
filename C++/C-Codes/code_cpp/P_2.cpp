#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number";
    cin >> n;
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <i ; j++)
        {
            cout<<i;
        }
        cout<<endl;

    }
    */
    /*for (int i = 0; i < n; i++)
    {
     for (int r = 0; r < n; r++)
     {
         cout<<" @ ";
     }
     cout<<endl;
    }
  */

    int m;
    cout << "Enter the number of column";
    cin >> m;
    /*for (int i = 0; i < n; i++)
    {
       if (i==0 || i==n-1)
       {
           for (int j = 0; j < m; j++)
           {
               cout<<"*";
           }

       }
       else
       {
           cout<<"*";
           for (int j = 0; j < m-2; j++)
           {
               cout<<" ";
           }
           cout<<"*";

       }
       cout<<endl;
    }
    */

 /*  for (int i = 0; i<n; i++)
   {
    for (int j = 0; j<i; j++)
    {
        cout<<"*";
    }
    cout<<endl;
   }
   */
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
        cout<<j++;
    }
    cout<<endl;
  }
  
}