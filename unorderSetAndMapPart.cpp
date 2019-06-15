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

	auto state = b.insert(std::make_pair(100, "good"));//state is a pair
	//auto insertIter = b.insert(c.begin(), c.end());
	b.emplace(std::make_pair(10, "has it"));
	b.emplace(11, std::string("again"));
	b.emplace(12, "third");
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
	}
	catch (...) {

	}
	auto findIter = b.find(10);
	if (findIter != std::end(b)/*b.end()*/) {
		auto& v = (*findIter).second;
	}
	else {

	}
}
