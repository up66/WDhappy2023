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
		(3)ʱ�ո��Ӷ� O(log2n)  �ռ䣺O(1)
*/


//�㷨�������˼�룺�ֱ���A,B����λ������Ϊa��b���������£�
/**
		one:a=b a��b��Ϊ������λ��
		two:a<b ���A�н�С��B�нϴ��һ�룬Ҫ�����������ĳ�����ͬ
		three:a>b ����A�нϴ��B�н�С��һ�룬Ҫ�����������ĳ�����ͬ
		�ڱ������������������У��ظ�1.2.3������ֱ�����������о�ֻ��һ��Ԫ��Ϊֹ����С��Ԫ�ؼ�Ϊ������λ��
*/

int M_Search(int A[],int B[],int n){
		int s1=0,d1=n-1,m1,s2=0,d2=n-1,m2;
		//�ֱ��ʾA,B����λ����ĩβ������λ�� //s1 m1 d1,s2 m2  d2
		while(s1!=d1||s2!=d2){
				m1=(s1+d1)/2;//A��λ���±�
				m2=(s2+d2)/2;//B��λ���±�
				if(A[m1]==B[m2]) //if A B��λ����ͬ������һ������
						return A[m1];
				if(A[m1]<B[m2]){  //if A < B��λ��,����A�н�С�ģ�B �нϴ��
						if((s1+d1)%2==0){
								s1=m1;  //A����λ��=A��ĩβ��
								d2=m2;  //B��ĩβ��=B����λ���� //m1 d1,s2 m2
						}
						else{
								s1=m1+1;
								d2=m2;  //m1+1 d1,s2 m2
						}
				}
				else{  //����A�нϴ�ĺ�B�н�С��
						if((s1+d1)%2==0){
							  d1=m1;
								s2=m2;	//s1 d1 m2 d2
						}
				}
		}
		return A[s1]<B[s2]?A[s1]:B[s2]; //���������еĽ�Сֵ //s1,s2ʼ�ձ���Ķ�����λ��
}

//12 ��������A=(a0,a1,����a^n-1),0<= a^i <n(0<=i<n)
//������ap1=ap2=����apm=x��m>n/2����0<=pk<n,a<=k<=n������xΪA����Ԫ�ء�
//����A=(0,5,5,3,5,7,5,5) 5Ϊ��Ԫ�أ�5> 8/2��  ����A=(0,5,5,3,5,1,5,7) (4< 8/2)û����Ԫ�ء�
/**
		����A�е�n��Ԫ�ر�����һ��һά�����У��ҳ�A����Ԫ�أ�������������������-1
		��1�������㷨�Ļ������˼��
		��2�����뼰ע��
		��3��ʱ�ո��Ӷ� O(n)  �ռ䣺O(1)
*/

/**
		�㷨˼��:��ǰ����ɨ������Ԫ�أ���ǳ�һ�����ܳ�Ϊ��Ԫ�ص�ֵNum��ȷ�����Ƿ�Ϊ��Ԫ��.������
		(1)ѡȡ��ѡ����Ԫ�ء���ǰ����ɨ��ÿ������������һ������������Num�浽c�У���¼��Num���ִ������ٴγ���+1,�����1�����¸������������浽c�У�
		���¼���Ϊ1����ʼ��һ�ּ������ӵ�ǰλ�ÿ�ʼ�ظ��������̣�ֱ��ɨ����ȫ������Ԫ��
		(2)�ж�c��Ԫ���Ƿ�����������Ԫ�أ��ٴ�ɨ������飬ͳ��c��Ԫ�س��ֵĴ�����������n/2����Ϊ��Ԫ�أ����򲻴���
*/

int Majority(int A[],int n){
		int i,c,count-1;//c����������Ԫ�أ�count��������
		c=A[0];
		for(i=1;i<n;i++)
				if(A[i]==c)
						count++;
				else
						if(count>0)  //�����Ǻ�ѡ��Ԫ�ص����
								count--;
						else{
							c=A[i]; //������ѡ��Ԫ�أ����¼���
							count=1;
						}
		if(count>0)
				for(i=count=0;i<n;i++)
						if(A[i]==c)
								count++; //ͳ�ƺ�ѡ��Ԫ�ص�ʵ�ʳ��ִ���
		if(count>n/2)
				return c;//ȷ����Ԫ��
		else
				return -1;
}


//13 ��n��n>=1�������������飬�ҳ�������δ���ֵ���С����������������{-5,3,2,3}��δ������С������1������{1,2,3}δ������С������4
/**
		��1���㷨�Ļ������˼��
				Ҫ����ʱ���Ͼ����ܸ�Ч���ռ任ʱ�䡣����һ�����ڱ�ǵ�����B[n],������¼A���Ƿ������1~n����������B[0]��Ӧ������1��B[n-1]��Ӧ������n
			��ʼ��B��ȫ��Ϊ0.
			����A�к���n�����������ܷ��ص�ֵΪ1~n+1  A��n�����պ�Ϊ1~nʱ����n+1  ����С������Ϊn+1��
			������A�г���С�ڵ���0�����n��ֵ�ᵼ��1~n�г��ֿ���λ�ã����ؽ����1~n֮��  ����С��������1~n֮�䣩
			������A�г�����С�ڵ���0��ֵ������ȡ����  ��С��0ʱ�����ڴ˷�Χ�ڵ���С��������
		��2�������ע��
		��3��ʱ�ո��Ӷ�  O(n)  �ռ䣺O(n)
*/
int findMissMin(int A[],int n){
		int i,*B; //�������
		B=(int *)malloc(sizeof(int)*n);//����ռ�
		memset(B,0,sizeof(int)*n);//����ֵΪ0
		for(i=0;i<n;i++)
				if(A[i]>0&&A[i]<=n) //��ֵ��0-n��Χ�ڣ��������B
						B[A[i]-1]=1;
		for(i=0;i<n;i++)//ɨ������B���ҵ�Ŀ��ֵ
				if(B[i]==0) //��ֵ����0��1�Ǳ���ǵ�=���ҵ�����0��ֵ��Ϊ�����±꣬��B[0]=0 ��0+1=1  ����B[0]=B[1]=B[2]=1��B[3]=0;��i+1=4
						break;
		return i+1;//���ؽ�� 
}

