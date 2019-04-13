	#include<bits/stdc++.h>

	using namespace std;
	#define capacity 4


	#define start_routine() int begtime = clock();
	#define end_routine() int endtime = clock(); \
						  cout << "\n\nTime elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";


	int s[capacity];
	bool already_there(int t){
		for(int i=0;i<capacity;i++){
			if(s[i]==t)
				return true;
		}
		return false;
	}

	int pageFaults(int pages[], int n)
	{

		int indexes[10000];
	    memset(indexes, INT_MAX, sizeof(indexes));

		int page_faults = 0;
		for (int i=0; i<n; i++)
		{
						if(already_there(pages[i])){
							indexes[pages[i]]=i;
						}


						else {
							pos = 0;
	            for(int k = 0; k < capacity; k++)
	            {
									if(s[k]==-1){
										pos=k;
										break;
									}
	                if (indexes[s[k]] < indexes[s[pos]]){
	         						pos = k;
	                }

	            }
	            s[pos] = pages[i];
	            indexes[s[pos]] = i;
							page_faults++;

						}

		}
		return page_faults;
	}

	int main()
	{
		start_routine();
		int pages[] = {1,2,3,4,1,2,3,4,1};
		int n = sizeof(pages)/sizeof(pages[0]);
		memset(s,-1,sizeof(s));
		cout << pageFaults(pages, n) << endl;
		end_routine();//for time elapsed
		return 0;
	}
