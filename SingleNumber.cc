#include <iostream>

using namespace std;

class Solution{
	public:
		int singleNumber(int A[], int n){
			int r=0;
			for(int i=0;i<n;i++)
				r^=A[i];
			return r;
		}
};

int main(){
	int a[]={1,2,3,1,2};
	Solution s;
	cout <<s.singleNumber(a,5) <<endl;
	return 0;
}
