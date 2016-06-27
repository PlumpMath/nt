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
  
  char buffer[1024];
  for (ULONG size = 0; size = src.read(buffer, sizeof(buffer));) {
    if (!dst.write(buffer, size)) {
      return 3;
    }
  }
  
  return 0;
}