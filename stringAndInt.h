#include <ctype.h>
char *Int2String(int num) // 10进制
{
    char str[1000];
    int i = 0;   //指示填充str
    if (num < 0) //如果num为负数，将num变正
    {
        num = -num;
        str[i++] = '-';
    }
    //转换
    do
    {
        str[i++] = num % 10 + 48; //取num最低位 字符0~9的ASCII码是48~57；简单来说数字0+48=48，ASCII码对应字符'0'
        num /= 10;                //去掉最低位
    } while (num);                // num不为0继续循环

    str[i] = '\0';

    //确定开始调整的位置
    int j = 0;
    if (str[0] == '-') //如果有负号，负号不用调整
    {
        j = 1; //从第二位开始调整
        ++i;   //由于有负号，所以交换的对称轴也要后移1位
    }
    //对称交换
    for (; j < i / 2; j++)
    {
        //对称交换两端的值 其实就是省下中间变量交换a+b的值：a=a+b;b=a-b;a=a-b;
        str[j] = str[j] + str[i - 1 - j];
        str[i - 1 - j] = str[j] - str[i - 1 - j];
        str[j] = str[j] - str[i - 1 - j];
    }

    return str; //返回转换后的值
}
int String2Int(const char *nptr)
{
    int c;     /* 当前要转换的字符(一个一个字符转换成数字) */
    int total; /* 当前转换结果 */
    int sign;  /* 标志转换结果是否带负号*/

    /*跳过空格，空格不进行转换*/
    while (isspace((int)(unsigned char)*nptr))
        ++nptr;

    c = (int)(unsigned char)*nptr++; //获取一个字符准备转换
    sign = c;                        /*保存符号标示*/
    if (c == '-' || c == '+')
        c = (int)(unsigned char)*nptr++; /*跳过'+'、'-'号，不进行转换*/

    total = 0; //设置转换结果为0

    while (isdigit(c))
    {                                    //如果字符是数字
        total = 10 * total + (c - '0');  /* 根据ASCII码将字符转换为对应的数字，并且乘10累积到结果 */
        c = (int)(unsigned char)*nptr++; /* 取下一个字符 */
    }

    //根据符号指示返回是否带负号的结果
    if (sign == '-')
        return -total;
    else
        return total;
}
