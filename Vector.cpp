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
	if (b.empty()) {	//���b�ǿյģ���ô�������������������δ�������
		b.front();	//undefined
		b.back();	//undefined
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

	b.erase(b.begin());			//ɾ��һ������
	b.erase(b.begin(), b.end());	//ɾ��һ�����������

	b.push_back(10.0f);
	b.pop_back();
	auto iter = b.insert(b.end(), 100.0f);	//����һ������
	b.insert(b.end(), h.begin(), h.end());	//����һ�����������
	b.emplace(b.end(), 10.0f);	//c++11
	b.emplace_back(10.0f);		//c++11
	b.resize(10);			//һ������ ���ô�С
	b.resize(100, 1.0f);	//�������ô�С ����ֵ
	b.clear();	//������� �����ͷ��ڴ�
	b.shrink_to_fit();

	//��C�Ľ�ڻ���
	std::vector<char> carr(100, 0);
	strcpy(&carr[0], "hello world\n");	//ʹ��carr.data()����
	printf("%s", carr.begin());		//���Ǵ�����÷�

	//std::vector<bool> ��Ҫ��vector���boolֵ
}