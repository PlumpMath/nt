#include <sys/init.h>
#include <sys/file.h>
#include <sys/memory.h>

namespace sys {

int init()
{
  auto file = sys::file(L"\\??\\C:\\Windows\\System32\\kernel32.dll", FILE_GENERIC_READ, FILE_SHARE_READ, FILE_OPEN);
  if (!file) {
    return 1;
  }
  
  IMAGE_DOS_HEADER image_dos_header = {};
  if (!file.read(&image_dos_header, sizeof(image_dos_header))) {
    return 2;
  }

  IMAGE_NT_HEADERS32 image_nt_headers32 = {};
  if (!file.read(&image_nt_headers32, sizeof(image_nt_headers32))) {
    return 3;
  }

  // TODO: https://www.joachim-bauch.de/tutorials/loading-a-dll-from-memory/

  return 0;
}

}  // namespace sys
