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
