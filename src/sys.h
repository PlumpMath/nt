#pragma once
#include <windows.h>
#include <winternl.h>

extern "C" {

// ZwCreateFile
// https://msdn.microsoft.com/en-us/library/windows/hardware/ff566424.aspx
NTSTATUS NTAPI SysCreateFile(
  OUT    PHANDLE FileHandle,
  IN     ACCESS_MASK DesiredAccess,
  IN     POBJECT_ATTRIBUTES ObjectAttributes,
  OUT    PIO_STATUS_BLOCK IoStatusBlock,
  IN     PLARGE_INTEGER AllocationSize OPTIONAL,
  IN     ULONG FileAttributes,
  IN     ULONG ShareAccess,
  IN     ULONG CreateDisposition,
  IN     ULONG CreateOptions,
  IN     PVOID EaBuffer OPTIONAL,
  IN     ULONG EaLength
);

// ZwClose
// https://msdn.microsoft.com/en-us/library/windows/hardware/ff566417.aspx
NTSTATUS NTAPI SysClose(
  IN     HANDLE Handle
);

// ZwReadFile
// https://msdn.microsoft.com/en-us/library/windows/hardware/ff567072.aspx
NTSTATUS NTAPI SysReadFile(
  IN     HANDLE FileHandle,
  IN     HANDLE Event OPTIONAL,
  IN     PIO_APC_ROUTINE ApcRoutine OPTIONAL,
  IN     PVOID ApcContext OPTIONAL,
  OUT    PIO_STATUS_BLOCK IoStatusBlock,
  OUT    PVOID Buffer,
  IN     ULONG Length,
  IN     PLARGE_INTEGER ByteOffset OPTIONAL,
  IN     PULONG Key OPTIONAL
);

// ZwWriteFile
// https://msdn.microsoft.com/en-us/library/windows/hardware/ff567121.aspx
NTSTATUS NTAPI SysWriteFile(
  IN     HANDLE FileHandle,
  IN     HANDLE Event OPTIONAL,
  IN     PIO_APC_ROUTINE ApcRoutine OPTIONAL,
  IN     PVOID ApcContext OPTIONAL,
  OUT    PIO_STATUS_BLOCK IoStatusBlock,
  IN     PVOID Buffer,
  IN     ULONG Length,
  IN     PLARGE_INTEGER ByteOffset OPTIONAL,
  IN     PULONG Key OPTIONAL
);

// ZwAllocateVirtualMemory
// https://msdn.microsoft.com/en-us/library/windows/hardware/ff566416.aspx
NTSTATUS SysAllocateVirtualMemory(
  IN     HANDLE ProcessHandle,
  IN OUT PVOID* BaseAddress,
  IN     ULONG_PTR ZeroBits,
  IN OUT PSIZE_T RegionSize,
  IN     ULONG AllocationType,
  IN     ULONG Protect
);

// ZwFreeVirtualMemory
// https://msdn.microsoft.com/en-us/library/windows/hardware/ff566460.aspx
NTSTATUS SysFreeVirtualMemory(
  IN     HANDLE ProcessHandle,
  IN OUT PVOID *BaseAddress,
  IN OUT PSIZE_T RegionSize,
  IN     ULONG FreeType
);


void* __cdecl memset(void* data, int value, size_t size);

}  // extern "C"
