#include<algorithm>
#include<chrono>
#include<deque>
#include<iostream>
#include<list>
#include<map>
#include<random>
#include<set>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<forward_list>

static void vectorPart();
static void dequePart();
static void listPart();
static void forwardListPart();
static void mapPart();
static void setPart();
static void unorderedSetAndMapPart();
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
	forwardListPart();
	dequePart();
	listPart(); 
	mapPart();
	setPart();
	unorderedSetAndMapPart();

	return 0;
}

static void vectorPart() {
	/*
	namespace space std {
		template<typename T,typename Allocator = allocator<T>>
		class  vector;
	}
	特点随机访问元素，末端添加和删除元素效率高，前端和中间删除和添加元素效率低，
	存在当前容器大小和容量的关系
	*/
	using Group = std::vector<float>;

	Group a;
	Group b = a;
	Group c(a);
	Group d(10);
	Group e(10, 1.0f);
	Group f(e.begin(), e.end());
	Group g({ 1.0f,2.0f,3.0f });
	Group h = { 1.0f,3.0f,4.0f };

	d.empty();
	d.size();
	d.max_size();
	d.capacity();
	d.reserve(100);
	d.shrink_to_fit();
	//operator == != < > <= >=

	//赋值
	b = g;
	b.assign(3, 1.0f);
	b.assign(g.begin(), g.end());
	b.assign({ 1.0f,2.0f,3.0f });

	//交换
	b.swap(a);
	std::swap(a, b);

	//元素访问
	b[0];
	b.at(0);	//std::out_of_range
	if (b.empty()) {				//如果b是空的，那么下面两个函数将会产生未定义错误
		b.front();				//undefined
		b.back();				//undefined
	}
	b.front();
	b.back();

	//迭代器相关
	a.begin();
	a.end();
	a.cbegin();
	a.cend();
	a.rbegin();
	a.rend();
	a.crbegin();
	a.crend();

	a.pop_back();	//可能会产生未定义错误
	//单线程不会出错
	//多线程可能会出错
	if (!a.empty())
		a.pop_back();

	auto iter_after = b.erase(b.begin());		//删除一个数据 返回删除元素下一个位置的迭代器
	iter_after = b.erase(b.begin(),b.end());	//删除一个区间的数据

	b.push_back(10.0f);
	b.pop_back();
	auto iter = b.insert(b.end(), 100.0f);	//插入一个数据
	b.insert(b.end(), h.begin(), h.end());	//插入一各区间的数据
	b.emplace(b.end(), 10.0f);				//c++11
	b.emplace_back(10.0f);					//c++11
	b.resize(10);							//一个参数 设置大小
	b.resize(100, 1.0f);					//重新设置大小 并填值
	b.clear();							//清楚数据 但不释放内存
	b.shrink_to_fit();

	//和C的借口互用
	std::vector<char> carr(100, 0);
	strcpy(&carr[0], "hello world\n");	//使用carr.data()更好
	printf("%s", carr.begin());		//这是错误的用法

	//std::vector<bool> 不要在vector里放bool值
}

