#pragma once
#include <iostream>
#include <exception>
#include <string>

class custom_vector {
private:
    int _size;
    int* data{};
public:
    custom_vector() = default;

    // Create by length
    custom_vector(int length = 1) {
        try {
            if (length > 0) {
                this->data = new int[length] {};
                for (int i = 0; i < length; i++) this->data[i] = 0;
                _size = length;
            }
            else throw std::length_error(std::to_string(length));
        }
        catch (const std::length_error& e) {
            std::cout << "Invalid length of custom_vector. " << typeid(e).name() << std::endl;
        }
        catch (const std::bad_alloc& e) {
            std::cerr << "Allocator error: " << typeid(e).name() << std::endl;
        }
    }

    // Element access by [] operator
    int& operator[](int index) {
        try {
            if (index < 0 || index > _size - 1) throw std::length_error(std::to_string(index));
            else return this->data[index];
        }
        catch (const std::length_error& e) {
            std::cerr << "Wrong index! " << typeid(e).name() << std::endl;
        }
    }

    // Create by another custom_vector
    custom_vector(const custom_vector& cv) {
        try {
            _size = cv._size;
            this->data = new int[_size] {};
            for (int i = 0; i < _size; i++) this->data[i] = cv.data[i];
        }
        catch (const std::bad_alloc& e) {
            std::cerr << "Allocator error: " << typeid(e).name() << std::endl;
        }
    }

    // Resize
    void resize(int new_size) {
        try {
            int* new_data = new int[new_size];
            for (int i = 0; i < new_size; i++) new_data[i] = this->data[i];
            _size = new_size;
            delete[] this->data;
            this->data = new_data;
        }
        catch (const std::bad_alloc& e) {
            std::cerr << "Allocator error: " << typeid(e).name() << std::endl;
        }
    }

    // Get size of custom_vector
    int size() { return _size; }

    // Insert by position
    void insert(int numb, int pos) {
        try {
            if (pos > 0 && pos <= _size) {
                _size++;
                int* new_data = new int[_size];
                for (int i = 0; i < _size; i++) {
                    if (i == pos - 1) new_data[i] = numb;
                    else {
                        if (i < pos) new_data[i] = this->data[i];
                        else new_data[i] = this->data[i - 1];
                    }
                }
                delete[] this->data;
                this->data = new_data;
            }
            else throw std::length_error(std::to_string(pos));
        }
        catch (const std::bad_alloc& e) {
            std::cerr << "Allocator error: " << typeid(e).name() << std::endl;
        }
        catch (const std::length_error& e) {
            std::cerr << "Wrong index! " << typeid(e).name() << std::endl;
        }
    }

    // Delete by index
    void delete_at(int index) {
        try {
            if (index > 0 && index <= _size) {
                _size--;
                int* new_data = new int[_size];
                for (int i = 0; i < _size + 1; i++) {
                    if (i == index - 1) continue;
                    else
                        if (i < index) new_data[i] = this->data[i];
                        else new_data[i - 1] = this->data[i];
                }
                delete[] this->data;
                this->data = new_data;
            }
            else throw std::length_error(std::to_string(index));
        }
        catch (const std::bad_alloc& e) {
            std::cerr << "Allocator error: " << typeid(e).name() << std::endl;
        }
        catch (const std::length_error& e) {
            std::cerr << "Wrong index! " << typeid(e).name() << std::endl;
        }
    }

    void push_back(int new_numb) {
        try {
            int* new_data = new int[_size + 1];
            for (int i = 0; i < _size; i++) new_data[i] = this->data[i];
            new_data[_size] = new_numb;
            _size++;
            delete[] this->data;
            this->data = new_data;
        }
        catch (const std::bad_alloc& e) {
            std::cerr << "Allocator error: " << typeid(e).name() << std::endl;
        }
    }


    void push_front(int new_numb) {
        try {
            int* new_data = new int[_size + 1];
            new_data[0] = new_numb;
            _size++;
            for (int i = 1; i < _size; i++) new_data[i] = this->data[i - 1];
            delete[] this->data;
            this->data = new_data;
        }
        catch (const std::bad_alloc& e) {
            std::cerr << "Allocator error: " << typeid(e).name() << std::endl;
        }
    }

};
