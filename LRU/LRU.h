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
            if(it == cacheMap.end())  //��δ���У�����-1
            return -1;
            else {
                int v = cacheMap[key]->value;
                CacheNode newNode;
                newNode.value = v;
                newNode.key = key;
                cacheList.push_front(newNode); //���·��ʵ������ƶ�������ͷ
                cacheList.erase(cacheMap[key]);           //ɾ������ԭ��λ�õ�����
                cacheMap[key] = cacheList.begin(); //�����·���Ԫ����ӳ����е���Ϣ
                return v;
            }
        }

        void set(int key, int value) {
            unordered_map<int,list<CacheNode>::iterator>::iterator it = cacheMap.find(key);
            CacheNode newNode;
            newNode.key = key;
            newNode.value = value;

            if(it == cacheMap.end()){ //δ����

                if(this->capacity == cacheList.size()) {//cache������ɾ����βԪ��
                    cacheMap.erase(cacheList.back().key);
                    cacheList.pop_back();
                }

                cacheList.push_front(newNode);     //����Ԫ�ط��ڶ�ͷ
                cacheMap[key] = cacheList.begin();
            }

            else{//����
                if(cacheMap[key] == cacheList.begin())   //��Ҫset��Ԫ�ؾ��ڶ�ͷ����ֱ���޸�
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
