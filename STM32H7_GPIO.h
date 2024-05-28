
#ifndef SOURCES_ADC_DRIVER_ADC_DRIVER_H_
#define SOURCES_ADC_DRIVER_ADC_DRIVER_H_

/************************************************************************************
 * Include file
 ************************************************************************************/
#include "adc_hal.h"
#include "gpio_driver.h"

typedef enum
{
	ADC_DRV_OK,   	/* Successful ADC driver operation */
	ADC_DRV_ERROR,	/* ADC driver encountered an error */

}ADC_DRV_State;
/* Structure defining the configuration parameters for ADC0 */
typedef struct
{
    gpio_name           PortName;			 /* GPIO port name for ADC pin */
    uint32_t            PinName; 		     /* GPIO pin number for ADC pin */
    Adc0ConverterConfig ConverterConfig;	 /* Configuration for ADC0 converter */

}Adc0_config;

/************************************************************************************
 * Prototypes
 ************************************************************************************/

/*************************************************************************************
  * Function Name:		ADC0_DRV_Init
  * Description:		Initializes the ADC driver for ADC0 based on the provided configuration.
  * @param adc0_config:	Pointer to the configuration structure for ADC0.
  * @return status:     Initialization status
  ************************************************************************************/
ADC_DRV_State ADC0_DRV_Init(Adc0_config * adc0_config);

/*************************************************************************************
  * Function Name:		ADC0_DRV_Read
  * Description:		Reads the ADC conversion result from ADC0.
  * @param adc0_config:	Pointer to the configuration structure for ADC0.
  * @return uint32_t:	ADC conversion result.
  ************************************************************************************/
uint32_t ADC0_DRV_Read(Adc0_config * adc0_config);

#endif /* SOURCES_ADC_DRIVER_ADC_DRIVER_H_ */
