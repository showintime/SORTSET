
//MUST INCLUDE　IT
#include "iostream"


//程序版本,DEBUG为测试版本
#define DEBUG


//指定数组长度
#define AMAX 10

//指定数组类型
typedef int MType;


/*
函数:void GravitySort(MType arr[], int len)
说明:重力排序(仅能用于非负整数排序)
参数:arr为传入的数组的地址
参数:len为传入数组的长度
*/
void GravitySort(MType arr[], int len)
{
	MType arrMax;
	MType arrMin;

	int i = 0, j = 0;
	arrMax = arr[0];
	arrMin = arr[0];
	for (i = 0; i < len; i++)
	{
		if (arrMax < arr[i])
		{
			arrMax = arr[i];
		}
		if (arrMin > arr[i])
		{
			arrMin = arr[i];
		}
	}
	MType *pTable = (MType *)malloc(sizeof(MType)*(arrMax - arrMin));

	for (i = 0; i < arrMax - arrMin; i++)
	{
		pTable[i] = 0;
	}

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < arr[i] - arrMin; j++)
		{
			pTable[j]++;
		}
		arr[i] = arrMin;
	}

	for (i = len - 1; i >= 0; i--)
	{
		for (j = 0; j < (arrMax - arrMin) &&pTable[j] != 0; j++)
		{
			arr[i] += 1;
			pTable[j]--;
		}

	}

	free(pTable);

}

/*
函数:void QuickSort(MType arr[], int low, int high)
说明:快速排序
参数:arr为传入数组的地址
参数:low为待排序数组的起始下标
参数:high为待排序数组的终止下标

*/
void QuickSort(MType arr[], int low, int high)
{
	//如果传入的数组的起始地址大于或等于终止地址,则退出排序算法
	if (low >= high)
	{
		return;
	}
	//记录排序的起始地址
	int teml = low;
	//记录排序的终止地址
	int temr = high;
	//临时变量，用于交换两个数的位置
	MType tema;

	while (low != high)
	{
		//从右端找到一个比arr[tem1]小的数,记录下标为high
		if (arr[high] > arr[teml])
		{
			high--;
			continue;
		}
		//再从左端找到一个比arr[tem1]大的数,记录下标为low
		if (arr[low] <= arr[teml])
		{
			low++;
			continue;
		}
		//交换两个下标的值
		tema = arr[low];
		arr[low] = arr[high];
		arr[high] = tema;

		

	}
	//将arr[teml]的值与arr[low]的值交换,交换后low下标左边的值都比它小,右边的值都比它大
	tema = arr[teml];
	arr[teml] = arr[low];
	arr[low] = tema;

	//递归排列low下标左端的数
	QuickSort(arr, teml, low - 1);
	//递归排列low下标右端的数
	QuickSort(arr, low + 1, temr);


}




/*
函数:void SelectSort(MType arr[], int len)
说明:选择排序
参数:arr为传入数组的地址
参数:len为传入数组的长度
*/
void SelectSort(MType arr[], int len)
{
	//_
	int i = 0, j = 0;
	//临时变量，用于交换两个数的位置
	MType tema;
	//每一次循环都能找到最大值和最小值两个数字,所以只需循环一半即可
	for (i = 0; i < len/2; i++)
	{
		//寻找第i层最大最小值
		for (j = i; j < len - 1 - i; j++)
		{
			//arr[i]为第i层最小值
			if (arr[i] > arr[j])
			{
				tema = arr[i];
				arr[i] = arr[j];
				arr[j] = tema;
			}
			//arr[len - i -1]为第i层最大值
			if (arr[len - 1 - i] < arr[j])
			{
				tema = arr[len - 1 - i];
				arr[len - 1 - i] = arr[j];
				arr[j] = tema;
			}
		}
	}


#ifdef DEBUG
	std::cout << "SelectSort" << std::endl;
#endif // DEBUG


}

/*
函数:void SelectSortDG(MType arr[],int low, int high)
说明:选择排序(递归实现)
参数:arr为传入的数组的地址
参数:low为待排列数组的起始下标
参数:high为待排列的数组的终止下表
*/
void SelectSortDG(MType arr[],int low, int high)
{
	//如果传入的数组的起始下标大于终止下标,则退出排列算法
	if (low >= high)
	{
		return;
	}
	//_
	int i = 0;
	//临时变量，用于交换两个数的位置
	MType tema;
	//从给定数组的指定位置排列,循环结束后arr[low]为该段数组的最小值,arr[high]为该段数组的最大值
	for (i = low; i <= high; i++)
	{
		//找到数组中最小值
		if (arr[i] < arr[low])
		{
			tema = arr[i];
			arr[i] = arr[low];
			arr[low] = tema;
		}
		//找到数组中的最大值
		if (arr[i] > arr[high])
		{
			tema = arr[i];
			arr[i] = arr[high];
			arr[high] = tema;
		}
	}

	//递归内层
	SelectSortDG(arr, low + 1, high - 1);

}



/*
函数:void InsertSortDG(MType arr[], int len)
说明:插入排序(递归实现)
参数:arr为传入的数组的地址
参数:len为传入数组的长度
*/
void InsertSortDG(MType arr[], int len)
{
	//如果待插入的数组的长度只有1时,则直接返回即可,无需进行排序
	if (len == 1)
	{
		return;
	}
	//调用自己,对前len-1个数,该语句执行完,即前len-1个数已有序
	InsertSortDG(arr, len - 1);
	//_
	int i = 0;
	//临时变量，用于交换两个数的位置,存储待插入的数
	MType tema = arr[len - 1];
	//循环条件为从插入的数字之前的有序数中查找比这个数小的数,如果没有的话,j为0
	//即该循环结束后,j即为带插入的数的位置
	for (i = len - 1; i > 0 && tema < arr[i - 1]; i--)
	{
		arr[i] = arr[i-1];
	}
	arr[i] = tema;
}


