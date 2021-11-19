#include "Button.h"
#ifdef PINS_SWITCHES
static const Pin pins_switches[] = {PINS_SWITCHES};
static const unsigned int numswitches = PIO_LISTSIZE(pins_switches);
#endif

/*Function is used to intialize pushbutton 

//use this with unsigned char Button_init(unsigned int Swtich)
// Push button #1 index.
#define PUSHBUTTON_4_8   0
// Push button #2 index.
#define PUSHBUTTON_3_7   1
// Push button #3 index.
#define PUSHBUTTON_2_6   2
// Push button #4 index.
#define PUSHBUTTON_1_5   3
*/
unsigned char Button_init(unsigned int Swtich){
    /*Conigure Swtich */
return( PIO_Configure(&pins_switches[Swtich],1));

}
/**
 * @brief function is used to intialize all pushbuttons 
 * 
 * @param size number of pushbutons (4)
 * @return unsigned char 
 */
unsigned char Button_all_init(unsigned int size){
return PIO_Configure(pins_switches,size);
}