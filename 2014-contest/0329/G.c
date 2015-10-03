#include <iostream>  
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // time.h也可,用于计算程序运行时间和生成随机种子数   
using namespace std;  
#define SELF_RAND_MAX 0x7FFFFFFF  
int main()  
{  
 //typedef long clock_t   
 clock_t start_time = clock();//计时开始  
   
    srand(unsigned(time(0)));//生成时间种子  
 //生成的数值在1000到1000万之间   
    const int MAX = 1000000;  
    const int MIN = 10;  
    /*读入数据 freopen("in.txt","r",stdin);  
 //写入数据 freopen("out.txt","w",stdout); 
 //fclose(stdin);//关闭文件  
    //fclose(stdout);//关闭文件  
    把标准输入流stdin重定向到in.txt文件中， 
 这样在用scanf或是用cin输入时便不会从标准输入流读取数据, 
 而是从in.txt文件中获取输入。 
 只要把输入数据事先粘贴到in.txt，调试时就方便多了。  
    */  
  freopen("data.txt","w",stdout);  
  //cout << "---Generate 10,000,000 random numbers\  
  //         which maybe repeated---" << endl;  
 for(int i = 0; i < 100000; ++i){  
  //#define RAND_MAX 0x7FFF  
    //较标准unsigned long data = ( MAX * rand() )/ ( RAND_MAX + MIN)+ 1;  
    //unsigned long data = (MAX - MIN + 1 ) * rand() + MIN;  
   //unsigned long data = ((MAX - MIN + 1 ) * rand()   + MIN) % 10000000;  
   unsigned long data = rand() % (MAX - MIN + 1) + MIN;//较标准   
    cout << data << ' '; //输出数据到data.txt   
 }  
 fclose(stdout);  
 freopen("time.txt","w",stdout);  
 cout << endl   
      << "---the end---"   
   << endl;  
   //CLOCKS_PER_SEC控制精度，在windows环境下是1000,linux下是多少完了  
   //简单地说windows下是毫秒级，而linux下是纳秒级   
    cout << "elapsed time:" << double(clock() - start_time) / CLOCKS_PER_SEC  
         << 's' << endl;  
  //  fclose(stdout);  
}  