//14  ������Ԫ��(a,b,c)(a,b,c��Ϊ����)�ľ���D=|a-b|+|b-c|+|c-a| ���������ǿ���������S1,S2,S3.��������ֱ�洢��3�������С�
//����������п��ܵ���Ԫ��(a,b,c)(a,b,c�ֱ�����S1,S2,S3)�е���С���롣
/**
		���磺S1={-1,0,9}��S2={-25,-10,10,11},S3={2,9,17,30,41}������С����Ϊ2����Ӧ����Ԫ��{9,10,9}
*/
/**
		(1)�������˼��
				���ۣ�
				one��a=b=cʱ��������С
				two���������������a<=b<=c ������  a__(L1)___b___(L2)___c  a___(L3)___c
				L1=|a-b|  L2=|b-c|  L3=|c-a|  D=|a-b|+|b-c|+|c-a|=L1+L2+L3=2L3
				���Ͽ�֪������D��С�Ĺؼ���ac֮��ľ���
		(2)�����ע��
		(3)ʱ�ո��Ӷ� O(n),O(1)
*/
/**
		�㷨�Ļ���˼�룺
		1��ʹ��Dmin��¼�����Ѵ������Ԫ�����С���룬��ֵΪһ���㹻���������
		2������S1,S2,S3�ֱ𱣴�������A,B,C�С�������±����i=j=k=0����i<|S1|��j<|S2|��k<|S3|ʱ����|S|��ʾ����S�е�Ԫ�ظ�������ѭ��ִ���������
		a.���㣨A[i],B[j],C[k]���ľ���D������D��
		b.��D<Dmin,��Dmin=D������D��
		c.��A[i],B[j],C[k]�е���Сֵ���±�+1,�����շ�������СֵΪa�����ֵΪc��c�������a���ҵ���С�ľ���D��
		3�����Dmin  
*/
#define INT_MAX ox7fffffff //�������� 0x7FFFFFFF �Ķ����Ʊ�ʾ���ǳ�����λ�� 0�����඼��1,�������������� int����Ϊ��һλ�Ƿ���λ��0 ��ʾ����������
int abs_(int a){//�������ֵ
		if(a<0)
				return -a;
		else
				return a;
}
bool xls_min(int a,int b,int c){//a�Ƿ�������������Сֵ
		if(a<=b&&a<=c)
				return true;
		return false;
}
int findMinofTrip(int A[],int n,int B[],int m,int c[],int p){
		//D_min��¼��Ԫ���е���С���룬����ֵΪINT_MAX
		int i=0,j=0,k=0,D_min=INT_MAX,D;
		while(i<n&&j<m&&k<p&&D_min>0){
				D=abs_(A[i]-B[j])+abs_(B[j]-C[k])+abs_(C[k]-A[i]);//����D
				if(D<D_min)
						D_min=D; //��ȡ��Сֵ������D
				if(xls_min(A[i],B[j],C[k]))
						i++; //����a
				else if(xls_min(B[j],C[k],A[i]))
						j++; 
				else
						k++;
		}
		return D_min;
}


//������
/**
*/

typedef struct LNode{ 
		ElemType data;
		struct LNode *next; //ָ����
}LNode,*LinkLst;

//ͷ�巨
LinkList List_HeadInsert(LinkList &L){
		LNode *s,int x;
		L=(LinkList)malloc(sizeof(LNode)); //����ͷ���
		L->next=NULL;  //��ʼΪ������
		scanf("%d",&x);
		while(x!=9999){ //9999����
				s=(LNode*)malloc(sizeof(LNode));//�����½��
				s->data=x;
				s->next=L->next;  //  L s(x) 
				L->next=s;        //�Ȱ��²�����ģ����ݡ�ָ���򣩴���ã���ȥ����L��s�Ĺ�ϵ����ֹ������
				scanf("%d",&x);
		}
		return L;
}

//β�巨����������
LinkList List_TailInsert(LinkList &L){  // L(r) s(ֵΪx)���²����s�����β��㣩
		int x;
		L=(LinkList)malloc(sizeof(LNode)); //����ͷ���
		LNode *s,*r=L;//rΪ��βָ��
		scanf("%d",&x);
		while(x!=9999){ //9999����
				s=(LNode*)malloc(sizeof(LNode));//�����½��
				s->data=x;
				r->next=s;   
				r=s;       //rָ���µı�β���
				scanf("%d",&x);
		}
		r->next=NULL;//βָ���ÿ�
		return L;
}

//����Ų��ҽ��ֵ
LNode *GetElem(LinkList L,int i){
		int j=1;//��ʼΪ1
		LNode *p=L->next; //��һ�����ָ�븳��p
		if(i==0)
				return L;  //����ͷ���
		if(i<1)
				return NULL;
		while(p&&j<i){ //Ѱ�ҽ���ڵ�һ��ֵ֮�󣬱����������
				p=p->next;
				j++;
		}
		return p;  //����Ѱ�ҵ��ĵ�i�����
}

//��ֵ���ұ���
LNode *LocateElem(LinkList L,ElemType e){
		LNode *p=L->next; //�ӵ�һ����㿪ʼ����
		while(p!=NULL&&p->data!=e)
				p=p->next;
		return p;
}

//��������� ʱ�临�Ӷȣ�O(n)
//����a��p�� s(ֵΪx)(λ��i) b����
p=GetElem(L,i-1); //���Ҳ���λ�õ�ǰ�����
s->next=p->next;
p->next=s;

//��ĳ������ǰ��(ת��Ϊ������)   ʱ�临�Ӷȣ�O(1)
//  s  a(p) b ��a(p) s  b (��p->data��s->data���н���)
s->next=p->next;
p->next=s;
temp=p->data;
p->data=s->data;
s->data=temp;


//ɾ����i�����
// (p)a (q)b(i) c  ɾ��b
pGetElem(L,i-1);
q=p->next; //qָ��ɾ�����
p->next=q->next; //��*q�������С��Ͽ���
freeq(q);  //�ͷŽ��Ĵ洢�ռ�
/*���������Ǵ�����ͷ���˳�����ǰ����㣬Ȼ��ִ��ɾ��������ʱ�临�Ӷ�O(n) 
  ɾ������ú�̽�����ʵ�֣�ʵ���ǽ���̽��ֵ��������Ȼ��ɾ����̽�㣬ʱ�临�Ӷ�O(1).������ɾ��*p(ת����pֵ����q��qɾ��)
*/
q=p->next;
p->data=p->next->data;
p->next=q->next;
freeq(q);



/***************************************˫����*********************************************************************************/
//������ͣ�
typedef struct DNode{  //˫����������
		ElemType data;
		struct DNode *prior,*next;
}DNode,*DLinklist;

//˫���������*s  
//p(aֵ) s(xֵ) c
s->next=p->next; //s��� s>c  1
p->next->prior=s; //p���ǰ��  s<c  2
s->prior=p; //sǰ�� p<s
p->next=s;  //p���  p>s  4
//1,2������4֮ǰ

//ɾ��
//p(a)  q(b) c
p->next=q->next;  //p>q
q->next->prior=p;  //p<q
free(q);

//��̬����
#define MaxSize 50
typedef struct{
		ElemType data;
		int next;//�¸�Ԫ�ص������±�
}SLinkList(MaxSize);




/*********************************************�����ڶ���******************************************************/

//����//
/**����������������**/
typedef struct LNode{     //���嵥����������
		ElemType data;					//������
		struct LNode *next;   //ָ����
}LNode,*LinkList;



//01���һ���ݹ��㷨��ɾ������ͷ���ĵ�����L������ֵΪx�Ľ��
//f(L,x)��f(L->next,x)������ɾ����L->nextΪ�׽��ĵ�����������ֵ����x�Ľ��
/**
��ֹ������f(L,x)�����κ�����   LΪ�ձ�ʱ
�ݹ�����:f(L,x)ɾ��L��㣬f(L>next,x)(��L->data==x)
f(L,x)=f(L->next,x); �������
*/
void Del_X_3(LinkList &L,ElemType x){
		LNode *p;  //pָ���ɾ�����
		if(L==NULL){
				return;
		}
		if(L->data==x){  //��L��ָ���ֵΪx
				p=L;  //ɾ��*L,����Lָ����һ���
				L=L->next;
				free(p);
				Del_X_3(L,x);//�ݹ����
		}
		else   //��L��ָ���ֵ��Ϊx
				Del_X_3(L->next,x);	//�ݹ����
}

