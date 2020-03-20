/* SPDX-License-Identifier: GPL-2.0-or-later */
#ifndef _ASM_INST_H
#define _ASM_INST_H

/*
 * Instruction data type for POWER
 */

#ifdef __powerpc64__

typedef struct ppc_inst {
	union {
		struct {
			u32 word;
			u32 pad;
		} __packed;
		struct {
			u32 prefix;
			u32 suffix;
		} __packed;
	};
} ppc_inst;

#define PPC_INST(x) ((ppc_inst) { .word = (x), .pad = 0 })
#define PPC_INST_PREFIXED(x, y) ((ppc_inst) { .prefix = (x), .suffix = (y) })

static inline int ppc_inst_opcode(ppc_inst x)
{
	return x.word >> 26;
}

static inline bool ppc_inst_prefixed(ppc_inst x) {
	return ppc_inst_opcode(x) == 1;
}

static inline int ppc_inst_len(ppc_inst x)
{
	if (ppc_inst_prefixed(x))
		return 8;
	else
		return 4;
}

static inline u32 ppc_inst_word(ppc_inst x)
{
	return x.word;
}

static inline u32 ppc_inst_prefix(ppc_inst x)
{
	return x.prefix;
}

static inline u32 ppc_inst_suffix(ppc_inst x)
{
	return x.suffix;
}


static inline ppc_inst ppc_inst_read(const void *ptr)
{
	ppc_inst inst;
	inst.word = *(u32 *)ptr;
	if (ppc_inst_prefixed(inst))
		inst.suffix = *((u32 *)ptr + 1);
	else
		inst.pad = 0;
	return inst;
}

static inline void ppc_inst_write(ppc_inst *ptr, ppc_inst x)
{
	if (ppc_inst_prefixed(x)) {
		*(u32 *)ptr = x.prefix;
		*((u32 *)ptr + 1) = x.suffix;
	} else {
		*(u32 *)ptr = x.word;
	}
}

static inline bool ppc_inst_equal(ppc_inst x, ppc_inst y)
{
	return !memcmp(&x, &y, sizeof(struct ppc_inst));
}

static inline bool ppc_inst_null(ppc_inst x)
{
	return x.word == 0 && x.pad == 0;
}

static inline u32 ppc_inst_mask(ppc_inst x, u32 mask)
{
	return ppc_inst_word(x) & mask;
}

#else /* !__powerpc64__ */

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

#endif /* __powerpc64__ */
#endif /* _ASM_INST_H */
