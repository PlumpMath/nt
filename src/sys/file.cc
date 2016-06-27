#include <sys/file.h>
#include <sys/string.h>

namespace sys {

file::file() :
  handle_(nullptr)
{}

file::file(PCWSTR filename, ACCESS_MASK access, ULONG share_access, ULONG create_disposition) :
  file()
{
  open(filename, access, share_access, create_disposition);
}

file::file(file&& other) :
  file()
{
  close();
  handle_ = other.handle_;
  other.handle_ = nullptr;
}

file& file::operator=(file&& other)
{
  close();
  handle_ = other.handle_;
  other.handle_ = nullptr;
  return *this;
}

file::~file()
{
  close();
}

file::operator bool() const
{
  return handle_ ? true : false;
}

bool file::open(PCWSTR filename, ACCESS_MASK access, ULONG share_access, ULONG create_disposition)
{
  auto str = string(filename);
  OBJECT_ATTRIBUTES object = {};
  object.Length = sizeof(object);
  object.Attributes = OBJ_CASE_INSENSITIVE;
  object.ObjectName = &str;
  IO_STATUS_BLOCK status_block = {};
  return NT_SUCCESS(SysCreateFile(&handle_, access | SYNCHRONIZE, &object, &status_block, nullptr, FILE_ATTRIBUTE_NORMAL, share_access, create_disposition, FILE_SYNCHRONOUS_IO_NONALERT, nullptr, 0));
}

bool file::close()
{
  auto handle = handle_;
  handle_ = nullptr;
  return NT_SUCCESS(SysClose(handle));
}

ULONG file::read(PVOID data, ULONG size)
{
  IO_STATUS_BLOCK status = {};
  if (!NT_SUCCESS(SysReadFile(handle_, nullptr, nullptr, nullptr, &status, data, size, nullptr, nullptr))) {
    return 0;
  }
  if (!NT_SUCCESS(status.Status)) {
    return 0;
  }
  return static_cast<ULONG>(status.Information);
}

ULONG file::write(const PVOID data, ULONG size)
{
  IO_STATUS_BLOCK status = {};
  if (!NT_SUCCESS(SysWriteFile(handle_, nullptr, nullptr, nullptr, &status, const_cast<PVOID>(data), size, nullptr, nullptr))) {
    return 0;
  }
  if (!NT_SUCCESS(status.Status)) {
    return 0;
  }
  return static_cast<ULONG>(status.Information);
}

}  // namespace sys