//02 �ڴ�ͷ���ĵ�����L�У�ɾ������ֵΪx�Ľ�㣬���ͷ���ռ䣬����ֵΪx�Ĳ�Ψһ
/*�ⷨһ:p��ͷ��βɨ�赥����preָ��*p��ǰ������p��ָ���ֵΪxɾ��������pָ����һ����㣬������pre��pָ��ͬ������һ�����*/
void Del_X_1(LinkList &L,ElemType x){
		//LΪ��ͷ���ĵ�����
		LNode *p=L->next,*pre=L,*q;//��p��pre�ĳ�ʼֵ   ////       (pre)L p------  L----pre------p(q)(ɾ��)----m(p->next)  
		while(p!=NULL){
				if(p->data==x){
						q=p;  //q��ָ���(��ַ)
						p=p->next;  
						pre->next=p;  //ɾ��*q���
						free(q);   //�ͷ�*q���Ŀռ�
				}
				else{
						pre=p;  //��ʱp�㲻����x�����ǰ�����������
						p=p->next;
				}
		}
}

/*�ⷨ��:����β�巨������������pָ��ɨ��L���н�㣬����ֵ��Ϊxʱ���������ӵ�L֮�󣬷����ͷ�*/
void Del_X_2(LinkList &L,ElemType x){
		//LΪ��ͷ���ĵ�����
		LNode *p=L->next,*r=L,*q;       ////    L(r)---p---   //rָ��β��㣬���ֵΪͷ���
		while(p!=NULL){
				if(p->data!=x){
						r->next=p;
						r=p;  //�൱��r=r->next;
						p=p->next;//����ɨ��   //r��p�������λ   �����һδΪ�գ�r����β���
				}
				else{
						q=p;     //��ȵ�ʱ�򣬰�p���λ�ã�����x����λ�ø�ֵ��q�����ͷ�,��һ��ֵ��ֵ�����p
						p=p->next;
						free(q);
				}
		}
		r>next=NULL;//�����������βָ��ΪNULL
}
//���������㷨ɨ��һ������ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�O(1)

//03 L��ͷ���ĵ�����ʵ���������ÿ�����ֵ
/**
		�ı�����ķ��򡣻��ɽ���ջʵ�֣�ÿ����һ�����ʱ�����ý�����ջ�У�����������֮���ٴ�ջ����ʼ������ֵ�������ɵݹ�ʵ��ÿ�η���
		һ����㣬�ȵݹ����������Ľ�㣬�������㱾��
*/
void R_Print(LinkList L){
		//��β��ͷ���������L��ÿ������ֵ
		if(L->next!=NULL){
				R_Print(L->next); //�ݹ�
		}
		if(L!=NULL)   //��������һλ�������֮ǰ
				print(L->data); //�������
}
void R_Ignore_Head(LinkList L){
		if(L->next!=NULL)
				R_Print(L->next);  //�������һ��Ԫ�أ��ݹ�ʵ��ȡ�����һ��ֵλ�ã��Ӷ����
}

//04 ��ͷ��㵥����Lɾ��һ����Сֵ����Ч�㷨��������Сֵ��Ψһ�ģ�
LinkList Delete_Min(LinkList &L){
		//L�Ǵ�ͷ���ĵ�����
		LNode *pre=L,*p=pre->next;//pΪ����ָ�룬preΪ��ǰ��  ..(L)-pre(minpre)...p(minp)(ɾ��)...minp->next
		LNode *minpre=pre,*minp=p;//������Сֵ��ǰ��
		while(p!=NULL){
				if(p->data<minp->data){  //���ڸ�С��
						minp=p;
						minpre=pre;
				}
				pre=p;
				p=p->next;  //����ɨ���¸����
		}
		minpre->next=minp->next;
		free(minp);  //ɾ����Сֵ���
		return L;
}

//05 ��ͷ��㵥����L�͵����ã����͵ء������ռ临�Ӷ�ΪO(1)
LinkList Reverse_1(LinkList L){
		//�ⷨһ��ͷ���ժ�£��ӵ�һ��㿪ʼ��һ�β嵽ͷ���֮��ͷ�巨������������ֱ�����һ�����Ϊֹ
		LNode *p,*r;//pΪ����ָ�룬rΪp�ĺ�̣��Է�����
		p=L->next;//�ӵ�һ����㿪ʼ
		L->next=NULL;//�Ƚ�ͷ���L��next����ΪNULL   --------L---p---r(p->next)
		while(p!=NULL){
				r=p->next;
				p->next=L->next;  //p�����뵽ͷ���֮��  ----p-----r(p)
				L->next=p;
				p=r;
		}
		return L;
}

//�ⷨ����
LinkList Reverse_1(LinkList L){
//���α������Ա�L���������ָ�뷴ת
		LNode *pre,*p=L->next,*r=p->next; ------L(pre)--p--r---(������������)
		p->next=NULL;    //�����һ�����
		while(r!=NULL){  //rΪ�գ�˵��pΪ���һ�����
				pre=p;
				p=r;
				r=r->next;
				p->next=pre; //ָ�뷴ת
		}
		L->next=p; //�������һ�����
		return L;
}
//ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)


//06 ��ͷ���L������ʵ��Ԫ�ص�������
//����ֱ�Ӳ������򣬹���һ�����ݽ�����������Ȼ������ɨ��ʣ�£�����p��ǰ���ͺ��
void Sort(LinkList &L){
		//ʵ�ֵ�����L�����ţ�ʹ���������
		LNode *p=L->next,*pre;
		LNode *r=p->next;//r����*p��̽��ָ�룬�Ա��ֲ�����
		p->next=NULL;
		p=r;  //---L---p(---r)��p(r)����һ��Ԫ�أ�,(��L�б����ҳ���p������ݲ���),,,,
		while(p!=NULL){
				r=p->next;  //--pre(L)        p---r---
				pre=L;
				while(pre->next!=NULL&&pre->next->data<p->data) //�����ǰ
						pre=pre->next;//��������в��Ҳ���*p��ǰ�����*pre
				p->next=pre->next;
				pre->next=p;
				p=r;//ɨ��ԭ��������ʣ�µĽ��
		}
}

