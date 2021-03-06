/***************************************************************************
 *   Copyright (C) 2009 - 2010 by Simon Qian <SimonQian@SimonQian.com>     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef __AVR8_INTERNAL_H_INCLUDED__
#define __AVR8_INTERNAL_H_INCLUDED__

#define AVR8_ISP						0
#define AVR8_JTAG						1
#define AVR8_HVPP						2
#define AVR8_HVSP						3

#define AVR8_PARAM_JTAG_FULL_BITSTREAM	0
#define AVR8_PARAM_ISP_EERPOM_PAGE_EN	1
#define AVR8_PARAM_ISP_POLL				2

extern struct program_functions_t avr8isp_program_functions;
extern struct program_functions_t avr8jtag_program_functions;

#endif /* __AVR8_INTERNAL_H_INCLUDED__ */

