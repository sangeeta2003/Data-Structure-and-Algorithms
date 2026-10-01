#include <bits/stdc++.h>
using namespace std;


class Solution{
    public :
    vector<int>findUnio(vector<int>& arr1 , vector<int>& arr2){
        vector<int>unionSet;
        int n = arr1.size();
        int m = arr2.size();
        int i = 0 ;
        int j = 0;
        while(i < n && j < m ){
            if(arr1[i] < arr2[j]){
                if(unionSet.empty() || unionSet.back() != arr1[i]){
                    unionSet.push_back(arr1[i]);
                    
                }
                i++;
            }
            else if(arr1[i] > arr2[j]){
                if(unionSet.empty() || unionSet.back() != arr2[j]){
  unionSet.push_back(arr2[j]);
  
                }
                j++;

            }
            else{
                if(unionSet.empty() || unionSet.back() != arr1[i]){
                    unionSet.push_back(arr1[i]);
                   
                }
                 i++;
                    j++;
            }
        }
            while(i < n){
                 if(unionSet.empty() || unionSet.back() != arr1[i]){
                    unionSet.push_back(arr1[i]);
                    
                }
                i++;
            }
            while(j < m){
                 if(unionSet.empty() || unionSet.back() != arr2[j]){
  unionSet.push_back(arr2[j]);
 
            }
             j++;
        }
return unionSet;
    }

};
int main(){
    Solution sol;
   
     int n;
    cout << "Enter size of array1: ";
    cin >> n;
    int m;
    cout << "Enter size of array2: ";
    cin >> m;

    vector<int>arr1(n);
    cout << "Enter elements of array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
     vector<int>arr2(m);
    cout << "Enter elements of array: ";
    for(int j = 0; j < m; j++) {
        cin >> arr2[j];
    }
    vector<int>ans = sol.findUnio(arr1, arr2);
   for(int  num : ans){
    cout << num;
   }

    return 0;

}