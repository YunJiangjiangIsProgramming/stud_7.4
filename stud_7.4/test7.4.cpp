#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

//�ַ������
//string.at()����������һ������ĳ���±���ַ�,�ǳ��������������е�[]
//int* ansArr = new int[len1 + len2](); ��δ��������˸�������ʼ�����е�Ԫ��Ϊ0
class Solution1 {
public:
    string multiply(string num1, string num2) {
        // ���num1��num2����һ����"0"��ֱ�ӷ���"0"
        // ������Ϊ�κ�������0������0�����Կ�����ǰ���ؽ��
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int len1 = num1.size(); // ��ȡnum1�ĳ���
        int len2 = num2.size(); // ��ȡnum2�ĳ���

        // ����һ������ansArr���ڴ洢�����˻���ÿһλ���
        // ����ĳ�����len1 + len2����Ϊ������˵���󳤶���len1 + len2
        int* ansArr = new int[len1 + len2]();

        // ��num1�����λ��ʼ�����������λ
        for (int i = len1 - 1; i >= 0; i--) {
            // ��num1�ĵ�ǰλת��Ϊ����
            int x = num1.at(i) - '0';
            // ��num2�����λ��ʼ�����������λ
            for (int j = len2 - 1; j >= 0; j--) {
                // ��num2�ĵ�ǰλת��Ϊ����
                int y = num2.at(j) - '0';
                // ��x��y�ĳ˻��ӵ�ansArr�Ķ�Ӧλ��
                // ����ʹ��i + j + 1����ΪansArr��������0��ʼ����num1��num2��������1��ʼ
                ansArr[i + j + 1] += x * y;
            }
        }

        // �����λ
        // ��ansArr�����λ��ʼ�����������λ
        for (int i = len1 + len2 - 1; i > 0; i--) {
            // ����λ�ӵ�ǰһλ
            ansArr[i - 1] += ansArr[i] / 10;
            // ����ǰλȡģ����������
            ansArr[i] %= 10;
        }

        // ����һ�����ַ���ans���ڴ洢���ս��
        string ans;

        // ����ansArr��ǰ��0
        int index = 0;
        while (index < len1 + len2 && ansArr[index] == 0) {
            index++;
        }
        // ��ansArrת��Ϊ�ַ�����ע������������Ѿ�������ǰ��0
        while (index < len1 + len2) {
            ans.append(to_string(ansArr[index]));
            index++;
        }

        // �ͷŶ�̬������ڴ�
        delete[] ansArr;

        return ans; // ���������˻����ַ�����ʾ
    }
};


int main()
{


	return 0;
}