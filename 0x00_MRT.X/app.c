/* 
 * File:   app.c
 * Author: Mohamed Maher
 * Created on October 5, 2023, 4:04 PM
 */

#include "app.h"
#define F_CPU 1000000UL
#include <util/delay.h>

/* Configuration of LED_1*/
pin_config_t led_1={
    
    .port= PORTB_INDEX,
    .pin=pin0,
    .direction=GPIO_DIRECTION_OUTPUT,
    .logic=GPIO_LOW
            
};

/* Configuration of LED_2*/
pin_config_t led_2={
    
    .port= PORTB_INDEX,
     .pin=pin1,
     .direction=GPIO_DIRECTION_OUTPUT,
     .logic=GPIO_LOW
            
};

/* Configuration of LED_3*/
pin_config_t led_3={
    
    .port= PORTB_INDEX,
    .pin=pin2,
    .direction=GPIO_DIRECTION_OUTPUT,
    .logic=GPIO_LOW
            
};

/* Configuration of LED_4*/
pin_config_t led_4={
    
    .port= PORTB_INDEX,
    .pin=pin3,
    .direction=GPIO_DIRECTION_OUTPUT,
    .logic=GPIO_LOW
            
};

/* Configuration of LED_5*/
pin_config_t led_5={
    
    .port= PORTB_INDEX,
    .pin=pin4,
    .direction=GPIO_DIRECTION_OUTPUT,
    .logic=GPIO_LOW
            
};
   
     
      /* Global Variables:*/
      Std_ReturnType ret =E_NOT_OK;
      direction_t led_1_st;
      logic_t btn1_status;
      uint8 port_direction_status;
      uint8 port_logic_status;
      
      
    /* main function */
    int main(){
    application_intialize();
  
   while(1){
       
       ret=gpio_pin_toggle_logic(&led_1);
       ret=gpio_pin_toggle_logic(&led_2);
       ret=gpio_pin_toggle_logic(&led_3);
       ret=gpio_pin_toggle_logic(&led_4);
       ret=gpio_pin_toggle_logic(&led_5);
     _delay_ms(25);
    }
    return 0;
}
    
    
    /* Intialization Function of the PINs and PORTs */
    
    void application_intialize(void){
    ret=gpio_pin_intialize(&led_1); 
    ret=gpio_pin_intialize(&led_2);
    ret=gpio_pin_intialize(&led_3);
    ret=gpio_pin_intialize(&led_4);
    ret=gpio_pin_intialize(&led_5);
    
    }
    