#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
char origin[15];
char tmp[15];
int  origin_len;
int res = 0;

int similar(){
	int result = 0;
	
	for(int i = 0; i < origin_len; i++ )
		for(int j = 0; j < strlen(tmp); j++ )
			if(origin[i] == tmp[j]){
				tmp[j] = ' ';
				result ++;
				break;
			}
		if(strlen(tmp) == origin_len && origin_len == result) return 1;
		if(strlen(tmp) == (origin_len - 1) && strlen(tmp) == result) return 1;
		if(strlen(tmp) == (origin_len + 1) && origin_len == result) return 1;
		if(strlen(tmp) == origin_len && (origin_len-1) == result) return 1;
		return 0;
}	

int main(){
	
	scanf("%d",&n);
	scanf("%s",&origin);
	origin_len = strlen(origin);
	
	for(int i = 1; i < n; i++ ){
		scanf("%s",&tmp);
		res += similar();
	}
	printf("%d\n",res);
}
