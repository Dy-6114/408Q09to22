/*��Ŀ��
��֪һ����������A=(a0,a1,...,an-1)������0<=ai<n(0<i<n)��������ap1=ap2=...=apm=x��m>n/2�����xΪA����Ԫ�ء�����A=(0,5,5,3,5,7,5,5)����5Ϊ��Ԫ�أ�
����A=(0,5,5,3,5,1,5,7),��A��û����Ԫ�ء�����A�е�n��Ԫ�ر�����һ��һά�����У������һ�������ܸ�Ч���㷨���ҳ�A����Ԫ�ء���������Ԫ�أ��������Ԫ�أ�
�������-1��Ҫ��
1.�����㷨�Ļ������˼��
2.�������˼�룬����c,c++,Java�����㷨���ؼ�֮������ע��
3.˵���㷨��ʱ�临�ӶȺͿռ临�Ӷ�
*/
/*������
1.���˼�룺��1������һ����������
��2��ʹ�ø���������±����Ԫ��ֵ�����������ֵ����Ԫ�س��ֵĸ���
��3����¼���ִ�������Ԫ��
��4���жϸ�Ԫ�س��ֵĴ����Ƿ����n/2�������򷵻ظ�Ԫ�أ����򷵻�-1��
2.�㷨ʵ�����£�
3.ʱ�临�Ӷȣ�O(n)
�ռ临�Ӷ�:O(n)
*/

#include <iostream>
using namespace std;

int GetMajority(int A[], int n)
{
    int max = 0, *temp;
    temp = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        temp[i] = 0;
    }//������������
    for (int k = 0; k < n; k++)
    {
        temp[A[k]]++; //��¼A������ÿ��Ԫ�س��ֵĴ���
        if (temp[A[k]] > temp[max])
        {
            max = A[k]; //maxΪ���ִ��������Ԫ��
        }
    }
    if (temp[max] > (n / 2))
        return max;
    return -1;
}
/*���Ž⣺
1.���˼�룺�����Ǵ�ǰ���ɨ������Ԫ�أ���ǳ�һ�����ܳ�Ϊ��Ԫ�ص�Ԫ��Num��Ȼ�����¼�����ȷ��num�Ƿ�����Ԫ��
��1��ѡȡ��ѡ����Ԫ�أ�����ɨ�����������е�ÿ������������һ������������Num���浽c�У���¼Num�ĳ��ִ���Ϊ1��
����������һ�������Ե���Num�������+1���������-1������������0ʱ������������һ���������浽c�У��������¼�Ϊ1����ʼ��һ�ּ�����
���ӵ�ǰλ�ÿ�ʼ�ظ��������̣�ֱ��ɨ����ȫ������Ԫ�ء�
��2���ж�cԪ���Ƿ�����������Ԫ�أ��ٴ�ɨ������飬ͳ��c��Ԫ�س��ֵĴ�����������n/2����Ϊ��Ԫ�أ����������в�������Ԫ�ء�
2.�㷨ʵ�����£�
3.ʱ�临�Ӷȣ�O(n)
�ռ临�Ӷ�:O(1)
*/

int GetMajority_pro(int A[],int n)
{
    int c, count = 1;
    c = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] == c) count++;
        else if(count>0) count--;
        else{
            count = 1;
            c = A[i];
        }
    }
    if(count>0)
        for (int i = count = 0; i < n; i++)
        {
            if (A[i] == c) count++;
        }
    if(count > n/2) return c;
    return -1;   
    
}



int main(){
    int B[] = {0,5,5,3,5,1,5,7};
    int A[] = {0,5,5,3,5,7,5,5};
    cout<<"һ��ⷨ"<<endl;
    cout<<"A�����е���Ԫ��Ϊ:"<<GetMajority(A,8)<<endl;
    cout<<"B�����е���Ԫ��Ϊ:"<<GetMajority(B,8)<<endl;
    cout<<"���Žⷨ"<<endl;
    cout<<"A�����е���Ԫ��Ϊ:"<<GetMajority_pro(A,8)<<endl;
    cout<<"B�����е���Ԫ��Ϊ:"<<GetMajority_pro(B,8);
    return 0;
}