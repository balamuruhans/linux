/* SPDX-License-Identifier: GPL-2.0-or-later */
/*
 * Copyright 2020 IBM Corporation.
 *
 * Provides raw encoding for PowerPC instructions
 */
#ifndef _ASM_POWERPC_PPC_OPCODE_RAW_H
#define _ASM_POWERPC_PPC_OPCODE_RAW_H

#include <asm/ppc-opcode.h>

#define PPC_STR_CP_ABORT        stringify_in_c(.long PPC_CP_ABORT)
#define PPC_STR_COPY(a, b)      stringify_in_c(.long PPC_COPY(a, b))
#define PPC_STR_DARN(t, l)      stringify_in_c(.long PPC_DARN(t, l))
#define PPC_STR_DCBAL(a, b)     stringify_in_c(.long PPC_DCBAL(a, b))
#define PPC_STR_DCBZL(a, b)     stringify_in_c(.long PPC_DCBZL(a, b))
#define PPC_STR_LQARX(t, a, b, eh) \
				stringify_in_c(.long PPC_LQARX(t, a, b, eh))
#define PPC_STR_LDARX(t, a, b, eh) \
				stringify_in_c(.long PPC_LDARX(t, a, b, eh))
#define PPC_STR_LWARX(t, a, b, eh) \
				stringify_in_c(.long PPC_LWARX(t, a, b, eh))
#define PPC_STR_STQCX(t, a, b)  stringify_in_c(.long PPC_STQCX(t, a, b))
#define PPC_STR_MADDHD(t, a, b, c) \
				stringify_in_c(.long PPC_MADDHD(t, a, b, c))
#define PPC_STR_MADDHDU(t, a, b, c) \
				stringify_in_c(.long PPC_MADDHDU(t, a, b, c))
#define PPC_STR_MADDLD(t, a, b, c) \
				stringify_in_c(.long PPC_MADDLD(t, a, b, c))
#define PPC_STR_MSGSND(b)       stringify_in_c(.long PPC_MSGSND(b))
#define PPC_STR_MSGSYNC         stringify_in_c(.long PPC_MSGSYNC)
#define PPC_STR_MSGCLR(b)       stringify_in_c(.long PPC_MSGCLR(b))
#define PPC_STR_MSGSNDP(b)      stringify_in_c(.long PPC_MSGSNDP(b))
#define PPC_STR_MSGCLRP(b)      stringify_in_c(.long PPC_MSGCLRP(b))
#define PPC_STR_PASTE(a, b)     stringify_in_c(.long PPC_PASTE(a, b))
#define PPC_STR_POPCNTB(a, s)   stringify_in_c(.long PPC_POPCNTB(a, s))
#define PPC_STR_POPCNTD(a, s)   stringify_in_c(.long PPC_POPCNTD(a, s))
#define PPC_STR_POPCNTW(a, s)   stringify_in_c(.long PPC_POPCNTW(a, s))
#define PPC_STR_RFCI            stringify_in_c(.long PPC_RFCI)
#define PPC_STR_RFDI            stringify_in_c(.long PPC_RFDI)
#define PPC_STR_RFMCI           stringify_in_c(.long PPC_RFMCI)
#define PPC_STR_TLBILX(t, a, b) stringify_in_c(.long PPC_TLBILX(t, a, b))
#define PPC_STR_WAIT(w)         stringify_in_c(.long PPC_WAIT(w))
#define PPC_STR_TLBIE(lp, a)    stringify_in_c(.long PPC_TLBIE(lp, a))
#define PPC_STR_TLBIE_5(rb, rs, ric, prs, r) \
				stringify_in_c(.long PPC_TLBIE_5(rb, \
						rs, ric, prs, r))
#define PPC_STR_TLBIEL(rb, rs, ric, prs, r) \
				stringify_in_c(.long PPC_TLBIEL(rb, \
						rs, ric, prs, r))
#define PPC_STR_TLBSRX_DOT(a, b)stringify_in_c(.long PPC_TLBSRX_DOT(a, b))
#define PPC_STR_TLBIVAX(a, b)   stringify_in_c(.long PPC_TLBIVAX(a, b))

#define PPC_STR_ERATWE(s, a, w) stringify_in_c(.long PPC_ERATWE(s, a, w))
#define PPC_STR_ERATRE(s, a, w) stringify_in_c(.long PPC_ERATRE(s, a, w))
#define PPC_STR_ERATILX(t, a, b)stringify_in_c(.long PPC_ERATILX(t, a, b))
#define PPC_STR_ERATIVAX(s, a, b) \
				stringify_in_c(.long PPC_ERATIVAX(s, a, b))
