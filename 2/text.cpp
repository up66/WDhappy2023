/*���������*/
//
//
/**/
//
/**/
//

/*1.�����ݿ�ɾ����СֵԪ�أ�����Ψһ�������ر�ɾ��Ԫ�أ��ճ�λ���ɺ�λ������˳���Ϊ�գ���ʾ������Ϣ���˳�*/
//�㷨˼�룺��������˳���������СֵԪ�ز���ס��λ�ã����������������һ��Ԫ����ճ���ԭ��СԪ�ص�λ��
//���룺
bool Del_Min(sqList &L,ElemType &value){
		if(L.length==0)    //�жϳ��ȣ�����Ϊ0���գ� ����false
				return false;
		value=L.data[0]; //�ٶ���һ��Ԫ����С��֮��ȽϽ��н���
		int pos=0;  //���ڱ��ɾ����Ԫ��λ��i
		for(int i=1;i<L.length;i++){
				if(L.data[i]<value){  //���ұȵ�һ��Ԫ��С�ģ����Ͻ��н���
						value=L.data[i];  //���ڸ�С�Ľ��н���
						pos=i;   //��סλ��
				}
		}
		L.data[pos]=L.data[L.length-1];//��λ�������һ��Ԫ�ز��䣬��Ϊ�±���0 ��ʼ���������һ��Ԫ�ص��±���length-1
		L.length--;//ɾ����СԪ�أ�Ψһ����˼�Ǽٶ�һ��������Ӧ������Ҫ����
		return true;
}

//2.����һ����Ч�㷨����˳���L������Ԫ�����ã�Ҫ���㷨�Ŀռ临�Ӷ�Ϊ1
/*�㷨˼�룺ɨ��˳���L��ǰ�벿�֣�����Ԫ��L.data[i](0 <= i < L.length/2),�������벿�ֵĶ�ӦԪ��L.data[L.length-i-1]���н���*/
//���룺
void Reserve(Sqlist &L){
		Elemtype temp;
		for(int i=0;i<L.length/2;i++){
				temp=L.data[i];   //����Ԫ�ظ�ֵ��temp����ֹ���渳ֵ����ǰ�����ݵ��¶�ʧ
				L.data[i]=L.data[L.length-i-1];  //��=��
				L.data[L.length-i-1]=temp; //��=temp(��ǰ�������Ԫ��)
		}
}


//3.���ڳ���Ϊn��˳���L����дʱ�临�Ӷ�0��n�����ռ临�Ӷ�0��1���㷨��ɾ����������ֵΪx��ֵ
//�㷨˼�룺k��¼������x��ֵ���޸�L����
//�ⷨһ��
void del_x_1(Sqlist &L,Elemtype x){
		int k=0,i;
		for(i=0;i<L.length;i++){
				if(L.data[i]!=x){
						L.data[k]=L.data[i]; //����Ѱ�Ҳ�����x��ֵ���ظ�ԭ���飬�±�仯
						k++;
				}
				L.length=k;
		}
}

//�ⷨ����
void del_x_2(Sqlist &L,Elemtype x){
		int k=0,i=0;
		while(i<L.length){
				if(L.data[i]==x)
						k++;
				else
						L.data[i-k]=L.data[i]; //ǰ��k��λ�� 7-6����
				i++;
		}
		L.length=L.length-k;
}

//4.(����˳���)ɾ��s-tֵ֮��Ԫ�أ�������(s<t)�����������˳���Ϊ�գ���ʾ������Ϣ
void Del_s_t2(Sqlist &L,Elemtype s,Elemtype t){
		int i,j;
		if(s>=t||L.length=0)
				return false;
		for(i=0;i<L.length&&L.data[i]<s;i++);//Ѱ�ҵ�һ������s��Ԫ�� �±�s<i   
		if(i>=L.length)
				return false;
		for(j=i;i<L.length&&L.data[j]<=t;j++);////Ѱ�ҵ�һ������t��Ԫ�� �±�j>t  
		for(;j<L.length;j++)
				L.data[i]=L.data[j]; //ǰ�ƣ����ɾ��Ԫ��(��ʼ��s-t��ǰ��i��j)   s ��i(ֵ���ڵ���s�ĵ�һ��Ԫ��)����t�� j
}


//5.(˳���)ɾ��s-tֵ֮��Ԫ�أ�������(s<t)(����s��t)�����������˳���Ϊ�գ���ʾ������Ϣ
void Del_s_t(Sqlist &L,Elemtype s,Elemtype t){
		int i,k=0;
		if(s>=t||L.length=0)
				return false;
		for(i=0;i<L.length;i++){
				if(L.data[i]>=s&&L.data[i]<=t)//Ѱ��s-tԪ�أ�������ݣ�
						k++;
				else
						L.data[i-k]=L.data[i];  //s(<=i)����t(<=)j
		}
		L.length-=k;
		return true;
}

//6 ����˳���(ֵ��ͬ��Ԫ������)��ɾ���ظ�Ԫ��,ʣ�����ͬ(���Ե��Կ�)
bool Delete_Same(SqList &L){
		int i,j;
		if(L.length==0)
				return false;
		for(i=0,j=1;j<L.length;j++)
				if(L.data[i]!=L.data[j])//��һ��Ԫ���ǲ��䣬��һ����ǰһ���Աȣ������ͬ�������ȥi++��j++����жϣ�if��ͬ��i���䣬j����Ҳ�ͬ�����ȥ
						L.data[++i]=L.data[j];//�൱�ڰ���ͬ�ĵڶ���Ԫ�ظ���  -----(����˵��L.data[0]ȷ��������Ƚϲ�ͬL.data[j]����)
		L.length=i+1;
		return true;
}
//�������������� o��n������ɢ�б�

