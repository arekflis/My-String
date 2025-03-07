#include<iostream>

using namespace std;


class STRING
{
private:
	char* BUFFER = nullptr;
	int size = 0;

public:
	STRING();
	explicit STRING(const char* BUFF) ;
	STRING(char tab[], int size);
	STRING(const STRING& OBJECT);
	STRING& operator=(const STRING& OBJECT);
	bool operator==(STRING& OBJECT);
	STRING operator+(const STRING& OBJECT);
	int length() const;
	~STRING();
	char GetConcreteElement(int j) const;
	STRING WithoutLastElement();
	STRING WithoutFirstElement();
	friend ostream& operator<<(ostream& out, STRING& OBJECT);
	friend istream& operator>>(istream& IS, STRING& OBJECT);
private:
	void clean();

};

