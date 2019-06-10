#include<algorithm>
#include<chrono>
#include<iostream>
#include<list>
#include<map>
#include<random>
#include<set>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>

static void vectorPart();
static void listPart();
static void mapPart();
static void setPart();
static void unorderedMapPart();
static void unorderedSetPart();
static void stlAlgorithm();

template<typename T>
void containerAllInterface(T& a, T& b) {
	T c;
	T d(a);
	T e = a;
	T f(std::move(a));
	auto iterB = b.begin();
	auto iterE = b.end();
	T g(b.begin(), b.end());
	b.size();
	b.empty();
	b.max_size();
	if (b == c) {

	}
	if (b != d) {

	}
	if (b < e) {

	}
	e = b;
	e = std::move(b);
	e.swap(g);//����array��˵ ���������ݵ������������� ����������ΪO(1);
	swap(e, g);
	e.cbegin(); //-> const_iterator
	e.cend();
	e.clear();
}

void test() {
	std::vector<int> a;
	std::vector<int> b;
	containerAllInterface(a, b);
}

int main(int argc,char** argv) {
	//STL��һ����ܣ������ݽṹ���㷨��һ������
	//���������������㷨
	//Container
	//1.����ʽ���� array vector deque list forward_list ���� ָ�� list
	//2.���������� set map multiset multiset ������ �����
	//hash_map hash_set
	//3.��˳������ unordered_map unordered_set unordered_multimap unordered_multiset
	//hash_map table
	//stl�����Ļ���֪ʶ����ʶ���֣�
	vectorPart();
	listPart(); 
	mapPart();
	setPart();
	unorderedMapPart();
	unorderedSetPart();

	return 0;
}