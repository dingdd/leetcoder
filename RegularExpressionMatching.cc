#include <iostream>

using namespace std;

class Solution{
	public:
		bool isMatch(const char *s, const char *p){
			if(!*s&&!*p)
				return true;
			if(!*p&&*s)
				return false;
			if(*(p+1)!='*'){
				if(!*s)
					return false;
				if(*p=='.')
					return isMatch(s+1, p+1);
				if(*p!=*s)
					return false;
				return isMatch(s+1, p+1);
			}
			if(!*s)
				return isMatch(s, p+2);
			if(*p=='.')
				return isMatch(s, p+2)||isMatch(s+1, p);
			if(*p!=*s)
				return isMatch(s, p+2);
			return isMatch(s+1, p)||isMatch(s, p+2);
		}
};

int main(){
	Solution su;
	char s[100],p[100];
	while(cin>>p>>s)
		cout <<su.isMatch(s,p) <<endl;
	return 0;
}
