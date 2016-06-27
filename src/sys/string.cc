#include <sys/string.h>

namespace sys {

UNICODE_STRING string(PCWSTR str)
{
  SHORT size = 0;
  for (auto c = str; *c; c++) {
    size += sizeof(WCHAR);
  }
  UNICODE_STRING s = {};
  s.Buffer = const_cast<PWSTR>(str);
  s.Length = size;
  s.MaximumLength = size;
  return s;
}

}  // namespace sys