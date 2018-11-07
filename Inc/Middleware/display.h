/****************************************************************************
 * \file        : display.h													*
 * \brief       : Display control middle layer header file					*
 * \author		: MLN														*
 * \date		: 06.11.18													*
 ***************************************************************************/

#ifndef DISPLAY_H_
#define DISPLAY_H_

/****************************************************************************
 * INCLUDES																	*
 ***************************************************************************/

/* USER CODE BEGIN Includes */
#include "../main.h"

/* USER CODE END Includes */



/****************************************************************************
 * DEFINITIONS																*
 ***************************************************************************/

/* USER CODE BEGIN Definitions */
#define DISPLAY_CMD_PORT	GPIOC
#define DISPLAY_DATA_PORT	GPIOB
#define DISPLAY_DC			GPIO_PIN_0
#define DISPLAY_WR			GPIO_PIN_0
#define DISPLAY_RD			GPIO_PIN_0
#define DISPLAY_RST			GPIO_PIN_0





#define		CMD_NOP                             0x00
#define		CMD_SOFTWARE_RESET                  0x01
#define		CMD_READ_DISP_ID                    0x04
#define		CMD_READ_DISP_STATUS                0x09
#define		CMD_DISP_POWER_MODE				    0x0A
#define		CMD_READ_DISP_MADCTRL               0x0B

#define		CMD_READ_DISP_PIXEL_FORMAT          0x0C
#define		CMD_READ_DISP_IMAGE_FORMAT          0x0D
#define		CMD_READ_DISP_SIGNAL_MODE           0x0E
#define		CMD_READ_DISP_SELF_DIAGNOSTIC       0x0F
#define		CMD_ENTER_SLEEP_MODE                0x10
#define		CMD_SLEEP_OUT                       0x11
#define		CMD_PARTIAL_MODE_ON                 0x12
#define		CMD_NORMAL_DISP_MODE_ON             0x13
#define		CMD_DISP_INVERSION_OFF              0x20
#define		CMD_DISP_INVERSION_ON               0x21

#define		CMD_GAMMA_SET                       0x26
#define		CMD_DISPLAY_OFF                     0x28
#define		CMD_DISPLAY_ON                      0x29
#define		CMD_COLUMN_ADDRESS_SET              0x2A
#define		CMD_ROW_ADDRESS_SET                 0x2B

#define		CMD_MEMORY_WRITE                    0x2C
#define		CMD_MEMORY_READ                     0x2E

#define		CMD_PARTIAL_AREA                    0x30
#define		CMD_VERT_SCROLL_DEFINITION          0x33
#define		CMD_TEARING_EFFECT_LINE_OFF         0x34
#define		CMD_TEARING_EFFECT_LINE_ON          0x35
#define		CMD_MEMORY_ACCESS_CONTROL           0x36
#define		CMD_VERT_SCROLL_START_ADDRESS       0x37

#define		CMD_IDLE_MODE_OFF                   0x38
#define		CMD_IDLE_MODE_ON                    0x39
#define		CMD_INTERFACE_PIXEL_FORMAT_SET      0x3A
#define		CMD_WRITE_MEMORY_CONTINUE           0x3C
#define		CMD_READ_MEMORY_CONTINUE            0x3E

#define		CMD_SET_TEAR_SCANLINE               0x44
#define		CMD_GET_SCANLINE                    0x45
#define		CMD_WRITE_DISPLAY_BRIGHTNESS        0x51
#define		CMD_READ_DISPLAY_BRIGHTNESS         0x52
#define		CMD_WRITE_CTRL_DISPLAY              0x53
#define		CMD_READ_CTRL_DISPLAY               0x54
#define		CMD_WRITE_CONTENT_ADAPT_BRIGHTNESS  0x55
#define		CMD_READ_CONTENT_ADAPT_BRIGHTNESS   0x56
#define		CMD_WRITE_MIN_CAB_LEVEL             0x5E
#define		CMD_READ_MIN_CAB_LEVEL              0x5F
#define		CMD_READ_ID1                        0xDA
#define		CMD_READ_ID2                        0xDB
#define		CMD_READ_ID3                        0xDC

/* Level 2 Commands (from the display Datasheet) */
#define		CMD_RAM_CONTROL						0xB0
#define		CMD_RGB_INTERFACE_CONTROL			0xB1
#define		CMD_PORCH_SETTING					0xB2

#define		CMD_FRAME_RATE_CONTROL_1				0xB3
#define		CMD_G_CONTROL						0xB7
#define		CMD_DIGITAL_GAMMA_ENABLE             0xBA
#define		CMD_VCOM_SETTING					    0xBB

#define		CMD_LCM_CONTROL								0xC0
#define		CMD_ID_CODE_SETTING							0xC1
#define		CMD_VDVVRH_COMMAND_ENABLE					0xC2
#define		CMD_VRH_SET									0xC3
#define		CMD_VDV_SET									0xC4
#define		CMD_VCOM_OFFSET_SET							0xC5
#define		CMD_FRAME_RATE_CONTROL_IN_NORMAL_MODE		0XC6
#define		CMD_CABC_CONTROL								0xC7
#define		CMD_REGISTER_VALUE_SELECTION_1               0xC8
#define		CMD_REGISTER_VALUE_SELECTION_2               0xCA

#define		CMD_POWER_CONTROL1							0xD0
#define		CMD_ENABLE_VAPVAN_SIGNAL_OUTPUT				0xD2
#define		CMD_POSITIVE_VOLTAGE_GAMMA_CONTROL           0xE0
#define		CMD_NEGATIVE_VOLTAGE_GAMMA_CONTROL           0xE1
#define		CMD_DIGITAL_GAMMA_CONTROL_1					0xE2
#define		CMD_DIGITAL_GAMMA_CONTROL_2					0xE3
#define		CMD_GATE_CONTROL								0XE4
#define		CMD_SPI2_ENABLE								0XE7
#define		CMD_POWER_CONTROL2							0xE8
#define		CMD_EQUALIZE_TIME_CONTROL					0xE9
#define		CMD_PROGRAMME_MODE_CONTROL					0xEC
#define		CMD_PROGRAMME_MODE_ENABLE					0xFA
#define		CMD_NVM_SETTING								0xFC
#define		CMD_PROGRAM_ACTION							0xFE

/* USER CODE END Definitions */



/****************************************************************************
 * PUBLIC VARIABLES															*
 ***************************************************************************/

/* USER CODE BEGIN Public variables */


/* USER CODE END Public variables */



/****************************************************************************
 * FUNCTION PROTOTYPES														*
 ***************************************************************************/

/**
 * \fn 		input_initAnalog(ADC_HandleTypeDef*)
 *
 * \brief 	Initializes sensor live update service: the ADC scans our sensors
 * 			continuously, passes each value to the DMA controller who stores our
 * 			values in analogValues table.
 *
 * 			The process runs solely on peripherals, saving us CPU power.
 */
void display_setBrightness(uint8_t brightness);



/**
 * \fn 		input_getInputs(void)
 *
 * \brief 	Copies ADC live-read values to local light and temperature variables.
 * 			Saves the last 8 states of each keypad key in keypadValues array.
 */
void display_init();

void display_writeCmd(uint16_t command);

void display_writeData(uint16_t data);

#endif /* DISPLAY_H_ */