static void dequePart() {
	//deque 是c++98中引入的动态数组（dynamic array）
	//namespace std {
	//	template<typename T,typename Allocator = allocator<T>>
	//	class  deque
	//}
	//特点随机访问元素，末端和头部添加删除元素效率高，中间删除和插入元素效率低，
	//元素的访问和迭代比vector要慢，迭代器不能使普通的指针
	using Group = std::deque<float>;

	Group a;
	Group b = a;
	Group c(a);
	Group d(10);
	Group e(10, 1.0f);
	Group f(e.begin(), e.end());
	Group g({ 1.0f,2.0f,3.0f });
	Group h = { 1.0f,3.0f,4.0f };

	d.empty();
	d.size();
	d.max_size();
	//和vector不同，deque不提供以下的函数
	//d.capacity();
	//d.reserve(100);
	d.shrink_to_fit();	//c++11
	//operator == != < > <= >=

	//赋值
	b = g;
	b.assign(3, 1.0f);
	b.assign(g.begin(), g.end());
	b.assign({ 1.0f,2.0f,3.0f });

	//交换
	b.swap(a);
	std::swap(a, b);
	//元素访问
	b[0];
	b.at(0);	//std::out_of_range
	if (b.empty()) {				//如果b是空的，那么下面两个函数将会产生未定义错误
		b.front();				//undefined
		b.back();				//undefined
	}
	b.front();
	b.back();

	//迭代器相关
	a.begin();
	a.end();
	a.cbegin();
	a.cend();
	a.rbegin();
	a.rend();
	a.crbegin();
	a.crend();

	a.pop_back();	//可能会产生未定义错误
	//单线程不会出错
	//多线程可能会出错
	if (!a.empty())
		a.pop_back();

	auto iter_after = b.erase(b.begin());		//删除一个数据 返回删除元素下一个位置的迭代器
	iter_after = b.erase(b.begin(), b.end());	//删除一个区间的数据

	b.push_back(10.0f);
	b.pop_back();
	b.pop_front();
	b.push_front(1.2f);
	auto iter = b.insert(b.end(), 100.0f);	//插入一个数据
	b.insert(b.end(), h.begin(), h.end());	//插入一各区间的数据
	b.emplace(b.end(), 10.0f);				//c++11
	b.emplace_back(10.0f);					//c++11
	b.emplace_front(1.3f);
	b.resize(10);							//一个参数 设置大小
	b.resize(100, 1.0f);					//重新设置大小 并填值
	b.clear();							//清楚数据 一般会释放空间
	b.shrink_to_fit();

	/*	//向客户端收包发包
	using Buffer = std::vector<char>;
	using BufferGroup = std::deque<Buffer>;
	BufferGroup group;
	Buffer buffer;
	auto ok = readFromClient(socket, &buffer);
	if (ok) {
		group.emplace_back(std::move(buffer));
	}
	else {
		//handle error
	}

	while (!group.empty()) {
		auto ok = sendToClient(socket, group.front());
		if (ok) {
			group.pop_front();
		}
		else {
			//handle error
			break;
		}
	}
	*/
}

static void listPart() {
	//list 是c++98中引入的双向串列（double linked list）
	//namespace std {
	//template<typename T, typename Allocator = allocator<T>>
	//class  list;
	//}
	//特点不支持随机访问元素，访问头部和尾部速度快，
	//任何位置插入删除很快，常量时间内完成
	//插入和删除不会造成迭代器失效
	//对于异常支持的好，出现异常对于list而言，要不成功，要么什么影响也没有

	using Group = std::list<float>;

	Group a;
	Group b = a;
	Group c(a);
	Group d(10);
	Group e(10, 1.0f);
	Group f(e.begin(), e.end());
	Group g({ 1.0f,2.0f,3.0f });
	Group h = { 1.0f,3.0f,4.0f };

	d.empty();
	d.size();
	d.max_size();
	//list也不支持以下的函数
	//d.capacity();
	//d.reserve(100);
	//d.shrink_to_fit();

	//operator == != < > <= >=

	//赋值
	b = g;
	b.assign(3, 1.0f);
	b.assign(g.begin(), g.end());
	b.assign({ 1.0f,2.0f,3.0f });

	//交换
	b.swap(a);
	std::swap(a, b);

	//元素访问，不能随机访问
	//b[0];
	//b.at(0);	//std::out_of_range
	if (b.empty()) {				//如果b是空的，那么下面两个函数将会产生未定义错误
		b.front();				//undefined
		b.back();				//undefined
	}
	b.front();
	b.back();

	//迭代器相关
	a.begin();
	a.end();
	a.cbegin();
	a.cend();
	a.rbegin();
	a.rend();
	a.crbegin();
	a.crend();
	//访问指定元素的方法
	auto iterBegin = a.begin();
	//assert(a,size() >= 10);
	for (int i = 0; i < 5; i++)
		++iterBegin;
	
	std::advance(iterBegin, 4);
	auto iter5 = std::next(iterBegin, 4);

	a.pop_back();	//可能会产生未定义错误
	//单线程不会出错
	//多线程可能会出错
	if (!a.empty())
		a.pop_back();

	auto iter_after = b.erase(b.begin());		//删除一个数据 返回删除元素下一个位置的迭代器
	iter_after = b.erase(b.begin(), b.end());	//删除一个区间的数据

	b.push_back(10.0f);
	b.pop_back();
	auto iter = b.insert(b.end(), 100.0f);	//插入一个数据
	b.insert(b.end(), h.begin(), h.end());	//插入一各区间的数据
	b.emplace(b.end(), 10.0f);				//c++11
	b.emplace_back(10.0f);					//c++11
	b.resize(10);							//一个参数 设置大小
	b.resize(100, 1.0f);					//重新设置大小 并填值
	b.clear();							//清楚数据 但不释放内存
	//b.shrink_to_fit();					//没有

	//算法
	b.remove(1.0f);		//删除列表里全部等于参数的值
	b.remove_if([](auto v) {return v > 100.0f; });	//删除符合条件的值
	b.reverse();	//由大到小排序
	b.sort();	//由小到大
	g.sort();	//
	b.merge(g);	//两个排好序的list合并
	c.unique();	//1 1 2 2 1 1 3 4 -> 1 2 1 3 4 去掉重复的
	c.splice(c.begin(), b);	//把后一个参数直接拼接到c的某一个位置
}

