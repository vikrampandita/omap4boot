/*
 * Copyright (C) 2011 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/* omap44xx ID detection and reporting */

#include <aboot/aboot.h>
#include <aboot/io.h>
#include <omap5/hw.h>


struct omap_id {
	omap_rev    rev_num;
	u32         rev_reg_val;
};

static struct omap_id  map[] = {
        { OMAP_5430_ES1_DOT_0, 0x0B94202F },
        { OMAP_REV_INVALID,    0x00000000 },
};

#define CONTORL_ID_CODE (0x4A002204)
omap_rev get_omap_rev(void)
{
	u8 i;
	u32 id_code;

	id_code = readl(CONTORL_ID_CODE);
	for (i = 0; map[i].rev_num != OMAP_REV_INVALID; i++) {
		if (map[i].rev_reg_val == id_code) {
			return map[i].rev_num;
		}
	}

	return OMAP_REV_INVALID;
}
