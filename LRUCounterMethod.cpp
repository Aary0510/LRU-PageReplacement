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

bool full(){
	for(int i=0;i<capacity;i++){
		if(s[i]== -1)
			return false;
	}
	return true;
}

int pageFaults(int pages[], int n)
{

	int indexes[10000];
    memset(indexes, INT_MAX, sizeof(indexes));

	int page_faults = 0;
	for (int i=0; i<n; i++)
	{

		for(int j = 0; j < capacity; j++)
        {

					if(already_there(pages[i])){
						indexes[pages[i]]=i;
					}

					else if(s[j]==-1)
					{
						s[j] = pages[i];
						indexes[pages[i]] = i;
						//cout<<"Here is one page fault at the "<<i<<"th page \n";
						page_faults++;
						break;
					}
					else if(full()){
						int min = INT_MAX, pos = 0;
            for(int k = 0; k < capacity; k++)
            {
                if (indexes[s[k]] < min){
                    min = indexes[s[k]];
                    pos = k;
                }

            }
            s[pos] = pages[i];
            indexes[s[pos]] = i;
						page_faults++;
						//cout<<"Here is one page fault at the "<<i<<"th page \n";
					}


        }
	}
	return page_faults;
}

int main()
{
	start_routine();
	int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
	int n = sizeof(pages)/sizeof(pages[0]);
	memset(s,-1,sizeof(s));
	cout << pageFaults(pages, n) << endl;
	end_routine();//for time elapsed
	return 0;
}
