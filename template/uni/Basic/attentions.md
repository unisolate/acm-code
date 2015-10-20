1. 调试
输入输出格式？调试信息？文件函数？初始化？算术溢出？数组大小？
左右端点范围？acos/asin/sqrt 函数定义域？精度问题？
RE：爆栈？整数除以 0？数组严重越界？未 return 0？

2. Code::Blocks 更换终端
gnome-terminal -t $TITLE -x

3. 0 除以负数是负零，输出时加 eps，注意 sqrt(-0.00)

4. double 全局变量初始可能非零

5. 