//7 ������˳���ϲ�������� c=a��b(��ͬ��)����Ҫ��,������
bool Merge(SeqList A,SeqList B,SeqList &C){
		int i,j=0,k=0;
		if(A.length+B.length>C.MaxSize)
				return false;
		while(i<A.length&&j<B.length){
				if(A.data[i]<B.data[j])
						C.data[k++]=A.data[i++];//�Ȱ�A.data[i]���룬Ȼ��i++�ٽ��к���Ƚ�
				else
						C.data[k++]=B.data[j++];
		}
		while(i<A.length)  //���ȫ���Ƚ���֮�󻹻�ʣ��һ��û��ƥ����.�����ж�
				C.data[k++]=A.data[i++];
	  while(j<A.length)  
				C.data[k++]=B.data[j++];
		C.length=k;
		return true;
}


//8 һά�������������Ա�a��1-m����b��1-n���±꣬����˳���λ�û�����b����a֮ǰ
//��������������
typedef int DataType;
void Reserve(DataType A[],int left,int right,int arraySize){
		//a1 a2����an,b1,b2����bn
		//one:bn ���� b2,b1,an����a2,a1��ȫ�����ã�
		//two:b1,b2����bn,a1,a2����an
		Elemtype temp;
		if(left>right||right>=arraySize)
		int mid=(right+left)/2;
		for(int i=0;i<mid-left;i++){
				DataType temp=A[left+i];   //����Ԫ�ظ�ֵ��temp����ֹ���渳ֵ����ǰ�����ݵ��¶�ʧ
				A[left+i]=L.data[right-i];  //��=��
				A[right-i]=temp; //��=temp(��ǰ�������Ԫ��)
		}
}

void Exchange(DataType A[],int m,int n,int arraySize){
		Reserve(A,0,m+n-1,arraySize);//ȫ��
		Reserve(A,0,n-1,arraySize);//ǰ�벿��
		Reserve(A,n,m+n-1,arraySize);//��벿��
}


//9 ���Ա�a1-an,����������˳��洢�ڼ����������ʱ�������ֵΪxֵ���ҵ�����Ԫ�ػ������Ҳ������뵽���У�����Ȼ��������
//����˳���۰�=���۰�ʱ����
void SearchExchangeInsert(ElemType A[],ElemType x){
		int low=0,high=n-1,mid;
		while(low<high){     //�ҵ�A[mid]==x ��mid 
				mid=(low+high)/2;
				if(A[mid]==x) 
						break;
				else if(A[mid]<x)
						low=mid+1;
				else
						high=mid+1;
		}
		if(A[mid]==x&&mid!=n-1){  //mid!=high �������һ��Ԫ�ص���x�������ں��Ԫ�ؽ���,��ǰ�޳�������
				t=A[mid];
				A[mid]=A[mid+1];
				A[mid+1]=t;
		}
		if(low>high){     //����ʧ�ܣ����x���뵽������Ȼ��������
				for(i=n-1;i>high;i--) //n-1�ǲ���ʧ�ܵ�λ��,n-1��λ�ú��ƣ��������x����i=high������
						A[i+1]=A[i];
				A[i+1]=x;
		}
}


//10.һά����R��R��ѭ������p(0<p<n)  x0 x1����x(n-1)  =�� xp x(p+1) ��x(n-1) x1 x0 �� x(p-1)
/***
(1)�����㷨�Ļ������˼��
		�����������Ϊ����ab��ba(aǰp��Ԫ�أ�b�������µ�n-p��Ԫ��,)
		a����a^-1*b   b����a^-1*b^-1  ������a^-1*b^-1����  (a^-1*b^-1)^-1=ba
		��Reverse����ִ�����ò��� ��abcdefgh��ѭ���ƶ�3��p=3��λ�ù������£�
		Reverse(0,p-1);cba defgh
		Reverse(p,n-1);cba hgfed
		Reverse(0,n-1);defghabc
(2)�������˼�룬���룬�ؼ�֮����ע��
(3)ʱ�ո��Ӷ�
 Revesveʱ�临�Ӷȷֱ���O(p/2) O((n-p)/2) O(n/2)=��ʱ�临�Ӷȣ�O(n) �ռ临�Ӷ�O(1)
**/

void Revesve(int R[],int from,int to){
		int i,temp;
		for(int i=0;i<(to-from+1)/2;i++){
				temp=L.data[from+i];   //����Ԫ�ظ�ֵ��temp����ֹ���渳ֵ����ǰ�����ݵ��¶�ʧ
				L.data[from+i]=L.data[to-i];  //��=�� (�������Ϊ˫�򱼸�)
				L.data[to-i]=temp; //��=temp(��ǰ�������Ԫ��)
		}
}

void Converse(int R[],int n,int p){
		Reserve(R,0,p-1);//ȫ��
		Reserve(R,p,0,n-1);//ǰ�벿��
		Reserve(R,0,n-1);//��벿��
}


//11 L����S������L/2(����ȡ��)������ΪS����λ�� S1={11,13,15,17,19},��λ��15���������е���λ���ǰ�������Ԫ�ص��������е���λ����
//��S2={2,4,6,8,20} S1��S2����λ����11   =>�����ȳ���������A B���ҳ�A,B����λ��
/**
		(1)�㷨˼��
		(2)���뼰ע��
		(3)ʱ�ո��Ӷ�
*/


