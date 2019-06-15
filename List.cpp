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