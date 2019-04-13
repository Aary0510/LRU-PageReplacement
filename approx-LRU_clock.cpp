#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <bits/stdc++.h>

#include <bits/stdc++.h>
// #include <boost/algorithm/string.hpp>

using namespace std;

bool findAndUpdate(int &x,int arr[],
                    bool second_chance[],int frames)

    {
        int i;
        for(i = 0; i < frames; i++)
        {

            if(arr[i] == x)
            {
                second_chance[i] = true;
                return true;
            }
        }
        return false;

    };
int replaceAndUpdate(int &x,int arr[],
                bool second_chance[],int &frames,int &pointer)
    {
        while(true)
        {
            if(!second_chance[pointer])
            {
                arr[pointer] = x;
                return (pointer+1)%frames;
            }
            second_chance[pointer] = false;
            pointer = (pointer + 1) % frames;
        }
    }
vector<string> split(const string &s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> tokens;
        while (getline(ss, item, delim)) {
            tokens.push_back(item);
        }
        return tokens;
    }
void printHitsAndFaults(string reference_string,int &frames)
    {
        int pointer, i, l, x, pf;
        pointer = 0;
        pf = 0;

        int arr[frames];
        for(int s = 0;s<frames;s++)
            arr[s]=-1;
        bool second_chance[frames];
        vector<string> str;
        stringstream check1(reference_string);

    string intermediate;

    // Tokenizing w.r.t. space ' '
    while(getline(check1, intermediate, ' '))
    {
        str.push_back(intermediate);
    }
        l = str.size();
        for(i = 0; i < l; i++)
        {
            stringstream lol;
            lol<<str[i];
            lol>>x;
            if(!findAndUpdate(x,arr,second_chance,frames))
            {
                pointer = replaceAndUpdate(x,arr,
                        second_chance,frames,pointer);
                pf++;
            }
        }
        cout<<"Total page faults were "<<pf<<"\n";
    }
int main(){
    srand(time(0));
        string reference_string = "";
        int frames = 0;
        reference_string = "0 4 1 4 2 4 3 4 2 4 0 4 1 4 2 4 3 4";
        frames = 3;
        printHitsAndFaults(reference_string,frames);
        reference_string = "2 5 10 1 2 2 6 9 1 2 10 2 6 1 2 1 6 9 5 1";
        frames = 4;
        printHitsAndFaults(reference_string,frames);
}
