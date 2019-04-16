#include "iostream"

#define DEBUG

#define AMAX 10
typedef int MType;

/*
ѡ������
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
��������
*/
void QuickSort(MType arr[], int low, int high)
{
	if (low == high)
	{
		return;
	}

}



/*
����:void InsertSortDG(MType arr[], int len)
����:��������(�ݹ�ʵ��)
����:arrΪ���������ĵ�ַ
����:lenΪ��������ĳ���
*/
void InsertSortDG(MType arr[], int len)
{
	//��������������ĳ���ֻ��1ʱ,��ֱ�ӷ��ؼ���,�����������
	if (len == 1)
	{
		return;
	}
	//�����Լ�,��ǰlen-1����,�����ִ����,��ǰlen-1����������
	InsertSortDG(arr, len - 1);
	//_
	int i = 0;
	//��ʱ���������ڽ�����������λ��,�洢���������
	MType tema = arr[len - 1];
	//ѭ������Ϊ�Ӳ��������֮ǰ���������в��ұ������С����,���û�еĻ�,jΪ0
	//����ѭ��������,j��Ϊ�����������λ��
	for (i = len - 1; i > 0 && tema < arr[i - 1]; i--)
	{
		arr[i] = arr[i-1];
	}
	arr[i] = tema;
}


/*
����:void InsertSort(MType arr[], int len)
����:��������
����:arrΪ���������ĵ�ַ
����:lenΪ��������ĳ���
*/
void InsertSort(MType arr[], int len)
{
	
	//_
	int i = 0, j = 0;
	//��ʱ���������ڽ�����������λ��,�洢���������
	MType tema;
	for (i = 1; i < len; i++)
	{
		tema = arr[i];
		//ѭ������Ϊ�Ӳ��������֮ǰ���������в��ұ������С����,���û�еĻ�,jΪ0
		//����ѭ��������,j��Ϊ�����������λ��
		for (j = i ; j > 0 && tema < arr[j - 1]; j--)
		{
			//��ǰ����,���Ҵ������������֮�Ƚϵ���С,������Ƚϵ��������λ
			arr[j] = arr[j - 1];			
		}
		arr[j]=tema;
	}


#ifdef DEBUG
	std::cout << "InsertSort����" << std::endl;
#endif // DEBUG

}



/*
����:void BubbleSortJW(MType arr[], int len)
����:��β������
����:arrΪ���������ĵ�ַ
����:lenΪ��������ĳ���
*/
void BubbleSortJW(MType arr[], int len)
{
	

	//_
	int i = 0, j = 0;
	//��¼�Ƚϴ���
	int compilecounts = 0;
	//��¼��������
	int swapcounts = 0;
	//��������
	int flag = 0;
	//��ʱ���������ڽ�����������λ��
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
		//������ĵ�ֵû�з����ı�,˵��������������,�˳�
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
		//������ĵ�ֵû�з����ı�,˵��������������,�˳�
		if (flag == 0)
		{
			break;
		}
		
	}

#ifdef DEBUG
	std::cout << "BubbleSortJW����" << std::endl;
	std::cout << compilecounts << "�αȽ�" << std::endl;
	std::cout << swapcounts << "�ν���" << std::endl;
#endif // DEBUG




}


/*
����:void BubbleSort(MType arr[],int len)
����:ð������
����:arrΪ���������ĵ�ַ
����:lenΪ��������ĳ���
*/
void BubbleSort(MType arr[],int len)
{
	
	//_
	int i = 0, j = 0;
	//��¼�Ƚϴ���
	int compilecounts = 0;
	//��¼��������
	int swapcounts = 0;
	//��������
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
		//������ĵ�ֵû�з����ı�,˵��������������,�˳�
		if (flag == 0)
		{
			break;
		}
	}

#ifdef DEBUG
	std::cout << "BubbleSort����" << std::endl;
	std::cout << compilecounts << "�αȽ�" << std::endl;
	std::cout << swapcounts << "�ν���" << std::endl;

#endif // DEBUG

}


/*
����:void disp(MType arr[],int len)
����:��ӡ����
����:arrΪ���������ĵ�ַ
����:lenΪ��������ĳ���
*/
void disp(MType arr[],int len)
{
	
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}



//Main���
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
	
	std::cout << "ԭ����" << std::endl;
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