/*
 * Copyright (c) 2003, Adam Dunkels.
 * All rights reserved. 
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution. 
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior
 *    written permission.  
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
 *
 * This file is part of the Contiki desktop environment
 *
 * $Id: enabler-dsc.c,v 1.1 2006/04/17 15:18:16 kthacker Exp $
 *
 */

#include "dsc.h"

extern struct ctk_icon enabler_icon;
/*-----------------------------------------------------------------------------------*/
DSC(enabler_dsc,
    "Colorless grayish CTK theme",
    "enabler.prg",
    enabler_init,
    &enabler_icon);
/*-----------------------------------------------------------------------------------*/
#if CTK_CONF_ICON_BITMAPS
static unsigned char enablericon_bitmap[3*3*8] = {
  0xff,0xff,0xff,0xfc,0xf0,0xf0,0xe0,0xe0,
  0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,
  0xff,0xff,0xff,0x3f,0x0f,0x0f,0x07,0x07,

  0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,0xe0,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,

  0xe0,0xe0,0xf0,0xf0,0xfc,0xff,0xff,0xff,
  0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,
  0x07,0x07,0x0f,0x0f,0x3f,0xff,0xff,0xff
};
#endif /* CTK_CONF_ICON_BITMAPS */

#if CTK_CONF_ICON_TEXTMAPS
static char enablericon_textmap[9] = {
  '(', '=', ')',
  '|', 'o', '|',
  '(', '-', ')'
};
#endif /* CTK_CONF_ICON_TEXTMAPS */

static struct ctk_icon enabler_icon =
  {CTK_ICON("Enabler", enablericon_bitmap, enablericon_textmap)};
/*-----------------------------------------------------------------------------------*/
