#pragma once
#include "pros/adi.hpp"
#include "Constants.hpp"

using namespace pros;
using namespace Constants;
class StakeHolder{
    private:
    adi::DigitalOut Holder = adi::DigitalOut(StakeHolder_p, false);
    bool Holder_out = false;
    public:
    StakeHolder(){}
    void open(){Holder_out=!Holder_out; Holder.set_value(Holder_out);}
};