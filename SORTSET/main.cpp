#include "iostream"

#define DEBUG

#define AMAX 10
typedef int MType;

/*
选择排序
*/
void SelectSort(MType arr[], int len)
{
	int i = 0, j = 0;
	MType arrmax = 0, arrmin = 0;
	MType tema;
	for (i = 0; i < len/2; i++)
	{
		for (j = i; j < len - 1 - i; j++)
		{
			if (arr[i] > arr[j])
			{
				tema = arr[i];
				arr[i] = arr[j];
				arr[j] = tema;
			}
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


void SelectSortDG(MType arr[],int low, int high)
{
	if (high - low < 2)
	{
		return;
	}
	int i = 0;
	MType tema;
	for (i = low; i <= high; i++)
	{
		if (arr[i] < arr[low])
		{
			tema = arr[i];
			arr[i] = arr[low];
			arr[low] = tema;
		}
		if (arr[i] > arr[high])
		{
			tema = arr[i];
			arr[i] = arr[high];
			arr[high] = tema;
		}
	}


	SelectSortDG(arr, low + 1, high - 1);

}



/*
快速排序
*/
void QuickSort(MType arr[], int low, int high)
{
	if (low == high)
	{
		return;
	}

}



/*
函数:void InsertSortDG(MType arr[], int len)
功能:插入排序(递归实现)
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
功能:插入排序
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
功能:鸡尾酒排序
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
功能:冒泡排序
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
功能:打印数组
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

	for (int i = 0; i < AMAX; i++)
	{
		arr[i] = AMAX - i;
		arr1[i] = AMAX - i;
		arr2[i] = AMAX - i;
		arr3[i] = AMAX - i;
		arr4[i] = AMAX - i;
		arr5[i] = AMAX - i;
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
	




	return 0;
}