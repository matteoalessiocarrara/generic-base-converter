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

# include <stdint.h>
# include <stdlib.h>
# include <math.h>

# include "lib/readability/src/readability.h"


/* Converte un unsigned int in stringa, utilizzato il charset base_charset
 * 
 * È possibile specificare in min_len la lunghezza minima della stringa, saranno
 * aggiunti degli zeri (tradotti) a sinistra nel caso la stringa non fosse abbastanza
 * lunga.
 */
char * int_to_str(uint32_t num, const char * base_charset, const uint32_t min_len)
{
	
	const uint32_t base = str_len(base_charset);

	/* Il numero di cifre del numero, rappresentato in base 'base' */
	const uint32_t num_len = (uint32_t) (log(num) / log(base)) + 1;
	
	char * str = malloc(sizeof(char) * ((num_len < min_len? min_len : num_len) + 1));
	char * curr_char =  &str[(num_len < min_len? min_len : num_len)];
	
	
	*(curr_char--) = '\0';
	
	
	do
	{
		*(curr_char--) = base_charset[num % base];
		num /= base;
	}
	while(num > 0);
	
	
	while(curr_char >= str)
		*(curr_char--) = base_charset[0];
	
	
	return str;
}


/* Converte il carattere ch in int, cercando la sua posizione in base_charset
 * ATTENZIONE!! DA PER SCONTATO CHE ch SIA IN base_charset!!
 */
static inline uint32_t char_to_int(const char ch, const char * base_charset)
{
	uint32_t index = 0;	

	while(base_charset[index++] != ch);
	
	return --index;
}


/* Converte una stringa in int, interpretando la stringa come in base strlen(base_charset)
 * ATTENZIONE: TUTTI I CARATTERI DELLA STRINGA DEVONO ESSERE IN base_charset
 */ 
uint32_t str_to_int(const char * str, const char * base_charset)
{
	const uint32_t base = str_len(base_charset);
	const uint32_t str_len_ = str_len(str);
	uint32_t ret = 0;
	
	
	for(uint32_t i = 0; i < str_len_; i++)
		ret += (char_to_int(str[i], base_charset) * power(base, str_len_- 1 - i));
	
	
	return ret;
}
