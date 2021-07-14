#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
// ��������
class Tentacle {
public:
    explicit Tentacle(int id) noexcept
        : id_(id) {
    }

    int GetId() const noexcept {
        return id_;
    }

    Tentacle* GetLinkedTentacle() const noexcept {
        return linked_tentacle_;
    }
    void LinkTo(Tentacle& tentacle) noexcept {
        linked_tentacle_ = &tentacle;
    }
    void Unlink() noexcept {
        linked_tentacle_ = nullptr;
    }

private:
    int id_ = 0;
    Tentacle* linked_tentacle_ = nullptr;
};

template <typename T>
class PtrVector {
public:
    PtrVector() = default;

    // ������ ������ ���������� �� ����� �������� �� other
    PtrVector(const PtrVector& other) {

        // ���������� ���������� ����������� ��������������
        for (const auto& ot : other.GetItems()) {
            items_.push_back(ot ? new T(*ot) : nullptr);

        }

    }

    // ���������� ������� ������� � ����, �� ������� ��������� ���������,
    // � ������� items_
    ~PtrVector() {
        // ���������� ���� ����������� ��������������
        for (auto it : items_) {
            delete it;
        }
    }

    // ���������� ������ �� ������ ����������
    vector<T*>& GetItems() noexcept {
        // ���������� ����� ��������������
        return items_;
    }

    // ���������� ����������� ������ �� ������ ����������
    vector<T*> const& GetItems() const noexcept {
        // ���������� ����� ��������������
        return items_;
    }

    void AddItem(const T*& item) {
       
        items_.push_back(item);
    }

private:
    vector<T*> items_;
};

// ��������
class Octopus {
public:
    Octopus()
        : Octopus(8) {
    }

    explicit Octopus(int num_tentacles) {
        Tentacle* t = nullptr;
        try {
            for (int i = 1; i <= num_tentacles; ++i) {
                Tentacle* t = new Tentacle(i);      // ����� ��������� ���������� bad_alloc
                tentacles_.GetItems().push_back(t);  // ����� ��������� ���������� bad_alloc

                // �������� ��������� �� ��������, ������� ��� �������� � tentacles_,
                // ����� �� ������� ��� � ����������� catch ��������
                t = nullptr;
            }
        }
        catch (const bad_alloc&) {
            // ������� ��������, ������� ������ ������� � ��������� tentacles_
            //Cleanup();
            // ������� ��������, ������� �������, �� �� �������� � tentacles_
            delete t;
            // ����������� �� ���� ������� ��������� � ������� ����������,
            // ������� ����������� ����������, ����� �������� ����������� ���� �� ������
            // throw ��� ���������� ������ catch ��������� ���������� ���������� ����������
            throw;
        }
    }

    explicit Octopus(const Octopus& octopus) {
        for (const auto& oct : octopus.tentacles_.GetItems()) {
            tentacles_.GetItems().push_back(new Tentacle(*oct));

        }

    }

    // ��������� ����� �������� � ���������������,
    // ������ (����������_������� + 1):
    // 1, 2, 3, ...
    // ���������� ������ �� ����������� ��������
    Tentacle& AddTentacle() {
    //     ���������� ���������� �������� ��������������
        Tentacle* tentacle= new Tentacle(GetTentacleCount()+1);
        tentacles_.GetItems().push_back(tentacle);
        return *tentacle;

    
    }

    int GetTentacleCount() const noexcept {
        return static_cast<int>(tentacles_.GetItems().size());
    }

    const Tentacle& GetTentacle(size_t index) const {
        return *tentacles_.GetItems().at(index);
    }
    Tentacle& GetTentacle(size_t index) {
        return *tentacles_.GetItems().at(index);
    }

private:
     // ������ ������ ��������� �� ��������. ���� ������� ������� ��������� � ����
    PtrVector<Tentacle> tentacles_;
};

int main() {
    // �������� ��������������� ����������
    {
        // �� ��������� �������� ����� 8 �������
        Octopus default_octopus;
        assert(default_octopus.GetTentacleCount() == 8);

        // �������� ����� ����� �������� �� 8 ���������� �������
        Octopus quadropus(4);
        assert(quadropus.GetTentacleCount() == 4);

        // � ���� ������ �� ����� �������
        Octopus coloboque(0);
        assert(coloboque.GetTentacleCount() == 0);
    }

    // ��������� ����� ��������� ��������
    // ���������������� ���, ����� ���� ��� ���������� ����� AddTentacle
    
    {
        Octopus octopus(1);
        Tentacle* t0 = &octopus.GetTentacle(0);
        Tentacle* t1 = &octopus.AddTentacle();
        assert(octopus.GetTentacleCount() == 2);
        Tentacle* t2 = &octopus.AddTentacle();
        assert(octopus.GetTentacleCount() == 3);

        // ����� ���������� ������� ����� ��������� �������� �� ������ ����� �������
        assert(&octopus.GetTentacle(0) == t0);
        assert(&octopus.GetTentacle(1) == t1);
        assert(&octopus.GetTentacle(2) == t2);

        for (int i = 0; i < octopus.GetTentacleCount(); ++i) {
            assert(octopus.GetTentacle(i).GetId() == i + 1);
        }
    }
    

    // ��������� ����� ������������ � ��������� ���� �����
    {
        Octopus male(2);
        Octopus female(2);

        assert(male.GetTentacle(0).GetLinkedTentacle() == nullptr);

        male.GetTentacle(0).LinkTo(female.GetTentacle(1));
        assert(male.GetTentacle(0).GetLinkedTentacle() == &female.GetTentacle(1));

        male.GetTentacle(0).Unlink();
        assert(male.GetTentacle(0).GetLinkedTentacle() == nullptr);
    }

    // ����� ��������� ����� ���� ����������� ����� �������, �������
    // �������� ��������� ������� ������������� ���������
    {
        // ���������� ���������� � ������ ����������� �������
        for (int num_tentacles = 0; num_tentacles < 10; ++num_tentacles) {
            Octopus male(num_tentacles);
            Octopus female(num_tentacles);
            // ����� ��� ������� ���� ����� �� ��������
            for (int i = 0; i < num_tentacles; ++i) {
                male.GetTentacle(i).LinkTo(female.GetTentacle(num_tentacles - 1 - i));
            }

            Octopus male_copy(male);
            // ��������� ��������� ������� �����
            assert(male_copy.GetTentacleCount() == male.GetTentacleCount());
            for (int i = 0; i < male_copy.GetTentacleCount(); ++i) {
                // ������ �������� ����� ����������� �� ������, ��������� �� ������ ������������� ��������
                assert(&male_copy.GetTentacle(i) != &male.GetTentacle(i));
                // ������ �������� ����� ������������ � ���� �� ��������, ��� � ������������
                assert(male_copy.GetTentacle(i).GetLinkedTentacle() == male.GetTentacle(i).GetLinkedTentacle());
            }
        }
        // ���� �� ������ ��� �������, �� ���������� ����������, ������ �����,
        // ������ ��� �������������� ���������
        cout << "Everything is OK"s << endl;
    }
}

*/