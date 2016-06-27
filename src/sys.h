#pragma once
#include <windows.h>
#include <winternl.h>

extern "C" {

NTSTATUS NTAPI SysCreateFile(
  OUT PHANDLE FileHandle,
  IN  ACCESS_MASK DesiredAccess,
  IN  POBJECT_ATTRIBUTES ObjectAttributes,
  OUT PIO_STATUS_BLOCK IoStatusBlock,
  IN  PLARGE_INTEGER AllocationSize OPTIONAL,
  IN  ULONG FileAttributes,
  IN  ULONG ShareAccess,
  IN  ULONG CreateDisposition,
  IN  ULONG CreateOptions,
  IN  PVOID EaBuffer OPTIONAL,
  IN  ULONG EaLength
);

NTSTATUS NTAPI SysClose(
  IN  HANDLE Handle
);

NTSTATUS NTAPI SysReadFile(
  IN  HANDLE FileHandle,
  IN  HANDLE Event OPTIONAL,
  IN  PIO_APC_ROUTINE ApcRoutine OPTIONAL,
  IN  PVOID ApcContext OPTIONAL,
  OUT PIO_STATUS_BLOCK IoStatusBlock,
  OUT PVOID Buffer,
  IN  ULONG Length,
  IN  PLARGE_INTEGER ByteOffset OPTIONAL,
  IN  PULONG Key OPTIONAL
);

NTSTATUS NTAPI SysWriteFile(
  IN  HANDLE FileHandle,
  IN  HANDLE Event OPTIONAL,
  IN  PIO_APC_ROUTINE ApcRoutine OPTIONAL,
  IN  PVOID ApcContext OPTIONAL,
  OUT PIO_STATUS_BLOCK IoStatusBlock,
  IN  PVOID Buffer,
  IN  ULONG Length,
  IN  PLARGE_INTEGER ByteOffset OPTIONAL,
  IN  PULONG Key OPTIONAL
);

void* __cdecl memset(void* data, int value, size_t size);
void* __cdecl malloc(size_t size);

}  // extern "C"
