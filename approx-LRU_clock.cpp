#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <bits/stdc++.h>

#include <bits/stdc++.h>
// #include <boost/algorithm/string.hpp>
using namespace std;

static int frms = 0;
static string reference_string = "";
static int ptr=0;

vector<string> split(const string &s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> tokens;
        while (getline(ss, item, delim)) {
            tokens.push_back(item);
        }
        return tokens;
    }


bool search(int &x,int values[],bool clock_tracker[])

    {
        int i;
        for(i = 0; i < frms; i++)
        {

            if(values[i] == x)
            {
                clock_tracker[i] = true;
                return true;
            }
        }
        return false;
    };

int replace(int &x,int values[],bool clock_tracker[])
    {
        while(true)
        {
            if(!clock_tracker[ptr])
            {
                values[ptr] = x;
                return (ptr+1)%frms;
            }
            clock_tracker[ptr] = false;
            ptr = (ptr + 1) % frms;
        }
    }

void evaluate()
    {

        int values[frms];
        memset(values, -1, frms * sizeof(values[0]));
        bool clock_tracker[frms];
        vector<string> str;
        stringstream check1(reference_string);
        string intermediate;
        while(getline(check1, intermediate, ' '))
        {
            str.push_back(intermediate);
        }
        ptr=0;
        int x;
        int misses=0;
        for(int i = 0; i < str.size(); i++)
        {
            stringstream lol;
            lol<<str[i];
            lol>>x;
            if(!search(x,values,clock_tracker))
            {
                ptr = replace(x,values,
                        clock_tracker);
                misses++;
            }
        }
        cout<<"Number of misses "<<misses<<"\n";
    }

int main(){
        reference_string = "0 4 1 4 2 4 3 4 2 4 0 4 1 4 2 4 3 4";
        frms = 3;
        evaluate();
        reference_string = "2 5 10 1 2 2 6 9 1 2 10 2 6 1 2 1 6 9 5 1";
        frms = 4;
        evaluate();
}
