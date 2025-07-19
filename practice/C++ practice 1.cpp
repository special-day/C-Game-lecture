# include<iostream>
# include<vector>
# include<fstream>

class Student
{
	std::string m_first = "First";
	std::string m_last	= "Last";
	int			m_id	= 0;
	float		m_avg	= 0;

public:

	Student() {}

	Student(std::string first, std::string last, int id, float avg)
		: m_first	(first)
		, m_last	(last)
		, m_id		(id)
		, m_avg		(avg)
	{
	}

	int getAvg() const
	{
		return m_avg;
	}

	int getID() const
	{
		return m_id;
	}

	std::string getFirst() const
	{
		return m_first;
	}

	std::string getLast() const
	{
		return m_last;
	}

	void print() const // 바꾸지 않겠다는 표시. 이러면 바꾸려고 해도 안됨.
	{
		std::cout << m_first << " " << m_last << " ";
		std::cout << m_id << " " << m_avg << "\n";
	}

};

class Course
{
	std::string m_name = "Course";
	std::vector<Student> m_students;

public:
	Course() {}

	Course(const std::string& name)
		: m_name(name)
	{
	}

	void addStudent(const Student& s)
	{
		m_students.push_back(s);
	}

	const std::vector<Student>& getStudents() const
	{
		return m_students;
	}

	void loadFromFile(const std::string& filename)
	{
		std::ifstream fin(filename);
		std::string first, last;
		int id;
		float avg;

		while (fin >> first)
		{
			fin >> last >> id >> avg;

			addStudent(Student(first, last, id, avg));
		}
		
	}

	void print() const
	{
		for (const auto& s : m_students)
		{
			s.print();
		}
	}
};

int main(int argc, char* argv[])
{
	std::vector<int> vec;
	vec.push_back(42);
	vec.push_back(10);
	vec.push_back(11);

	for (size_t i = 0; i < vec.size(); ++i) // 인덱스 순회 시 size_t를 사용하는 것이 안전하다.
	{
		std::cout << vec[i] << "\n";
	}

	for (int a : vec)
	{
		std::cout << a << "\n";
	}

	std::vector<float> vec2;
	vec2.push_back(42.5f);
	vec2.push_back(10.1f);

	for (auto a : vec2) // 근데 이렇게 하면 copying 한다
	{
		std::cout << a << "\n";
	}

	for (auto& a : vec2) // 따라서 레퍼런스 변수로 선언하는 게 좋음.
	{
		std::cout << a << "\n";
	}


	Student s1;
	Student s2("Dave", "Churchill", 1, 3.14);
	
	const Student s3("Jane", "Doe", 202200001, 99.9);

	std::cout << s3.getLast() << "\n";

	s3.print();

	Course comp4300("COMP 4300");
	comp4300.addStudent(s1);
	comp4300.addStudent(s2);
	comp4300.addStudent(s3);
	comp4300.addStudent(Student("Billy", "Bob", 3, 50.0));

	comp4300.print();

	Course c("COMP 4300");
	c.loadFromFile("students.txt");
	c.print();

	return 0;
}
