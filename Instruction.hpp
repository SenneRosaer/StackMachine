//
// Created by sennerosaer on 8/25/19.
//

#ifndef STACKMACHINE_INSTRUCTION_HPP
#define STACKMACHINE_INSTRUCTION_HPP

#include "iostream"
#include "memory"
#include "stack"
#include "Data.hpp"
using namespace std;

namespace sm {

    template<typename T> using data_t = unique_ptr<Data<T>>;

    template<typename T>
    class Instruction {
    protected:
        shared_ptr<stack<data_t<T>>> m_stack;

    public:
        void setStack(const shared_ptr<stack<data_t<T>>> &mStack) {
            m_stack = mStack;
        }

        virtual void execute() = 0;


    };


    template<typename T> using IS = Instruction<T>;



    template<typename T>
    class PushData: public Instruction<T>{
    private:
        data_t<T> m_data;
    public:
        explicit PushData(data_t<T> &&mData) : m_data(move(mData)) {}

        void execute() override {
            IS<T>::m_stack->push(move(m_data));
        }
    };

    template<typename T>
    class AddNumber: public Instruction<T>{
    public:
        void execute() override {
            data_t<T> stack_val_1 = move(IS<T>::m_stack->top());
            IS<T>::m_stack->pop();

            data_t<T> stack_val_2 = move(IS<T>::m_stack->top());
            IS<T>::m_stack->pop();

            T new_val = stack_val_2->getMData() + stack_val_1->getMData();

            IS<T>::m_stack->push(make_unique<Data<T>>(new_val));
        }

    };

    template<typename T>
    class SubNumber: public Instruction<T>{
    public:
        void execute() override {
            data_t<T> stack_val_1 = move(IS<T>::m_stack->top());
            IS<T>::m_stack->pop();

            data_t<T> stack_val_2 = move(IS<T>::m_stack->top());
            IS<T>::m_stack->pop();

            T new_val = stack_val_2->getMData() - stack_val_1->getMData();

            IS<T>::m_stack->push(make_unique<Data<T>>(new_val));
        }

    };

    template<typename T>
    class MulNumber: public Instruction<T>{
    public:
        void execute() override {
            data_t<T> stack_val_1 = move(IS<T>::m_stack->top());
            IS<T>::m_stack->pop();

            data_t<T> stack_val_2 = move(IS<T>::m_stack->top());
            IS<T>::m_stack->pop();

            T new_val = stack_val_2->getMData() * stack_val_1->getMData();

            IS<T>::m_stack->push(make_unique<Data<T>>(new_val));
        }

    };

    template<typename T>
    class DivNumber: public Instruction<T>{
    public:
        void execute() override {
            data_t<T> stack_val_1 = move(IS<T>::m_stack->top());
            IS<T>::m_stack->pop();

            data_t<T> stack_val_2 = move(IS<T>::m_stack->top());
            IS<T>::m_stack->pop();

            T new_val = stack_val_2->getMData() / stack_val_1->getMData();

            IS<T>::m_stack->push(make_unique<Data<T>>(new_val));

        }

    };

    template<typename T>
    class PrintData: public Instruction<T>{
    public:
        void execute() override {
            data_t<T> stack_val = move(IS<T>::m_stack->top());
            cout << stack_val->getMData() << endl;
            IS<T>::m_stack->push(move(stack_val));
        }

    };

    template<typename T>
    class EndProgram: public Instruction<T>{
    public:
        void execute() override {
            while(!IS<T>::m_stack->empty()){
                data_t<T> stack_val = move(IS<T>::m_stack->top());
                IS<T>::m_stack->pop();
                stack_val.reset();
            }
        }

    };


    template<typename T> using instruction_t = std::unique_ptr<Instruction<T>>;
}



#endif //STACKMACHINE_INSTRUCTION_HPP
