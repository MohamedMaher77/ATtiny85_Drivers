/* 
 * File:   hal_gpio.h
 * Author: HP
 *
 * Created on October 5, 2023, 6:48 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* section: includes */

#include"avr/io.h"
#include"../mcal_std_types.h"
#include"../hal_gpio_cfg.h"



/* section: macro declaration */
#define BIT_MASK     (uint8)1
#define PORT_PIN_MAX_NUMBER   6
#define PORT_MAX_NUMBER   1
#define GPIO_PORT_PIN_CONFIGURATIONS   (CONFIG_ENABLE)
#define GPIO_PORT_CONFIGURATIONS        (CONFIG_ENABLE)


/* section: macro function declarations */
#define HWREG8 (_X)                   (*((volatile uint8*)(_x)))

#define SET_BIT(REG, BIT_POSN)        (REG |= (BIT_MASK << BIT_POSN))
#define CLEAR_BIT(REG, BIT_POSN)      (REG &= ~(BIT_MASK << BIT_POSN))
#define TOGGLE_BIT(REG, BIT_POSN)     (REG ^= (BIT_MASK << BIT_POSN))
#define READ_BIT(REG,BIT_POSN)        ((REG>>BIT_POSN) & BIT_MASK)


/* section: data type declarations */
typedef enum{
    GPIO_LOW=0,
    GPIO_HIGH
    
}logic_t;

typedef enum{
    GPIO_DIRECTION_INPUT=0,
    GPIO_DIRECTION_OUTPUT
    
}direction_t;


typedef enum{
   pin0=0,
   pin1,
   pin2,
   pin3,
   pin4
  
}pin_index__t;

typedef enum{
    PORTB_INDEX=0
}port_index_t;

typedef struct{
    uint8 port :1;      /* @ref port_index_t*/
    uint8 pin :3;       /* @ref pin_index_t*/
    uint8 direction :1; /* @ref direction_index_t*/
    uint8 logic :1;     /* @ref logic_t */
}pin_config_t;

/*section: function declarations */
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config);
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status);
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config,logic_t logic);
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config,logic_t *logic);
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config);
Std_ReturnType gpio_pin_intialize(const pin_config_t *_pin_config);

Std_ReturnType gpio_port_direction_intialize(port_index_t port, uint8 direction);
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status);
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic);
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic);
Std_ReturnType gpio_port_toggle_logic(port_index_t port);






#endif	/* HAL_GPIO_H */




