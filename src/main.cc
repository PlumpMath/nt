#include <sys/init.h>

int main()
{
  if (auto ec = sys::init()) {
    return ec;
  }
  return 0;
}