mmap:   
    mmap将一个文件或者其它对象映射进内存。文件被映射到多个页上，如果文件的大小不是所有页的大小之和，最后一个页不被使用的空间将会清零。mmap在用户空间映射调用系统中作用很大。

    头文件  #include<sys/mman.h>
    函数原型
        void* mmap(void* start,size_t length,int prot,int flags,int fd,off_t offset);
        int munmap(void* start,size_t length);

        mmap()[1] 必须以PAGE_SIZE为单位进行映射，而内存也只能以页为单位进行映射，若要映射非PAGE_SIZE整数倍的地址范围，要先进行内存对齐，强行以PAGE_SIZE的倍数大小进行映射。
        用法:

    下面说一下内存映射的步骤:
    用open系统调用打开文件, 并返回描述符fd.
    用mmap建立内存映射, 并返回映射首地址指针start.
    对映射(文件)进行各种操作, 显示(printf), 修改(sprintf).
    用munmap(void *start, size_t lenght)关闭内存映射.
    用close系统调用关闭文件fd.
    UNIX网络编程第二卷进程间通信对mmap函数进行了说明。该函数主要用途有三个：
    1、将一个普通文件映射到内存中，通常在需要对文件进行频繁读写时使用，这样用内存读写取代I/O读写，以获得较高的性能；
    2、将特殊文件进行匿名内存映射，可以为关联进程提供共享内存空间；
    3、为无关联的进程提供共享内存空间，一般也是将一个普通文件映射到内存中。

    函数：void *mmap(void *start,size_t length,int prot,int flags,int fd,off_t offsize);
    参数start：指向欲映射的内存起始地址，通常设为 NULL，代表让系统自动选定地址，映射成功后返回该地址。

    参数length：代表将文件中多大的部分映射到内存。

    参数prot：映射区域的保护方式。可以为以下几种方式的组合：
    PROT_EXEC 映射区域可被执行
    PROT_READ 映射区域可被读取
    PROT_WRITE 映射区域可被写入
    PROT_NONE 映射区域不能存取

    参数flags：影响映射区域的各种特性。在调用mmap()时必须要指定MAP_SHARED 或MAP_PRIVATE。
    MAP_FIXED 如果参数start所指的地址无法成功建立映射时，则放弃映射，不对地址做修正。通常不鼓励用此旗标。
    MAP_SHARED对映射区域的写入数据会复制回文件内，而且允许其他映射该文件的进程共享。
    MAP_PRIVATE 对映射区域的写入操作会产生一个映射文件的复制，即私人的“写入时复制”（copy on write）对此区域作的任何修改都不会写回原来的文件内容。
    MAP_ANONYMOUS建立匿名映射。此时会忽略参数fd，不涉及文件，而且映射区域无法和其他进程共享。
    MAP_DENYWRITE只允许对映射区域的写入操作，其他对文件直接写入的操作将会被拒绝。
    MAP_LOCKED 将映射区域锁定住，这表示该区域不会被置换（swap）。

    参数fd：要映射到内存中的文件描述符。如果使用匿名内存映射时，即flags中设置了MAP_ANONYMOUS，fd设为-1。有些系统不支持匿名内存映射，则可以使用fopen打开/dev/zero文件，然后对该文件进行映射，可以同样达到匿名内存映射的效果。

    参数offset：文件映射的偏移量，通常设置为0，代表从文件最前方开始对应，offset必须是分页(4k)大小的整数倍。

    返回值：

    若映射成功则返回映射区的内存起始地址，否则返回MAP_FAILED(－1)，错误原因存于errno 中。
