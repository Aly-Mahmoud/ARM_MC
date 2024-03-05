#include "LED.h"
#include "GPIO.h"

extern const LED_strLEDConfig_t LED_arrOfStrLEDs[NUM_OF_LEDS];

GPIO_Error_t LED_Init (void)
{
	GPIO_Error_t LOC_Status = GPIO_NOK;
	GPIO_Pin_t Led;

	Pin_Mode  = GPIO_MODE_OP_PP;
	Pin_Speed = GPIO_SPEED_HIGH;

	for ( U8 idx = 0 ; idx < NUM_OF_LEDS ; idx++ )
	{
		Led.pin    = LED_arrOfStrLEDs[idx].pin;
		Led.Port   = LED_arrOfStrLEDs[idx].Port;
		LOC_Status = GPIO_Init(&LED_arrOfStrLEDs);
		if (LOC_Status == GPIO_OK)
		{
			LOC_Status = GPIO_Set_PinValue(LED_arrOfStrLEDs[LED_NAME].Port , LED_arrOfStrLEDs[LED_NAME].Pin  , LED_arrOfStrLEDs[LED_NAME].Connection ^ LED_arrOfStrLEDs[LED_NAME].Init_Value);
		}
	}
	return LOC_Status;
}

GPIO_Error_t LED_SetStatus ( LEDs_t LED_NAME , U32 LED_STATUS )
{
	GPIO_Error_t LOC_Status = GPIO_NOK;

	LOC_Status = GPIO_Set_PinValue(LED_arrOfStrLEDs[LED_NAME].Port , LED_arrOfStrLEDs[LED_NAME].Pin  , LED_arrOfStrLEDs[LED_NAME].Connection ^ LED_STATUS);

	return LOC_Status
};