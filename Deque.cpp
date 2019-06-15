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