//
// Created by sennerosaer on 8/25/19.
//

#ifndef STACKMACHINE_PROGRAM_HPP
#define STACKMACHINE_PROGRAM_HPP

#include "iostream"
#include "memory"
#include "Instruction.hpp"
#include "vector"
using namespace std;

namespace sm {

    template<size_t MAX, typename T>
    class Program {
    private:
        vector<instruction_t<T>> m_instructions = {};
        unsigned int m_instr_ptr = 0;
        shared_ptr<stack<data_t<T>>> m_stack;

    public:
        Program &operator<<(instruction_t<T>&& intr){
            if(m_instructions.size() < MAX) {
                m_instructions.push_back(move(intr));
            } else {
                throw length_error("Too many instructions added");
            }
            return *this;
        }

        instruction_t<T> &operator[](unsigned int instr_ptr){
            return m_instructions[instr_ptr];
        }

        void setStack(const shared_ptr<stack<data_t<T>>> &mStack) {
            m_stack = mStack;
        }

        void run(){
            for (m_instr_ptr; m_instr_ptr < m_instructions.size() ; m_instr_ptr++) {
                m_instructions[m_instr_ptr]->setStack(m_stack);
                m_instructions[m_instr_ptr]->execute();
            }
        }
    };


}
#endif //STACKMACHINE_PROGRAM_HPP
