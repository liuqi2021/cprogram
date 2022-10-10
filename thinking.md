1/  对于printf函数来说，当打印的是字符串时，传的参数是地址，当打印值时，传递的参数是值；
    Puts函数接收的是地址，如puts(s)
    具体可以参考function_parameter.c


(1)在malloc的时候，注意传递给函数的参数是不是要用二级指针,因为如果传递的是一维指针的话，可能会在子函数中生成的指针不能被释放，详细可看mallo.c;
(2)在给字符赋值的时候，注意变量是字符变量还是字符指针字符变量可以直接赋值，但是字符指针需要使用strcpy()函数进行赋值;
(3)#typedef struct{}STU/struct{}STU; 

2.
 1831  gcc -shared -fpic -o libfifo.so fifo.c
 1832  ls
 1835  sudo mv libfifo.so /usr/local/lib/
 1839  sudo cp fifo.h /usr/local/include/
 1841  sudo /sbin/ldconfig

3.
标准io和系统io不可以混用。原因是标准IO有缓冲区，当执行完文件的写操作之后不是立即写入磁盘中，而是放在了缓冲区。当使用标准IO执行完写操作，又使用系统IO执行写操作时，会导致指向文件的当前位置不同。


4.
dup2 is better than dup2

5.
写程序时不能将自己的思维局限于写一个函数，应当时刻记得自己写的是一个模块，属于一个系统，要保证程序的安全性。除了避免写越界，内存泄露以外，还要保证资源谁打开谁关闭

6.
big_file.c文件在调用lseek函数时写了一个很大的整形，导致溢出，需要声明为long long类型才可以