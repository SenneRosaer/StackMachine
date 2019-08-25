#include <iostream>
#include "StackMachine.hpp"
using namespace sm;

int main() {
    try {
        const int MAX_SIZE = 10;

        Program<MAX_SIZE,float> prog;
        prog << make_unique<PushData<float>>(make_unique<Data<float>>(3.0))
             << make_unique<PushData<float>>(make_unique<Data<float>>(3.2))
             << make_unique<SubNumber<float>>()
             << make_unique<PushData<float>>(make_unique<Data<float>>(1.7))
             << make_unique<MulNumber<float>>()
             << make_unique<PushData<float>>(make_unique<Data<float>>(2.0))
             << make_unique<AddNumber<float>>()
             << make_unique<PrintData<float>>()
             << make_unique<EndProgram<float>>();

        StackMachine<MAX_SIZE,float> machine;
        machine.run(prog);


    } catch (exception& e){
        cerr << "Machine stopped (error: "<< e.what() << ")" << endl;
    }
}