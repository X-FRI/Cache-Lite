#include <PerpetualCache.h>
#include <assert.h>
#include <exception>
#include <stdexcept>

void
testPutAndGet()
{
  PerpetualCache<int, int> cache;
  cache.put(1, 100);
  assert(cache.get(1) == 100);
}

void
testRemove()
{
  PerpetualCache<int, int> cache;
  cache.put(1, 100);
}

void
testRemove()
{
  PerpetualCache<int, int> cache;
  cache.put(1, 100);
  cache.remove(1);
  try
    {
      cache.get(1);
      assert(false); // Should not reach here
    }
  catch (const std::out_of_range &)
    {
      assert(true); // Expected exception
    }
}

void
testGet()
{
  PerpetualCache<int, int> cache;
  cache.put(1, 100);
  try
    {
      cache.get(2);
      assert(false); // Should not reach here
    }
  catch (const std::out_of_range &)
    {
      assert(true); // Expected exception
    }
}

void
testClear()
{
  PerpetualCache<int, int> cache;
  cache.put(1, 100);
  cache.put(2, 200);
  cache.clear();
  try
    {
      cache.get(1);
      assert(false); // Should not reach here
    }
  catch (const std::out_of_range &)
    {
      assert(true); // Expected exception
    }
  try
    {
      cache.get(2);
      assert(false); // Should not reach here
    }
  catch (const std::out_of_range &)
    {
      assert(true); // Expected exception
    }
}

int
main()
{
  testPutAndGet();
  testRemove();
  testClear();
  return 0;
}