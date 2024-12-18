#include "strint.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <numeric>

using namespace lab3;
using namespace std;

vector<Strint> fromVector(vector<Strint> &source, int begin, int end) {
    if (end < begin) {
        return vector<Strint>();
    }
    vector<Strint> dest(end - begin + 1);
    std::copy(source.begin() + begin, source.begin() + end + 1, dest.begin());
    return dest;
}

int main() {
    std::srand(std::time(0));

    int vec_size;

    cout << "Введите размер вектора от 500 до 1000" << endl;
    cin >> vec_size;

    // 1
    cout << "Step 1" << endl;
    while ((vec_size < 500) || (vec_size > 1000)) {
        cout << "Неверный ввод. Введите целое число от 500 до 1000." << endl;
        cin >> vec_size;
    }   

    vector<Strint> v1(vec_size);
    std::generate(v1.begin(), v1.end(), Strint::get_random_strint);
    
    // 2
    cout << "Step 2" << endl;
    vector<Strint> v2;
    v2.reserve(200);
    std::copy(v1.end() - 200, v1.end(), std::back_inserter(v2));

    // 3
    cout << "Step 3" << endl;
    const int n = 30;
    auto comparator = [](const Strint& lhs, const Strint& rhs) {
		return lhs.get_int() < rhs.get_int();
	};
    auto rComparator = [&](const Strint& lhs, const Strint& rhs) {
		return !comparator(lhs, rhs);
	};

    std::partial_sort(v1.begin(), v1.begin() + n, v1.end(), rComparator);
    std::list<Strint> list1(n);
    std::copy(v1.begin(), v1.begin() + n, list1.begin());

    // 4
    cout << "Step 4" << endl;
    std::list<Strint> list2(n);
    std::sort(v2.begin(), v2.end(), comparator);
    std::copy(v2.begin(), v2.begin() + n, list2.begin());

    // 5
    cout << "Step 5" << endl;
    v1.erase(v1.begin(), v1.begin() + n);
    v2.erase(v2.begin(), v2.begin() + n);

    // 6
    cout << "Step 6" << endl;
    auto addition = [](const Strint& lhs, const Strint& rhs) {
		return Strint(lhs.get_int() + rhs.get_int(), lhs.get_str());
	};
    Strint sum = reduce(list1.begin(), list1.end(), Strint(0, "xyz"), addition);

    // 7
    cout << "Step 7" << endl;
    auto condition = [&](Strint& x) { return x.get_int() % 2 == 1; };
    auto newEnd = std::remove_if(list2.begin(), list2.end(), condition);
    list2.erase(newEnd, list2.end());

    // 8
    cout << "Step 8" << endl;
    std::vector<Strint> v3;
    std::sort(v1.begin(), v1.end(), comparator);
    std::sort(v2.begin(), v2.end(), comparator);
    std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(), comparator);

    // 9
    cout << "Step 9" << endl;
    int diff = std::abs(static_cast<int>(list1.size()) - static_cast<int>(list2.size()));
    std::list<Strint>& greater = list1.size() > list2.size() ? list1 : list2;
    
    auto end = greater.begin();
    std::advance(end, diff);
    
    greater.erase(greater.begin(), end);
    
    std::list<std::pair<Strint, Strint>> list3;
    std::transform(
        list1.begin(), list1.end(), 
        list2.begin(), std::back_inserter(list3), 
        [&](const Strint &a, const Strint &b) {
            return std::make_pair(a, b);
        }
    );

    // 10
    cout << "Step 10" << endl;
    size_t min_vec_size = std::min(v1.size(), v2.size());
    std::vector<std::pair<Strint, Strint>> v4(min_vec_size);
    std::transform(
        v1.begin(), v1.begin() + min_vec_size,
        v2.begin(), std::back_inserter(v4),
        [&](const Strint &a, const Strint &b) {
            return std::make_pair(a, b);
        }
    );

    return 0;

}
