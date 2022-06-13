/*
 * @Auther: WYZF
 * @Date: 2021-12-20 16:55:37
 * @version: 
 * @LastEditTime: 2021-12-21 10:03:23
 */
#include <stdio.h>
void fordemo(void);
void fordemo(void)
{
    int i,j,k;
    for(j=0;j<1000;j++)
    {
        if(j%100==0)
        {
            ++k;
            i=720000/(k*100);printf("i变量值：%d\n",i);
        }
        
    }
}

// void times(void);
// void times(void)
// {

// }
int main(void)
{
    
    fordemo();
}
