.code

align 10h
public SysCreateFile
SysCreateFile PROC
  mov     r10, rcx
  mov     eax, 55h
  syscall
  ret
SysCreateFile ENDP

align 10h
public SysClose
SysClose PROC
  mov     r10, rcx
  mov     eax, 0Fh
  syscall
  ret
SysClose ENDP

align 10h
public SysReadFile
SysReadFile PROC
  mov     r10, rcx
  mov     eax, 06h
  syscall
  ret
SysReadFile ENDP

align 10h
public SysWriteFile
SysWriteFile PROC
  mov     r10, rcx
  mov     eax, 08h
  syscall
  ret
SysWriteFile ENDP

align 10h
public SysAllocateVirtualMemory
SysAllocateVirtualMemory PROC
  mov     r10, rcx
  mov     eax, 18h
  syscall
  ret
SysAllocateVirtualMemory ENDP

align 10h
public SysFreeVirtualMemory
SysFreeVirtualMemory PROC
  mov     r10, rcx
  mov     eax, 1Eh
  syscall
  ret
SysFreeVirtualMemory ENDP

memset PROC
  arg     = qword ptr  8
  mov     [rsp + arg], rdi
  mov     r9, rcx
  test    r8, r8
  jz      short __memset_return
  mov     rdi, rcx
  movsx   rax, dl
  mov     rcx, r8
  rep     stosb
__memset_return:
  mov     rdi, [rsp + arg]
  mov     rax, r9
  ret
memset ENDP

end