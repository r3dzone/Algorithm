#import<iostream>#import<algorithm>
using namespace std;main(){int x,y,w,h;cin>>x>>y>>w>>h;cout<<min(min(w-x,h-y),min(x,y));}