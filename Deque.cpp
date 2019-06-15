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