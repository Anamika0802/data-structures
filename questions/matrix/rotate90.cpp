#include<iostream>
#include<vector>
using namespace std; 
// Function to rotate the matrix 90 degree clockwise
void rotate90Clockwise(vector<vector<int>> &a,int N)
{
 
    // Traverse each cycle
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
 
            // Swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}
 
// Function for print matrix
void printMatrix(vector<vector<int>> arr,int N)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}
int main(){
    int n;
    vector<vector<int>>a;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        vector<int>rows;
        for (int j = 0; j < n; j++)
        {
            int el;
            cin>>el;
            rows.push_back(el);
        }
        a.push_back(rows);
    }
   printMatrix(a,n);
   rotate90Clockwise(a,n); 
   printMatrix(a,n);
}