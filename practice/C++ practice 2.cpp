# include<iostream>

void pp(int& a)
{
	std::cout << &a << " " << a << " " << sizeof(a) << "\n";
}

template <typename T>
class DynamicArray
{
	size_t	 m_size;
	T*	 m_arr;

public:

	DynamicArray(size_t size)
		: m_size(size)
		, m_arr(new T[size])
	{
		std::cout << "Array Constructor\n";
	}

	~DynamicArray()
	{
		delete[] m_arr;
		std::cout << "Array Destructor\n";
	}

	T get(size_t index) const
	{
		return m_arr[index];
	}

	void set(size_t index, T val)
	{
		m_arr[index] = val;
	}

	void print() const
	{
		for (size_t i = 0; i < m_size; ++i)
		{
			std::cout << i << " " << m_arr[i] << "\n";
		}
	}

	const T& operator [](size_t index) const // const 버전 오퍼레이터 오버로딩
	{
		return m_arr[index];
	}

	T& operator [](size_t index) // const 아닌 버전
	{
		return m_arr[index];
	}

};

int main(int argc, char* argv[])
{

	int arr[10] = {};
	int* harr = new int[10];

	for (size_t i = 0; i < 10; ++i)
	{
		pp(arr[i]); // 데이터가 연속적으로 들어감
	}

	for (size_t i = 0; i < 10; ++i)
	{
		pp(harr[i]); // 힙 영역에 할당
	}

	int	  a = 10;
	int	  b = 25;
	int* pa = &a;
	int* pb = &b;

	pp(a);
	pp(b);

	DynamicArray<float> myArray(10);

	std::cout << myArray[2] << "\n";

	myArray[3] = 3.14159;
	myArray[2] = 2.78;

	myArray.print();

	return 0;
}