static void forwardListPart() {
	//forward_list 是c++11中引入的单项串列（singly linked list）
	//namespace std {
	//	template<typename T,typename Allocator = allocator<T>>
	//	class forward_list;
	//}
	//特点不支持随机访问，访问头部元素的速度快
	//“forward_list和自己手写的c_style singly linked list”相比。
	//没有任何的时间和空间上的额外开销，任何性质如果和这个目标抵触，我们放弃该特征
	//任何位置插入和删除元素都很快，常量时间完成
	//插入和删除不会造成迭代器失效
	//对于异常支持好，出现异常对于forward_list而言，要不成功，要不什么影响都没有

	using Group = std::forward_list<float>;

	Group a;
	Group b = a;
	Group c(a);
	Group d(10);
	Group e(10, 1.0f);
	Group f(e.begin(), e.end());
	Group g({ 1.0f,2.0f,3.0f });
	Group h = { 1.0f,3.0f,4.0f };

	d.empty();
	//d.size();
	d.max_size();
	//list也不支持以下的函数
	//d.capacity();
	//d.reserve(100);
	//d.shrink_to_fit();

	//operator == != < > <= >=

	//赋值
	b = g;
	b.assign(3, 1.0f);
	b.assign(g.begin(), g.end());
	b.assign({ 1.0f,2.0f,3.0f });

	//交换
	b.swap(a);
	std::swap(a, b);

	//元素访问，不能随机访问
	//b[0];
	//b.at(0);	//std::out_of_range
	b.front();
	//b.back();

	//迭代器相关
	a.begin();
	a.end();
	a.cbegin();
	a.cend();
	a.before_begin();
	a.cbefore_begin();
	//a.rbegin();
	//a.rend();
	//a.crbegin();
	//a.crend();
	//访问指定元素的方法
	auto iterBegin = a.begin();


	auto iter_after = b.erase_after(b.before_begin());		//return void
	iter_after = b.erase_after(b.before_begin(), b.end());	//return void

	//b.push_back(10.0f);
	//b.pop_back();
	b.push_front(1.2f);
	b.emplace_front(1.3f);
	auto iter = b.insert_after(b.before_begin(), 100.0f);	//插入一个数据
	iter = b.insert_after(b.before_begin(), 10, -10.0f);	//插入一各区间的数据
	b.insert_after(b.before_begin(), h.begin(), h.end());
	//b.emplace(b.end(), 10.0f);				//c++11
	//b.emplace_back(10.0f);					//c++11
	b.resize(10);							//一个参数 设置大小
	b.resize(100, 1.0f);					//重新设置大小 并填值
	
	//算法
	b.remove(1.0f);		//删除列表里全部等于参数的值
	b.remove_if([](auto v) {return v > 100.0f; });	//删除符合条件的值
	b.reverse();	//由大到小排序
	b.sort();	//由小到大
	g.sort();	//
	b.merge(g);	//两个排好序的list合并
	c.unique();	//1 1 2 2 1 1 3 4 -> 1 2 1 3 4 去掉重复的
	c.splice_after(c.begin(), b);	//把后一个参数直接拼接到c的某一个位置

	Group forlist = { 1,2,3,4,5 };
	auto fiter = forlist.before_begin();
	for (int i = 0; i < 2; ++i)
		++fiter;
	forlist.insert_after(fiter, 10);
}

