#include "../headers/container.hpp"

Container::Container() {
    len = 0;
}

Container::~Container() {
    Clear();
}

void Container::Clear() {
    for (int32_t i = 0; i < len; i++) {
        delete storage[i];
        storage[i] = nullptr;
    }
    len = 0;
}

void Container::In(FILE *inputFile) {
    while ((storage[len] = CommonSquare::StaticIn(inputFile)) != nullptr) {
        len++;
    }
    fclose(inputFile);
}

void Container::InRnd(size_t size) {
    while (len < size) {
        if ((storage[len] = CommonSquare::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

void Container::Out(FILE *outputFile) {
    for (size_t i = 0; i < len; i++) {
        storage[i]->out(outputFile);
    }
}


void Container::swap(size_t idx1, size_t idx2) {
    CommonSquare* temp = storage[idx1];
    storage[idx1] = storage[idx2];
    storage[idx2] = temp;
}


void Container::shakeSort() {
    size_t i, j, k, m = len;
    for(i = 0; i < m;) {
        for(j = i + 1; j < m; j++) {
            if(storage[j]->average() < storage[j - 1]->average())
                swap(j, j - 1);
        }
        m--;
        for(k = m - 1; k > i; k--) {
            if(storage[k]->average() < storage[k - 1]->average())
                swap(k, k - 1);
        }
        i++;
    }

}