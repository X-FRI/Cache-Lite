#include <LRUCache.h>
#include <iostream>

int
main()
{

  LRUCache<int, int> cache(4);
  cache.put(1, 1);
  cache.put(2, 2);
  cache.put(3, 3);
  cache.put(4, 4);
  try
    {
      std::cout << cache.get(3);
    }
  catch (const std::exception & e)
    {
      std::cerr << e.what() << '\n';
    }
  cache.put(5, 5);
  try
    {
      std::cout << cache.get(1);
    }
  catch (const std::exception & e)
    {
      std::cerr << e.what() << '\n';
    }

  cache.put(6, 6);
  cache.put(7, 7);
  cache.put(8, 8);
  cache.put(9, 9);
  cache.put(10, 10);
}