#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> NP;
bool comp(NP lhs, NP rhs){
	return lhs.first<rhs.first;
}

class Solution{
	public:
		vector<int> twoSum(vector<int> &numbers, int target){
			int n=numbers.size();
			vector<int> index(n);
			vector<NP> nI(n);
			for(int i=0;i<n;i++)
				nI[i]=make_pair(numbers[i],i+1);
			sort(nI.begin(), nI.end(), comp);
			for(int i=0;i<n;i++){
				numbers[i]=nI[i].first;
				index[i]=nI[i].second;
			}
			vector<int>::iterator begin,end,iter;
			begin=numbers.begin();
			end=numbers.end();
			vector<int> result(2);
			while(begin!=end){
				iter=lower_bound(begin+1,end,target-*begin);
				if(*iter+*begin==target){
					result[0]=index[begin-numbers.begin()];
					result[1]=index[iter-numbers.begin()];
					return result;
				}
				if(iter==end){
					begin++;
					continue;
				}
				begin++;
				end=iter+1;
			}
			return result;
		}
};

int main(){
	Solution s;
	int myints[]={2,1,9,4,4,56,90,3};
	vector<int> r(myints, myints+8);
	r=s.twoSum(r, 8);
	return 0;
}
