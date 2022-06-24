#include<bits/stdc++.h>
using namespace std;

bool isGoodVector(vector<int>A){
	vector<int> Good = {1,3,2};
	if(A.size()!=Good.size()) return 0;
	for(int i=0;i<A.size();i++){
		if(A[i]!=Good[i]) return 0;
	}
	return 1;
}
bool isTargertPreceding(vector<int> A,int j){
    for(int i=0;i<A.size();i++){
        if(A[i]==j) return false;
    }
    return true;
}

void print(vector<int>A){
	cout<<"{";
	for(int a:A) cout<<a<<",";
	cout<<"}\n";
}


void recursion(vector<int> A,int i){
	cout<<"Called recursion for: i: "<<i<<" A:"; 
	print(A);
    if(i==A.size()){
        if(isGoodVector(A)){
        	cout<<"\n \n ans: ";
            print(A);
        }
        return;
    }

    if(A[i]!=-1) {
    	recursion(A,i+1);
    	return;
    }

    for(int j=1;j<=A.size();j++){
        if(isTargertPreceding(A,j)){
            A[i] = j;
            recursion(A,i+1);
        }
    }
}

int main(){
	recursion({1,-1,-1},0);
}
