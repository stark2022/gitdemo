/*
 * @Auther: WYZF
 * @Date: 2021-11-18 18:42:03
 * @version:printf函数输出字符串时，从0号元素开始检索，遇到'\0'才停止,然后把'\0'前面的字符全部输出
 * 但是在单片机中不存在这种问题，这里要特别注意
 * @LastEditTime: 2022-06-01 15:06:54
 */
#include <stdio.h>
int main() {
    char str[30];
    char c;
    int i;
    for (c = 65, i = 0; c <= 90; c++, i++) {
        str[i] = c;
    }
    str[i] = 0;  //此处为添加的代码，也可以写作 str[i] = '\0';
    printf("%s\n", str);

    return 0;
}