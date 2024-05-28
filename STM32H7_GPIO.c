/*
 * gpio_hal.c
 *
 *  Created on: Dec 9, 2023
 *      Author: Le Nguyen Van Duong
 */
#include  "gpio_hal.h"

/************************************************************************************
 * Static Function
 ************************************************************************************/
static GPIO_Type * Check_Gpio(Hal_Gpio Gpio);

/*************************************************************************************
  * Function Name:		Check_Gpio
  * Description:		Corresponding GPIO_Type pointer for a given HAL_GPIO identifier.
  * @param  Gpio: 		Identifier for the HAL_GPIO.
  * @return GPIO_Type*: Pointer to the corresponding GPIO_Type structure.
  ************************************************************************************/
static GPIO_Type * Check_Gpio(Hal_Gpio Gpio)
{
    GPIO_Type * Type;
    /* Define an array of PORT_Type pointers */
    GPIO_Type * Gpio_Val[] = GPIO_BASE_PTRS;

    int index = 0;

    if (Gpio >= HAL_GPIOA && Gpio <= HAL_GPIOE)
    {
        /* Calculate the index corresponding to the specified HAL_PORT */
        index = Gpio - HAL_GPIOA;

        /* Get the PORT_Type pointer from the array */
        Type = Gpio_Val[index];
    }
    else
    {
        /* Do nothing */
    }
    return Type;

}

/************************************************************************************
 * Function
 ************************************************************************************/
void GPIO_HAL_Output(Hal_Gpio Gpio, uint8_t Pin, Pin_Logic Logic)
{

    if (Logic == GpioDigitalHigh)
    {
        /* Set the pin to a high logic level */
        GPIO_PDOR_REG(Check_Gpio(Gpio)) |= 1 << Pin;

    }
    else if (Logic == GpioDigitalLow)
    {
        /* Set the pin to a low logic level */
        GPIO_PDOR_REG(Check_Gpio(Gpio)) &= ~1 << Pin;
    }
}

void GPIO_HAL_Clear_Output(Hal_Gpio Gpio, uint8_t Pin)
{
    /*  Clear the output (set the pin to a high logic level) */
    GPIO_PCOR_REG(Check_Gpio(Gpio)) |= 1 << Pin;
}

void GPIO_HAL_Set_Output(Hal_Gpio Gpio, uint8_t Pin)
{
    /* Set the output (set the pin to a low logic level) */
    GPIO_PSOR_REG(Check_Gpio(Gpio))|= (1 << Pin);
}

void GPIO_HAL_Toggle_Output(Hal_Gpio Gpio, uint8_t Pin)
{
    /* Toggle the logic level of the specified pin */
    GPIO_PTOR_REG(Check_Gpio(Gpio)) |= 1 << Pin;
}

void GPIO_HAL_DataDirection(Hal_Gpio Gpio, uint8_t Pin, Pin_Direct Direct)
{

    if (Direct == GpioDigitalOutput)
    {
        /* Configure the pin as an output */
        GPIO_PDDR_REG(Check_Gpio(Gpio)) |= 1 << Pin;

    }
    else if (Direct == GpioDigitalInput)
    {
        /* Configure the pin as an input */
        GPIO_PDDR_REG(Check_Gpio(Gpio)) &= ~1 << Pin;
    }

}

uint32_t GPIO_HAL_Set_Input(Hal_Gpio Gpio, uint8_t Pin)
{
    /* Read and return the logic level of the specified input pin */
    return GPIO_PDIR_REG(Check_Gpio(Gpio)) >> Pin & 0x01;

}

/* End of file */
