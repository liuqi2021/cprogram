这个双向循环链表实现了回调函数的应用，需要好好看一下
回调函数的原理是：1、首先定义一个被回调的函数；
                2、使用typedef定义一个和回调函数相同的函数；
                3、将该函数的类型传递给调用回调函数的函数，之后调用回调函数的函数会调用回调函数


 *p = malloc(sizeof(**p));
  *p = malloc(sizeof(*p));

  // typedef struct user_func{
//     void (*print_student)(const void *);

// }user_function;


        memcpy(value, tmp->data, sizeof(*data));
        // memcpy(value, tmp->data, ptr->size);