//
// Created by sennerosaer on 8/25/19.
//

#ifndef STACKMACHINE_DATA_HPP
#define STACKMACHINE_DATA_HPP

#include "iostream"
#include "memory"

using namespace std;

namespace sm {
    template<typename T>
    class Data {
    private:
        const T m_data;
    public:
        explicit Data(const T mData) : m_data(mData) {}

        T getMData() const {
            return m_data;
        }
    };


}

#endif //STACKMACHINE_DATA_HPP
