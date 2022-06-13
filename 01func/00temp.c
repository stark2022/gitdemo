/*
 * @Descripttion: 库函数源码函数的实现比较
 * @version:
 * @Author: wyzf
 * @Date: 2022-05-28 13:50:08
 * @LastEditors: wyzf
 * @LastEditTime: 2022-05-31 14:03:03
 */

#include <stdio.h>
#include <string.h>
int strcmp_alias(char *s1, char *s2) {
    int i, result;
    for (i = 0; (result = s1[i] - s2[i]) == 0; i++) {
        if (s1[i] == '\0' || s2[i] == '\0') {
            break;
        }
    }

    return result;
}

int main() {
    char str1[] = "abcdefg";
    char str2[] = "abcdefgh";
    char str3[] = "a";
    //重复使用strcmp_alias()函数
    int result_1_2 = strcmp_alias(str1, str2);
    int result_1_3 = strcmp_alias(str1, str3);
    printf("str1  - str2 = %d\n", result_1_2);
    printf("str1  - str3 = %d\n", result_1_3);

    int result_strcmp = strcmp(str1, str2);
    printf("str1-str2=%d\n", result_strcmp);
    return 0;
}





// int
// STRCMP (const char *p1, const char *p2)
// {
//   const unsigned char *s1 = (const unsigned char *) p1;
//   const unsigned char *s2 = (const unsigned char *) p2;
//   unsigned char c1, c2;

//   do
//     {
//       c1 = (unsigned char) *s1++;
//       c2 = (unsigned char) *s2++;
//       if (c1 == '\0')
// 	return c1 - c2;
//     }
//   while (c1 == c2);

//   return c1 - c2;
// }
// libc_hidden_builtin_def (strcmp)
