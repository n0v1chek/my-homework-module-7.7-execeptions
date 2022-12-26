#pragma once
#include <iostream>
#include <exception>
#include <string>

class custom_vector {
private:
    int _size;
    int* data{};
public:
    explicit custom_vector(char) = delete;
    explicit custom_vector(float) = delete;
    explicit custom_vector(double) = delete;

    custom_vector() = default;
    // Create by length
    custom_vector(int length);
    // Element access by [] operator
    int& operator[](int index);
    int at(int index);
    // Create by another custom_vector
    custom_vector(const custom_vector& cv);
    // Resize
    void resize(int new_size);
    // Get size of custom_vector
    int size();
    // Insert by position
    void insert(int numb, int pos);
    // Delete by index
    void delete_at(int index);
    void push_back(int new_numb);
    void push_front(int new_numb);

};

class _out_of_range :public std::exception {
public:
    virtual const char* what() const noexcept override;
};

class bad_length :public std::exception {
public:
    virtual const char* what() const noexcept override;
};

