#include <unordered_map>
#include <list>
#include <stdexcept>
#include <iostream>

class LRUCache
{
private:
    int capacity_;
    std::list<std::pair<int, int>> linked_list_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache_;

    void make_first(std::list<std::pair<int, int>>::iterator it)
    {
        linked_list_.splice(linked_list_.begin(), linked_list_, it);
    }

public:
    LRUCache(int capacity_)
    {
        this->capacity_ = capacity_;
    }

    int get(int key)
    {
        if (cache_.find(key) == cache_.end())
        {
            return -1;
        }
        auto it = cache_[key];
        make_first(it);
        return it->second;
    }

    void put(int key, int value)
    {
        if (cache_.find(key) == cache_.end())
        {
            cache_[key] = linked_list_.insert(linked_list_.begin(), {key, value});

            if (cache_.size() > capacity_)
            {
                cache_.erase(linked_list_.back().first);
                linked_list_.pop_back();
            }
        }
        else
        {
            auto it = cache_[key];
            it->second = value;
            make_first(it);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity_);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// ["LRUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"]

// [[10],[10,13],[3,17],[6,11],[10,5],[9,10],[13],[2,19],[2],[3],[5,25],[8],[9,22],[5,5],[1,30],[11],[9,12],[7],[5],[8],[9],[4,30],[9,3],[9],[10],[10],[6,14],[3,1],[3],[10,11],[8],[2,14],[1],[5],[4],[11,4],[12,24],[5,18],[13],[7,23],[8],[12],[3,27],[2,12],[5],[2,9],[13,4],[8,18],[1,7],[6],[9,29],[8,21],[5],[6,30],[1,12],[10],[4,15],[7,22],[11,26],[8,17],[9,29],[5],[3,4],[11,30],[12],[4,29],[3],[9],[6],[3,4],[1],[10],[3,29],[10,28],[1,20],[11,13],[3],[3,12],[3,8],[10,9],[3,26],[8],[7],[5],[13,17],[2,27],[11,15],[12],[9,19],[2,15],[3,16],[1],[12,17],[9,1],[6,19],[4],[5],[5],[8,1],[11,7],[5,2],[9,28],[1],[2,2],[7,4],[4,22],[7,24],[9,26],[13,28],[11,26]]

// expected
// [null,null,null,null,null,null,-1,null,19,17,null,-1,null,null,null,-1,null,-1,5,-1,12,null,null,3,5,5,null,null,1,null,-1,null,30,5,30,null,null,null,-1,null,-1,24,null,null,18,null,null,null,null,-1,null,null,18,null,null,-1,null,null,null,null,null,18,null,null,-1,null,4,29,30,null,12,-1,null,null,null,null,29,null,null,null,null,17,22,18,null,null,null,-1,null,null,null,20,null,null,null,-1,18,18,null,null,null,null,20,null,null,null,null,null,null,null]

int main()
{
    LRUCache *obj = new LRUCache(10);
    obj->put(10, 13);
    obj->put(3, 17);
    obj->put(6, 11);
    obj->put(10, 5);
    obj->put(9, 10);
    std::cout << obj->get(13) << std::endl;
    obj->put(2, 19);
    std::cout << obj->get(2) << std::endl;
    std::cout << obj->get(3) << std::endl;
    obj->put(5, 25);
    std::cout << obj->get(8) << std::endl;
    obj->put(9, 22);
    obj->put(5, 5);
    obj->put(1, 30);
    std::cout << obj->get(11) << std::endl;
    obj->put(9, 12);
    std::cout << obj->get(7) << std::endl;
    std::cout << obj->get(5) << std::endl;
    std::cout << obj->get(8) << std::endl;
    std::cout << obj->get(9) << std::endl;
    obj->put(4, 30);
    obj->put(9, 3);
    std::cout << obj->get(9) << std::endl;
    std::cout << obj->get(10) << std::endl;
    std::cout << obj->get(10) << std::endl;
    obj->put(6, 14);
    obj->put(3, 1);
    std::cout << obj->get(3) << std::endl;
    obj->put(10, 11);
    std::cout << obj->get(8) << std::endl;
    obj->put(2, 14);
    std::cout << obj->get(1) << std::endl;
    std::cout << obj->get(5) << std::endl;
    std::cout << obj->get(4) << std::endl;
    obj->put(11, 4);
    obj->put(12, 24);
    obj->put(5, 18);
    std::cout << obj->get(13) << std::endl;
    obj->put(7, 23);
    std::cout << obj->get(8) << std::endl;
    std::cout << obj->get(12) << std::endl;
    obj->put(3, 27);
    obj->put(2, 12);
    std::cout << obj->get(5) << std::endl;
    obj->put(2, 9);
    obj->put(13, 4);
    obj->put(8, 18);
    obj->put(1, 7);
    std::cout << obj->get(6) << std::endl;
    obj->put(9, 29);
    obj->put(8, 21);
    std::cout << obj->get(5) << std::endl;
    obj->put(6, 30);
    obj->put(1, 12);
    std::cout << obj->get(10) << std::endl;
    obj->put(4, 15);
    obj->put(7, 22);
    obj->put(11, 26);
    obj->put(8, 17);
    obj->put(9, 29);
    std::cout << obj->get(5) << std::endl;
    std::cout << obj->get(3) << std::endl;
    std::cout << obj->get(11) << std::endl;
    std::cout << obj->get(10) << std::endl;
    obj->put(3, 4);
    obj->put(11, 30);
    std::cout << obj->get(12) << std::endl;
    obj->put(4, 29);
    std::cout << obj->get(3) << std::endl;
    std::cout << obj->get(9) << std::endl;
    std::cout << obj->get(6) << std::endl;
    obj->put(3, 4);
    std::cout << obj->get(1) << std::endl;
    std::cout << obj->get(10) << std::endl;
    obj->put(3, 29);
    obj->put(10, 28);
    obj->put(1, 20);
    obj->put(11, 13);
    std::cout << obj->get(3) << std::endl;
    obj->put(3, 12);
    obj->put(3, 8);
    obj->put(10, 9);
    obj->put(3, 26);
    std::cout << obj->get(8) << std::endl;
    std::cout << obj->get(7) << std::endl;
    std::cout << obj->get(5) << std::endl;
    obj->put(13, 17);
    obj->put(2, 27);
    obj->put(11, 15);
    std::cout << obj->get(12) << std::endl;
    obj->put(9, 19);
    obj->put(2, 15);
    obj->put(3, 16);
    std::cout << obj->get(1) << std::endl;
    obj->put(12, 17);
    obj->put(9, 1);
    obj->put(6, 19);
    std::cout << obj->get(4) << std::endl;
    std::cout << obj->get(5) << std::endl;
    std::cout << obj->get(5) << std::endl;
    obj->put(8, 1);
    obj->put(11, 7);
    obj->put(5, 2);
    obj->put(9, 28);
    std::cout << obj->get(1) << std::endl;
    obj->put(2, 2);
    obj->put(7, 4);
    obj->put(4, 22);
    obj->put(7, 24);
    obj->put(9, 26);
    obj->put(13, 28);
    obj->put(11, 26);
}