#include <cstdio>
#include <cstring>

using namespace std;

char board[20][20];

int nextY[4][2] = {{-1,-1},{-1,-1},{0,-1},{0,-1}}; //L, _|, ㄱ, r 
int nextX[4][2] = {{0,1},{0,-1},{1,1},{1,0}};

bool judgeAllBlack(int H,int W){
	for(int i = 0; i < H; i++)
		for(int j = 0; j < W; j++)
			if(board[i][j] == '.') return false;
	return true;
}

int boardcover(int y, int x, int H, int W){ //현재위치가 y,x일때 y,x를 채우고 나머지를 전부 채우는 경우의 수
	if(y < 0){
		if(judgeAllBlack) return 1;
		else return 0;
	}
	if(x >= W) return boardcover(y-1,0,H,W);
	if(board[y][x] == '#') return boardcover(y,x+1,H,W);
	int ret = 0;
	
	board[y][x] = '#';
	for(int i = 0; i < 4; i++){
		int nY1 = y+nextY[i][0];
		int nY2 = y+nextY[i][1];
		int nX1 = x+nextX[i][0];
		int nX2 = x+nextX[i][1];
		
		if(nY1 < H && nY1 >= 0 && nX1 < W && nX1 >= 0 && 
			board[nY1][nX1] == '.' && board[nY2][nX2] == '.'){
			board[nY1][nX1] = '#';
			board[nY2][nX2] = '#';
			ret += boardcover(y,x+1,H,W);
			board[nY1][nX1] = '.';
			board[nY2][nX2] = '.';
		}
	}
	board[y][x] = '.';
	return ret;
}

int main(){
	int C,H,W;
	
	scanf("%d",&C);
	for(int i = 0; i < C; i++){
		scanf("%d %d",&H,&W);
		for(int j = H-1; j >= 0; j--){
			scanf("%s",board[j]);
		}
		printf("%d\n",boardcover(H-1,0,H,W));
	}
	return 0;
}