//07 ��ͷ��㵥��������Ԫ������ֵ����ɾ�����н��ڸ�������ֵ����Ϊ������������֮���Ԫ�أ������ڣ�
void RangeDelete(LinkList &L,int min,int max){
		LNode *pr=L,*p=L->link;//p�Ǽ��ָ�룬pr��ǰ��ָ��  p->link��ʾ��ǰ�ڵ㣨p������һ���ڵ�
		while(p!=NULL){
				if(p->data>min&&p->data<max){  //Ѱ�ұ�ɾ���㣬ɾ��
						pr->link=p->link;
						free(p);
						p=p->link;
				} 
				else{						//�������Ѱ�ұ�ɾ���
						pr=p;
						p=p->link;  //---pr--p--p->link
				}
}

//08 ���������������ҳ���������Ĺ������
/**
		��������й�����㣬�����������ĳһ��㿪ʼ�����ǵ�next��ָ��ͬһ����㡣����ֻ��һ��next�򣬴ӵ�һ��������㿪ʼ����������غϵģ�������
		�ٷֲ档���������й������������غϵĵ�����������״��������Y������X��
		ֻ��ֱ���������������һ����㣬������β�����һ���ģ���˵�������й�����㣬������������û�й�����㡣
		������˳����������ܱ�֤��������ͬʱ���������β��㣬���ȿ��ܲ�ͬ������һ����������һ����㳤k�����ڳ�������������k����㣬֮��
		��ͬ��������ʱ�临�Ӷ�O(len1+len2)��
*/
LinkList Search_lst_Common(LinkList L1,LinkList L2){
		//���㷨ʵ�������Ե�ʱ�����ҵ�����������ĵ�һ���������
		int len1=Length(L1),len2=Length(L2);//�������������
		LinkList longList,shortList;//�ֱ�ָ����ϳ��ͽ϶̵�����
		if(len1>len2){
				longList=L1->next;
				shortList=L2->next;
				dist=len1-len2;//��֮��
		}
		else{
				longList=L2->next;
				shortList=L1->next;
				dist=len2-len1;//��֮��
		}
		while(dist--)  //���������ȱ�������dist����㣬Ȼ��ͬ��
				longList=longList->next;
		while(longList!=NULL){ //ͬ��Ѱ�ҹ������
				if(longList==shortList) //�ҵ���һ���������
						return longList;
				else{
						longList=longList->next;
						shortList=shortList->next;
				}
		}
		return NULL;
}

//09 ��ͷ���ĵ�����headͷָ�룬���ṹΪ��data��next����dataΪ����Ԫ�أ�nextΪָ�룬������������������и���������Ԫ�ز�
//�ͷŽ����ռ�Ĵ洢�ռ䣨������ʹ��������Ϊ�����ռ䣩
/**
		�㷨˼�룺��������б�������ÿ�α���֮���ҵ�����������СֵԪ�أ�������ͷŽ����ռ�ռ䣻��Ѱ�Ҵ�СֵԪ�أ�������ͷſռ䣬�����ȥ
		ֱ������Ϊ�գ�����ͷ�ͷ�����ռ�洢�ռ䡣ʱ�临�Ӷ�O(n^2)
*/

void Min_Delete(LinkList &head){
//head�Ǵ�ͷ���ĵ������ͷָ�룬����˳������������е�����Ԫ��
		while(head->next!=NULL){//ѭ������ʣͷ���
				LNode *pre=head; //preΪԪ����Сֵ����ǰ������ָ��
				LNode *p=pre->next; //pΪ����ָ��       ---pre(head)---p(pre->next)---p->next
				while(p->next!=NULL){
						if(p->next->data<pre->next->data)
								pre=p;
						p=p->next;
				}
				print(pre->next->data);//�����Сֵ�������
				u=pre->next;//ɾ����Сֵ����Ԫ��
				pre->next=u->next;
				free(u);
		}
		free(head);//�ͷ�ͷ���
}


//10 ��ͷ���ĵ�����A�ֽ�Ϊ������ͷ���ĵ�����A,B��ʹ��A���к���ԭ�������Ϊ������Ԫ�أ�B����Ϊ��ż����ţ��ұ������˳�򲻱�
//�㷨˼��"����һ��������ű�������ֵΪ0����ÿ����һ���������Զ���1��Ȼ��������е���ż�Խ�������A/B.�ظ��ϲ�������β
LinkList DisCreat_l(LinkList &A){
		//����A�н�㰴��ŵ���ż�Էֽ⵽��A/B
		int i=0;
		LinkList B=(LinkList)malloc(sizeof(LNode)); //����B���ͷ
		B->next=NULL;
		LNode *ra=A,*rb=B,*p;//A/B��β��β���
		p=A->next;
		A->next=NULL;
		while(p!=NULL){
				i++;
				if(i%2==0){
						rb->next=p;
						rb=p;
				}
				else{
						ra->next=p;
						ra=p;
				}
				p=p->next;
		}
		ra->next=NULL;
		rB->next=NULL;
		return B;
}

//11 C={a1,b1,a2,����an,bn}Ϊ���Ա����ô�ͷ����hc�������ţ����Ϊ�������Ա��͵��㷨��ʹ��A={a1,a2����an},B={b1,b2����bn}
//�㷨˼�룺��������˼�룬������ű��������ߵĲ�������ڶ�B��Ľ���������β�巨�����ǲ���ͷ�巨
LinkList DisCreate_2(LinkList &A){
		LinkList B=(LinkList)malloc(sizeof(LNode));//����B���ͷ
		B->next=NULL;  //B��ĳ�ʼ��
		LNode *p=A->next,*q;  //pΪ����ָ��  ---ra---p
		LNode *ra=A;//raʼ��ָ��A��β��� 
		while(p!=NULL){
				ra->next=p;  //��*p����A�ı�β   B->next=NULL p=A->next  q=p->next  ��A֮��һ��Ԫ�ش浽B�У�	
				ra=p;
				p=p->next;
				if(p!=null){
						q=p->next;  //-----B------     ---p--q---
						p->next=B->next;//ͷ���*p�������������q����*p�ĺ��
						B->next=p;  //��*p���뵽B��ǰ��
						p=q;
				}
		}
		ra->next=NULL;
		return B;

}

//12 �ڵ�����������Ա��У�����ֵ��ͬԪ�ش��ڡ��洢��ʽΪ������ȥ����ֵ��ͬ��Ԫ�أ�ʹ�ñ������ظ���Ԫ��
//����{7,10,10,21,30,42,42,42,51,70}����Ϊ{7,10,21,30,42,51,70}
//�㷨˼�룺�����������������ֵͬ��Ľ�㶼�����ڵģ���pɨ�����������L����*p����ֵ�� //ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
void Del_Same(LinkList &L){
		//L�ǵ��������������㷨ɾ��������ֵ��ͬ��Ԫ��
		LNode *p=L->next,*q;//pΪ����ָ��
		if(p==NULL)
				return;
		while(p->next!=NULL){
				q=p->next;//qָ��*p�ĺ��ָ��  ---p--q(ɾ���˽��)---
				if(p->data==q->data){  //�ҵ��ظ�ֵ�Ľ��
						p->next=q->next;
						free(q);//�ͷ���ͬԪ��ֵ�Ľ��
				}
				else
						p=p->next;
		}
}

//13 ������Ԫ�ص����������е����Ա����Ե�������ʽ�洢���ϲ�������Ϊһ����Ԫ�صݼ��������еĵ�����
//Ҫ������ԭ������������Ľ���Ź鲢��ĵ�����
/**
		�㷨˼�룺�����������Ѿ���Ԫ�ص����������У�����ϲ�ʱ�����ӵ�һ����㿪ʼ���бȽϣ�����С�Ľ�����������У�ͬʱ���ƹ���ָ�롣
		������Ҫ��������Ԫ��ֵ�ݼ��������У����½��Ľ���Ӧ��ͷ�巨���ȽϽ������ܻ���һ������Ϊ�գ�ͷ�巨һ�ν�ʣ�������
*/
void MergeList(LinkList &La,LinkList &Lb){
		//�ϲ�������������������ͷ��㣩����ʹ�ϲ��������ݼ�����
		LNode *r,*pa=La->next,*pb=Lb->next;//�ֱ�La��Lb�Ĺ���ָ��
		La->next=NULL;//La��Ϊ��������ͷָ�룬�Ƚ���������ʼ��Ϊ��-La-pa--
		while(pa&&pb)
				if(pa->data<=pb->data){  //---pa--r--       --------pb------
						r=pa->next;//r�ݴ�pa�ĺ�̽��ָ��(pa���С��ȥ��pa,�͵�La��)
						pa->next=La->next;
						La->next=pa;
						pa=r;///(�ָ�pa)Ϊ��ǰ���ȽϽ��
				}
				else{
						r=pb->next;
						pb->next=La->next;
						La->next=pb;
						pb=r;
				}
				if(pa)
						pb=pa;//����ʣ��Ĳ���(pa����)
				while(pb){  //���β��뵽La�У�ͷ�巨��
						r=pb->next;
						pb->next=La->next;
						La->next=pb;
				}
				free(Lb);
}

//14 ��A,B��������������ͷ��㣩������Ԫ�ص����������һ���㷨��A��B�еĹ���Ԫ�ز�������C��Ҫ���ƻ�A,B���
/**
		�㷨˼�룺��A,B�����򣬿��Դӵ�һ��Ԫ�������αȽ�A,B�����Ԫ�أ���Ԫ��ֵ���ȣ���ֵС�ĺ��ƣ�����ȣ�����һ��ֵ����������Ԫ��ֵ���½��
		ʹ��β�巨���뵽�������У���������ԭ��ָ�����һλ��ֱ������һ�������������β
*/ 
void Get_Common(LinkList A,LinkList B){
		//���㷨����������A��B�Ĺ���Ԫ�صĵ�����
		LNode *p=A->next,*q=B->next,*r,*s;
		LinkList C=(LinkList)malloc(sizeof(LNode));//������C
		r=C;//rʼ��ָ��C��β���
		while(p!=NULL&&q!=NULL){
				if(p->data<q->data)
						p=p->next;//��A�ĵ�ǰԪ�ؽ�С������ָ��
				else if(p->data>q->data)
						q=q->next;//��B�ĵ�ǰԪ�ؽ�С������ָ��
				else{
						s=(LNode*)malloc(sizeof(LNode));
						s->data=p->data;//���Ʋ������*s
						r->next=s;
						r=s;
						p=p->next;
						q=q->next;
				}
		}
}
		

//15 A,B��ʾ�������ϣ���Ԫ�ص���ż���У�A��B�Ľ�������ŵ�A������


//16 A=a1,a2����am��B=b1,b2����bn�Ѿ����뵽�����������У��ж�B�Ƿ���A������������

//17 �жϴ�ͷ����ѭ�������Ƿ�Գ�

//18 ����ѭ������������ͷָ��ֱ�Ϊh1��h2����дһ������������h2���ӵ�����h1֮��Ҫ�����Ӻ��������Ȼ����ѭ��������ʽ

//19 ��ͷ����ѭ�������� ���ֵ��Ϊ�������������ҳ��������н��ֵ��С�Ľ�㲢�����Ȼ�󽫸ý�����ɾ����֪���������Ϊֹ��ɾ��ͷ���

//20 ��ͷָ��ΪL�Ĵ���ͷ�ķ�ѭ��˫��������ÿ������г���pred��ǰ��ָ�룩��data��next�⣬����һ������Ƶ����freq��
//��������ǰ����ֵ����ʼ��Ϊ0��ÿ���������н���һ��Locate(L,x),��x����freq+1����ʹ����������Ƶ�ȵݼ�˳�����С�
//������ʵĽ������Ƶ����ͬ�Ľ��֮ǰ���Ա�ʹƵ�����ʵĽ�����ǿ�����ͷ�������ҵ��Ľ��ĵ�ַ������Ϊָ����

//21 �������л������������һ������ָ�루ͨ��Ϊ�գ�ָ�������е�ĳ����㣬�жϵ������Ƿ���ڻ�
/**
(1)�㷨����˼��
(2)���롢ע��
(3)ʱ�ո��Ӷ�
*/

//22 ��ͷ���ĵ�����  data|link
//ֻ��ͷָ��list�����ı�����ǰ���£�Ѱ�������е�����k��λ�õĽ�㣨kΪ�����������ҳɹ������dataֵ��������1�����򷵻�0
/**
(1)�㷨����˼��
(2)���롢ע��
(3)ʱ�ո��Ӷ�
*/

//23 ��ͷ���ĵ������浥�ʣ���������������ͬ�ĺ�׺���ɹ���ͬ�ĺ�׺�洢�ռ䣬����:loading being  (������p41)
//str1��str2�ֱ�ָ�������������е������ͷ��㣬���ṹ data|next �ҵ���������ͬ��׺����ʼλ��(���е�i)
/**
(1)�㷨����˼��
(2)���롢ע��
(3)ʱ�ո��Ӷ�
*/
//���ù鲢˼�룬������������ָ��pa,pb��������������й鲢ɨ�裬
//ֻ��ͬʱ�����������ϵ�Ԫ�ز����ӵ����������ֻ����һ��,�������ȫ���ͷţ���һ�����������Ϻ��ͷ���һ��
//����ʣ�µ�ȫ�����
LinkList Union(LinkList &la,LinkList &lb){
	pa=la->next; //�蹤��ָ��ֱ�Ϊpa,pb
	pb=lb->next;
	pc=la;
	while(pa&&pb){
		if(pa->data==pb->data){
			
		}
	}

}

//24 ��������m�����������ṹ[data][link],��|data|<=n(nΪ������)������������data����ֵ��ȵĽ�㣬��������һ�γ��ֵĽ���ɾ������
//����ֵ��ȵĽ�㡣����head���£�head->21->-15->-15->-7->15  ɾ��֮��head->21->-15->-7
/**
(1)�㷨����˼��
(2)����������������Ͷ���
(3)���롢ע��
(4)ʱ�ո��Ӷȣ�O��m�� O��n����������ռ�����n+1����ʼ����Ϊ0���������ظ���+1.�ж�0֮���ɾ����
*/


//25 ���Ա�L={a1,a2,a3����an}���ô�ͷ���ĵ������棬���壺
typedef struct node{
		int data;
		struct node *next;
}NODE;
/**
Ҫ��ռ临�Ӷ�O(1)��ʱ���Ͼ����ܸ�Ч���㷨����������L�еĸ���㣬�õ�L'={a1,an,a2,a^n-1����}
*/
/**
(1)�㷨����˼��
(2)����������������Ͷ���
(3)���롢ע��
(4)ʱ�ո��Ӷ�
*/
//ʵ�֣�һ��һ���ߣ�һ������������󣬵�һ��Ϊ�е㣬�ڶ���Ϊβ��㡣β�������ָ����λ���һ����ͷ�巨����
//Ȼ���� ���в���  O��m��O��n����


/*********************************3  ջ������*******************************************/
#define MaxSize 50
typedef struct {
	ElemType data[MaxSize]; //���ջ��Ԫ��
	int top;//ջ��ָ��
}SqStack;
/**
ջ��ָ��S.top  ��ʼ����:S.top=-1  ջ��Ԫ��S.data[S.top]
65ҳ
ջ��:S.top==-1   ջ��:S.top==MaxSize-1  ջ��:S.top+1  (˳��ջ����ջ����)
*/
//��1����ʼ��
void InitStack(SqStack &S){
	S.top=-1;
}
//��2����ջ��
bool StackEmpty(SqStack S){
	if(S.top==-1)
		return true;
	else
		return false;
}
//��3����ջ
bool Push(SqStack &S,ElemType x){
	if(S.top==MaxSize-1)//ջ�� ����
		return false;
	S.data[++S.top]=x;//ָ���ȼ�1������ջ
	return true;
}
//��4����ջ
bool Pop(SqStack &S,ElemType &x){
	if(S.top==-1)
		return false;
	x=S.data[S.top--];//�ȳ�ջ��ָ���ټ�һ
	return true;
}
//��5����ջ��Ԫ��
bool GetTop(SqStack S,ElemType &x){
	if(S.top==-1)
		return false;
	x=S.data[S.top];
	return true;
}

//��ջ
typedef struct Linknode{
	ElemType data;  //������
	struct Linknode *next;//ָ���� 
}*LiStack;

/**     �ۺ�Ӧ����70          */
//3 �����Ƿ�Ϸ� i o ��ʼ����̬��Ϊ��
int Judge(char A[]){
//�ж��ַ�����A�е�������������Ƿ��ǺϷ����У��Ƿ���true ��false
	int i=0;
	int j=k=0;
	while(A[i]!='\0'){//δ���ַ�����β
		case 'I':
			j++;
			break;
		case 'O':
			k++;
			if(k>j){
				printf("���зǷ�\n");
				exit(0);
			}
		i++;
	}
	if(j!=k){
		printf("���зǷ�\n");
		return false;
	}
	else{
		printf("���кϷ�\n");
		return true;
	}
}
//�Ƿ����ĶԳ�
int dc(LinkList L,int n){
//L�Ǵ�ͷ����n��Ԫ�ص��������㷨�ж������Ƿ����ĶԳ�
	int i;
	char s[n/2];//s�ַ�ջ
	p=L->next;//p����ָ��
	for(i=0;i<n/2;i++){ //�����ǰһ��Ԫ�ؽ�ջ
		s[i]=p->data;
		p=p->next;
	}
	i--; //�ָ�����iֵ
	if(n%2==1) //���� ���ƹ����Ľ��
		p=p->next;
	while(p!=NULL&&s[i]==p->data){//����Ƿ����ĶԳ�
		i--;//��ǰ��ǰ
		p=p->next;//�к����
	}
	if(i==-1)
		return 1;//���Ķѳ�
	else
		return 0;//�����Ķѳ�
}

//s1,s2˳��ջ ջ������ ӭ�������洢��ʽ ��ƽ�ջ��ջ���� -----1����maxsize------
/**
����ջ���������ռ䣬������ջ��ջ�������������ˣ���ʼʱ��s1ջ��ָ��Ϊ-1 s2Ϊmaxsize
����ջ������ʱΪջ����ջ��Ԫ�ػ�ָ

*/
#define maxsize 100
#define elemtp int  //����Ԫ������Ϊ����
typedef struct {
	elemtp stack[maxsize]; //ջ�ռ�
	int top[2];//topΪ����ջ��ָ��
}stk;
stk s;  //s�����϶���Ľṹ���ͱ�����Ϊȫ�ֱ���
//(1)��ջ
int push(int i,elemtp x){
//��ջ������iΪջ�ţ�i=0��ʾ��ߵ�s1ջ��i=1��ʾ�ұߵ�s2ջ x����ջԪ��
	if(i<0||i>1){
		printf("ջ�����벻��");
		exit(0);
	}
	if(s.top[1]-s.top[0]==1){
		printf("ջ����");
		return 0;
	}
	switch(i){
	case 0: 
		s.stack[++s.top[0]]=x; //��ߴ�ͷ��ʼ�����±�
		return 1;
		break;
	case 1:
		s.stack[--s.top[1]]=x; //�ұߴ��м俪ʼ���±�
		return 1;
	}
}
//(2)��/��ջ
elemtp pop(int i){
//��ջ�㷨��i����ջ�ţ�i=0ʱΪs1ջ��i=1ʱΪs2ջ
//��ջ�ɹ�������ջԪ�أ����򷵻�-1
	if(i<0||i>1){
		printf("ջ���������");
		exit(0);
	}
	switch(i){
	case 0:
		if(S.top[0]==-1){
			printf("ջ��\n");
			return -1;
		}
		else
			return s.stack[s.top[0]--]; //ջ���Ƚ����
		break;
	case 1:
		if(S.top[1]==maxsize){
			printf("ջ��\n");
			return -1;
		}
		else
			return s.stack[s.top[1]++];
		break;
	}
}

//����
#define MaxSize 50
typedef struct {
	ElemType data[MaxSize];
	int front,rear; //��ͷ��βָ��
}SqQueue;
/**
��ʼ(�ӿ�):Q.front==Q.rear==0

ѭ������:
��ʼ:Q.front==Q.rear==0
����:Q.front==(Q.rear+1)%MaxSize
�ӿ�:Q.front==Q.rear
���׽�:Q.front==(Q.front+1)%MaxSize
��β��:Q.rear==(Q.rear+1)%MaxSize
���г���:(Q.rear+MaxSize-Q.front)%MaxSize
*/


//ѭ�����в���
//��1����ʼ��
void InitQueue(SqQueue &Q){
	Q.front==Q.rear==0;
}
//��2���жӿ�
bool isEmpty(SqQueue Q){
	if(Q.front==Q.rear)
		retrn true;
	else
		return false;
}
//��3�����  //�Ƚ��ȳ�(�����) (β��ͷ��)
bool Enqueue(SqQueue &Q,ElemType x){
	if(Q.front==(Q.rear+1)%MaxSize)
		return false;
	Q.data[Q.rear]=x;
	Q.rear=(Q.rear+1)%MaxSize;
	return true;
}
//��4������
bool DeQueue(SqQueue &Q,ElemType &x){
	if(Q.front==Q.rear)
		return false;
	x=Q.data[Q.front];
	Q.front=(Q.front+1)%MaxSize;
	return true;
}




//���е���ʽ�洢
typedef struct LinkNode{
	ElemType data;
	struct LinkNode *next; 
}LinkNode;

typedef struct {
	LinkNode *front,*rear;
}LinkQueue;

/**
��ʽ����Ϊ��:Q.front=NULL��Q.rear=NULL(����ͷ������ʽ���в����鷳��,ͨ�����Ͻ��)
*/
//��ʽ���в���
(1)��ʼ��
void InitQueue(LinkQueue &Q){
	Q.front==Q.rear=(LinkNode*)malloc(sizeof(LinkNode));//����ͷ���
	Q.front->next=NULL;
}
(2)�жӿ�
bool IsEmpty(LinkQueue Q){
	if(Q.front==Q.rear)
		return true;
	else
		return false;
}
(3)���
void EnQueue(LinkQueue &Q,ElemType x){
	LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
	s->data=x; //�����½��
	s->next=NULL;
	Q.rear->next=s;
	Q.rear=s;
}

(4)����
bool DeQueue(LinkQueue &Q,ElemType &x){
	if(Q.front==Q.rear)
		return true;
	LinkNode *p=Q.front->next;
	x=p->data; //p����
	Q.front->next=Q.front;
	if(Q.rear==p)
		Q.rear=Q.front;  //ԭ����ֻ��һ����㣬ɾ������
	free(p);
	retun true;
}


////Ӧ����85 
//1ѭ�����ж������õ���tag��������������1������0
/**
��ʼ:Q.front=Q.rear=0 tag=0
�ӿ�:Q.front=Q.rear  Q.tag==0
����:Q.front=Q.rear  Q.tag==1
����:Q.data[Q.rear]=x    Q.rear=(Q.rear+1)%MaxSize  Q.tag=1
����:x=Q.data[Q.front]   Q.front=(Q.front+1)%MaxSize  Q.tag=0
*/

int EnQueue(SqQueue &Q,ElemType x){
	if(Q.front==Q.rear&&Q.tag==1)
		return 0;//����(ֻ�����)
	Q.data[Q.rear]=x;
	Q.rear=(Q.rear+1)%MaxSize;
	Q.tag=1;
	return 1;
}
int DeQueue1(SqQueue &Q,ElemType &x){
	if(Q.front==Q.rear&&Q.tag==0)
		return 0;//�ӿ�(ֻ�г���)
	x=Q.data[Q.front];
	Q.front=(Q.front+1)%MaxSize;
	Q.tag=0;
	return 1;
}

//2  Q���� S��ջ������(������-��ջ-��ջ-�����)
void Inverser(Stack &S,Queue &Q){
//���㷨ʵ�ֽ������е�Ԫ������
	while(!QueueEmpty(Q)){
		x=DeQueue(Q);
		Push(S,x);
	}
	while(!StackEmpty(Q)){
		Pop(S,x);
		EnQueue(Q,x);
	}

}

//3 ����s1��s2ջģ�����
/**
(1)��s2��ջ�������ӣ���s2Ϊ�գ����Ƚ�s1�е�����Ԫ���͵�s2
(2)��s1��ջ����ӣ���s1���������ȱ�֤s2Ϊ�գ����ܽ�s1Ԫ��ȫ�����뵽s2
*/
//���
int EnQueue(Stack &S1,Stack &S2,ElemType e){
	if(!StackOverflow(S1)){
		Push(S1,e);  //�뵽s1��
		return 1;
	}
	if(StackOverflow(S1)&&!StackEmpty(S2)){
		printf("������");
		return 0;
	}
	if(StackOverflow(S1)&&StackEmpty(S2)){
		while(!StackEmpty(S1)){
			Pop(S1,x);  //s1����s2��
			Push(S2,x);
		}
	}
	Push(S1,e);  //--x->S1->S2
	return 1;
}
//����
void DeQueue(Stack &S1,Stack &S2,ElemType &x){
	if(!StackEmpty(S2)){
		Pop(S2,x);  //����s2��
	}
	else if(StackEmpty(S1)){
		printf("����Ϊ��");
	}
	else{
		while(!StackEmpty(S1)){
			Pop(S1,x);  //s1����s2��==>s1Ϊ��
			Push(S2,x);  //--S1->S2->x
		}
	Pop(S2,x);
	}
}
//�ж϶���Ϊ��
int QueueEmpty(Stack S1,Stack S2){
	if(StackEmpty(S1)&&StackEmpty(S2))
		return 1;
	else
		return 0;
}

//Ӧ��
/**
	Բ������������ƥ��  96
	����ƥ����ջ�ĵ���Ӧ��
*/
bool BracketsCheck(char *str){
	InitStack(S);//��ʼ��ջ
	int i=0;
	while(str[i]!='\0'){
		switch(str[i]){
			//��������ջ
			case '(':
				Push(S,'(');
				break;
			case '[':
				Push(S,'(');
				break;
			case '{':
				Push(S,'(');
				break;
			//���������ţ����ջ��
			case ')':
				Pop(S,e);
				if(e!='(')
					return false;
				break;
			case ']':
				Pop(S,e);
				if(e!=']')
					return false;
				break;
			case '}':
				Pop(S,e);
				if(e!='}')
					return false;
				break;
			default:
				break;
		}//switch
	i++;
	}//while
	if(!IsEmpty(S)){
		printf("���Ų�ƥ��\n");
		return false;
	}
	else{
		printf("����ƥ��\n");
		return true;
	}

}

//�������
/**
	�����������ʻ(���಻��ͨ)��ջ�����ڵ��ȣ������n��Ӳ�����������ᣨH,S���ȴ����ȣ�
	�����n�ڳ�����е��Ȳ�����ʹ�����������ᶼ��������Ӳ������֮ǰ
	�㷨˼�룺���г����Դ˼�飬Ӳ����ջ�ȴ����ȣ�ȫ���������ȵ�����֮��
*/
void Train_Arrange(char *train){
//���ַ���train��ʾ�𳵣�H��ʾӲ����S��ʾ����
	char *p=train,*q=train,c;
	stack s;
	InitStack(s);//��ʼ��ջ
	while(*p){
		if(*p=='H')
			Push(s,*p);
		else
			*(q++)=*p;//��s���ȵ�ǰ��
		p++;
	}
	while(!IsEmpty(s)){
		Pop(s,c);
		*(q++)=c;
	}
}

//����ջʵ�ֵݹ麯��
/**
Pn(x)=| 1 n=0  //fv1
	  |	2x n=1  //fv2
	  | 2x*P_n-1(x)-2(n-1)*P_n-2 (x) n>1
	  �㷨˼�룺��ջ���ڱ���n�Ͷ�Ӧ��Pn(x)ֵ
*/
double p(int n,double x){
	struct stack{
		int no;//����nֵ
		double val;//����Pn(x)ֵ
	}st[MaxSize];
	int top=-1,i;//topΪջst���±�ֵ����
	double fv1=1,fv2=2*x;//n=0,n=1�ĳ�ֵ
	for(i=n;i>=2;i--){  //nֵ�仯  n n-1 n-2 ����2��n>1��
		top++;
		st[top].no=i; //top=1 st[1].no=n
	}  //��ջ
	while(top>=0){
		st[top].val=2*x*fv2-2*(st[top].no-1)*fv1; //st[1].val=2x*2x-2(n-1)1  P(x)
		fv1=fv2;    //1---��2x   P_n-2 (x) 
		fv2=st[top].val; //n>1ʱ��ֵ   //2x--��P(x)  P_n-1 (x) ��Ϊ�µĵݹ�������� ֱ��top<0
		top--;  //��ջ
	}
	if(n==0)
		return fv1;
	return fv2;  //��ʽ����n>=1

}


//�����ֶ�
/**                                                                               
	ÿ��10��������Ϊ�ͳ��ͻ�����
	�涨��ͬ�೵�ȵ����ϴ����ͳ������ڻ�����ÿ��4���ͳ����������1�����������ͳ�����4�������������
	�޻����ȴ�������ͳ����ϴ�
*/

Queue q;//
Queue q1;//�ͳ�����
Queue q2;//��������
void manager(){
	int i=0;j=0;//j��ʾ�ɴ�
	while(j<10){
		if(!QueueEmpty(q1)&&i<4){  //�ͳ�����4����
			DeQueue(q1,x);//�ͳ����г���
			EnQueue(q,x);//�ͳ��϶ɴ�
			i++; //�ͳ�����һ
			j++;//�ɴ��ϵ��ܳ�������1
		}
		else if(i==4&&!QueueEmpty(q2)){ //�ͳ�������4�� !QueueEmpty(q2)����Ϊ��
			DeQueue(q2,x);//�������г���
			EnQueue(q,x);
			j++;
			i=0;//ÿ��һ��������i���¼��� (��Ϊ4���ͳ���1������)
		}
		else{
			while(j<10&&i<4&&!QueueEmpty(q2)){ //һ�β���10����������Ϊ��
				DeQueue(q2,x);//�������г���(���ͳ����ˣ��û������)
				EnQueue(q,x);//�����϶ɴ�
				i++;
				j++;
			}
			i=0;
		}
		if(QueueEmpty(q1)&&QueueEmpty(q2))//�ͳ��գ�������
			j=11;  //������ɴ�
	}
}

/*********************************4  ��*******************************************/
//����˳��洢
#define MAXSIZE 255
typedef struct {
	char ch[MAXSIZE]; //ÿ�������洢һ���ַ�  ��ַ����
	int length;
}

//�ѷ���洢��ʾ
typedef struct {
	char *ch;//����������洢����chָ�򴮵Ļ���ַ
	int length;//����   ��ַ����
}HString;


//��ģʽƥ���㷨 ��λ������������ĸ����һ�γ��ֵ�λ��
int Index(SString S,SString T){
	int i=1,j=1;
	while(i<=S.length && j<=T.length){
		if(S.ch[i]==T.ch[i]){
			++i;
			++j;//�����ȽϺ���ַ�
		}
		else{
			i=i-j+2;//ĸ��ָ���������ƥ��
			j=1;//�Ӵ���ͷ��ʼ
		}
	}
	if(j>T.length)
		return i-T.length; //ĸ-�Ӵ�����
	else
		return 0;
}

//��ģʽ����next  117
void get_next(String T,int next[]){
	int i=1;j=0;
	next[1]=0;
	while(i<T.length){
		if(j==0||T.ch[i]==T.ch[j]){//T.ch[1]==T.ch[0]  �ɴ˿ɵ�next[1]=1(��ʼ�̶����� 0 1)
			++i;
			++j;
			next[i]=j;//��Pi=Pj ��next[j+1]=next[j]+1  //next[2]=1=next[1]]+1
		}
		else
			j=next[j]; //����Ⱦ�j=0(j����)��Ȼ���������ѭ�����бȽ�
	}
}
//O(mn) һ������£�����//O(m+n)



//KMP�㷨 //O(m+n) һ�����ͨ�㷨��ö࣬�ŵ������������ݣ�һֱ����Ѱ�ң�next�ǻ��ݼ�¼Ѱ�ң�
int Index_KMP(String S,String T,int next[]){
	int i=1,j=1;
	while(i<=S.length&&j<=T.length){
		if(j==0||S.ch[i]=T.ch[j]){
			++i;
			++j;//�������Ƚ�
		}
		else
			j=next[j]; //ģʽ�������ƶ�(��ͬ) next[1]=0;
	}
	if(j>T.length)
		return i-T.length;//ƥ��ɹ������ص�һ�γ��ֵ�λ��
	else
		return 0;
}


//KMP�㷨�Ľ�һ���Ż�
void get_nextval(String T,int nextval[]){
	int i=1,j=0;
	nextval[1]=0;
	while(i<T.length){
		if(j==0||T.ch[i]==T.ch[j]){
			++i;
			++j;
			if(T.ch[i]!=T.ch[j])
				nextval[i]=j;
			else
				nextval[i]=nextval[j];
		}
		else
			j=nextval[j];  //�Ӵ���ĸ�����Եȣ��Ӵ��Աȵ�����
	}
}
/*********************************5 ���������*******************************************/
//����������ʽ�洢�ṹ
typedef struct BiTNode{
	ElemTye data; //������
	struct BiTNode *lchild,*rchild;//���Һ���ָ��
}BiTNode,*BiTree;  //n�����Ķ��������У���n+1��������

//Ӧ����ѡһ�����룺134
/**
	������ ˳��洢 i,j�������Ĺ������Ƚ��ֵ
	��Ȼ���ڣ����������Ǹ���㣬���������ʣ���һ���i��˫�׽����i/2
	i>j ���i���ڲ�δ���j������ڲ�Σ����i˫�׽��i/2(=j)��i��j������������Ƚ��
		��i/2!=j ��i=i/2 �ý���˫�׽��Ϊ��㣬�ݹ�������� 
	i<j ͬ��
*/
ElemType Comm_Ancestor(SqTree T,int i,int j){
//���㷨�ڶ������в��ҽ��i��j������������Ƚ��(�ݹ�)
	if(T[i]!='#'&&T[j]!='#'){ //��Ŵ���
		while(i!=j){
			if(i>j)
				i=i/2;
			else
				j=j/2;
		}
		return T[i];
	}
}


//������ ���� 139
//������� 
/**
	������������������  Ϊ��ʲôҲ����
*/
void PreOrder(BiTree T){
	if(T!=NULL){
		visit(T);
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

//�������
void InOrder(BiTree T){
	if(T!=NULL){
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}

//�������
void PostOrder(BiTree T){
	if(T!=NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}


//��������ķǵݹ��㷨(������)
void InOrder2(BiTree T){
	InitStack(S);
	BiTree p=T;//��ʼ��ջ���Ƚ��������p�Ǳ���ָ��
	while(p||!IsEmpty(S)){  //ջ��Ϊ�ջ�p��Ϊ��ʱѭ��
		if(p){  
			Push(S,p);//��ǰ�����ջ
			p=p->lchild;//���Ӳ�Ϊ�գ�һֱ������  
		}//����ȫ����ջ   ���η��ʳ�ջ�������Һ���
		else{
			Pop(S,p);
			visit(p);//ջ��Ԫ�س�ջ�����ʳ�ջ��㣨��ʱ�����㣩
			p=p->rchild;//����������
		}
	}
}

//��������ķǵݹ��㷨  ������
void PreOrder2(BiTree T){
	InitStack(S);
	BiTree p=T;//��ʼ��ջ���Ƚ��������p�Ǳ���ָ��
	while(p||!IsEmpty(S)){  //ջ��Ϊ�ջ�p��Ϊ��ʱѭ��
		if(p){  
			visit(p);
			Push(S,p);//��ǰ�����ջ
			p=p->lchild;//���Ӳ�Ϊ�գ�һֱ������  
		}//����ȫ����ջ   ���η��ʳ�ջ�������Һ���
		else{
			Pop(S,p);
			p=p->lchild;//����������
		}
	}
}


//��α���  94  142 WD
void levelOrder(BiTree T){
	InitQueue(Q);//��ʼ����������
	BiTree p;
	EnQueue(Q,T);//����������
	while(!IsEmpty(Q)){
		DeQueue(Q,p);
		visit(p);  //���ʳ��ӽ��
		if(p->lchild!=NULL)
			DeQueue(Q,p->lchid); //��������Ϊ�գ���������������
		if(p->rchild!=NULL)
			DeQueue(Q,p->rchid); //��������Ϊ�գ���������������
	}
}


//����������
// lchild ltag data rtag rchild

/**
ltag:    0 lchild����      1 lchildǰ��
rtag:	 0 rchild�Һ���      1 lchild���
*/

//�����������洢�ṹ��
typedef struct ThreadNode{
	ElemType data;
	struct ThreadNode *lchild,*rchild;
	int ltag,rtag;
}ThreadNode,*ThreadTree;


//p135����
// 05 ��֪һ������˳��ṹ�洢�����ŷֱ�Ϊi��j��������������Ĺ������Ƚ���ֵ

//�ǿն�������Ҷ�ӽ�����=��Ϊ2�ڵ���+1  => n0=n2+1(p131����)
//֤��:
/**
		���Ϊ0,1,2�Ľ������ֱ�Ϊn0,n1,n2,�������n=n0+n1+n2
		�ٿ��������ķ�֧������������⣬�����㶼��һ����֧���룬��BΪ��֧��������n=B+1,������Щ��֧���ɶ�Ϊ1��2�������ģ�������B=n1+2n2
		���ǵ�n0+n1+n2=n1+2n2+1,��n0=n2+1
*/


//1 ���������p139��


//2 �������

//3 �������

//4 �ݹ�ͷǵݹ�

//5 ��α���

//p149 