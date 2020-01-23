#import<iostream>
main(){int a,b,v,tmp;std::cin>>a>>b>>v;tmp=((v-a)/(a-b))+1;if(((v-a)%(a-b))!=0)tmp+=1;std::cout<<tmp;}