#ifndef LRU_H_INCLUDED
#define LRU_H_INCLUDED
#include<unordered_map>
#include<list>
using namespace std;

class LRUCache{


    struct CacheNode{
        int key;
        int value;
    };

    private:
        unsigned int capacity;
        list<CacheNode> cacheList;
        unordered_map<int,list<CacheNode>::iterator> cacheMap;

    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
        }

        int get(int key) {
            unordered_map<int,list<CacheNode>::iterator>::iterator it = cacheMap.find(key);
            if(it == cacheMap.end())  //若未命中，返回-1
            return -1;
            else {
                int v = cacheMap[key]->value;
                CacheNode newNode;
                newNode.value = v;
                newNode.key = key;
                cacheList.push_front(newNode); //将新访问的数据移动到链表头
                cacheList.erase(cacheMap[key]);           //删除链表原来位置的数据
                cacheMap[key] = cacheList.begin(); //更改新访问元素在映射表中的信息
                return v;
            }
        }

        void set(int key, int value) {
            unordered_map<int,list<CacheNode>::iterator>::iterator it = cacheMap.find(key);
            CacheNode newNode;
            newNode.key = key;
            newNode.value = value;

            if(it == cacheMap.end()){ //未命中

                if(this->capacity == cacheList.size()) {//cache已满，删除队尾元素
                    cacheMap.erase(cacheList.back().key);
                    cacheList.pop_back();
                }

                cacheList.push_front(newNode);     //将新元素放在队头
                cacheMap[key] = cacheList.begin();
            }

            else{//命中
                if(cacheMap[key] == cacheList.begin())   //若要set的元素就在队头，则直接修改
                    cacheMap[key]->value = value;
                else{
                    cacheList.erase(cacheMap[key]);
                    cacheList.push_front(newNode);
                    cacheMap[key] = cacheList.begin();
                }
            }

         }

};

#endif // LRU_H_INCLUDED
