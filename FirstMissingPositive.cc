#include <iostream>

using namespace std;

class Solution{
	public:
		int firstMissingPositive(int A[], int n){
			for(int i=0,t,j;i<n;i++){
				j=A[i];
				while(j>0&&j<=n&&A[j-1]!=j){
					t=A[j-1];
					A[j-1]=j;
					j=t;
				}
			}
			for(int i=0;i<n;i++){
				if(A[i]!=i+1)
					return i+1;
			}
			return n+1;
		}
};

int main(){
	int in[][4]={{1,2,0},{3,4,-1,1}};
	Solution s;
	cout <<s.firstMissingPositive(in[0],3) <<endl;
	cout <<s.firstMissingPositive(in[1],4) <<endl;
	return 0;
}
