#ifndef LS_H_
#define LS_H_

// #define S_IFMT  00170000
// #define S_IFSOCK 0140000
// #define S_IFLNK	 0120000
// #define S_IFREG  0100000
// #define S_IFBLK  0060000
// #define S_IFDIR  0040000
// #define S_IFCHR  0020000
// #define S_IFIFO  0010000
// #define S_ISUID  0004000
// #define S_ISGID  0002000
// #define S_ISVTX  0001000

extern int lsFileL(const char * filename);
extern int lsDirL(const char *dirname);
extern int ls(const char *path);
extern int lsFile(const char *filename);
extern int lsDir(const char *dirname);
#endif