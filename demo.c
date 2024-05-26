int　n　 = 5;
double　x;
int* p1 = &n;
double* pd = &x;
x = n;　　　　　　　// 隐式类型转换
pd = p1;　　　　　　// 编译时错误
//更复杂的类型也是如此。假设有如下声明：
int* pt;
int(*pa)[3];
int ar1[2][3];
int ar2[3][2];
int** p2; // 一个指向指针的指针
//有如下的语句：
pt = &ar1[0][0]; // 都是指向int的指针
pt = ar1[0]; // 都是指向int的指针
pt = ar1;  // 无效
pa = ar1;  // 都是指向内含3个int类型元素数组的指针
pa = ar2;  // 无效
p2 = &pt;  // both pointer-to-int *
*p2 = ar2[0]; // 都是指向int的指针
p2 = ar2; // 无效