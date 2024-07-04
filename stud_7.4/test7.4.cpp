#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

//字符串相乘
//string.at()可以橡数组一样访问某个下标的字符,非常好用类似数组中的[]
//int* ansArr = new int[len1 + len2](); 这段代码最后加了个（）初始化所有的元素为0
class Solution1 {
public:
    string multiply(string num1, string num2) {
        // 如果num1或num2中有一个是"0"，直接返回"0"
        // 这是因为任何数乘以0都等于0，所以可以提前返回结果
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int len1 = num1.size(); // 获取num1的长度
        int len2 = num2.size(); // 获取num2的长度

        // 创建一个数组ansArr用于存储两数乘积的每一位结果
        // 数组的长度是len1 + len2，因为两数相乘的最大长度是len1 + len2
        int* ansArr = new int[len1 + len2]();

        // 从num1的最低位开始，遍历到最高位
        for (int i = len1 - 1; i >= 0; i--) {
            // 将num1的当前位转换为整数
            int x = num1.at(i) - '0';
            // 从num2的最低位开始，遍历到最高位
            for (int j = len2 - 1; j >= 0; j--) {
                // 将num2的当前位转换为整数
                int y = num2.at(j) - '0';
                // 将x和y的乘积加到ansArr的对应位置
                // 这里使用i + j + 1是因为ansArr的索引从0开始，而num1和num2的索引从1开始
                ansArr[i + j + 1] += x * y;
            }
        }

        // 处理进位
        // 从ansArr的最高位开始，遍历到最低位
        for (int i = len1 + len2 - 1; i > 0; i--) {
            // 将进位加到前一位
            ansArr[i - 1] += ansArr[i] / 10;
            // 将当前位取模，保存余数
            ansArr[i] %= 10;
        }

        // 创建一个空字符串ans用于存储最终结果
        string ans;

        // 跳过ansArr的前导0
        int index = 0;
        while (index < len1 + len2 && ansArr[index] == 0) {
            index++;
        }
        // 将ansArr转换为字符串，注意这里的索引已经跳过了前导0
        while (index < len1 + len2) {
            ans.append(to_string(ansArr[index]));
            index++;
        }

        // 释放动态分配的内存
        delete[] ansArr;

        return ans; // 返回两数乘积的字符串表示
    }
};


int main()
{


	return 0;
}