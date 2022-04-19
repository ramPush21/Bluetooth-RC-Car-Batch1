#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HMOT_interface.h"
#include "HBLTH_interface.h"

hblthClass_t obj_blthComm;
hmotClass_t  obj_mot1(MOT_CHANNEL_1);
hmotClass_t  obj_mot2(MOT_CHANNEL_2);

int main(void)
{
    u8_t x;

    while(1)
    {
        obj_blthComm.getData(&x);

        if(x == 'F')
        {
            obj_mot1.updateMotor(255, MOT_MAIN_DIR);
            obj_mot2.updateMotor(128, MOT_OTHER_DIR);
            x = 0;
        }
        else if(x == 'B')
        {
            obj_mot1.updateMotor(0, MOT_STOP);
            obj_mot2.updateMotor(0, MOT_STOP);
            x=0;
        }   
    }

    return 0;
}