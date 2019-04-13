#include <bits/stdc++.h>
using namespace std;
static int capacity=0;
static int ptr=0;

bool search(int &x, int values[], bool clock_tracker[])
{
	int i;
	for(i=0;i<capacity;i++) {
		if(values[i]==x) {
			clock_tracker[i]=true;
			return true;
		}
	}
	return false;
}
int replace(int &x, int values[], bool clock_tracker[]) {
	while(true) {
		if(!clock_tracker[ptr]) {
			values[ptr]=x;
			return (ptr+1)%capacity;
		}
		clock_tracker[ptr]=false;
		ptr=(ptr+1)%capacity;
	}
}
long long Timer=0;
int pages[1000005];
int evaluate(int n) {
	Timer=0;
	int values[capacity];
	memset(values,-1,capacity*sizeof(values[0]));
	bool clock_tracker[capacity];
	ptr=0;
	int x;
	int misses=0;
	for(int i=0;i<n;i++) {
		x=pages[i];
		if(!search(x,values,clock_tracker)) {
			ptr=replace(x,values,clock_tracker);
			misses++;
			Timer+=50;
		} else
			Timer+=10;
	}
	return misses;
}

int main() {
	freopen("input.txt","r",stdin);
	freopen("outputclock.txt","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>pages[i];
	for(capacity=2; capacity<=100; capacity+=9) {
		auto clk=clock();
		cout<<capacity<<" "<<evaluate(n)<<" ";
		cout<<(clock()-clk+0.0)/CLOCKS_PER_SEC<<" "<<Timer<<endl;
	}
}
