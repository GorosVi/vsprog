/**************************************************************************
 *  Copyright (C) 2008 by Simon Qian                                      *
 *  SimonQian@SimonQian.com                                               *
 *                                                                        *
 *  Project:    Versaloon                                                 *
 *  File:       USB_TO_xxx.c                                              *
 *  Author:     SimonQian                                                 *
 *  Versaion:   See changelog                                             *
 *  Purpose:    implementation file for USB_TO_XXX                        *
 *  License:    See license                                               *
 *------------------------------------------------------------------------*
 *  Change Log:                                                           *
 *      YYYY-MM-DD:     What(by Who)                                      *
 *      2008-11-07:     created(by SimonQian)                             *
 **************************************************************************/

#include "app_cfg.h"
#if USB_TO_XXX_EN

#include "USB_TO_XXX.h"

void USB_TO_XXX_ProcessCmd(uint8* dat, uint16 len)
{
	uint16 USB_TO_XXX_CmdIdx;
	uint16 USB_TO_XXX_CmdLen_tmp;

	// for USB_TO_ALL command, data area(from the 3rd byte) is the real command to execute
	if(dat[0] == USB_TO_ALL)
	{
		USB_TO_XXX_CmdIdx = 3;
	}
	else
	{
		USB_TO_XXX_CmdIdx = 0;
	}

	// Poll for all the data received
	while(USB_TO_XXX_CmdIdx < len)
	{
		// get command length
		USB_TO_XXX_CmdLen_tmp = dat[USB_TO_XXX_CmdIdx + 1] + (dat[USB_TO_XXX_CmdIdx + 2] << 8) - 3;
		// poll command type and call different module
		switch(dat[USB_TO_XXX_CmdIdx])
		{
/****************************** Page0 ******************************/
#if USB_TO_USART_EN
		case USB_TO_USART:
			USB_TO_USART_ProcessCmd(dat + USB_TO_XXX_CmdIdx + 3, USB_TO_XXX_CmdLen_tmp);
			break;
#endif
#if USB_TO_SPI_EN
		case USB_TO_SPI:
			USB_TO_SPI_ProcessCmd(dat + USB_TO_XXX_CmdIdx + 3, USB_TO_XXX_CmdLen_tmp);
			break;
#endif
#if USB_TO_I2C_EN
		case USB_TO_I2C:
			USB_TO_I2C_ProcessCmd(dat + USB_TO_XXX_CmdIdx + 3, USB_TO_XXX_CmdLen_tmp);
			break;
#endif
#if USB_TO_GPIO_EN
		case USB_TO_GPIO:
			USB_TO_GPIO_ProcessCmd(dat + USB_TO_XXX_CmdIdx + 3, USB_TO_XXX_CmdLen_tmp);
			break;
#endif
#if USB_TO_CAN_EN
		case USB_TO_CAN:
			USB_TO_CAN_ProcessCmd(dat + USB_TO_XXX_CmdIdx + 3, USB_TO_XXX_CmdLen_tmp);
			break;
#endif
#if USB_TO_PWM_EN
		case USB_TO_PWM:
			USB_TO_PWM_ProcessCmd(dat + USB_TO_XXX_CmdIdx + 3, USB_TO_XXX_CmdLen_tmp);
			break;
#endif
#if USB_TO_ADC_EN
		case USB_TO_ADC:
			USB_TO_ADC_ProcessCmd(dat + USB_TO_XXX_CmdIdx + 3, USB_TO_XXX_CmdLen_tmp);
			break;
#endif
#if USB_TO_DAC_EN
		case USB_TO_DAC:
			USB_TO_DAC_ProcessCmd(dat + USB_TO_XXX_CmdIdx + 3, USB_TO_XXX_CmdLen_tmp);
			break;
#endif
#if USB_TO_MICROWIRE_EN
		case USB_TO_MICROWIRE:
			USB_TO_MICROWIRE_ProcessCmd(dat + USB_TO_XXX_CmdIdx + 3, USB_TO_XXX_CmdLen_tmp);
			break;
#endif

/****************************** Page1 ******************************/
#if USB_TO_JTAG_LL_EN
		case USB_TO_JTAG_LL:
			USB_TO_JTAG_LL_ProcessCmd(dat + USB_TO_XXX_CmdIdx + 3, USB_TO_XXX_CmdLen_tmp);
			break;
#endif
#if USB_TO_JTAG_HL_EN
		case USB_TO_JTAG_HL:
			USB_TO_JTAG_HL_ProcessCmd(dat + USB_TO_XXX_CmdIdx + 3, USB_TO_XXX_CmdLen_tmp);
			break;
#endif
#if USB_TO_ISSP_EN
		case USB_TO_ISSP:
			USB_TO_ISSP_ProcessCmd(dat + USB_TO_XXX_CmdIdx + 3, USB_TO_XXX_CmdLen_tmp);
			break;
#endif
#if USB_TO_C2_EN
		case USB_TO_C2:
			USB_TO_C2_ProcessCmd(dat + USB_TO_XXX_CmdIdx + 3, USB_TO_XXX_CmdLen_tmp);
			break;
#endif
#if USB_TO_LPCICP_EN
		case USB_TO_LPCICP:
			USB_TO_LPCICP_ProcessCmd(dat + USB_TO_XXX_CmdIdx + 3, USB_TO_XXX_CmdLen_tmp);
			break;
#endif
#if USB_TO_MSP430_JTAG_EN
		case USB_TO_MSP430_JTAG:
			USB_TO_MSP430_JTAG_ProcessCmd(dat + USB_TO_XXX_CmdIdx + 3, USB_TO_XXX_CmdLen_tmp);
			break;
#endif

/****************************** Page2 ******************************/
#if USB_TO_POWER_EN
		case USB_TO_POWER:
			USB_TO_POWER_ProcessCmd(dat + USB_TO_XXX_CmdIdx + 3, USB_TO_XXX_CmdLen_tmp);
			break;
#endif
		case USB_TO_DELAY:
			DelayUSMS(dat[USB_TO_XXX_CmdIdx + 3] + (dat[USB_TO_XXX_CmdIdx + 4] << 8));

			buffer_out[rep_len++] = USB_TO_XXX_OK;
			break;
		default:
			buffer_out[rep_len++] = USB_TO_XXX_CMD_NOT_SUPPORT;
			break;
		}

		// add command length to the USB_TO_XXX_CmdIdx
		// 3 more bytes are command char(1 byte), command length(2 bytes)
		USB_TO_XXX_CmdIdx += USB_TO_XXX_CmdLen_tmp + 3;
	}
}

#endif		// #if USB_TO_XXX_EN