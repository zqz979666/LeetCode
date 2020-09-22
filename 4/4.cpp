#include <stdio.h>
#include <iostream>
#include <vector>
#include <windows.h>
//#include <cstring>

using namespace std;

int main(){

    vector<int> nums1,nums2;
    int l1=0,l2=0;
    int tmp=0,n=0;
    cout << "please input the length of nums1: " ;
    cin >> l1;
    nums1.resize(l1);
    cout << "please input the nums1: " ;
    while(n < l1)
    {
        cin >> tmp;
        nums1[n] = tmp;
        ++n;
    }
    n=0;
    cout << "please input the length of nums2: " ;
    cin >> l2;
    nums2.resize(l2);
    cout << "please input the nums2: " ;
    while(n < l2)
    {
        cin >> tmp;
        nums2[n] = tmp;
        ++n;
    }

    double result=0.0;
    int i=0,j=0,k=0;
    int flag = 0;
    if(l1 != 0 || l2 !=0)
    {
        if(l1 == 0)
        {
            if(l2%2 == 0) result = (nums2[l2/2 -1] + nums2[l2/2])/2.0;
            else result = nums2[l2/2];

            return result;
        }
        if(l2 == 0)
        {
            if(l1%2 == 0) result = (nums1[l1/2 -1] + nums1[l1/2])/2.0;
            else result = nums1[l1/2];

            return result;
        }
        while(k != (l1+l2)/2 && i != l1 && j != l2)//遍历找到中间位置的数
        {
            if(nums1[i] > nums2[j])
            {
                ++j;
                ++k;
                flag = 1;//最新的移动属于j
            }
            else{
                ++i;
                ++k;
                flag = 0;//最新的移动属于i
            }
        }
        //这里犯了一个逻辑错误。并不是说谁最后一个移动那么谁就是最接近中位数的一个
        //还需要比较一次大小

        //另外一个错误，当nums1或者nums2走到头时，k可能不是l1和l2的平均值
        //因此当k不是平均值时，不能用k去减i,而是用(l1+l2)/2表达式减k
        if((l1+l2)%2==0)//总元素个数为偶数，则中位数为平均值
        {
            if(i == l1)//若nums1到头，则nums2必不可能到头
            {
                if(k == (l1+l2)/2)//若此时已经到达中间的数
                    result = (nums1[i-1]+nums2[j])/2.0;
                else{//若没达到中间数，说明nums2还需要往右走
                    result = (nums2[j+(l1+l2)/2-k-1]+nums2[j+(l1+l2)/2-k])/2.0;
                }
            }
            if(j == l2)//若nums2到头，同理
            {
                if(k == (l1+l2)/2)//若此时已经到达中间的数
                    result = (nums1[i]+nums2[j-1])/2.0;
                else{//若没达到中间数，说明nums1还需要往右走
                    result = (nums1[i+(l1+l2)/2-k-1]+nums1[i+(l1+l2)/2-k])/2.0;
                }
            }
            if(i != l1 && j != l2)//若都没有到头,则必定k到达中间数
            {
                if(flag == 0) result = (nums1[i-1]+(nums2[j]>nums1[i]?nums1[i]:nums2[j]))/2.0;//最新的移动属于i，所以i退回1,另一个数为两者中较小数
                else result = ((nums1[i]>nums2[j]?nums2[j]:nums1[i])+nums2[j-1])/2.0;
            }
        }
        if((l1+l2)%2!=0)//总元素个数为奇数，则中位数为某个元素
        {
            if(i == l1)//若nums1到头，则nums2必不可能到头
            {
                if(k == (l1+l2)/2)//若此时已经到达中间的数，则最后一步必定是i移动
                    result = nums2[j];
                else{//若没达到中间数，说明nums2还需要往右走
                    result = nums2[j+(l1+l2)/2-k];
                }
            }
            if(j == l2)//若nums2到头，同理
            {
                if(k == (l1+l2)/2)//若此时已经到达中间的数,则最后一步必定是j移动
                    result = nums1[i];
                else{//若没达到中间数，说明nums1还需要往右走
                    result = nums1[i+(l1+l2)/2-k];
                }
            }
            if(i != l1 && j != l2)//若都没有到头,则必定k到达中间数
            {
                if(flag == 0) result = nums1[i]>nums2[j]?nums2[j]:nums1[i];//最新的移动属于i，所以i退回1
                else result = nums2[j]>nums1[i]?nums1[i]:nums2[j];
            }
        }
    }
    cout.precision(4);
    cout << "the middle number: " << result;

    system("pause");
    return 0;
}