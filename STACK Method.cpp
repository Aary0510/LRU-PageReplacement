#include<bits/stdc++.h>
using namespace std;
int capacity;
#define start_routine() int begtime = clock();
#define end_routine() int endtime = clock(); \
					  cout << "\n\nTime elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
int pages[1000005];
long long Timer=0;
struct STACK {
	int *deq;
	int size=0,capacity;
	STACK(int capacity) : capacity(capacity) {
		deq=new int[capacity];
	}
	int insert(int value) {
		for(int i=size-1;i>=0;i--) {
			if(deq[i]==value) {
				for(int j=i;j+1<size;j++)
					deq[j]=deq[j+1];
				deq[size-1]=value;
				Timer+=10;
				return 0;
			}
		}
		if(size==capacity) {
			for(int i=0;i+1<size;i++)
				deq[i]=deq[i+1];
			deq[size-1]=value;
		} else {
			deq[size]=value;
			size++;
		}
		Timer+=50;
		return 1;
	}
};
int main() {
	freopen("input.txt","r",stdin);
	freopen("outputstack.txt","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>pages[i];
	}
	auto clk=clock();
	for(capacity=2;capacity<=100;capacity+=9) {
		Timer=0;
		auto clk=clock();
		STACK *cache=new STACK(capacity);
		int pagefaults=0;
		for(int j=0;j<n;j++) {
			pagefaults+=cache->insert(pages[j]);
		}
		cout<<capacity<<" "<<pagefaults<<" ";
		cout<<(clock()-clk+0.0)/CLOCKS_PER_SEC<<" "<<Timer<<endl;
	}
	cerr<<(clock()-clk+0.0)/CLOCKS_PER_SEC<<endl;
	return 0;
}

