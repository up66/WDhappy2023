/*王道计算机*/
//
//
/**/
//
/**/
//

/*1.从数据库删除最小值元素（假设唯一）并返回被删除元素，空出位置由后位补。若顺序表为空，显示错误信息并退出*/
//算法思想：搜索整个顺序表，查找最小值元素并记住其位置，搜索结束后用最后一个元素填补空出的原最小元素的位置
//代码：
bool Del_Min(sqList &L,ElemType &value){
		if(L.length==0)    //判断长度，长度为0即空， 返回false
				return false;
		value=L.data[0]; //假定第一个元素最小，之后比较进行交换
		int pos=0;  //用于标记删除的元素位置i
		for(int i=1;i<L.length;i++){
				if(L.data[i]<value){  //查找比第一个元素小的，不断进行交换
						value=L.data[i];  //存在更小的进行交换
						pos=i;   //记住位置
				}
		}
		L.data[pos]=L.data[L.length-1];//将位置由最后一个元素补充，因为下标是0 开始，所以最后一个元素的下标是length-1
		L.length--;//删除最小元素（唯一的意思是假定一个），相应长度需要减少
		return true;
}

//2.设置一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为1
/*算法思想：扫描顺序表L的前半部分，对于元素L.data[i](0 <= i < L.length/2),将其与后半部分的对应元素L.data[L.length-i-1]进行交换*/
//代码：
void Reserve(Sqlist &L){
		Elemtype temp;
		for(int i=0;i<L.length/2;i++){
				temp=L.data[i];   //把左元素赋值给temp，防止后面赋值覆盖前面数据导致丢失
				L.data[i]=L.data[L.length-i-1];  //左=右
				L.data[L.length-i-1]=temp; //右=temp(先前保存的左元素)
		}
}


//3.对于长度为n的顺序表L，编写时间复杂度0（n），空间复杂度0（1）算法，删除表中所有值为x的值
//算法思想：k记录不等于x的值，修改L长度
//解法一：
void del_x_1(Sqlist &L,Elemtype x){
		int k=0,i;
		for(i=0;i<L.length;i++){
				if(L.data[i]!=x){
						L.data[k]=L.data[i]; //遍历寻找不等于x的值返回给原数组，下标变化
						k++;
				}
				L.length=k;
		}
}

//解法二：
void del_x_2(Sqlist &L,Elemtype x){
		int k=0,i=0;
		while(i<L.length){
				if(L.data[i]==x)
						k++;
				else
						L.data[i-k]=L.data[i]; //前移k个位置 7-6类似
				i++;
		}
		L.length=L.length-k;
}

//4.(有序顺序表)删除s-t值之间元素（连续）(s<t)，若不合理或顺序表为空，显示错误信息
void Del_s_t2(Sqlist &L,Elemtype s,Elemtype t){
		int i,j;
		if(s>=t||L.length=0)
				return false;
		for(i=0;i<L.length&&L.data[i]<s;i++);//寻找第一个大于s的元素 下标s<i   
		if(i>=L.length)
				return false;
		for(j=i;i<L.length&&L.data[j]<=t;j++);////寻找第一个大于t的元素 下标j>t  
		for(;j<L.length;j++)
				L.data[i]=L.data[j]; //前移，填补被删除元素(开始：s-t，前移i《j)   s 【i(值大于等于s的第一个元素)……t】 j
}


//5.(顺序表)删除s-t值之间元素（连续）(s<t)(包含s和t)，若不合理或顺序表为空，显示错误信息
void Del_s_t(Sqlist &L,Elemtype s,Elemtype t){
		int i,k=0;
		if(s>=t||L.length=0)
				return false;
		for(i=0;i<L.length;i++){
				if(L.data[i]>=s&&L.data[i]<=t)//寻找s-t元素（包含便捷）
						k++;
				else
						L.data[i-k]=L.data[i];  //s(<=i)……t(<=)j
		}
		L.length-=k;
		return true;
}

//6 有序顺序表(值相同的元素连续)中删除重复元素,剩余均不同(可以调试看)
bool Delete_Same(SqList &L){
		int i,j;
		if(L.length==0)
				return false;
		for(i=0,j=1;j<L.length;j++)
				if(L.data[i]!=L.data[j])//第一个元素是不变，后一个和前一个对比，如果不同，插入进去i++，j++向后判断，if相同，i不变，j向后找不同插入进去
						L.data[++i]=L.data[j];//相当于把相同的第二个元素覆盖  -----(简单来说：L.data[0]确定，后面比较不同L.data[j]插入)
		L.length=i+1;
		return true;
}
//如果本题是无序表 o（n），用散列表

