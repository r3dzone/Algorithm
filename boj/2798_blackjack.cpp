//Made By R3dzone
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int res = -1;

vector<int> card;
vector<int> sel;

void blackjack(int x){
	if(sel.size() == 3){
		int sum = sel[0]+sel[1]+sel[2];
		if(sum <= m)
			res = max(res,sum);
		return;
	}
	
	for(int i = x+1; i < n; i++){
		sel.push_back(card[i]);
		blackjack(i);
		sel.pop_back();
	}
}

int main(){
	scanf("%d %d",&n,&m);
	int inp1;
	for(int i = 0; i < n; i++){
		scanf("%d",&inp1);
		card.push_back(inp1);
	}
	blackjack(-1);
	printf("%d",res);
	return 0;
}
