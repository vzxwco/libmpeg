/* (C) Copyright 2001 by Felix Opatz <felix@zotteljedi.de>
 *
 * Copyright (c) 2003
 *    Felix Opatz <felix@zotteljedi.de>.  All rights reserved.
 *
 * Copyright (c) 2007
 *    Philip Busch <philip@0xe3.com>. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer as
 *    the first lines of this file unmodified.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL FELIX OPATZ BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _MPEG_H
#define _MPEG_H


#define MPEG_VERSION_1		3
#define MPEG_VERSION_2		2
#define MPEG_VERSION_2_5	0

#define LAYER_VERSION_1		3
#define LAYER_VERSION_2		2
#define LAYER_VERSION_3		1

#define CMODE_STEREO        	0
#define CMODE_JOINT_STEREO  	1
#define CMODE_DUAL_CHANNEL  	2
#define CMODE_SINGLE_CHANNEL    3

/* number of samples per frame */
#define FRAME_SIZE_LAYER_1      384
#define FRAME_SIZE_LAYER_2      1152
#define FRAME_SIZE_LAYER_3      1152

#define MASK_SYNC       0xFFE00000
#define SHIFT_SYNC      21

#define MASK_MPEG       0x180000
#define SHIFT_MPEG      19

#define MASK_LAYER      0x60000
#define SHIFT_LAYER     17

#define MASK_PROT       0x10000
#define SHIFT_PROT      16

#define MASK_BITRATE    0xF000
#define SHIFT_BITRATE   12

#define MASK_FREQ       0xC00
#define SHIFT_FREQ      10

#define MASK_PADDING    0x200
#define SHIFT_PADDING   9

#define MASK_PRIV       0x100
#define SHIFT_PRIV      8

#define MASK_CHAN       0xC0
#define SHIFT_CHAN      6

#define MASK_MODE_EXT   0x30
#define SHIFT_MODE_EXT  4

#define MASK_COPYRIGHT	0x8
#define SHIFT_COPYRIGHT 3

#define MASK_ORIG       0x4
#define SHIFT_ORIG      2

#define MASK_EMPHASIS   0x3
#define SHIFT_EMPHASIS  0

struct mpeg {
	int		mpeg_version;
	int		layer_desc;
	int		bitrate;
	int		freq;
	int		chan;
	int             mode_ext;
	int             emphasis;
	int             bit_padding;
	int             bit_priv;
	int             bit_copyright;
	int             bit_orig;
	int             bit_prot;
};

int mpeg_read(const char *, struct mpeg *);
unsigned long int mpeg_seek_next_header(FILE *);
int mpeg_extract_info(unsigned long int, struct mpeg *);
size_t mpeg_frame_length(struct mpeg *);
size_t mpeg_frame_bytes(struct mpeg *);
void mpeg_print(struct mpeg *);

#endif  /* ! _MPEG_H */
