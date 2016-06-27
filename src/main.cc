#include <sys/file.h>

int main()
{
  auto src = sys::file(L"\\??\\C:\\Workspace\\src.txt", FILE_GENERIC_READ, FILE_SHARE_READ, FILE_OPEN);
  if (!src) {
    return 1;
  }

  auto dst = sys::file(L"\\??\\C:\\Workspace\\dst.txt", FILE_GENERIC_WRITE, 0, FILE_OVERWRITE_IF);
  if (!dst) {
    return 2;
  }
  
  //ULONG buffer_size = 1024;
  //void* buffer_data = malloc(buffer_size);
  //for (ULONG size = 0; size = src.read(buffer_data, buffer_size);) {
  //  if (!dst.write(buffer_data, size)) {
  //    return 3;
  //  }
  //}
  
  return 0;
}