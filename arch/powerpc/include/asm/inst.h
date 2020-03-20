/* SPDX-License-Identifier: GPL-2.0-or-later */
#ifndef _ASM_INST_H
#define _ASM_INST_H

/*
 * Instruction data type for POWER
 */

typedef u32 ppc_inst;

#define PPC_INST(x) (x)

static inline int ppc_inst_len(ppc_inst x)
{
	return sizeof(ppc_inst);
}

static inline int ppc_inst_opcode(ppc_inst x)
{
	return x >> 26;
}

static inline u32 ppc_inst_word(ppc_inst x)
{
	return x;
}

static inline ppc_inst ppc_inst_read(const ppc_inst *ptr)
{
	return *(ppc_inst *)ptr;
}

static inline void ppc_inst_write(void *ptr, ppc_inst x)
{
	*(ppc_inst *)ptr = x;
}

static inline bool ppc_inst_equal(ppc_inst x, ppc_inst y)
{
	return x == y;
}

static inline bool ppc_inst_null(ppc_inst x)
{
	return x == 0;
}

static inline u32 ppc_inst_mask(ppc_inst x, u32 mask)
{
	return ppc_inst_word(x) & mask;
}

#endif /* _ASM_INST_H */
