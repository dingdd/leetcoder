#include <iostream>
#include <vector>

using namespace std;

class Solution{
	public:
		void setZeroes(vector< vector<int> > &matrix){
			int xLen=matrix.size();
			if(xLen<1)
				return;
			int yLen=matrix[0].size();
			int r0=1,c0=1;
			for(int i=0;i<xLen;i++){
				if(matrix[i][0]!=0)
					continue;
				c0=0;
			}
			for(int j=0;j<yLen;j++){
				if(matrix[0][j]!=0)
					continue;
				r0=0;
			}
			for(int i=1;i<xLen;i++){
				for(int j=1;j<yLen;j++){
					if(matrix[i][j]!=0)
						continue;
					matrix[0][j]=0;
					matrix[i][0]=0;
				}
			}
			for(int i=1;i<xLen;i++){
				if(matrix[i][0]!=0)
					continue;
				for(int j=1;j<yLen;j++)
					matrix[i][j]=0;
			}
			for(int j=1;j<yLen;j++){
				if(matrix[0][j]!=0)
					continue;
				for(int i=1;i<xLen;i++)
					matrix[i][j]=0;
			}
			if(!c0)
				for(int i=0;i<xLen;i++)
					matrix[i][0]=0;
			if(!r0)
				for(int j=0;j<yLen;j++)
					matrix[0][j]=0;
			return;
		}
};

int main(){
	Solution s;
	vector<int> m1(2,1);
	vector< vector<int> > m(2,m1);
	m[1][0]=0;
	s.setZeroes(m);

	return 0;
}