static void setPart() {
	//set multiset 是c++98中引入的二叉树数据结构
	//namespace std {
	//	template<typena T,typename Compare=less<T>,typename Allocator = allocator<T>>
	//	class multiset;
	//}
	//特点自动将元素排序
	//插入和删除查找O(logn) 1000->20
	//元素必须支持严格的顺序
	//1.x < y == true, y < x == false;
	//2.x < y == true, y < z == true, x < z == true;
	//3.x < x ===false;
	//4.a == b, b == c, c == a;
	//不能改变元素的值
	//
	//辅助的类
	//namespace std {
	//	template<typename T1,typename T2>
	//	struct pair {
	//		T1 first;
	//		T2 second;
	//	};
	//}

	using Group = std::set<float>;
	Group a;
	Group b = a;
	Group c(a);
	Group d(c.begin(), c.end());
	Group g({ 1.0f,4.0f,3.0f });
	Group h = { 1.0f,3.0f,4.0f };

	d.empty();
	d.size();
	d.max_size();

	auto keycomp = c.key_comp();
	auto valuecomp = c.value_comp();

	//赋值
	b = g;

	//交换
	b.swap(a);
	std::swap(a, b);

	//迭代器相关
	a.begin();
	a.end();
	a.cbegin();
	a.cend();
	a.rbegin();
	a.rend();
	a.crbegin();
	a.crend();
	auto iterBegin = a.begin();

	//算法函数
	//set count 0 1
	//multiset count >= 0
	auto num = a.count(1.0f);
	auto findIter = a.find(1.0f);
	if (findIter == a.end()) {
		//not find
	}
	else {
		*findIter;
	}
	auto lower = a.lower_bound(1.0f);
	if (lower != a.end()) {
		if (*lower == 1.0f) {
			//has 1.0f
		}
	}
	auto high = a.upper_bound(1.0f);
	auto range = a.equal_range(1.0f);//return std::make_pair(a.lower_bound(1.0f),a.upper_bound(1.0f));

	auto eraseIter = b.erase(b.begin());
	eraseIter = b.erase(b.begin(), b.end());

	auto state = b.insert(100.0f);//state is a pair
	//auto insertIter = b.insert(c.begin(), c.end());
	b.emplace(100.0f);
	b.emplace_hint(b.end(), 100.0f);

}

/*
#include<iostream>
#include<set>
#include<string>

class Person {
private:
	int m_age;
	std::string m_name;
public:
	Person(int a, std::string n) :m_age{ a }, m_name{ std::move(n) } {}
	int age() const { return m_age; };
	const std::string& name() const { return m_name; }
	void print() const { std::cout << m_age << ":" << m_name << std::endl; }
};

struct CompareAge {
	template<typename T>
	bool operator () (const T& t1, const T& t2) const {
		return t1.age() < t2.age();
	}
};

struct CompareName {
	template<typename T>
	bool operator () (const T& t1, const T& t2) const {
		return t1.age() < t2.age();
	}
};
	
int main() {
	Person a(14,"Alice");
	Person b(25, "Bob");
	Person c(17, "Camily");

	std::cout << "order of age:\n";
	using Group = std::set<Person, CompareAge>;
	Group g;
	g.insert(a);
	g.insert(b);
	g.insert(c);
	for (auto& v : g) {
		v.print();
	}
	std::cout << "\n";

	using Group = std::set<Person, CompareName>;
	Group g;
	g.insert(a);
	g.insert(b);
	g.insert(c);
	for (auto& v : g) {
		v.print();
	}
	std::cout << "\n";
}
*/

