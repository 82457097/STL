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
