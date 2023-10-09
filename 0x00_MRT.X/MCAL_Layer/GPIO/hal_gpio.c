/* 
 * File:   hal_gpio.c
 * Author: HP
 *
 * Created on October 5, 2023, 3:25 AM
 */

#include"hal_gpio.h"

/**
 * 
 * @param _pin_config
 * @return status of the function
 * E_OK: done successfully
 * E_NOT_OK: issue
 */
#if GPIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_pin_direction_intialize(const pin_config_t *_pin_config){
    Std_ReturnType ret=E_OK;
    if(NULL==  _pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER -1){
        ret=E_NOT_OK;
    }
    else{
    switch(_pin_config->direction ){
        case GPIO_DIRECTION_OUTPUT :
            SET_BIT(DDRB, _pin_config->pin);
            break;
        case GPIO_DIRECTION_INPUT :
             CLEAR_BIT(DDRB, _pin_config->pin);
            break;
            
        default: ret= E_NOT_OK ;
    }
    }

    return ret;
}
#endif

/**
 * 
 * @param _pin_config
 * @param direction_status
 * @return status of the function
 * E_OK: done successfully
 * E_NOT_OK: issue
 */
#if GPIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status){
Std_ReturnType ret=E_OK;
if(NULL==_pin_config || NULL== direction_status || _pin_config->pin > PORT_PIN_MAX_NUMBER -1){
        ret=E_NOT_OK;
    }
    else{
     *direction_status= READ_BIT(DDRB, _pin_config->pin);
    
     
    }
    return ret;
}
#endif

/**
 * 
 * @param _pin_config
 * @param logic
 * @return status of the function
 * E_OK: done successfully
 * E_NOT_OK: issue
 */
#if GPIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_pin_write_logic(const pin_config_t *_pin_config,logic_t logic){
Std_ReturnType ret=E_OK;
if(NULL==_pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER -1){
        ret=E_NOT_OK;
    }
    else{
    switch(logic){
        case GPIO_LOW:
            CLEAR_BIT(PORTB, _pin_config->pin);
            break;
        case GPIO_HIGH:
            SET_BIT(PORTB, _pin_config->pin);
            break;
        default: ret= E_NOT_OK; ;
    
    
    }
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @param logic
 * @return status of the function
 * E_OK: done successfully
 * E_NOT_OK: issue
 */
#if GPIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_pin_read_logic(const pin_config_t *_pin_config,logic_t *logic){
Std_ReturnType ret=E_OK;
if(NULL==_pin_config|| NULL==logic || _pin_config->pin > PORT_PIN_MAX_NUMBER -1){
        ret=E_NOT_OK;
    }
    else{
     *logic= READ_BIT(PINB, _pin_config->pin);
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @return status of the function
 * E_OK: done successfully
 * E_NOT_OK: issue
 */
#if GPIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_pin_toggle_logic(const pin_config_t *_pin_config){
Std_ReturnType ret=E_OK;
if(NULL==_pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER -1){
        ret=E_NOT_OK;
    }
    else{
    TOGGLE_BIT(PORTB, _pin_config->pin);
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config
 * @return status of the function
 * E_OK: done successfully
 * E_NOT_OK: issue
 */
#if GPIO_PORT_PIN_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_pin_intialize(const pin_config_t *_pin_config){
    Std_ReturnType ret=E_OK;
    if(NULL==_pin_config || _pin_config->pin > PORT_PIN_MAX_NUMBER -1){
        ret=E_NOT_OK;
    }
    else{
     ret=gpio_pin_direction_intialize(_pin_config);
     ret=gpio_pin_write_logic(_pin_config, _pin_config->logic);
    }

    return ret;
}
#endif
/**
 * 
 * @param port
 * @param direction
 * @return status of the function
 * E_OK: done successfully
 * E_NOT_OK: issue
 */
#if GPIO_PORT_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_port_direction_intialize(port_index_t port, uint8 direction){
Std_ReturnType ret=E_OK;
if(port >PORT_MAX_NUMBER -1){
    ret=E_NOT_OK;
}
else{
 DDRB= direction;
}
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param direction_status
 * @return staus of the function
 * E_OK: done successfully
 * E_NOT_OK: issue
 */
#if GPIO_PORT_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_port_get_direction_status(port_index_t port, uint8 *direction_status){
Std_ReturnType ret=E_OK;
if(NULL==direction_status || port >PORT_MAX_NUMBER -1){
        ret=E_NOT_OK;
    }
    else{
    *direction_status=DDRB;
    
    }
    return ret;
}
#endif

/**
 * 
 * @param port
 * @param logic
 * @return status of the function
 * E_OK: done successfully
 * E_NOT_OK: issue
 */
#if GPIO_PORT_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic){
Std_ReturnType ret=E_OK;
if( port >PORT_MAX_NUMBER -1){
        ret=E_NOT_OK;
    }
    else{
    PORTB=logic;
    
    }
    return ret;
}
#endif

/**
 * 
 * @param port
 * @param logic
 * @return status of the function
 * E_OK: done successfully
 * E_NOT_OK: issue
 */
#if GPIO_PORT_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic){
Std_ReturnType ret=E_OK;
if(NULL==logic ||  port >PORT_MAX_NUMBER -1){
        ret=E_NOT_OK;
    }
    else{
    *logic=PINB;
    }
    return ret;
}
#endif

/**
 * 
 * @param port
 * @return status of the function
 * E_OK: done successfully
 * E_NOT_OK: issue
 */
#if GPIO_PORT_CONFIGURATIONS==CONFIG_ENABLE
Std_ReturnType gpio_port_toggle_logic(port_index_t port){
Std_ReturnType ret=E_OK;
if( port >PORT_MAX_NUMBER -1){
        ret=E_NOT_OK;
    }
    else{
    PORTB= PORTB^0xFF;
    }
    return ret;
}
#endif

