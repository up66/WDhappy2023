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