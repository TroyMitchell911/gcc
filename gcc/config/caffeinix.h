/* 如果您希望进行特定于目标的 GCC 更改，这将很有用。 */
#undef TARGET_CAFFEINIX
#define TARGET_CAFFEINIX 1 

/* 运行 i686-myos-gcc/x86_64-myos-gcc 工具链时所需的默认参数
   */
#undef LIB_SPEC 
#define LIB_SPEC "-lc" /* 链接至 C 标准库 */

/* 在用户代码之前链接的文件。
   %s 告诉 GCC 在库目录中查找这些文件。*/
#undef STARTFILE_SPEC 
#define STARTFILE_SPEC "crt0.o%s crti.o%s crtbegin.o%s" 

/* 在用户代码后链接的文件。 */
#undef ENDFILE_SPEC 
#define ENDFILE_SPEC "crtend.o%s crtn.o%s" 

/* 附加预定义宏。*/
#undef TARGET_OS_CPP_BUILTINS 
#define TARGET_OS_CPP_BUILTINS() \
  do { \
    builtin_define("__caffeinix__"); \
    builtin_define("__unix__"); \
    builtin_assert("system=caffeinix"); \
    builtin_assert("system=unix"); \
    builtin_assert("system=posix"); \
  } while (0)

/* Tell ld to force 4KB pages*/
#undef LINK_SPEC
#define LINK_SPEC "-z max-page-size=4096"
#ifdef LIB_SPEC
#undef LIB_SPEC
#endif
#define LIB_SPEC "-lc -lg -lm -lnosys"