static void mapPart() {
	//map multimap是c++98中引入的二叉树数据结构
	//namespace std {
	//	template<typename	Key, typename T, typename Compare = less<key>, typename Allocator
	//		= allocator<pair<const key, T>>>
	//		class map;
	//	template<typename	Key, typename T, typename Compare = less<key>, typename Allocator
	//		= allocator<pair<const key, T>>>
	//		class multimap;
	//}
	//特点自动将元素排序
	//插入和删除查找O（logn）
	//Key元素支持严格的弱顺序
	//1.x < y == true, y < x == false;
	//2.x < y == true, y < z == true, x < z == true;
	//3.x < x ===false;
	//4.a == b, b == c, c == a;
	//不能改变Key的值

	using Group = std::map<int, std::string>;
	Group a;
	Group b = a;
	Group c(a);
	Group d(c.begin(), c.end());
	Group g({ { 1,"a" }, { 2,"test" }, { 3,"test" } });

	d.empty();
	d.size();
	auto keycomp = c.key_comp();
	auto valuecomp = c.value_comp();

	//赋值
	b = g;

	//交换
	b.swap(a);
	std::swap(a, b);

	//迭代器相关
	a.begin();
	a.end();
	a.cbegin();
	a.cend();
	a.rbegin();
	a.rend();
	a.crbegin();
	a.crend();
	auto iterBegin = a.begin();

	//算法函数
	//set count 0 1
	//multiset count >= 0
	auto num = a.count(1);
	auto findIter = a.find(1);
	if (findIter == a.end()) {
		//not find
	}
	else {
		*findIter; //std::pair<const int,std::string>&
	}
	/*auto lower = a.lower_bound(1);
	if (lower != a.end()) {
		if (*lower == 1) {
			//has 1
		}
	}*/
	auto high = a.upper_bound(1);
	auto range = a.equal_range(1);//return std::make_pair(a.lower_bound(1.0f),a.upper_bound(1.0f));

	auto eraseIter = b.erase(b.begin());
	eraseIter = b.erase(b.begin(), b.end());

	auto state = b.insert(std::make_pair(100,"good"));//state is a pair
	//auto insertIter = b.insert(c.begin(), c.end());
	b.emplace(std::make_pair(10,"has it"));
	b.emplace(11, std::string("again"));
	b.emplace(12,"third");
	b.emplace_hint(b.end(), 13, "haha");


	//[] 先找中括号里的键值是否已经存在
	//auto string
	//[]->auto iter = b.insert(std::make_pair(13,std::string())).first;
	//return (*iter).second;
	auto& info = b[10];
	b[13];

	//at
	try {
		auto& findInfo = b.at(10);	//const
	} catch(...) {

	}
	auto findIter = b.find(10);
	if (findIter != std::end(b)/*b.end()*/) {
		auto& v = (*findIter).second;
	}
	else {

	}
}

static void unorderedSetAndMapPart() {
	//unordered_multiset unordered_set
	//unordered_multimap unordered_map是c++11中以hash table为基础的，内部没有明确的顺序元素
	//namespace std {
	//	template<typename Key, typename T, typename Hash = hash<Key>, typename
	//		EqPred = equal_to<T>, typename Allocator = allocator<pair<const Key, T>>>
	//		class unorderdmap;
	//	template<typename Key, typename T, typename Hash = hash<Key>, typename
	//		EqPred = equal_to<T>, typename Allocator = allocator<pair<const Key, T>>>
	//		class multimap;
	//	template<typename Key, typename T, typename Hash = hash<Key>, typename
	//		EqPred = equal_to<T>, typename Allocator = allocator<pair<const Key, T>>>
	//		class unordered_set;
	//	template<typename Key, typename T, typename Hash = hash<Key>, typename
	//		EqPred = equal_to<T>, typename Allocator = allocator<pair<const Key, T>>>
	//		class unordered_multiset;
	//}
}

static void stlAlgorithm() {

}