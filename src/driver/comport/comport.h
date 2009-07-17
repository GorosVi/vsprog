/***************************************************************************
 *   Copyright (C) 2009 by Simon Qian <SimonQian@SimonQian.com>            *
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
#ifndef __COMPORT_H_INCLUDED__
#define __COMPORT_H_INCLUDED__

#define COMM_STOPBIT_1					'1'
#define COMM_STOPBIT_1P5				'P'
#define COMM_STOPBIT_2					'2'

#define COMM_PARITYBIT_NONE				'N'
#define COMM_PARITYBIT_ODD				'O'
#define COMM_PARITYBIT_EVEN				'E'

#define COMM_HANDSHAKE_NONE				'N'
#define COMM_HANDSHAKE_SOFTWARE			'S'
#define COMM_HANDSHAKE_HARDWARE			'H'

void comm_close(void);
RESULT comm_open(char *comport, uint32 baudrate, uint8 datalength, 
				 char paritybit, char stopbit, char handshake);
int32 comm_read(uint8 *buffer, uint32 num_of_bytes);
int32 comm_write(uint8 *buffer, uint32 num_of_bytes);
int32 comm_ctrl(uint8 dtr, uint8 rts);

#endif /* __COMPORT_H_INCLUDED__ */
