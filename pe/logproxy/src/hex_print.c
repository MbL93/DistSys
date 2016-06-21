
/*
 * hex_print.c
 *
 *
 * $Id: hex_print.c,v 1.2 2005/11/18 22:14:38 ralf Exp $
 *
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>

#include "hex_print.h"


void
hex_print(FILE *fd, const char *s, ushort len, ushort offset)
{
  int i;
  char hex_buffer[49];
  char ascii_buffer[17];
  char buffer[5];

  strcpy(hex_buffer, "");
  strcpy(ascii_buffer, "");
  fprintf(fd, "%06x:", offset);
  for(i=0; i<len; i++) {
    if((i % 16) == 0 && i > 0) {
      fprintf(fd, "%s | %s\n", hex_buffer, ascii_buffer);
      fprintf(fd, "%06x:", i+offset);
      strcpy(hex_buffer, "");
      strcpy(ascii_buffer, "");
    } /* end if */
    sprintf(buffer, " %02x", (unsigned char)(s[i]));
    strcat(hex_buffer, buffer);
    sprintf(buffer, "%c", isprint(s[i]) ? s[i] : '.');
    strcat(ascii_buffer, buffer);
  } /* end for */
  fprintf(fd, "%-48s | %s\n", hex_buffer, ascii_buffer);
} /* end of hex_print */
