/*2.1 �����ڶ��£������⡣��һС�ڣ����Ա�*/

/*
#include <stdio.h>

typedef struct student
{
	int num;
	char name[30];
	char sex[30];
}stu, * Studet;
//����һ���ṹ���������������壬��main�н��нṹ��ֵ��֮�����

typedef int INT;
int main()
{
	stu s = { 180,"��ɺ","��" };
	Studet p;
  int n = 100;
	p = &s;
	printf("%d,���:%d\n", n, p->num);
	printf("����:%s,�Ա�:%s\n",p->name,p->sex);
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
	d = (int*)malloc(20);//ǿ������ת��
	d[0] = 1;
}

int main()
{
	int s = 10;
	change(s);
	printf("%d\n", s);
	int* d = NULL;
	gave(d);//��*dָ��ĵ�ַd����
	printf("%d\n", d[0]);

	int a = 10;
	int* b = &a;
	printf("%d\n",a);//aֵ��10
	printf("%d\n",&a);	//aֵ��ַ��xx
	printf("%d\n",b);//*b��&a(ȡa�ĵ�ַ)��b�ǵ�ַ��*bָ���ȡֵ��b��xx
	printf("%d\n",*b);//*b��ֵ����aֵ��10
	printf("%d\n",&*b);//��ȡ
	printf("%d\n",*&b);
	printf("%d\n",*&a);
	return 0;
}
*/


/*01 ɾ����СԪ�أ�����Ψһ����������СԪ�أ��ճ�λ�ú��油*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>  
#define MaxSize 50
#define InitSize 100
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize]; //�ٶ�˳����Ԫ������ElemType
	int length;  //˳���ĵ�ǰ����
}SqList;		//˳�������Ͷ���

//��̬���䡣��̬����

typedef struct {
	ElemType *data; //ָ����̬���������ָ��
	int length;  //�������������͵�ǰ����
}SeqList;		//��̬��������˳�������Ͷ���
//c:malloc,c++:new


//11 ������� iλ��(1<=i<L.length+1)
bool ListInsert(SqList &L,int i,ElemType e){
		if(i<1||i>L.length+1) //�ж�i�Ĳ���λ���Ƿ�Ϸ�
				return false;
		if(L.length>=MaxSize) //�жϴ洢�ռ��Ƿ����������򲻲�
				return false;
		for(int j=L.length;j>=i;j--) //��ʼ��length-1~i,����������i(j)~length-1+1
				L.data[j]=L.data[j-1];  //i��Ԫ�غ��� i==>
		L.data[i-1]=e;//iλ�ò���
		L.length++;
		return true;
}

//22 ɾ������ iλ��(1<=i<L.length)����Χ�Ͳ��벻ͬ��
bool ListDelete(SqList &L,int i,ElemType &e){
		if(i<1||i>L.length) 
				return false;
		e=L.data[i-1];//iλ��ɾ�����±�i-1+1�� ��i��Ԫ��ǰ�� i<==
		for(int j=i;j<L.length;j++) //��ʼ��length-1~i,����������i(j)~length-1+1
				L.data[j-1]=L.data[j];  //i
		L.length--;
		return true;
}

//˳�����
int LocalElem(SqList L,ElemType e){
		int i;
		for(i=0;i<L.length;i++)
				if(L.data[i]==e)//��ǰ=������ҵ�һ��Ԫ�ص���e��ֵ
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

//7 ������˳���ϲ�������� c=a��b(��ͬ��)����Ҫ��,������
bool Merge(SqList A,SqList B,SqList &C){
		int i=0,j=0,k=0;
		if(A.length+B.length>MaxSize)
				return false;
		while(i<A.length&&j<B.length){
				if(A.data[i]<=B.data[j])
						C.data[k++]=A.data[i++];//�Ȱ�A.data[i]���룬Ȼ��i++�ٽ��к���Ƚ�
				else
						C.data[k++]=B.data[j++];
		}
	//	printf("2121212\n");
		while(i<A.length)  //���ȫ���Ƚ���֮�󻹻�ʣ��һ��û��ƥ����.�����ж�
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
				L.data[i]=i;//����ֵ
				L.length++; //length���ܶ�
		}
		for(i=0;i<10;i++){
				B.data[i]=i;//����ֵ
				B.length++; //length���ܶ�
		}
		//ListInsert(L,2,121);//i�������λ���Ǵ�1��ʼ����Ҫ�������±����
		//ListInsert(B,2,121);
		//ListInsert(L,3,121);
		Merge(L,B,C);
		//ListDelete(L,3,e);//һ���Բ���
		//Delete_Same(L);
		int local=LocalElem(L,5);//����Ԫ��Ϊ5��λ�ã������±꣩
		//printf("%d\n",local);
		for(i=0;i<C.length;i++){
				printf("%d\t",C.data[i]);
		}
		return 0;
}





