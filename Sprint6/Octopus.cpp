#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
// Щупальце
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

    // Создаёт вектор указателей на копии объектов из other
    PtrVector(const PtrVector& other) {

        // Реализуйте копирующий конструктор самостоятельно
        for (const auto& ot : other.GetItems()) {
            items_.push_back(ot ? new T(*ot) : nullptr);

        }

    }

    // Деструктор удаляет объекты в куче, на которые ссылаются указатели,
    // в векторе items_
    ~PtrVector() {
        // Реализуйте тело деструктора самостоятельно
        for (auto it : items_) {
            delete it;
        }
    }

    // Возвращает ссылку на вектор указателей
    vector<T*>& GetItems() noexcept {
        // Реализуйте метод самостоятельно
        return items_;
    }

    // Возвращает константную ссылку на вектор указателей
    vector<T*> const& GetItems() const noexcept {
        // Реализуйте метод самостоятельно
        return items_;
    }

    void AddItem(const T*& item) {
       
        items_.push_back(item);
    }

private:
    vector<T*> items_;
};

// Осьминог
class Octopus {
public:
    Octopus()
        : Octopus(8) {
    }

    explicit Octopus(int num_tentacles) {
        Tentacle* t = nullptr;
        try {
            for (int i = 1; i <= num_tentacles; ++i) {
                Tentacle* t = new Tentacle(i);      // Может выбросить исключение bad_alloc
                tentacles_.GetItems().push_back(t);  // Может выбросить исключение bad_alloc

                // Обнуляем указатель на щупальце, которое уже добавили в tentacles_,
                // чтобы не удалить его в обработчике catch повторно
                t = nullptr;
            }
        }
        catch (const bad_alloc&) {
            // Удаляем щупальца, которые успели попасть в контейнер tentacles_
            //Cleanup();
            // Удаляем щупальце, которое создали, но не добавили в tentacles_
            delete t;
            // Конструктор не смог создать осьминога с восемью щупальцами,
            // поэтому выбрасываем исключение, чтобы сообщить вызывающему коду об ошибке
            // throw без параметров внутри catch выполняет ПЕРЕВЫБРОС пойманного исключения
            throw;
        }
    }

    explicit Octopus(const Octopus& octopus) {
        for (const auto& oct : octopus.tentacles_.GetItems()) {
            tentacles_.GetItems().push_back(new Tentacle(*oct));

        }

    }

    // Добавляет новое щупальце с идентификатором,
    // равным (количество_щупалец + 1):
    // 1, 2, 3, ...
    // Возвращает ссылку на добавленное щупальце
    Tentacle& AddTentacle() {
    //     Реализуйте добавление щупальца самостоятельно
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
     // Вектор хранит указатели на щупальца. Сами объекты щупалец находятся в куче
    PtrVector<Tentacle> tentacles_;
};

int main() {
    // Проверка конструирования осьминогов
    {
        // По умолчанию осьминог имеет 8 щупалец
        Octopus default_octopus;
        assert(default_octopus.GetTentacleCount() == 8);

        // Осьминог может иметь отличное от 8 количество щупалец
        Octopus quadropus(4);
        assert(quadropus.GetTentacleCount() == 4);

        // И даже вообще не иметь щупалец
        Octopus coloboque(0);
        assert(coloboque.GetTentacleCount() == 0);
    }

    // Осьминогу можно добавлять щупальца
    // Раскомментируйте код, после того как реализуете метод AddTentacle
    
    {
        Octopus octopus(1);
        Tentacle* t0 = &octopus.GetTentacle(0);
        Tentacle* t1 = &octopus.AddTentacle();
        assert(octopus.GetTentacleCount() == 2);
        Tentacle* t2 = &octopus.AddTentacle();
        assert(octopus.GetTentacleCount() == 3);

        // После добавления щупалец ранее созданные щупальца не меняют своих адресов
        assert(&octopus.GetTentacle(0) == t0);
        assert(&octopus.GetTentacle(1) == t1);
        assert(&octopus.GetTentacle(2) == t2);

        for (int i = 0; i < octopus.GetTentacleCount(); ++i) {
            assert(octopus.GetTentacle(i).GetId() == i + 1);
        }
    }
    

    // Осьминоги могут прицепляться к щупальцам друг друга
    {
        Octopus male(2);
        Octopus female(2);

        assert(male.GetTentacle(0).GetLinkedTentacle() == nullptr);

        male.GetTentacle(0).LinkTo(female.GetTentacle(1));
        assert(male.GetTentacle(0).GetLinkedTentacle() == &female.GetTentacle(1));

        male.GetTentacle(0).Unlink();
        assert(male.GetTentacle(0).GetLinkedTentacle() == nullptr);
    }

    // Копия осьминога имеет свою собственную копию щупалец, которые
    // копируют состояние щупалец оригинального осьминога
    {
        // Перебираем осьминогов с разным количеством щупалец
        for (int num_tentacles = 0; num_tentacles < 10; ++num_tentacles) {
            Octopus male(num_tentacles);
            Octopus female(num_tentacles);
            // Пусть они хватают друг друга за щупальца
            for (int i = 0; i < num_tentacles; ++i) {
                male.GetTentacle(i).LinkTo(female.GetTentacle(num_tentacles - 1 - i));
            }

            Octopus male_copy(male);
            // Проверяем состояние щупалец копии
            assert(male_copy.GetTentacleCount() == male.GetTentacleCount());
            for (int i = 0; i < male_copy.GetTentacleCount(); ++i) {
                // Каждое щупальце копии размещается по адресу, отличному от адреса оригинального щупальца
                assert(&male_copy.GetTentacle(i) != &male.GetTentacle(i));
                // Каждое щупальце копии прицепляется к тому же щупальцу, что и оригинальное
                assert(male_copy.GetTentacle(i).GetLinkedTentacle() == male.GetTentacle(i).GetLinkedTentacle());
            }
        }
        // Если вы видите эту надпись, то разрушение осьминогов, скорее всего,
        // прошло без неопределённого поведения
        cout << "Everything is OK"s << endl;
    }
}

*/