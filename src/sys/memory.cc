#include <sys/memory.h>
#include <sys.h>

namespace sys {

void* malloc(size_t size)
{
  PVOID data = nullptr;
  if (NT_SUCCESS(SysAllocateVirtualMemory(reinterpret_cast<HANDLE>(-1), &data, 0, &size, MEM_COMMIT, PAGE_READWRITE))) {
    return data;
  }
  return nullptr;
}

void free(void* data)
{
  SIZE_T size = 0;
  SysFreeVirtualMemory(reinterpret_cast<HANDLE>(-1), &data, &size, MEM_RELEASE);
}

}  // namespace sys