/****************************************************************************
 * \file        : display.c													*
 * \brief       : Display control middle layer								*
 * \author		: MLN														*
 * \date		: 06.11.18													*
 ***************************************************************************/


/****************************************************************************
 * INCLUDES																	*
 ***************************************************************************/

/* USER CODE BEGIN Includes */
#include "../../Inc/Middleware/display.h"

/* USER CODE END Includes */



/****************************************************************************
 * VARIABLES																*
 ***************************************************************************/

/* USER CODE BEGIN Variables */
TIM_HandleTypeDef htim1;

uint8_t display_isAsleep = 1;

/* USER CODE END Variables */



/****************************************************************************
 * FUNCTION PROTOTYPES														*
 ***************************************************************************/



/****************************************************************************
 * FUNCTIONS																*
 ***************************************************************************/

void display_setBrightness(uint8_t brightness){
	uint32_t brightnessSetting = 0;

	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);

	if (brightness > 0){
		brightnessSetting = brightness * TIM1_MAX / 100;
		// Setting new brightness to TIM1 Capture/Compare register (PWM ON state)
		TIM1->CCR1 = brightnessSetting;
		HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
		if (display_isAsleep == 1){
			display_writeCommand(CMD_SLEEP_OUT);
			display_isAsleep = 0;
		}
	}else if (display_isAsleep == 0){
		display_writeCommand(CMD_ENTER_SLEEP_MODE);
		display_isAsleep = 1;
	}

}



void display_init(){
	HAL_GPIO_WritePin(DISPLAY_CMD_PORT, DISPLAY_RD, GPIO_PIN_SET);
	HAL_GPIO_WritePin(DISPLAY_CMD_PORT, DISPLAY_WR, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DISPLAY_CMD_PORT, DISPLAY_RST, GPIO_PIN_RESET);
	// MAY NEED DELAY
	HAL_GPIO_WritePin(DISPLAY_CMD_PORT, DISPLAY_RST, GPIO_PIN_SET);
	// MAY NEED DELAY

	display_writeCommand(CMD_SLEEP_OUT);

	display_writeCommand(CMD_MEMORY_ACCESS_CONTROL);
	display_writeData(0x0080);

	display_writeCommand(CMD_INTERFACE_PIXEL_FORMAT_SET);
	display_writeData(0x0066);

	display_writeCommand(CMD_PORCH_SETTING);
	display_writeData(0x000C);
	display_writeData(0x000C);
	display_writeData(0x0000);
	display_writeData(0x0033);
	display_writeData(0x0033);

	display_writeCommand(CMD_G_CONTROL);
	display_writeData(0x0035);

	display_writeCommand(CMD_VCOM_SETTING);
	display_writeData(0x002B);

	display_writeCommand(CMD_LCM_CONTROL);
	display_writeData(0x002C);

	display_writeCommand(CMD_VDVVRH_COMMAND_ENABLE);
	display_writeData(0x0001);
	display_writeData(0x00FF);

	display_writeCommand(CMD_VRH_SET);
	display_writeData(0x0011);

	display_writeCommand(CMD_VDV_SET);
	display_writeData(0x0020);

	display_writeCommand(CMD_FRAME_RATE_CONTROL_IN_NORMAL_MODE);
	display_writeData(0x000F);

	display_writeCommand(CMD_POWER_CONTROL1);
	display_writeData(0x00A4);
	display_writeData(0x00A1);

	display_writeCommand(CMD_POSITIVE_VOLTAGE_GAMMA_CONTROL);
	display_writeData(0x00D0);
	display_writeData(0x0000);
	display_writeData(0x0005);
	display_writeData(0x000E);
	display_writeData(0x0015);
	display_writeData(0x000D);
	display_writeData(0x0037);
	display_writeData(0x0043);
	display_writeData(0x0047);
	display_writeData(0x0009);
	display_writeData(0x0015);
	display_writeData(0x0012);
	display_writeData(0x0016);
	display_writeData(0x0019);

	display_writeCommand(CMD_NEGATIVE_VOLTAGE_GAMMA_CONTROL);
	display_writeData(0x00D0);
	display_writeData(0x0000);
	display_writeData(0x0005);
	display_writeData(0x000D);
	display_writeData(0x000C);
	display_writeData(0x0006);
	display_writeData(0x002D);
	display_writeData(0x0044);
	display_writeData(0x0040);
	display_writeData(0x000E);
	display_writeData(0x001C);
	display_writeData(0x0018);
	display_writeData(0x0016);
	display_writeData(0x0019);

	display_writeCommand(CMD_COLUMN_ADDRESS_SET);
	display_writeData(0x0000);
	display_writeData(0x0000);
	display_writeData(0x0000);
	display_writeData(0x00EF);

	display_writeCommand(CMD_ROW_ADDRESS_SET);
	display_writeData(0x0000);
	display_writeData(0x0000);
	display_writeData(0x0001);
	display_writeData(0x003F);

	// MAY NEED DELAY

}



void display_writeCmd(uint16_t command){
	HAL_GPIO_WritePin(DISPLAY_CMD_PORT, DISPLAY_DC, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DISPLAY_CMD_PORT, DISPLAY_RD, GPIO_PIN_SET);
	HAL_GPIO_WritePin(DISPLAY_CMD_PORT, DISPLAY_WR, GPIO_PIN_RESET);

	// Resetting bit output registers
	DISPLAY_DATA_PORT->BSRR &= 0xFFFF0000;
	// Masking command on the port
	DISPLAY_DATA_PORT->BSRR |= command;

	// MAY NEED DELAY
	HAL_GPIO_WritePin(DISPLAY_CMD_PORT, DISPLAY_WR, GPIO_PIN_SET);
	// MAY NEED DELAY
}



void display_writeData(uint16_t data){
	// Resetting bit output registers
	DISPLAY_DATA_PORT->BSRR &= 0xFFFF0000;
	// Masking data on the port
	DISPLAY_DATA_PORT->BSRR |= data;

	HAL_GPIO_WritePin(DISPLAY_CMD_PORT, DISPLAY_DC, GPIO_PIN_SET);
	HAL_GPIO_WritePin(DISPLAY_CMD_PORT, DISPLAY_WR, GPIO_PIN_RESET);
	// MAY NEED DELAY
	HAL_GPIO_WritePin(DISPLAY_CMD_PORT, DISPLAY_WR, GPIO_PIN_SET);
}
