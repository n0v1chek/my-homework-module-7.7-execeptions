#include "custom_vector.h"


custom_vector::custom_vector(int length = 1) {
    try {
        if (length > 0) {
            this->data = new int[length] {};
            for (int i = 0; i < length; i++) this->data[i] = 0;
            _size = length;
        }
        else throw bad_length();
    }
    catch (const bad_length& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Allocator error: " << typeid(e).name() << std::endl;
    }
    catch (char) {
        std::cout << "char!" << std::endl;
    }
}

int& custom_vector::operator[](int index) {
    try {
        if (index < 0 || index > _size - 1) throw _out_of_range();
        else return this->data[index];
    }
    catch (const _out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
}

int custom_vector::at(int index) {
    try {
        if (index < 0 || index > _size - 1) throw _out_of_range();
        else return this->data[index];
    }
    catch (const _out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
}

custom_vector::custom_vector(const custom_vector& cv) {
    try {
        _size = cv._size;
        this->data = new int[_size] {};
        for (int i = 0; i < _size; i++) this->data[i] = cv.data[i];
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Allocator error: " << typeid(e).name() << std::endl;
    }
}

void custom_vector::resize(int new_size) {
    try {
        if (new_size > 0) {
            int* new_data = new int[new_size];
            for (int i = 0; i < new_size; i++) new_data[i] = this->data[i];
            _size = new_size;
            delete[] this->data;
            this->data = new_data;
        }
        else throw bad_length();
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Allocator error: " << typeid(e).name() << std::endl;
    }
    catch (const bad_length& e) {
        std::cout << e.what() << std::endl;
    }
}

int custom_vector::size() { return _size; }

void custom_vector::insert(int numb, int pos) {
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
        else throw _out_of_range();
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Allocator error: " << typeid(e).name() << std::endl;
    }
    catch (const _out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
}

void custom_vector::delete_at(int index) {
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
        else throw _out_of_range();
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Allocator error: " << typeid(e).name() << std::endl;
    }
    catch (const _out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
}

void custom_vector::push_back(int new_numb) {
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

void custom_vector::push_front(int new_numb) {
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

// -------------    Exceptions    -------------//

const char* _out_of_range::what() const noexcept {
    return "Index error!";
}

const char* bad_length::what() const noexcept {
    return "Length error!";
}