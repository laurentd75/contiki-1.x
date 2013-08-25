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
 * This file is part of the Contiki desktop OS
 *
 * $Id: cc-conf.h,v 1.1 2006/04/17 15:02:26 kthacker Exp $
 *
 */
#ifndef __CC_CONF_H__
#define __CC_CONF_H__

/* This file is used to configure stuff that depends on the
   capabilities of the C compiler used. */

/* CC_CONF_REGISTER_ARGS: 1 or 0; 1 if the C compiler can handle the
   "register" keyword in function argument, 0 otherwise. */
#define CC_CONF_REGISTER_ARGS          0

/* CC_CONF_FUNCTION_POINTR_ARGS: 1 or 0; 1 if the C compiler can
   handle function arguments with function pointers, 0 otherwise. */
#define CC_CONF_FUNCTION_POINTER_ARGS  1

/* CC_CONF_FASTCALL: if the C compiler supports the fastcall keyword,
   it should be defined here. If the C compiler does not support it,
   leave the definition blank. 

   Example:
   #define CC_CONF_FASTCALL               fastcall */
#define CC_CONF_FASTCALL

#endif /* __CC_CONF_H__ */
