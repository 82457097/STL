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