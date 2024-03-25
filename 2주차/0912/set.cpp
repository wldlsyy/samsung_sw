#include<iostream>
#include <set>
using namespace std; 


int main()
{
	set<int> s; 
	s.insert(10); 
	s.insert(9); 
	s.insert(8); 
	s.insert(7); 
	s.insert(1);

	for (auto it = s.begin(); it != s.end(); ++it) {
		cout << *it << " "; 
	}

	s.empty(); // true false 
	s.size(); // 5 
	s.count(3); // 0(안존재)또는1(존재)
	s.count(10); // 0(안존재)또는1(존재)

	auto it = s.find(1);  // 1 검색, it 는 1값의 iterator 
	if (it == s.begin()) {
		cout << "시작위치" << endl;
	}
	it++; // 그 다음 순서값 위치 
	cout << *it << endl;  // 7
	it++; 
	cout << *it << endl; // 8 

	it = s.end(); 
	--it; 
	cout << *it; // 제일 큰 원소 

	auto ret = s.insert(6); 
	ret.first; // 등록된 iterator (6의 iterator)
	ret.second; // 등록여부 

	ret = s.insert(6); 
	ret.second; //등록여부는 실패 

	// 삭제 
	auto ret2 = s.erase(2); // 값으로 삭제 , O(log N), // 삭제 여부를 리턴
	auto ret3 =s.erase(ret.first); // 거의 O(1) // 삭제된 다음 이터레이터를 반환 
	



	return 0; 
}
