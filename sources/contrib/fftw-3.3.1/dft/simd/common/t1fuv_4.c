/*
 * Copyright (c) 2003, 2007-11 Matteo Frigo
 * Copyright (c) 2003, 2007-11 Massachusetts Institute of Technology
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Tue Feb 21 19:01:04 EST 2012 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -n 4 -name t1fuv_4 -include t1fu.h */

/*
 * This function contains 11 FP additions, 8 FP multiplications,
 * (or, 9 additions, 6 multiplications, 2 fused multiply/add),
 * 13 stack variables, 0 constants, and 8 memory accesses
 */
#include "t1fu.h"

static void t1fuv_4(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 6)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 6), MAKE_VOLATILE_STRIDE(rs)) {
	       V T1, T7, T2, T5, T8, T3, T6;
	       T1 = LD(&(x[0]), ms, &(x[0]));
	       T7 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
	       T2 = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
	       T5 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
	       T8 = BYTWJ(&(W[TWVL * 4]), T7);
	       T3 = BYTWJ(&(W[TWVL * 2]), T2);
	       T6 = BYTWJ(&(W[0]), T5);
	       {
		    V Ta, T4, Tb, T9;
		    Ta = VADD(T1, T3);
		    T4 = VSUB(T1, T3);
		    Tb = VADD(T6, T8);
		    T9 = VSUB(T6, T8);
		    ST(&(x[0]), VADD(Ta, Tb), ms, &(x[0]));
		    ST(&(x[WS(rs, 2)]), VSUB(Ta, Tb), ms, &(x[0]));
		    ST(&(x[WS(rs, 3)]), VFMAI(T9, T4), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 1)]), VFNMSI(T9, T4), ms, &(x[WS(rs, 1)]));
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 4, XSIMD_STRING("t1fuv_4"), twinstr, &GENUS, {9, 6, 2, 0}, 0, 0, 0 };

void XSIMD(codelet_t1fuv_4) (planner *p) {
     X(kdft_dit_register) (p, t1fuv_4, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_twiddle_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 4 -name t1fuv_4 -include t1fu.h */

/*
 * This function contains 11 FP additions, 6 FP multiplications,
 * (or, 11 additions, 6 multiplications, 0 fused multiply/add),
 * 13 stack variables, 0 constants, and 8 memory accesses
 */
#include "t1fu.h"

static void t1fuv_4(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 6)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 6), MAKE_VOLATILE_STRIDE(rs)) {
	       V T1, T8, T3, T6, T7, T2, T5;
	       T1 = LD(&(x[0]), ms, &(x[0]));
	       T7 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
	       T8 = BYTWJ(&(W[TWVL * 4]), T7);
	       T2 = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
	       T3 = BYTWJ(&(W[TWVL * 2]), T2);
	       T5 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
	       T6 = BYTWJ(&(W[0]), T5);
	       {
		    V T4, T9, Ta, Tb;
		    T4 = VSUB(T1, T3);
		    T9 = VBYI(VSUB(T6, T8));
		    ST(&(x[WS(rs, 1)]), VSUB(T4, T9), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 3)]), VADD(T4, T9), ms, &(x[WS(rs, 1)]));
		    Ta = VADD(T1, T3);
		    Tb = VADD(T6, T8);
		    ST(&(x[WS(rs, 2)]), VSUB(Ta, Tb), ms, &(x[0]));
		    ST(&(x[0]), VADD(Ta, Tb), ms, &(x[0]));
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 4, XSIMD_STRING("t1fuv_4"), twinstr, &GENUS, {11, 6, 0, 0}, 0, 0, 0 };

void XSIMD(codelet_t1fuv_4) (planner *p) {
     X(kdft_dit_register) (p, t1fuv_4, &desc);
}
#endif				/* HAVE_FMA */
