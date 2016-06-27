#pragma once
#include <sys.h>

namespace sys {

class file {
public:
  file();
  file(PCWSTR filename, ACCESS_MASK access, ULONG share_access, ULONG create_disposition);

  file(file&& other);
  file& operator=(file&& other);

  ~file();

  operator bool() const;

  bool open(PCWSTR filename, ACCESS_MASK access, ULONG share_access, ULONG create_disposition);
  bool close();

  ULONG read(PVOID data, ULONG size);
  ULONG write(const PVOID data, ULONG size);

private:
  HANDLE handle_;
};

}  // namespace sys