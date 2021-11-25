

#include "PIT.h"

Timer_cfg_s PIT_Configuration0  =
{ 
	PIT_TIMER,// useful when you try to impliment other timers 
	PIT_MODE,// useful when you try to impliment other timers 
	PIT_INTERRUPT_MODE,//INTERRUPT OR POOLING 
	TIMER_PRESCALER_64,/*it will not start untill we call timer start function*/
    1,
    25,
    //Function called when interrupt happens 
    //or time is reached 
    pit_hook
};

/************************************************************************/
/*		         TIMER FUNCTIONS' PROTOTYPES		        */
/************************************************************************/



/**
 * Input: Pointer to a structure contains the information needed to initialize the timer.
 * Output:
 * In/Out:
 * Return: The error status of the function.
 * Description: Initiates the module.
 *
 */
ERROR_STATUS Timer_Init(Timer_cfg_s* Timer_cfg)
{ERROR_STATUS ret_error = E_OK;
/*Description
Purpose
Interface for configuration the Periodic Interval Timer (PIT) peripheral.

Usage

    Initialize the PIT with the desired period using PIT_Init(). Alternatively, the Periodic Interval Value (PIV) can be configured manually using PIT_SetPIV().
    Start the PIT counting using PIT_Enable().
    Enable & disable the PIT interrupt using PIT_EnableIT() and PIT_DisableIT().
    Retrieve the current status of the PIT using PIT_GetStatus().
    To get the current value of the internal counter and the number of ticks that have occurred, use either PIT_GetPIVR() or PIT_GetPIIR() depending on whether you want the values to be cleared or not.

*/

    switch (Timer_cfg->Timer_Polling_Or_Interrupt)
    {
    case PIT_INTERRUPT_MODE:
    
            PIT_Init(Timer_cfg->period,Timer_cfg->pit_frequency);
            AIC_ConfigureIT(AT91C_ALL_INT, 0, pit_hook);
            AIC_EnableIT(AT91C_ALL_INT);
            PIT_EnableIT();
        break;
    case PIT_POLLING_MODE:
           PIT_Init(Timer_cfg->period,Timer_cfg->pit_frequency);
           PIT_DisableIT();
        break;

    default:
    ret_error = E_NOK;
        break;
    }
    

return ret_error;

}
void pit_hook(void)
{




}
/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to be started.
 *	Timer_Count: The start value of the timer.
 * Output:
 * In/Out:
 * Return: The error status of the function.
 * Description: This function strats the needed timer.
 *
 */
ERROR_STATUS Timer_Start(Timer_cfg_s* Timer_cfg)
{
ERROR_STATUS ret_error = E_OK;
switch (Timer_cfg ->Timer_CH_NO)
{
case PIT_TIMER:
     PIT_Enable();
     PIT_SetPIV(Timer_cfg->period);
    break;
default:
ret_error =  E_NOK;
    break;
}
return ret_error;
}

/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to be stopped.
 * Output:
 * In/Out:
 * Return: The error status of the function.
 * Description: This function stops the needed timer.
 *
 */
ERROR_STATUS Timer_Stop(uint8_t Timer_CH_NO){
ERROR_STATUS ret_error = E_OK;
switch (Timer_CH_NO)
{
case PIT_TIMER:
    AT91C_BASE_PITC->PITC_PIMR &= ~(AT91C_PITC_PITEN);

    break;

default:
    ret_error = E_NOK;
    break;
}


return ret_error;
}

/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to get its status.
 * Output:
 * 	Data: A variable of type bool returns if the flag of the timer is raised or not.
 * In/Out:
 * Return: The error status of the function.
 * Description: This function is used to return if the flag of the timer is raised or not.
 *
 */
ERROR_STATUS Timer_GetStatus(uint8_t Timer_CH_NO, uint32_t* status)
{

ERROR_STATUS ret_error = E_OK;
switch (Timer_CH_NO)
{
case PIT_TIMER:
*status = PIT_GetStatus();

    break;

default:
    ret_error = E_NOK;
    break;
}


return ret_error;
}

/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to get its value.
 * Output:
 * 	Data: This is the output variable of the function which holds the value of the timer.
 * In/Out:
 * Return: The error status of the function.
 * Description: This function is used to return the value of the timer.
 *
 */
ERROR_STATUS Timer_GetValue(uint8_t Timer_CH_NO, uint32_t* Data)
{
ERROR_STATUS ret_error = E_OK;
switch (Timer_CH_NO)
{
case PIT_TIMER:
*Data = PIT_GetPIIR();

    break;

default:
    ret_error = E_NOK;
    break;
}
return ret_error;
}


/**
 * Input:
 * 	Timer_CH_NO: The channel number of the timer needed to get its value.
 * Output:
 * 	Data: This is the output variable of the function which holds the value of the timer.
 * In/Out:
 * Return: The error status of the function.
 * Description: This function is used to return the mode of the timer.
 *
 */
ERROR_STATUS Timer_MODE(uint8_t Timer_CH_NO, uint32_t* mode)
{
ERROR_STATUS ret_error = E_OK;
switch (Timer_CH_NO)
{
case PIT_TIMER:
*mode = PIT_GetMode();

    break;

default:
    ret_error = E_NOK;
    break;
}

    return ret_error;
}








