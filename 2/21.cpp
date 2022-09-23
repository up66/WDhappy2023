/*2.1 王道第二章，代码题。第一小节，线性表*/

/*
#include <stdio.h>

typedef struct student
{
	int num;
	char name[30];
	char sex[30];
}stu, * Studet;
//定义一个结构，里面有三个主体，在main中进行结构赋值，之后输出

typedef int INT;
int main()
{
	stu s = { 180,"张珊","男" };
	Studet p;
  int n = 100;
	p = &s;
	printf("%d,身高:%d\n", n, p->num);
	printf("姓名:%s,性别:%s\n",p->name,p->sex);
	return 0;
}
*/

/*
#include <stdio.h>
#include <malloc.h>

void change(int& s)
{
	s++;

};
void gave(int*& d)
{
	d = (int*)malloc(20);//强制类型转换
	d[0] = 1;
}

int main()
{
	int s = 10;
	change(s);
	printf("%d\n", s);
	int* d = NULL;
	gave(d);//把*d指针的地址d传入
	printf("%d\n", d[0]);

	int a = 10;
	int* b = &a;
	printf("%d\n",a);//a值：10
	printf("%d\n",&a);	//a值地址：xx
	printf("%d\n",b);//*b是&a(取a的地址)，b是地址，*b指针获取值。b：xx
	printf("%d\n",*b);//*b是值，是a值：10
	printf("%d\n",&*b);//先取
	printf("%d\n",*&b);
	printf("%d\n",*&a);
	return 0;
}
*/


/*01 删除最小元素（假设唯一），返回最小元素，空出位置后面补*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>  
#define MaxSize 50
#define InitSize 100
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize]; //假定顺序表的元素类型ElemType
	int length;  //顺序表的当前长度
}SqList;		//顺序表的类型定义

//静态分配。动态分配

typedef struct {
	ElemType *data; //指定动态分配数组的指针
	int length;  //数组的最大容量和当前个数
}SeqList;		//动态分配数组顺序表的类型定义
//c:malloc,c++:new


//11 插入操作 i位置(1<=i<L.length+1)
bool ListInsert(SqList &L,int i,ElemType e){
		if(i<1||i>L.length+1) //判断i的插入位置是否合法
				return false;
		if(L.length>=MaxSize) //判断存储空间是否已满。满则不插
				return false;
		for(int j=L.length;j>=i;j--) //开始是length-1~i,插入数据是i(j)~length-1+1
				L.data[j]=L.data[j-1];  //i后元素后移 i==>
		L.data[i-1]=e;//i位置插入
		L.length++;
		return true;
}

//22 删除操作 i位置(1<=i<L.length)（范围和插入不同）
bool ListDelete(SqList &L,int i,ElemType &e){
		if(i<1||i>L.length) 
				return false;
		e=L.data[i-1];//i位置删除，下标i-1+1后 即i后元素前移 i<==
		for(int j=i;j<L.length;j++) //开始是length-1~i,插入数据是i(j)~length-1+1
				L.data[j-1]=L.data[j];  //i
		L.length--;
		return true;
}

//顺序查找
int LocalElem(SqList L,ElemType e){
		int i;
		for(i=0;i<L.length;i++)
				if(L.data[i]==e)//从前=》后查找第一个元素等于e的值
						return i+1;
				return 0;
}

bool Delete_Same(SqList &L){
		int i,j;
		if(L.length==0)
				return false;
		for(i=0,j=1;j<L.length;j++)
				if(L.data[i]!=L.data[j])
						L.data[++i]=L.data[j];
		L.length=i+1;
		return true;
}

//7 两有序顺序表合并新有序表 c=a并b(不同的)（重要）,返回新
bool Merge(SqList A,SqList B,SqList &C){
		int i=0,j=0,k=0;
		if(A.length+B.length>MaxSize)
				return false;
		while(i<A.length&&j<B.length){
				if(A.data[i]<=B.data[j])
						C.data[k++]=A.data[i++];//先把A.data[i]插入，然后i++再进行后面比较
				else
						C.data[k++]=B.data[j++];
		}
	//	printf("2121212\n");
		while(i<A.length)  //最后全部比较完之后还会剩余一个没有匹配完.进行判断
				C.data[k++]=A.data[i++];
	  while(j<A.length)  
				C.data[k++]=B.data[j++];
		C.length=k;
		//printf("ccc:%d\n",C.length);
		return true;
}

int main()
{
		SqList L;
		SqList B;
		SqList C;
		int i=0,e=0;
		int flag=0;
		L.length=0;
		B.length=0;
		for(i=0;i<10;i++){
				L.data[i]=i;//赋初值
				L.length++; //length不能丢
		}
		for(i=0;i<10;i++){
				B.data[i]=i;//赋初值
				B.length++; //length不能丢
		}
		//ListInsert(L,2,121);//i代表插入位置是从1开始，不要和数组下标混淆
		//ListInsert(B,2,121);
		//ListInsert(L,3,121);
		Merge(L,B,C);
		//ListDelete(L,3,e);//一次性操作
		//Delete_Same(L);
		int local=LocalElem(L,5);//查找元素为5的位置（不是下标）
		//printf("%d\n",local);
		for(i=0;i<C.length;i++){
				printf("%d\t",C.data[i]);
		}
		return 0;
}