#define PPC_STR_ERATSX(t, a, w) stringify_in_c(.long PPC_ERATSX(t, a, w))
#define PPC_STR_ERATSX_DOT(t, a, w) \
				stringify_in_c(.long PPC_ERATSX_DOT(t, a, w))
#define PPC_STR_SLBFEE_DOT(t, b)stringify_in_c(.long PPC_SLBFEE_DOT(t, b))
#define __PPC_STR_SLBFEE_DOT(t, b) \
				stringify_in_c(.long __PPC_SLBFEE_DOT(t, b))
#define PPC_STR_ICBT(c, a, b)   stringify_in_c(.long PPC_ICBT(c, a, b))
#define PPC_STR_LBZCIX(t, a, b) stringify_in_c(.long LBZCIX(t, a, b))
#define PPC_STR_STBCIX(s, a, b) stringify_in_c(.long STBCIX(s, a, b))

#define PPC_STR_STXVD2X(s, a, b)stringify_in_c(.long STXVD2X(s, a, b))
#define PPC_STR_LXVD2X(s, a, b) stringify_in_c(.long LXVD2X(s, a, b))
#define PPC_STR_MFVRD(a, t)     stringify_in_c(.long MFVRD(a, t))
#define PPC_STR_MTVRD(t, a)     stringify_in_c(.long MTVRD(t, a))
#define PPC_STR_VPMSUMW(t, a, b)stringify_in_c(.long VPMSUMW(t, a, b))
#define PPC_STR_VPMSUMD(t, a, b)stringify_in_c(.long VPMSUMD(t, a, b))
#define PPC_STR_XXLOR(t, a, b)  stringify_in_c(.long XXLOR(t, a, b))
#define PPC_STR_XXSWAPD(t, a)   stringify_in_c(.long XXSWAPD(t, a))
#define PPC_STR_XVCPSGNDP(t, a, b) \
				stringify_in_c(.long XVCPSGNDP(t, a, b))

#define PPC_STR_VPERMXOR(vrt, vra, vrb, vrc) \
				stringify_in_c(.long VPERMXOR(vrt, vra,	\
							vrb, vrc))

#define PPC_STR_NAP             stringify_in_c(.long PPC_NAP)
#define PPC_STR_SLEEP           stringify_in_c(.long PPC_SLEEP)
#define PPC_STR_WINKLE          stringify_in_c(.long PPC_WINKLE)

#define PPC_STR_STOP            stringify_in_c(.long PPC_STOP)

/* BHRB instructions */
#define PPC_STR_CLRBHRB         stringify_in_c(.long PPC_CLRBHRB)
#define PPC_STR_MFBHRBE(r, n)   stringify_in_c(.long PPC_MFBHRBE(r, n))

/* Transactional memory instructions */
#define PPC_STR_TRECHKPT        stringify_in_c(.long TRECHKPT)
#define PPC_STR_TRECLAIM(r)     stringify_in_c(.long TRECLAIM(r))
#define PPC_STR_TABORT(r)       stringify_in_c(.long TABORT(r))

/* book3e thread control instructions */
#define PPC_STR_MTTMR(tmr, r)   stringify_in_c(.long MTTMR(tmr, r))
#define PPC_STR_MFTMR(tmr, r)   stringify_in_c(.long MFTMR(tmr, r))

/* Coprocessor instructions */
#define PPC_STR_ICSWX(s, a, b)  stringify_in_c(.long PPC_ICSWX(s, a, b))
#define PPC_STR_ICSWEPX(s, a, b)stringify_in_c(.long PPC_ICSWEPX(s, a, b))

#define PPC_STR_SLBIA(IH)       stringify_in_c(.long PPC_SLBIA(IH))

#define PPC_STR_ISA_3_0_INVALIDATE_ERAT     PPC_STR_SLBIA(7)
#define PPC_STR_RADIX_INVALIDATE_ERAT_USER  PPC_STR_SLBIA(3)
#define PPC_STR_RADIX_INVALIDATE_ERAT_GUEST PPC_STR_SLBIA(6)

#define PPC_STR_VCMPEQUD_RC(vrt, vra, vrb) \
				stringify_in_c(.long VCMPEQUD_RC(vrt, \
								vra, vrb))

#define PPC_STR_VCMPEQUB_RC(vrt, vra, vrb) \
					stringify_in_c(.long VCMPEQUB_RC(vrt, \
								vra, vrb))
#endif /* _ASM_POWERPC_PPC_OPCODE_RAW_H */
