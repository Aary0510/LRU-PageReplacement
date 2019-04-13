#include<stdio.h>

long long max(long long a, long long b) { return a > b ? a : b; }

int LRUAging(long long Registers[], long long capacity, long long n) {
    long long m = 1 << n;
    int in = -1;
    for (int i = 1; i <= capacity; ++i) {
        if (m > Registers[i]) {
            m = Registers[i];
            in = i;
        }
    }
    return in;
}

void Shift(long long Registers[], long long capacity) {
    for (int i = 1; i <= capacity; ++i) {
        Registers[i] = (Registers[i] >> 1ll);
    }
}

/// LRU - Aging Register Method
long long pageFaults(long long pages[], long long n, long long capacity, long long T, long long R, long long HitTimeForRAM, long long MissPlusExtraTime, long long maxPageNumber)
{
    long long Registers[capacity + 1] = {};
    long long PagesIndex[maxPageNumber + 1] = {};
    long long TimeIfInMemory = HitTimeForRAM;
    long long TimeIfNotInMemory = HitTimeForRAM + MissPlusExtraTime;
    long long TotalPageFaults = 0;
    long long used = 0;
    long long Timer = 0;
    for (int i = 0; i < n; ++i)
    {
        if (Timer >= T) {
            Timer -= T;
            Shift(Registers, capacity);
        }
        if (used < capacity) {
            if (PagesIndex[pages[i]] == 0) {
                PagesIndex[pages[i]] = used++;
                TotalPageFaults++;
                Timer += TimeIfNotInMemory;
            } else {
                Timer += TimeIfInMemory;
            }
        } else {
            if (PagesIndex[pages[i]] == 0) {
                /////Find the page with least Register value
                int LeastRecentlyUsedPageIndex = LRUAging(Registers, capacity, R);
                /////Set invalid for Paging out
                PagesIndex[LeastRecentlyUsedPageIndex] = 0;
                PagesIndex[pages[i]] = LeastRecentlyUsedPageIndex;
                TotalPageFaults++;
                Timer += TimeIfNotInMemory;
            } else {
                Timer += TimeIfInMemory;
            }
        }
        // Use page with PageIndex = PageIndex[pages[i]]
        Registers[PagesIndex[pages[i]]] |= (1 << (R - 1));
    }
    return TotalPageFaults;
}


int main()
{
    long long pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 9, 4, 1, 2, 3, 8};
    long long n = sizeof(pages) / sizeof(pages[0]);
    long long capacity = 4;
    long long R = 5;
    long long T = 9;
    long long HitTimeForRAM = 1;
    long long MissPlusExtraTime = 3;
    long long maxPageNumber = 0;
    for (int i = 0; i < n; ++i)
        maxPageNumber = max(maxPageNumber, pages[i]);
    printf("Total Number of Page Faults: %lld", pageFaults(pages, n, capacity, T, R, HitTimeForRAM, MissPlusExtraTime, maxPageNumber));
    return 0;
}
