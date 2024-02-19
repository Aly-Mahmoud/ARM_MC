
#include "GPIO.h"

typedef struct
{

    U32 GPIOx_MODER;
    U32 GPIOx_OTYPER;
    U32 GPIOx_OSPEEDR;
    U32 GPIOx_PUPDR;
    U32 GPIOx_IDR;
    U32 GPIOx_ODR;
    U32 GPIOx_BSRR;
    U32 GPIOx_LCKR;
    U32 GPIOx_AFRL;
    U32 GPIOx_AFRH;

}GPIOx_Peri_t;

#define GPIOA_u32BASEADDRESS 		 0x4002 0000
#define GPIOA						((GPIOx_Peri_t* )(GPIOA_u32BASEADDRESS))

#define GPIOB_u32BASEADDRESS 		 0x4002 0400
#define GPIOB						((GPIOx_Peri_t* )(GPIOB_u32BASEADDRESS))

#define GPIOC_u32BASEADDRESS 		 0x4002 0800
#define GPIOC						((GPIOx_Peri_t* )(GPIOC_u32BASEADDRESS))

void GPIO_Init (GPIOx_t GPIOx)
{
    GPIOx->MODER 
    GPIOx->OTYPER
    GPIOx->OSPEEDR
    GPIOx->PUPDR

};