#include<bits/stdc++.h>
using namespace std;
int capacity;
int s[100];
long long Timer = 0;
bool already_there(int t) {
	for(int i=0;i<capacity;i++) {
		if(s[i]==t)
			return true;
	}
	return false;
}
long long timeonhit=10,timeonmiss=50;
int pageFaults(int pages[], int n) {
	int indexes[10000];
	memset(s,-1,sizeof(s));
	memset(indexes,INT_MAX,sizeof(indexes));
	int pagefaults=0;
	Timer=0;
	for(int i=0;i<n;i++) {
		if(already_there(pages[i])) {
			indexes[pages[i]]=i;
			Timer+=timeonhit;
		}
		else {
			int pos=0;
			for(int k=0;k<capacity;k++) {
				if(s[k]==-1) {
					pos=k;
					break;
				}
				if(indexes[s[k]]<indexes[s[pos]]) {
					pos=k;
				}
			}
			s[pos]=pages[i];
			indexes[s[pos]]=i;
			pagefaults++;
			Timer+=timeonmiss;
		}
	}
	return pagefaults;
}
int pages[1000000];
int main() {
	freopen("input.txt","r",stdin);
	freopen("output1.txt","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>pages[i];
	}
	for(capacity=2; capacity<=100; capacity+=9) {
		auto clk=clock();
		cout<<capacity<<" "<<pageFaults(pages,n)<<" ";
		cerr<<capacity<<"\n";
		cout<<(clock()-clk+0.0)/CLOCKS_PER_SEC<<" "<<Timer<<endl;
	}
	return 0;
}
