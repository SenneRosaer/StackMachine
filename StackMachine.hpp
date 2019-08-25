//
// Created by sennerosaer on 8/25/19.
//

#ifndef STACKMACHINE_STACKMACHINE_HPP
#define STACKMACHINE_STACKMACHINE_HPP

#include "iostream"
#include "memory"
#include "stack"
#include "Program.hpp"

using namespace std;

namespace sm {

    template<size_t MAX, typename T>
    class StackMachine{
    private:
        shared_ptr<stack<data_t<T>>> m_stack;
    public:
        void run( Program<MAX,T> &prog){
            m_stack = make_shared<stack<data_t<T>>>();
            prog.setStack(m_stack);
            prog.run();
        };
    };





}





#endif //STACKMACHINE_STACKMACHINE_HPP
