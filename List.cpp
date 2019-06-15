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