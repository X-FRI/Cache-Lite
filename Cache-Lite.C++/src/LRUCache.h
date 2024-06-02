// LRU Cache
#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <cstdint>
#include <exception>
#include <list>
#include <unordered_map>
#include <utility>

template <typename K, typename V> class LRUCache
{
 public:
  using Key = K;
  using Value = V;
  LRUCache(size_t capacity)
    : capacity(capacity){};
  ~LRUCache() = default;
  Value &
  get(const Key & key)
  {
    if (map.find(key) == map.end())
      {
        // If the key does not exist, throw an exception
        throw std::runtime_error("Can not find in cache!");
      }
    // Move visited nodes to the head of the linked list
    cache.splice(cache.begin(), cache, map[key]);
    return map[key]->second;
  }

  void
  put(const Key key, const Value value) noexcept
  {
    if (map.find(key) != map.end())
      {
        // If the key exists,
        // update the value and move the node to the head of the linked list
        map[key]->second = value;
        cache.splice(cache.begin(), cache, map[key]);
        return;
      }
    if (cache.size() == capacity)
      {
        // If the capacity is full, delete the tail node
        int key_to_remove = cache.back().first;
        cache.pop_back();
        map.erase(key_to_remove);
      }
    // Insert the new node into the linked list header and update the map
    cache.emplace_front(key, value);
    map[key] = cache.begin();
  }

  void
  clear()
  {
    cache.clear();
    map.clear();
  }

 private:
  size_t capacity;
  std::list<std::pair<Key, Value>> cache;
  std::unordered_map<Key, typename std::list<std::pair<Key, Value>>::iterator> map;
};

#endif // ! LRU_CACHE_H