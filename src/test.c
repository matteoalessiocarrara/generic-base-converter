/*
 * Copyright 2016 Matteo Alessio Carrara <sw.matteoac@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

# include <stdio.h>
# include <stdint.h>
# include "generic_base_converter.c"


# define BIN_CHARSET "01"
# define OCT_CHARSET "01234567"
# define DEC_CHARSET "0123456789"
# define HEX_CHARSET "0123456789ABCDEF"

# define CHARSET BIN_CHARSET


int main()
{
	char * str;
	
	printf("Utilizzando il charset: \"%s\"\n\n", CHARSET);
	
	for(uint8_t num = 0; num <= 0xF; num++)
	{
		printf("Dec = %u, Str = \"%s\"\n", num, str = int_to_str(num, CHARSET, 0));
		printf("Str = \"%s\", Dec = %u\n", str, str_to_int(str, CHARSET));
		printf("\n");
	}
	
	return 0;
}
