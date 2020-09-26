#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
vector<int> order(int num)
{
        vector<int> order;
        for(int i=0;i<num;i++)
        {
                order.push_back(i);
        }
        return order;
}
vector<int> inorder(int num)
{
        vector<int> inorder;
        for(int i=num;i>=0;i--)
        {
                inorder.push_back(i);
        }
        return inorder;
}
vector<int> reorder1 (vector<int> test)
{
        int x = test.size();
        for(int i=0;i<x;i++)
        {
            int local;
            for(int j=i;j<x;j++)
            {
                if(test[j]<test[i])
                {
                    local = test[j];
                    test[j]=test[i];
                    test[i]=local;
                    
                }

            }
        
        }
        return test;
}
vector<int> cut(vector<int> test,int begin,int end)
{
        vector<int> cut;
        if(end>(int)test.size()-1)
        {
                cut.push_back(1);
                return cut; 
        }
        else{
                for(int i=begin;i<=end;i++)
                {
                        cut.push_back(test[i]);
                }
                return cut;
        }

}

vector<int> reorder2 (vector<int> test)
{
        if(test.size()>2)
        {
                int num = (int)test.size()/2;
                int num2 = (int)test.size()-1;
                vector<int> one = reorder2(cut(test,0,num));
                vector<int> second = reorder2(cut(test,num+1,num2));
               // for(int i=0;i<(int)one.size();i++)
               // {
               //         cout<<"reorder"<<one[i]<<endl;
               // }

                int count=0;
                for(int i=0;i<=num;i++)
                {    

                        int help=0;
                        for(int j=count;j<(int)second.size();j++)
                        {       
                                help=0;
                                if(one[i]<second[j])
                                {
                                       // cout<<"sss"<<one[i]<<endl;
                                        second.insert(second.begin()+j,one[i]);
                                        help=1;
                                        count=j+1;//记录当前位置
                                        break;
                                }
                                


                        }
                        if(help==0)
                        {
                                second.insert(second.end(),one[i]);//如果是比所有都大就放到最后
                        }
                }
                return second;

        }else{
                if(test.size()==1)
                {
                      // cout<<test[0]<<"single"<<endl;
                       return test; 
                }
                else{
                      if(test[0]>test[1])
                      {
                             // cout<<test[0]<<"xx"<<test[1]<<endl;
                              int local =test[1];
                              test[1]=test[0];
                              test[0]=local;
                           //   cout<<test[0]<<"xx"<<test[1]<<endl;
                              return test;
                      }
                      else{
                              
                              return test;
                      }

                }

        }
}

vector<int> reorder3(vector<int> test)
{
        int number=2;//用来记录一组最大数量。
        int num=test.size()/number;//记录完整组的数量
        bool iffull=(int) (test.size()-num*number)>number/2;//不完全但可分组是否存在
        while(test.size()*2/number>=1)
        {
            for(int i=0;i<num;i++)//我现在有num个分组，这每一个分组要进行一次排序
            {
                    int local = i*number;//记录当前位置，不可更改
                    int now =i*number+number/2;//记录上一个插入位置
                    int help = 0;//记录是否是最大值，插入位置无法插入的现象
                    for(int j=0;j<number/2;j++)//开始对每一个小循环排序
                    {
                            help = 0;
                            for(int k=now;k<(i+1)*number;k++)//循环比较完整组最后的数字大小，并且插入,j记录新的中点位置
                            {
                                    if(test[local]<test[k])
                                    {
                                             test.insert(test.begin()+k,test[local]);
                                             now = k;
                                             help=1;
                                             break;
                                    }

                            }
                            if(help == 0)//比它们都大
                            {
                                    test.insert(test.begin()+(i+1)*number,test[local]);
                            }
                           test.erase(test.begin()+local);//擦除前面的内容，使得长度保持恒定
                           

                    }


            }
            if(iffull)
            {     
                   int help=0;
                   int now = num*number+number/2;
                   int local = num*number;
                   for(int j=0;j<number/2;j++)//开始处理最后一个循环
                   {
                           help = 0;
                           for(int k=now;k<(int)test.size();k++)//循环比较完整组最后的数字大小，并且插入,j记录新的中点位置
                           {
                                   if(test[local]<test[k])
                                   {
                                            test.insert(test.begin()+k,test[local]);
                                            now = k;
                                            help=1;
                                            break;
                                   }
         
                           }
                           if(help == 0)//比它们都大
                           {
                                   test.insert(test.end(),test[local]);

                           }
                           test.erase(test.begin()+local);//擦除前面的内容，使得长度保持恒定
                   
                   }
            }


            number=number*2;
            num=test.size()/number;
            iffull=(int) (test.size()-num*number)>number/2;
        }
        return test;
}

vector<int> rander(int num)
{
        vector<int> rander;
        for(int i=0;i<num;i++)
        {
                rander.push_back(rand());
        }
        return rander;
}

int main()
{
        vector<int> obj=order(101);
        for(int i=0;i<101;i++)
        {
                cout<<obj[i]<<endl;
        }
        //obj[1]=90;
        cout<<obj[1]<<endl;
        vector<int> obj2=inorder(10000);
        for(int i =0;i<10000;i++)
        {
                cout<<obj2[i]<<endl;
        }
        vector<int> obj3=rander(100);
        for(int i = 0;i<100;i++)
        {
                cout<<obj3[i]<<endl;
        }
        obj3=reorder1(obj3);
        cout<<"test"<<endl;
        cout<<"test"<<endl;
        for(int i = 0;i<100;i++)
        {
                cout<<obj3[i]<<endl;
        }
        vector<int> test(obj.begin()+90,obj.begin()+100);
        cout<<"test"<<endl;
        int text = test.size();
        for(int i=0;i< text;i++)
        {
                cout<<test[i]<<endl;
        }
        vector<int> mine=reorder3(obj2);
        for(int i=0;i< (int)mine.size();i++)
        {
                cout<<mine[i]<<endl;
        }
                
}

