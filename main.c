#include "msp.h"


/**
 * main.c
 */
#define LED     (1 << 0) //Define the bit for the LED

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	//Set all PORT1 as LOW
	P1OUT = 0x00;

	//Set all PORT1 as OUTPUT
	P1DIR |=  0xFF;

	//Set P1.1 and P1.4 as INPUT
	P1DIR |= 0x12;

	//Activate the pull-up or pull-down resistor on P1.1 and P1.4
    P1REN |=  0x12;

    //Activate pull-up resistor on P1.1 and P1.4
    P1OUT |= 0x12;


    while(1) {
        //Test if P1IN is pressed
        int S1_pressed = !(P1IN & 0x02);


        if (S1_pressed){
            P1OUT |= LED; //On
        }
        else{
            P1OUT &=  ~LED;  // Off
        }
    }
}
