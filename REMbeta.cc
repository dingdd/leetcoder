#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

class Solution{
	public:
		bool isMatch(const char *s, const char *p);
};

const int inputN=53;

bool Solution::isMatch(const char *s, const char *p){
	int pLen=strlen(p), sLen=strlen(s);
	int stateN=pLen+2;
	int action[stateN][inputN];
	memset(action, 0, sizeof(action));
	int rstate=2, curS=1;
	for(int i=0;i<pLen;i++,rstate++){
		if(p[i+1]!='*'){
			if(p[i]=='.'){
				for(int j=1;j<53;j++)
					action[curS][j]=rstate;
			}
			else
				action[curS][p[i]-'a'+1]=rstate;
			curS=rstate;
		}
		else{
			action[curS][0]=rstate++;
			if(p[i]=='.'){
				for(int j=1;j<53;j++)
					action[curS][j]=rstate;
				for(int j=1;j<53;j++)
					action[rstate][j]=rstate;
			}
			else{
				action[curS][p[i]-'a'+1]=rstate;
				action[rstate][p[i]-'a'+1]=rstate;
			}
			action[rstate][0]=rstate-1;
			curS=rstate-1;
			i++;
		}
	}
	int accState=curS;
	typedef pair<int, int> Intp;
	queue<Intp> que;
	que.push(Intp(1,0));
	while(!que.empty()){
		Intp p=que.front();
		que.pop();
		if(p.first==accState&&!s[p.second])
			return true;
		if(action[p.first][0])
			que.push(Intp(action[p.first][0],p.second));
		if(p.second==sLen)
			continue;
		if(p.second<sLen&&!action[p.first][s[p.second]-96])
			continue;
		que.push(Intp(action[p.first][s[p.second]-96], p.second+1));
	}
	return false;
}

int main(){
	Solution so;
	char p[100]={0};
	char s[100]={0};
	while(cin>>p>>s)
		cout <<so.isMatch(s, p) <<endl;
	return 0;
}
