#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>

namespace Lab3a {

	class Hex {

	private:
		int len; //������� ����� ������� ����� 
		char* hex = nullptr; //������ �������� ����
		bool sign = true;

	public:
		//������������
		explicit Hex(); //������ �����������
		Hex(const long int num); //������������� 16-������ ����������
		Hex(const char* str); //������������� ��� ������ ��������

		Hex(const Hex&); //���������� �����������
		Hex(Hex&& num); //������������ �����������

		~Hex() { delete[] hex; hex = nullptr; }; //���������� 

		//������ � �������
		std::ostream& output(std::ostream&) const; //�����
		std::istream& input(std::istream&); //����

		//������ ������
		Hex Add(const Hex& num) const; //��������
		Hex Subtract(const Hex& num) const; //���������
		int Compare(const Hex& num) const; //���������
		int Compare(const Hex& num, bool abs) const; //��������� �� ������
		bool Parity() const; //�������� �� ��������
		Hex& Move_left(int n); //����� ����� 
		Hex& Move_right(int n); //����� ������

		//�������
		bool getSign() const { return sign; };
		int getLen() const { return len; }

		Hex& operator= (const Hex& num);

		//������ � �������
		friend std::istream& operator>>(std::istream& in, Hex& num);
		friend std::ostream& operator<<(std::ostream& out, const Hex& num);

		Hex operator+ (const Hex& num) const { return this->Add(num); }
		Hex operator- (const Hex& num) const { return this->Subtract(num); }

		Hex& operator>>= (const int n);
		Hex& operator<<= (const int n);

		Hex operator+= (const Hex& num) { return *this = *this + num; }

	private:
		Hex& twos�omplement();
		Hex& Complement(int n);
	};

	int charToHex(const char str);
	char hexToChar(const int num);
}
