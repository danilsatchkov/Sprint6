#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

/*
using namespace std;

// ������ �����
enum class CatBreed {
    Bengal,
    Balinese,
    Persian,
    Siamese,
    Siberian,
    Sphynx, SuccessSuccess
};

// ���
enum class Gender {
    Male,
    Female,
};

struct Cat {
    string name;
    Gender gender;
    CatBreed breed;
    int age;
};

string CatBreedToString(CatBreed breed) {
    switch (breed) {
    case CatBreed::Bengal:
        return "Bengal"s;
    case CatBreed::Balinese:
        return "Balinese"s;
    case CatBreed::Persian:
        return "Persian"s;
    case CatBreed::Siamese:
        return "Siamese"s;
    case CatBreed::Siberian:
        return "Siberian";
    case CatBreed::Sphynx:
        return "Sphynx"s;
    default:
        throw invalid_argument("Invalid cat breed"s);
    }
}

ostream& operator<<(ostream& out, CatBreed breed) {
    out << CatBreedToString(breed);
    return out;
}

ostream& operator<<(ostream& out, Gender gender) {
    out << (gender == Gender::Male ? "male"s : "female"s);
    return out;
}

ostream& operator<<(ostream& out, const Cat& cat) {
    out << '{' << cat.name << ", "s << cat.gender;
    out << ", breed: "s << cat.breed << ", age:"s << cat.age << '}';
    return out;
}

// ���������� ������ ���������� �� �������� ������� cats, ��������������� � ��������������
// ����������� comp. ���������� comp - �������, ����������� ��� ��������� ���� const Cat&
// � ������������ true, ���� �������� �����������, � false � ���� ������
template <typename Comparator>
vector<const Cat*> GetSortedCats(const vector<Cat>& cats, const Comparator& comp) {
    vector<const Cat*> sorted_cat_pointers;
    if (cats.empty()) return sorted_cat_pointers;

    for (const auto& c : cats) {

        sorted_cat_pointers.push_back(&c);

    }

    sort(sorted_cat_pointers.begin(), sorted_cat_pointers.end(), [comp](const Cat* lhs, const Cat* rhs) {
        return comp(*lhs, *rhs);
    });

    return sorted_cat_pointers;
    /*
    �������� ���� ������� ��������������. ���������:
    1) ��������� � ������ sorted_cat_pointers ������ �������� �� ������� cats.
    2) ������������ ������ sorted_cat_pointers � ������� ����������� ����������� comp.
       ��� ��� comp ���������� ������ �� �������, � ������������� ����� ���������,
       ��������� � sort ������ �������, ����������� ��������� � ������������ �������
       ��� ������ ����������� comp:
       [comp](const Cat* lhs, const Cat* rhs) {
           return comp(*lhs, *rhs);
       }
    

}

// ������� � ����� out �������� ��������, �� ������� ��������� ��������� ������� cat_pointers.
// ������ ������ ��������� vector<const Cat*>:
// {{Tom, male, breed: Bengal, age:2}, {Charlie, male, breed: Balinese, age:7}}
void PrintCatPointerValues(const vector<const Cat*>& cat_pointers, ostream& out) {
    // �������� ������� ��������������
    out << "{";
    string divide = ", ";
    for (auto c : cat_pointers) {
        if (c == cat_pointers.back())  divide = "";
        out << *c << divide;
        
    }
    out << "}";

}

int main() {
    const vector<Cat> cats = {
        {"Tom"s, Gender::Male, CatBreed::Bengal, 2},
        {"Leo"s, Gender::Male, CatBreed::Siberian, 3},
        {"Luna"s, Gender::Female, CatBreed::Siamese, 1},
        {"Charlie"s, Gender::Male, CatBreed::Balinese, 7},
        {"Ginger"s, Gender::Female, CatBreed::Sphynx, 5},
        {"Tom"s, Gender::Male, CatBreed::Siamese, 2},
    };

    {
        auto sorted_cats = GetSortedCats(cats, [](const Cat& lhs, const Cat& rhs) {
            return tie(lhs.breed, lhs.name) < tie(rhs.breed, rhs.name);
        });

        cout << "Cats sorted by breed and name:"s << endl;
        PrintCatPointerValues(sorted_cats, cout);
        cout << endl;
    }

    {
        auto sorted_cats = GetSortedCats(cats, [](const Cat& lhs, const Cat& rhs) {
            return tie(lhs.gender, lhs.breed) < tie(rhs.gender, rhs.breed);
        });

        cout << "Cats sorted by gender and breed:"s << endl;
        PrintCatPointerValues(sorted_cats, cout);
        cout << endl;
    }
}

*/