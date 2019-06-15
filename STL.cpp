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
	�ص��������Ԫ�أ�ĩ����Ӻ�ɾ��Ԫ��Ч�ʸߣ�ǰ�˺��м�ɾ�������Ԫ��Ч�ʵͣ�
	���ڵ�ǰ������С�������Ĺ�ϵ
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

	//��ֵ
	b = g;
	b.assign(3, 1.0f);
	b.assign(g.begin(), g.end());
	b.assign({ 1.0f,2.0f,3.0f });

	//����
	b.swap(a);
	std::swap(a, b);

	//Ԫ�ط���
	b[0];
	b.at(0);	//std::out_of_range
	if (b.empty()) {				//���b�ǿյģ���ô�������������������δ�������
		b.front();				//undefined
		b.back();				//undefined
	}
	b.front();
	b.back();

	//���������
	a.begin();
	a.end();
	a.cbegin();
	a.cend();
	a.rbegin();
	a.rend();
	a.crbegin();
	a.crend();

	a.pop_back();	//���ܻ����δ�������
	//���̲߳������
	//���߳̿��ܻ����
	if (!a.empty())
		a.pop_back();

	auto iter_after = b.erase(b.begin());		//ɾ��һ������ ����ɾ��Ԫ����һ��λ�õĵ�����
	iter_after = b.erase(b.begin(),b.end());	//ɾ��һ�����������

	b.push_back(10.0f);
	b.pop_back();
	auto iter = b.insert(b.end(), 100.0f);	//����һ������
	b.insert(b.end(), h.begin(), h.end());	//����һ�����������
	b.emplace(b.end(), 10.0f);				//c++11
	b.emplace_back(10.0f);					//c++11
	b.resize(10);							//һ������ ���ô�С
	b.resize(100, 1.0f);					//�������ô�С ����ֵ
	b.clear();							//������� �����ͷ��ڴ�
	b.shrink_to_fit();

	//��C�Ľ�ڻ���
	std::vector<char> carr(100, 0);
	strcpy(&carr[0], "hello world\n");	//ʹ��carr.data()����
	printf("%s", carr.begin());		//���Ǵ�����÷�

	//std::vector<bool> ��Ҫ��vector���boolֵ
}

