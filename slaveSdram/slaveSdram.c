/* 
 * "Small Hello World" example. 
 * 
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example 
 * designs. It requires a STDOUT  device in your system's hardware. 
 *
 * The purpose of this example is to demonstrate the smallest possible Hello 
 * World application, using the Nios II HAL library.  The memory footprint
 * of this hosted application is ~332 bytes by default using the standard 
 * reference design.  For a more fully featured Hello World application
 * example, see the example titled "Hello World".
 *
 * The memory footprint of this example has been reduced by making the
 * following changes to the normal "Hello World" example.
 * Check in the Nios II Software Developers Manual for a more complete 
 * description.
 * 
 * In the SW Application project (small_hello_world):
 *
 *  - In the C/C++ Build page
 * 
 *    - Set the Optimization Level to -Os
 * 
 * In System Library project (small_hello_world_syslib):
 *  - In the C/C++ Build page
 * 
 *    - Set the Optimization Level to -Os
 * 
 *    - Define the preprocessor option ALT_NO_INSTRUCTION_EMULATION 
 *      This removes software exception handling, which means that you cannot 
 *      run code compiled for Nios II cpu with a hardware multiplier on a core 
 *      without a the multiply unit. Check the Nios II Software Developers 
 *      Manual for more details.
 *
 *  - In the System Library page:
 *    - Set Periodic system timer and Timestamp timer to none
 *      This prevents the automatic inclusion of the timer driver.
 *
 *    - Set Max file descriptors to 4
 *      This reduces the size of the file handle pool.
 *
 *    - Check Main function does not exit
 *    - Uncheck Clean exit (flush buffers)
 *      This removes the unneeded call to exit when main returns, since it
 *      won't.
 *
 *    - Check Don't use C++
 *      This builds without the C++ support code.
 *
 *    - Check Small C library
 *      This uses a reduced functionality C library, which lacks  
 *      support for buffering, file IO, floating point and getch(), etc. 
 *      Check the Nios II Software Developers Manual for a complete list.
 *
 *    - Check Reduced device drivers
 *      This uses reduced functionality drivers if they're available. For the
 *      standard design this means you get polled UART and JTAG UART drivers,
 *      no support for the LCD driver and you lose the ability to program 
 *      CFI compliant flash devices.
 *
 *    - Check Access device drivers directly
 *      This bypasses the device file system to access device drivers directly.
 *      This eliminates the space required for the device file system services.
 *      It also provides a HAL version of libc services that access the drivers
 *      directly, further reducing space. Only a limited number of libc
 *      functions are available in this configuration.
 *
 *    - Use ALT versions of stdio routines:
 *
 *           Function                  Description
 *        ===============  =====================================
 *        alt_printf       Only supports %s, %x, and %c ( < 1 Kbyte)
 *        alt_putstr       Smaller overhead than puts with direct drivers
 *                         Note this function doesn't add a newline.
 *        alt_putchar      Smaller overhead than putchar with direct drivers
 *        alt_getchar      Smaller overhead than getchar with direct drivers
 *
 */


#include "altera_avalon_pio_regs.h"
#include "altera_avalon_mutex.h"
#include "system.h"
#include "unistd.h"

// FreeRTOS
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

// Asym
#define IS_SLAVE
#include "asym.h"

#define speedy 100

void xZerothTask( void * data){
	int value;
	while(1){
		taskENTER_CRITICAL();
		//alt_printf("Task 0 ");
		taskEXIT_CRITICAL();
		value = vAsymServeRequest(Task0);
		taskENTER_CRITICAL();
		alt_printf("%x: Task 0 Done\n", value);
		taskEXIT_CRITICAL();
		vTaskDelay(3000/speedy);
	}
}

void xFirstTask( void * data){
	int value;
	while(1){
		taskENTER_CRITICAL();
		//alt_printf("Task 1 ");
		taskEXIT_CRITICAL();
		value = vAsymServeRequest(Task1);
		taskENTER_CRITICAL();
		alt_printf("%x: Task 1 Done\n", value);
		taskEXIT_CRITICAL();
		vTaskDelay(3000/speedy);
	}
}
void xSecondTask( void * data){
	int value;
	while(1){
		taskENTER_CRITICAL();
		//alt_printf("Task 1 ");
		taskEXIT_CRITICAL();
		value = vAsymServeRequest(Task2);
		taskENTER_CRITICAL();
		alt_printf("%x: Task 2 Done\n", value);
		taskEXIT_CRITICAL();
		vTaskDelay(3000/speedy);
	}
}

void xThirdTask( void * data){
	int value;
	while(1){
		taskENTER_CRITICAL();
		//alt_printf("Task 1 ");
		taskEXIT_CRITICAL();
		value = vAsymServeRequest(Task3);
		taskENTER_CRITICAL();
		alt_printf("%x: Task 3 Done\n", value);
		taskEXIT_CRITICAL();
		vTaskDelay(3000/speedy);
	}
}

void xFourthTask( void * data){
	int value;
	while(1){
		taskENTER_CRITICAL();
		//alt_printf("Task 1 ");
		taskEXIT_CRITICAL();
		value = vAsymServeRequest(Task4);
		taskENTER_CRITICAL();
		alt_printf("%x: Task 4 Done\n", value);
		taskEXIT_CRITICAL();
		vTaskDelay(3000/speedy);
	}
}

void xFifthTask( void * data){
	int value;
	while(1){
		taskENTER_CRITICAL();
		//alt_printf("Task 1 ");
		taskEXIT_CRITICAL();
		value = vAsymServeRequest(Task5);
		taskENTER_CRITICAL();
		alt_printf("%x: Task 5 Done\n", value);
		taskEXIT_CRITICAL();
		vTaskDelay(3000/speedy);
	}
}

void xSixthTask( void * data){
	int value;
	while(1){
		taskENTER_CRITICAL();
		//alt_printf("Task 1 ");
		taskEXIT_CRITICAL();
		value = vAsymServeRequest(Task6);
		taskENTER_CRITICAL();
		alt_printf("%x: Task 6 Done\n", value);
		taskEXIT_CRITICAL();
		vTaskDelay(3000/speedy);
	}
}

int main()
{ 
	xAsymMutexInit();
	xAsymReqQueuInit();

	alt_putstr("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	alt_putstr("CPU 1 started\n");

	xTaskCreate(xZerothTask , "Task0" , 100, NULL, 2, NULL);
	xTaskCreate(xFirstTask , "Task1" , 100, NULL, 2, NULL);
	xTaskCreate(xSecondTask , "Task2" , 100, NULL, 2, NULL);
	xTaskCreate(xThirdTask , "Task3" , 100, NULL, 2, NULL);
	xTaskCreate(xFourthTask , "Task4" , 100, NULL, 2, NULL);
	xTaskCreate(xFifthTask , "Task5" , 100, NULL, 2, NULL);
	xTaskCreate(xSixthTask , "Task6" , 100, NULL, 2, NULL);
	//  xAsymTaskCreate(xSecondTask , Task2 );
	//  xAsymTaskCreate(xThirdTask , Task3 );
	//  xAsymTaskCreate(xFourthTask , Task4 );
	//  xAsymTaskCreate(xFifthTask , Task5 );
	//  xAsymTaskCreate(xSixthTask , Task6 );


	//  alt_putstr("Added tasks!\n");

	vTaskStartScheduler();
	alt_putstr("OOPs!\n");

	return 0;
}
