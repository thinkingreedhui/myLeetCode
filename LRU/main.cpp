#include <iostream>

#include"LRU.h"
using namespace std;

int main()
{
    LRUCache cache(2);
    cache.set(2,1);
    cache.set(2,2);
    list<int> t;
    t.push_back(1);
    t.push_back(2);
    t.push_back(3);
    list<int>::iterator it;
    it = t.end();
    it--;
    it--;
    t.splice(t.begin(),t,it);
    for(it = t.begin();it != t.end();it++)
        cout<<*it<<endl;
    return 0;
}