static void dequePart() {
	//deque ��c++98������Ķ�̬���飨dynamic array��
	//namespace std {
	//	template<typename T,typename Allocator = allocator<T>>
	//	class  deque
	//}
	//�ص��������Ԫ�أ�ĩ�˺�ͷ�����ɾ��Ԫ��Ч�ʸߣ��м�ɾ���Ͳ���Ԫ��Ч�ʵͣ�
	//Ԫ�صķ��ʺ͵�����vectorҪ��������������ʹ��ͨ��ָ��
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
	//��vector��ͬ��deque���ṩ���µĺ���
	//d.capacity();
	//d.reserve(100);
	d.shrink_to_fit();	//c++11
	//operator == != < > <= >=

	//��ֵ
	b = g;
	b.assign(3, 1.0f);
	b.assign(g.begin(), g.end());
	b.assign({ 1.0f,2.0f,3.0f });

	//����
	b.swap(a);
	std::swap(a, b);
	//Ԫ�ط���
	b[0];
	b.at(0);	//std::out_of_range
	if (b.empty()) {				//���b�ǿյģ���ô�������������������δ�������
		b.front();				//undefined
		b.back();				//undefined
	}
	b.front();
	b.back();

	//���������
	a.begin();
	a.end();
	a.cbegin();
	a.cend();
	a.rbegin();
	a.rend();
	a.crbegin();
	a.crend();

	a.pop_back();	//���ܻ����δ�������
	//���̲߳������
	//���߳̿��ܻ����
	if (!a.empty())
		a.pop_back();

	auto iter_after = b.erase(b.begin());		//ɾ��һ������ ����ɾ��Ԫ����һ��λ�õĵ�����
	iter_after = b.erase(b.begin(), b.end());	//ɾ��һ�����������

	b.push_back(10.0f);
	b.pop_back();
	b.pop_front();
	b.push_front(1.2f);
	auto iter = b.insert(b.end(), 100.0f);	//����һ������
	b.insert(b.end(), h.begin(), h.end());	//����һ�����������
	b.emplace(b.end(), 10.0f);				//c++11
	b.emplace_back(10.0f);					//c++11
	b.emplace_front(1.3f);
	b.resize(10);							//һ������ ���ô�С
	b.resize(100, 1.0f);					//�������ô�С ����ֵ
	b.clear();							//������� һ����ͷſռ�
	b.shrink_to_fit();

	/*	//��ͻ����հ�����
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
	//list ��c++98�������˫���У�double linked list��
	//namespace std {
	//template<typename T, typename Allocator = allocator<T>>
	//class  list;
	//}
	//�ص㲻֧���������Ԫ�أ�����ͷ����β���ٶȿ죬
	//�κ�λ�ò���ɾ���ܿ죬����ʱ�������
	//�����ɾ��������ɵ�����ʧЧ
	//�����쳣֧�ֵĺã������쳣����list���ԣ�Ҫ���ɹ���ҪôʲôӰ��Ҳû��

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
	//listҲ��֧�����µĺ���
	//d.capacity();
	//d.reserve(100);
	//d.shrink_to_fit();

	//operator == != < > <= >=

	//��ֵ
	b = g;
	b.assign(3, 1.0f);
	b.assign(g.begin(), g.end());
	b.assign({ 1.0f,2.0f,3.0f });

	//����
	b.swap(a);
	std::swap(a, b);

	//Ԫ�ط��ʣ������������
	//b[0];
	//b.at(0);	//std::out_of_range
	if (b.empty()) {				//���b�ǿյģ���ô�������������������δ�������
		b.front();				//undefined
		b.back();				//undefined
	}
	b.front();
	b.back();

	//���������
	a.begin();
	a.end();
	a.cbegin();
	a.cend();
	a.rbegin();
	a.rend();
	a.crbegin();
	a.crend();
	//����ָ��Ԫ�صķ���
	auto iterBegin = a.begin();
	//assert(a,size() >= 10);
	for (int i = 0; i < 5; i++)
		++iterBegin;
	
	std::advance(iterBegin, 4);
	auto iter5 = std::next(iterBegin, 4);

	a.pop_back();	//���ܻ����δ�������
	//���̲߳������
	//���߳̿��ܻ����
	if (!a.empty())
		a.pop_back();

	auto iter_after = b.erase(b.begin());		//ɾ��һ������ ����ɾ��Ԫ����һ��λ�õĵ�����
	iter_after = b.erase(b.begin(), b.end());	//ɾ��һ�����������

	b.push_back(10.0f);
	b.pop_back();
	auto iter = b.insert(b.end(), 100.0f);	//����һ������
	b.insert(b.end(), h.begin(), h.end());	//����һ�����������
	b.emplace(b.end(), 10.0f);				//c++11
	b.emplace_back(10.0f);					//c++11
	b.resize(10);							//һ������ ���ô�С
	b.resize(100, 1.0f);					//�������ô�С ����ֵ
	b.clear();							//������� �����ͷ��ڴ�
	//b.shrink_to_fit();					//û��

	//�㷨
	b.remove(1.0f);		//ɾ���б���ȫ�����ڲ�����ֵ
	b.remove_if([](auto v) {return v > 100.0f; });	//ɾ������������ֵ
	b.reverse();	//�ɴ�С����
	b.sort();	//��С����
	g.sort();	//
	b.merge(g);	//�����ź����list�ϲ�
	c.unique();	//1 1 2 2 1 1 3 4 -> 1 2 1 3 4 ȥ���ظ���
	c.splice(c.begin(), b);	//�Ѻ�һ������ֱ��ƴ�ӵ�c��ĳһ��λ��
}

static void forwardListPart() {
	//forward_list ��c++11������ĵ���У�singly linked list��
	//namespace std {
	//	template<typename T,typename Allocator = allocator<T>>
	//	class forward_list;
	//}
	//�ص㲻֧��������ʣ�����ͷ��Ԫ�ص��ٶȿ�
	//��forward_list���Լ���д��c_style singly linked list����ȡ�
	//û���κε�ʱ��Ϳռ��ϵĶ��⿪�����κ�������������Ŀ��ִ������Ƿ���������
	//�κ�λ�ò����ɾ��Ԫ�ض��ܿ죬����ʱ�����
	//�����ɾ��������ɵ�����ʧЧ
	//�����쳣֧�ֺã������쳣����forward_list���ԣ�Ҫ���ɹ���Ҫ��ʲôӰ�춼û��

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
	//listҲ��֧�����µĺ���
	//d.capacity();
	//d.reserve(100);
	//d.shrink_to_fit();

	//operator == != < > <= >=

	//��ֵ
	b = g;
	b.assign(3, 1.0f);
	b.assign(g.begin(), g.end());
	b.assign({ 1.0f,2.0f,3.0f });

	//����
	b.swap(a);
	std::swap(a, b);

	//Ԫ�ط��ʣ������������
	//b[0];
	//b.at(0);	//std::out_of_range
	b.front();
	//b.back();

	//���������
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
	//����ָ��Ԫ�صķ���
	auto iterBegin = a.begin();


	auto iter_after = b.erase_after(b.before_begin());		//return void
	iter_after = b.erase_after(b.before_begin(), b.end());	//return void

	//b.push_back(10.0f);
	//b.pop_back();
	b.push_front(1.2f);
	b.emplace_front(1.3f);
	auto iter = b.insert_after(b.before_begin(), 100.0f);	//����һ������
	iter = b.insert_after(b.before_begin(), 10, -10.0f);	//����һ�����������
	b.insert_after(b.before_begin(), h.begin(), h.end());
	//b.emplace(b.end(), 10.0f);				//c++11
	//b.emplace_back(10.0f);					//c++11
	b.resize(10);							//һ������ ���ô�С
	b.resize(100, 1.0f);					//�������ô�С ����ֵ
	
	//�㷨
	b.remove(1.0f);		//ɾ���б���ȫ�����ڲ�����ֵ
	b.remove_if([](auto v) {return v > 100.0f; });	//ɾ������������ֵ
	b.reverse();	//�ɴ�С����
	b.sort();	//��С����
	g.sort();	//
	b.merge(g);	//�����ź����list�ϲ�
	c.unique();	//1 1 2 2 1 1 3 4 -> 1 2 1 3 4 ȥ���ظ���
	c.splice_after(c.begin(), b);	//�Ѻ�һ������ֱ��ƴ�ӵ�c��ĳһ��λ��

	Group forlist = { 1,2,3,4,5 };
	auto fiter = forlist.before_begin();
	for (int i = 0; i < 2; ++i)
		++fiter;
	forlist.insert_after(fiter, 10);
}

static void setPart() {
	//set multiset ��c++98������Ķ��������ݽṹ
	//namespace std {
	//	template<typena T,typename Compare=less<T>,typename Allocator = allocator<T>>
	//	class multiset;
	//}
	//�ص��Զ���Ԫ������
	//�����ɾ������O(logn) 1000->20
	//Ԫ�ر���֧���ϸ��˳��
	//1.x < y == true, y < x == false;
	//2.x < y == true, y < z == true, x < z == true;
	//3.x < x ===false;
	//4.a == b, b == c, c == a;
	//���ܸı�Ԫ�ص�ֵ
	//
	//��������
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

	//��ֵ
	b = g;

	//����
	b.swap(a);
	std::swap(a, b);

	//���������
	a.begin();
	a.end();
	a.cbegin();
	a.cend();
	a.rbegin();
	a.rend();
	a.crbegin();
	a.crend();
	auto iterBegin = a.begin();

	//�㷨����
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
	//map multimap��c++98������Ķ��������ݽṹ
	//namespace std {
	//	template<typename	Key, typename T, typename Compare = less<key>, typename Allocator
	//		= allocator<pair<const key, T>>>
	//		class map;
	//	template<typename	Key, typename T, typename Compare = less<key>, typename Allocator
	//		= allocator<pair<const key, T>>>
	//		class multimap;
	//}
	//�ص��Զ���Ԫ������
	//�����ɾ������O��logn��
	//KeyԪ��֧���ϸ����˳��
	//1.x < y == true, y < x == false;
	//2.x < y == true, y < z == true, x < z == true;
	//3.x < x ===false;
	//4.a == b, b == c, c == a;
	//���ܸı�Key��ֵ

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

	//��ֵ
	b = g;

	//����
	b.swap(a);
	std::swap(a, b);

	//���������
	a.begin();
	a.end();
	a.cbegin();
	a.cend();
	a.rbegin();
	a.rend();
	a.crbegin();
	a.crend();
	auto iterBegin = a.begin();

	//�㷨����
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


	//[] ������������ļ�ֵ�Ƿ��Ѿ�����
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
	//unordered_multimap unordered_map��c++11����hash tableΪ�����ģ��ڲ�û����ȷ��˳��Ԫ��
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