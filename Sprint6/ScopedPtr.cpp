#include <cassert>
#include <stdexcept>
/*
// ����� ���������, ��������� ��������� ������ ��� ���� ����������.
// �������� ������� T ����� ��� �������, �� ������� ��������� ���������
template <typename T>
class ScopedPtr {
public:
    // ����������� �� ��������� ������ ������� ���������,
    // ��� ��� ���� ptr_ ����� �������� �� ��������� nullptr
    ScopedPtr() = default;

    // ������ ���������, ����������� �� ���������� raw_ptr.
    // raw_ptr ��������� ���� �� ������, ��������� � ���� ��� ������ new,
    // ���� �������� ������� ����������
    // ������������ noexcept ����������, ��� ����� �� ������� ����������
    explicit ScopedPtr(T* raw_ptr) noexcept {
        // ���������� ��������������
        ptr_ = raw_ptr;
    }

    // ������� � ������ ����������� �����������
    ScopedPtr(const ScopedPtr&) = delete;

    // ����������. ������� ������, �� ������� ��������� ����� ���������.
    ~ScopedPtr() {
        // ���������� ���� ����������� ��������������
        delete ptr_;
    }

    // ���������� ���������, ���������� ������ ScopedPtr
    T* GetRawPtr() const noexcept {
        // �������� ��� ������ ��������������
        return ptr_;
    }

    // ���������� �������� ��������, �� ������� ��������� ����� ���������
    // ���������� ������� �������� "������" ��������� � ������������� ���� ptr_ � null
    T* Release() noexcept {
        // ���������� ��������������
        T* raw_ptr = ptr_;
        ptr_ = nullptr;
        return raw_ptr;
    }
    explicit operator bool() const noexcept {
        // ���������� ��������������
        return ptr_ != nullptr;
    }

    // �������� ������������� ���������� ������ �� ������
    // ����������� ���������� std::logic_error, ���� ��������� �������
    T& operator*() const {
        // ���������� ��������������
        if (!ptr_) throw std::logic_error("logic error");
        return *ptr_;
    }

    // �������� -> ������ ���������� ��������� �� ������
    // ����������� ���������� std::logic_error, ���� ��������� �������
    T* operator->() const {
        // ���������� ��������������
        if (!ptr_) throw std::logic_error("logic error");
        return ptr_;
    }

private:
    T* ptr_ = nullptr;
};


*/