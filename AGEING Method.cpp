#include<bits/stdc++.h>
using namespace std;
int R = 12;
int capacity = 100;
vector<long long> Registers(capacity + 10, 0);
vector<long long> PagesIndex(110, 0);
vector<long long> which(capacity+10,0);
long long Timer=0;
long long T = 8;
long long pages[1000001];
long long n;
long long LRUAging() {
	long long m=1ll<<R;
	int in=1;
	for(int i=1;i<=capacity;++i) {
		if(m>Registers[i]) {
			m=Registers[i];
			in=i;
		}
	}
	return in;
}
void Shift() {
	for(int i=1;i<=capacity;++i)
		Registers[i]=(Registers[i]>>1ll);
}
long long pageFaults(long long maxPageNumber) {
	fill(Registers.begin(),Registers.end(),0);
	fill(PagesIndex.begin(),PagesIndex.end(),-1);
	fill(which.begin(),which.end(),-1);
	long long TimeIfInMemory=10;
	long long TimeIfNotInMemory=50;
	long long TotalPageFaults=0;
	long long used=0;
	Timer=0;
	for(int i=0;i<n;++i) {
		if(Timer>=T) {
			Timer-=T;
			Shift();
		}
		if(used<capacity) {
			if(PagesIndex[pages[i]]==-1) {
				PagesIndex[pages[i]]=used;
				TotalPageFaults++;
				which[used]=pages[i];
				used++;
				Timer+=TimeIfNotInMemory;
			} else {
				Timer+=TimeIfInMemory;
			}
		} else {
			if(PagesIndex[pages[i]]==-1) {
				long long LeastRecentlyUsedPageIndex=LRUAging();
				PagesIndex[which[LeastRecentlyUsedPageIndex]]=-1;
				which[LeastRecentlyUsedPageIndex]=pages[i];
				PagesIndex[pages[i]]=LeastRecentlyUsedPageIndex;
				Registers[LeastRecentlyUsedPageIndex]|=(1<<(R-1));
				TotalPageFaults++;
				Timer+=TimeIfNotInMemory;
			} else {
				Timer+=TimeIfInMemory;
			}
		}
	}
	return TotalPageFaults;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("outputageing.txt","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>pages[i];
	long long maxPageNumber=100;
	for(capacity=2;capacity<=100;capacity+=9) {
		auto clk=clock();
		cout<<capacity<<" "<<pageFaults(maxPageNumber)<<" ";
		cout<<(clock()-clk+0.0)/CLOCKS_PER_SEC<<" "<<Timer<<endl;
	}
	return 0;
}
