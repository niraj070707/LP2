#include <bits/stdc++.h>
using namespace std;

void find_all_combination( vector<int> combination, int ind){
    if(ind == combination.size()){
        for(auto it:combination){
            cout << it << " ";
        }cout << endl;
        return;
    }

    for(int i=ind; i<combination.size(); i++ ){
        swap(combination[i], combination[ind]);
        find_all_combination(combination,ind+1);
        swap(combination[i], combination[ind]);
    }
}


int main(){
    vector<int>input  = {1,2,3};
    find_all_combination(input, 0);
}