//7 两有序顺序表合并新有序表 c=a并b(不同的)（重要）,返回新
bool Merge(SeqList A,SeqList B,SeqList &C){
		int i,j=0,k=0;
		if(A.length+B.length>C.MaxSize)
				return false;
		while(i<A.length&&j<B.length){
				if(A.data[i]<B.data[j])
						C.data[k++]=A.data[i++];//先把A.data[i]插入，然后i++再进行后面比较
				else
						C.data[k++]=B.data[j++];
		}
		while(i<A.length)  //最后全部比较完之后还会剩余一个没有匹配完.进行判断
				C.data[k++]=A.data[i++];
	  while(j<A.length)  
				C.data[k++]=B.data[j++];
		C.length=k;
		return true;
}


//8 一维数组存放两个线性表，a（1-m），b（1-n）下标，两个顺序表位置互换，b放在a之前
//本题王道：逆置
typedef int DataType;
void Reserve(DataType A[],int left,int right,int arraySize){
		//a1 a2……an,b1,b2……bn
		//one:bn …… b2,b1,an……a2,a1（全部逆置）
		//two:b1,b2……bn,a1,a2……an
		Elemtype temp;
		if(left>right||right>=arraySize)
		int mid=(right+left)/2;
		for(int i=0;i<mid-left;i++){
				DataType temp=A[left+i];   //把左元素赋值给temp，防止后面赋值覆盖前面数据导致丢失
				A[left+i]=L.data[right-i];  //左=右
				A[right-i]=temp; //右=temp(先前保存的左元素)
		}
}

void Exchange(DataType A[],int m,int n,int arraySize){
		Reserve(A,0,m+n-1,arraySize);//全部
		Reserve(A,0,n-1,arraySize);//前半部分
		Reserve(A,n,m+n-1,arraySize);//后半部分
}


//9 线性表a1-an,递增有序且顺序存储于计算机，最少时间查找数值为x值，找到与后继元素互换，找不到插入到表中，表仍然递增有序
//可以顺序、折半=》折半时间少
void SearchExchangeInsert(ElemType A[],ElemType x){
		int low=0,high=n-1,mid;
		while(low<high){     //找到A[mid]==x 》mid 
				mid=(low+high)/2;
				if(A[mid]==x) 
						break;
				else if(A[mid]<x)
						low=mid+1;
				else
						high=mid+1;
		}
		if(A[mid]==x&&mid!=n-1){  //mid!=high 假设最后一个元素等于x，不存在后继元素交换,提前剔除这个情况
				t=A[mid];
				A[mid]=A[mid+1];
				A[mid+1]=t;
		}
		if(low>high){     //查找失败，这个x插入到表中仍然递增有序
				for(i=n-1;i>high;i--) //n-1是查找失败的位置,n-1后位置后移，插入这个x（当i=high结束）
						A[i+1]=A[i];
				A[i+1]=x;
		}
}


//10.一维数组R，R中循环左移p(0<p<n)  x0 x1……x(n-1)  =》 xp x(p+1) …x(n-1) x1 x0 … x(p-1)
/***
(1)给出算法的基本设计思想
		将这个问题视为数组ab》ba(a前p个元素，b代表余下的n-p个元素,)
		a逆置a^-1*b   b逆置a^-1*b^-1  最后真个a^-1*b^-1逆置  (a^-1*b^-1)^-1=ba
		设Reverse函数执行逆置操作 对abcdefgh左循环移动3（p=3）位置过程如下：
		Reverse(0,p-1);cba defgh
		Reverse(p,n-1);cba hgfed
		Reverse(0,n-1);defghabc
(2)根据设计思想，代码，关键之处给注释
(3)时空复杂度
 Revesve时间复杂度分别是O(p/2) O((n-p)/2) O(n/2)=》时间复杂度：O(n) 空间复杂度O(1)
**/

void Revesve(int R[],int from,int to){
		int i,temp;
		for(int i=0;i<(to-from+1)/2;i++){
				temp=L.data[from+i];   //把左元素赋值给temp，防止后面赋值覆盖前面数据导致丢失
				L.data[from+i]=L.data[to-i];  //左=右 (可以理解为双向奔赴)
				L.data[to-i]=temp; //右=temp(先前保存的左元素)
		}
}

void Converse(int R[],int n,int p){
		Reserve(R,0,p-1);//全部
		Reserve(R,p,0,n-1);//前半部分
		Reserve(R,0,n-1);//后半部分
}


//11 L升序S。处在L/2(向上取整)的数称为S的中位数 S1={11,13,15,17,19},中位数15，两个序列的中位数是包含所有元素的升序序列的中位数。
//例S2={2,4,6,8,20} S1和S2的中位数是11   =>两个等长升序序列A B，找出A,B的中位数
/**
		(1)算法思想
		(2)代码及注释
		(3)时空复杂度
*/