/*
函数:void InsertSort(MType arr[], int len)
说明:插入排序
参数:arr为传入的数组的地址
参数:len为传入数组的长度
*/
void InsertSort(MType arr[], int len)
{
	
	//_
	int i = 0, j = 0;
	//临时变量，用于交换两个数的位置,存储待插入的数
	MType tema;
	for (i = 1; i < len; i++)
	{
		tema = arr[i];
		//循环条件为从插入的数字之前的有序数中查找比这个数小的数,如果没有的话,j为0
		//即该循环结束后,j即为带插入的数的位置
		for (j = i ; j > 0 && tema < arr[j - 1]; j--)
		{
			//向前查找,并且待插入的数比与之比较的数小,则将这个比较的数向后移位
			arr[j] = arr[j - 1];			
		}
		arr[j]=tema;
	}


#ifdef DEBUG
	std::cout << "InsertSort数据" << std::endl;
#endif // DEBUG

}



/*
函数:void BubbleSortJW(MType arr[], int len)
说明:鸡尾酒排序
参数:arr为传入的数组的地址
参数:len为传入数组的长度
*/
void BubbleSortJW(MType arr[], int len)
{
	

	//_
	int i = 0, j = 0;
	//记录比较次数
	int compilecounts = 0;
	//记录交换次数
	int swapcounts = 0;
	//设置旗帜
	int flag = 0;
	//临时变量，用于交换两个数的位置
	MType tema;
	for (i = 0; i < len/2; i++)
	{
		flag = 0;
		for (j = i; j < len - 1 - i; j++)
		{


			compilecounts++;
			if (arr[j] > arr[j + 1])
			{
				tema = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tema;

				flag = 1;
				swapcounts++;
			}

		}
		//如果旗帜的值没有发生改变,说明所有数已有序,退出
		if (flag == 0)
		{
			break;
		}
		
		flag = 0;
		for (j = len - 1 - i - 1; j > i; j--)
		{
			compilecounts++;
			if (arr[j] < arr[j - 1])
			{
				tema = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tema;

				flag = 1;
				swapcounts++;
			}
		}
		//如果旗帜的值没有发生改变,说明所有数已有序,退出
		if (flag == 0)
		{
			break;
		}
		
	}

#ifdef DEBUG
	std::cout << "BubbleSortJW数据" << std::endl;
	std::cout << compilecounts << "次比较" << std::endl;
	std::cout << swapcounts << "次交换" << std::endl;
#endif // DEBUG




}


/*
函数:void BubbleSort(MType arr[],int len)
说明:冒泡排序
参数:arr为传入的数组的地址
参数:len为传入数组的长度
*/
void BubbleSort(MType arr[],int len)
{
	
	//_
	int i = 0, j = 0;
	//记录比较次数
	int compilecounts = 0;
	//记录交换次数
	int swapcounts = 0;
	//设置旗帜
	int flag = 0;
	//临时变量，用于交换两个数的位置
	MType tema;
	for (i = 0; i < len - 1; i++)
	{
		
		flag = 0;
		for (j = 0; j < len - 1 - i; j++)
		{


			compilecounts++;
			if (arr[j] > arr[j + 1])
			{
				tema = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tema;

				flag = 1;
				swapcounts++;
			}
			
		}
		//如果旗帜的值没有发生改变,说明所有数已有序,退出
		if (flag == 0)
		{
			break;
		}
	}

#ifdef DEBUG
	std::cout << "BubbleSort数据" << std::endl;
	std::cout << compilecounts << "次比较" << std::endl;
	std::cout << swapcounts << "次交换" << std::endl;

#endif // DEBUG

}


/*
函数:void disp(MType arr[],int len)
说明:打印数组
参数:arr为传入的数组的地址
参数:len为传入数组的长度
*/
void disp(MType arr[],int len)
{
	
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}



//Main入口
int main()
{
	
	MType arr[AMAX] = { 0 };
	MType arr1[AMAX] = { 0 };
	MType arr2[AMAX] = { 0 };
	MType arr3[AMAX] = { 0 };
	MType arr4[AMAX] = { 0 };
	MType arr5[AMAX] = { 0 };
	MType arr6[AMAX] = { 0 };
	MType arr7[AMAX] = { 0 };

	for (int i = 0; i < AMAX; i++)
	{
		arr[i] = AMAX - i;
		arr1[i] = AMAX - i;
		arr2[i] = AMAX - i;
		arr3[i] = AMAX - i;
		arr4[i] = AMAX - i;
		arr5[i] = AMAX - i;
		arr6[i] = AMAX - i;
		arr7[i] = AMAX - i;
	}
	
	std::cout << "原数据" << std::endl;
	disp(arr, AMAX);


	
	BubbleSort(arr, AMAX);
	disp(arr, AMAX);
	BubbleSortJW(arr1, AMAX);
	disp(arr1, AMAX);
	InsertSort(arr2, AMAX);
	disp(arr2, AMAX);
	InsertSortDG(arr3, AMAX);
	disp(arr3, AMAX);
	SelectSort(arr4, AMAX);
	disp(arr4, AMAX);
	SelectSortDG(arr5, 0, AMAX-1);
	disp(arr5, AMAX);
	QuickSort(arr6, 0, AMAX - 1);
	disp(arr6, AMAX);
	GravitySort(arr7, AMAX);
	disp(arr7, AMAX);




	return 0;
}