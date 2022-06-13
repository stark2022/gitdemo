/*
 * @Descripttion:
 * @version:
 * @Author: wyzf
 * @Date: 2022-06-13 10:39:46
 * @LastEditors: wyzf
 * @LastEditTime: 2022-06-13 10:43:03
 */
#include <stdio.h>
#include <string.h>
long factorial(int n);//函数声明 阶乘
long sum_factorial(long);//可以只显示形参的数据类型
int gcd(int, int);

int strchar(char *str, char);


//无参函数的定义
// dataType founctionName() {
//     //body
// }
int sum() {
    int sum = 0;
    for (int i = 1;i < 101;i++) {
        sum += i;
    }
    return sum;
}
//return出来的数据类型与dateType的类型一样
//只能有一个return被返回；且被返回后，后面的所有语句都不会被执行；

// 无返回值函数
// void是关键字，表示"空类型"或"无类型",函数不需要返回值即没有return或者返回值类型不确定(很少见)
void hello() {
    printf("Hello,world\n");
}

//有参函数的定义
// dataType functionName(dataType1 param1, dataType2, param2...) {
//     //body
// }
int sums(int m, int n) {
    int sum = 0;
    if (m > n) {
        int temp = m;
        m = n;
        n = temp;
    }
    for (int i = m;i <= n;i++) {
        sum += i;
    }

    return sum;
}

//判断素数
int prime(int n) {
    int is_prime = 1;
    if (n < 0) {
        printf("%d is a illegal number.\n", n);
    }
    for (int i = 2;i < n;i++) {
        if (n % i == 0) {
            is_prime = 0;
            break;
        }
    }
    if (is_prime > 0) {
        printf("%d is a prime number.\n", n);
    }
    else {
        printf("%d is not a prime number.\n", n);
    }
    return is_prime;
}

int n = 10;//全局变量
void func1() {
    int n = 20;//局部变量
    printf("func1 n: %d\n", n);
}

void func2(int n) {
    printf("func2 n: %d\n", n);
}
void func3() {
    printf("func3 n: %d\n", n);
}
//C语言不允许函数嵌套定义，必须在所有函数之外定义另一个函数
//函数不能嵌套函数定义，main也是一个函数定义，所以sum放在main外面\
//函数必须先定义然后再使用，所以sum要放在main前面
//当可执行文件加载到内存后，系统从main函数开始执行，系统调用以定义的main函数
int main() {
    hello();
    int a = sum();
    printf("The sum is %d\n", a);

    int begin = 5, end = 86;
    int result = sums(5, 86);
    printf("The sum from %d to %d is %d\n", begin, end, result);
    int num;
    scanf("%d", &num);
    prime(num);
    sum_factorial(num);

    int n = 30;//局部变量
    func1();func2(n);func3();
    //f1 n为函数内部局部变量:20 
    //f2 n为形参局部变量，main内的n为实参30
    //f3内无局部变量遂从全局变量中查找后 n:10
    {
        int n = 40;//局部变量
        printf("block n: %d\n", n);
    }
    printf("main n: %d\n", n);

    printf("The greatest common divisor is %d\n", gcd(100, 60));
    char utl[] = "http://ax-b.cn";
    char letter = 'c';
    if (strchar(utl, letter) >= 0) {
        printf("The letter is in the string.\n");
        printf("letter不在这里面： .\n");
    }
    else {
        printf("The letter is not in the string.\n");
        printf("letter不在这里面.\n");
    }
    return 0;
}

//函数的嵌套调用
// int a = 22, b = 11, c;
// c = a * b;
// 编译时出现错误：initializer element is not constant
// 在所有函数之外进行加减乘除运算、使用 if...else 语句、调用
// 一个函数等都是没有意义的，这些代码位于整个函数调用链条之外，
// 永远都不会被执行到。C语言也禁止出现这种情况，会报语法错误
long factorial(int n) {

    long result = 1;
    for (int i = 1;i <= n;i++) {
        result *= i;
    }
    return result;
}

long sum_factorial(long n) {

    long result = 0;
    for (int i = 1;i <= n;i++) {
        result += factorial(i);
    }
    printf("The sum_factorial is :%ld\n", result);
    return result;
}

//最大公约数
// 块级变量即 {} 在其内的局域变量只能在其内使用结束后即被覆盖
int gcd(int a, int b) {
    //若 a<b交换变量值
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
        printf("temp is : %d\n", temp);
    }
    while (b != 0) {
        int temp = b;//块级变量
        b = a % b;
        a = temp;
    }
    return a;
}
/**
数组作为函数的形参实际上是一个指针类型的形参，即将来可以接受
一个数组名表示的数组的起始地址！而并不是将一个数组的所有元素
传给一个函数，仅仅传递的是一个小小的指针变量
**/
int strchar(char *str, char c) {
    for (int i = 0, len = strlen(str);i < len;i++) {
        if (str[i] == c) {
            return i;
        }
    }
    return -1;
}