#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/errno.h>
#include "hello1.h"

MODULE_AUTHOR("Poltavskiy Volodymyr <whtspoint@gmail.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel");
MODULE_LICENSE("Dual BSD/GPL");

static unsigned int repeat_count = 1;
module_param(repeat_count, uint, 0644);
MODULE_PARM_DESC(repeat_count, "Скільки разів вивести рядок 'Hello, world!'");

static int __init hello2_init(void) {
    if (repeat_count == 0 || (repeat_count >= 5 && repeat_count <= 10)) {
        pr_warn("Невірне значення параметра.\n");
    } else if (repeat_count > 10) {
        pr_err("Невірне значення параметра. Модуль не завантажено.\n");
        return -EINVAL;
    }

    print_hello(repeat_count);

    return 0;
}

static void __exit hello2_exit(void) {
    pr_info("Unloading hello2 module\n");
}

module_init(hello2_init);
module_exit(hello2_exit);

MODULE_ALIAS("hello2");