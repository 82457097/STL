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
	Group C(a);
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
	if (b.empty()) {	//如果b是空的，那么下面两个函数将会产生未定义错误
		b.front();	//undefined
		b.back();	//undefined
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

	b.erase(b.begin());			//删除一个数据
	b.erase(b.begin(), b.end());	//删除一个区间的数据

	b.push_back(10.0f);
	b.pop_back();
	auto iter = b.insert(b.end(), 100.0f);	//插入一个数据
	b.insert(b.end(), h.begin(), h.end());	//插入一各区间的数据
	b.emplace(b.end(), 10.0f);	//c++11
	b.emplace_back(10.0f);		//c++11
	b.resize(10);			//一个参数 设置大小
	b.resize(100, 1.0f);	//重新设置大小 并填值
	b.clear();	//清楚数据 但不释放内存
	b.shrink_to_fit();

	//和C的借口互用
	std::vector<char> carr(100, 0);
	strcpy(&carr[0], "hello world\n");	//使用carr.data()更好
	printf("%s", carr.begin());		//这是错误的用法

	//std::vector<bool> 不要在vector里放bool值
}