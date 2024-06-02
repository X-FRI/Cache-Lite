// Perpetual Cache
#ifndef PERPETUAL_CACHE_H
#define PERPETUAL_CACHE_H

#include <hash_map>

template <typename K, typename V> class PerpetualCache
{
 public:
  using Key = K;
  using Value = V;
  PerpetualCache() = default;
  ~PerpetualCache() = default;
  void
  put(const Key & key, const Value & value)
  {
    cache[key] = value;
  }
  const Value &
  get(const Key & key) const
  {
    return cache[key];
  }
  Value
  remove(const Key & key)
  {
    return cache.erase(key);
  }
  void
  clear()
  {
    cache.clear();
  }

 private:
  std::hash_map<Key, Value> cache;
};

#endif // ! PERPETUAL_CACHE_H