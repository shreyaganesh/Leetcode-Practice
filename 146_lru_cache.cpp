#include "iostream"
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        cacheCapacity = capacity;
        currentSize=0;
    }

    int get(int key) {
        if(hashMap.find(key)==hashMap.end())
            return -1;
        else {
            list<int>::iterator it = hashMap[key];
            int result=*it;
            values.splice(values.begin(),values,it);
            return result;
        }
    }

    void put(int key, int value) {
        if(hashMap.find(key)==hashMap.end()){
            if(currentSize==cacheCapacity)
            {
                list<int>::iterator it;
                it=values.end();
                --it;
                unordered_map<int,list<int>::iterator>::iterator it_m;
                for(it_m = hashMap.begin(); it_m!=hashMap.end(); it_m++) {
                  if(it_m->second==it){
                    hashMap.erase(it_m);
                    break;
                  }
                }
                values.pop_back();
                currentSize--;
            }
            values.push_front(value);
            list<int>::iterator it=values.begin();
            hashMap.emplace(key,it);
            currentSize++;
            }
        else {
            list<int>::iterator it = hashMap[key];
            *it=value;
            values.splice(values.begin(),values,it);
            }
    }

private:
    unordered_map<int,list<int>::iterator> hashMap;
    list<int> values;
    int currentSize;
    int cacheCapacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

 int main(){
   LRUCache cache(2);
   /*["LRUCache","put","put","get","put","get","put","get","get","get"]
[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]*/
   cache.put(1,1);
   cache.put(2,2);
   cout<<cache.get(1)<<endl;
   cache.put(3,3);
   cout<<cache.get(2)<<endl;
   cache.put(4,4);
   cout<<cache.get(1)<<endl;
   cout<<cache.get(3)<<endl;
   cout<<cache.get(4)<<endl;
   return 0;
 }
