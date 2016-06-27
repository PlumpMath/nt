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
  mov     eax, 6
  syscall
  ret
SysReadFile ENDP

align 10h
public SysWriteFile
SysWriteFile PROC
  mov     r10, rcx
  mov     eax, 8
  syscall
  ret
SysWriteFile ENDP

memset PROC
  arg     = qword ptr  8
  mov     [rsp + arg], rdi
  mov     r9, rcx
  test    r8, r8
  jz      short memset_return
  mov     rdi, rcx
  movsx   rax, dl
  mov     rcx, r8
  rep     stosb
memset_return:
  mov     rdi, [rsp + arg]
  mov     rax, r9
  ret
memset ENDP

end