#include <cassert>
#include <vector>

template <typename T>
void ReverseArray(T* start, size_t size) {
    if (size == 0) return;
    for (int i = 0; i < size / 2; ++i) {
        std::swap(*(start + i), *(start + size - i-1));
    }
}
/*
int main() {
    using namespace std;

    vector<int> v = { 1, 2 };
    ReverseArray(v.data(), v.size());
    assert(v == (vector<int>{2, 1}));
}
*/