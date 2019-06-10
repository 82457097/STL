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
	e.swap(g);//对于array来说 会随着数据的增加消耗增加 其他的容器为O(1);
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
	//STL是一个框架，将数据结构和算法进一步抽象
	//容器、迭代器、算法
	//Container
	//1.序列式容器 array vector deque list forward_list 数组 指针 list
	//2.关联类容器 set map multiset multiset 二叉树 红黑树
	//hash_map hash_set
	//3.无顺序容器 unordered_map unordered_set unordered_multimap unordered_multiset
	//hash_map table
	//stl容器的基本知识（常识部分）
	vectorPart();
	listPart(); 
	mapPart();
	setPart();
	unorderedMapPart();
	unorderedSetPart();

	return 0;
}