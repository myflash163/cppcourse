# cppcourse

## 编辑器vscode

## 插件
c/c++
code Runer

## 文件描述符与文件指针转换

fileno:将文件指针转换为文件描述符
fdopen:将文件描述符转换位文件指针

## open() 系统调用

```
int open(const char *path,int flags);
int open(const char *path,int flags,mode_t mode);
```
- path:文件的名称，可以包含（绝对和相对）路径
- flags:文件打开模式
- mode:用来规定对该文件的所有者，文件的用户组及系统其他用户的访问权限

返回值
- 打开成功，返回文件描述符；
- 打开失败，返回-1


| 打开方式 |描述 | 
| --- | :---: | 
| O_RDONLY | 打开一个供读取的文件 | 
| O_WRONLY | 打开一个供写入的文件 |
| O_RDWR | 打开一个可供读写的文件 |
| O_APPEND | 写入的所有数据将被追加到文件末尾 |
| O_CREAT | 打开文件，如果文件不存在则建立文件 |
| O_EXCL | 如果已经置O_CREAT 且文件存在，则强制open()失败 |
| O_TRUNC | 在open()时，将文件的内容清空 |

## 系统能够打开的最大文件个数
```
cat /proc/sys/fs/file-max
```
