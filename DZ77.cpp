#include "custom_vector.h"


int main()
{
    custom_vector vec1(5);
    for (int i = 0; i < vec1.size(); i++) std::cout << vec1[i] << " ";
    std::cout << std::endl;
    vec1.push_back(99);
    for (int i = 0; i < vec1.size(); i++) std::cout << vec1[i] << " ";
    std::cout << std::endl;
    vec1.push_front(99);
    vec1.push_front(98);
    vec1.insert(999, -1);
    for (int i = 0; i < vec1.size(); i++) std::cout << vec1[i] << " ";
    std::cout << std::endl;
    vec1.delete_at(1);
    for (int i = 0; i < vec1.size(); i++) std::cout << vec1[i] << " ";
    std::cout << std::endl;

}