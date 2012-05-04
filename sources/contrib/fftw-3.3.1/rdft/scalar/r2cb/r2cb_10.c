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
/* Generated on Tue Feb 21 19:03:19 EST 2012 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_r2cb.native -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -sign 1 -n 10 -name r2cb_10 -include r2cb.h */

/*
 * This function contains 34 FP additions, 20 FP multiplications,
 * (or, 14 additions, 0 multiplications, 20 fused multiply/add),
 * 30 stack variables, 5 constants, and 20 memory accesses
 */
#include "r2cb.h"

static void r2cb_10(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP1_902113032, +1.902113032590307144232878666758764286811397268);
     DK(KP1_118033988, +1.118033988749894848204586834365638117720309180);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP618033988, +0.618033988749894848204586834365638117720309180);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(rs), MAKE_VOLATILE_STRIDE(csr), MAKE_VOLATILE_STRIDE(csi)) {
	       E Tb, T3, Tc, T6, Tq, To, Ty, Tw, Td, T9;
	       {
		    E Tu, Tn, T7, Tv, Tk, T8;
		    {
			 E T1, T2, Tl, Tm;
			 T1 = Cr[0];
			 T2 = Cr[WS(csr, 5)];
			 Tl = Ci[WS(csi, 2)];
			 Tm = Ci[WS(csi, 3)];
			 {
			      E Ti, Tj, T4, T5;
			      Ti = Ci[WS(csi, 4)];
			      Tb = T1 + T2;
			      T3 = T1 - T2;
			      Tu = Tl + Tm;
			      Tn = Tl - Tm;
			      Tj = Ci[WS(csi, 1)];
			      T4 = Cr[WS(csr, 2)];
			      T5 = Cr[WS(csr, 3)];
			      T7 = Cr[WS(csr, 4)];
			      Tv = Ti + Tj;
			      Tk = Ti - Tj;
			      Tc = T4 + T5;
			      T6 = T4 - T5;
			      T8 = Cr[WS(csr, 1)];
			 }
		    }
		    Tq = FMA(KP618033988, Tk, Tn);
		    To = FNMS(KP618033988, Tn, Tk);
		    Ty = FNMS(KP618033988, Tu, Tv);
		    Tw = FMA(KP618033988, Tv, Tu);
		    Td = T7 + T8;
		    T9 = T7 - T8;
	       }
	       {
		    E Te, Tg, Ta, Ts, Tf, Tr;
		    Te = Tc + Td;
		    Tg = Tc - Td;
		    Ta = T6 + T9;
		    Ts = T6 - T9;
		    Tf = FNMS(KP500000000, Te, Tb);
		    R0[0] = FMA(KP2_000000000, Te, Tb);
		    Tr = FNMS(KP500000000, Ta, T3);
		    R1[WS(rs, 2)] = FMA(KP2_000000000, Ta, T3);
		    {
			 E Th, Tp, Tt, Tx;
			 Th = FNMS(KP1_118033988, Tg, Tf);
			 Tp = FMA(KP1_118033988, Tg, Tf);
			 Tt = FMA(KP1_118033988, Ts, Tr);
			 Tx = FNMS(KP1_118033988, Ts, Tr);
			 R0[WS(rs, 3)] = FNMS(KP1_902113032, Tq, Tp);
			 R0[WS(rs, 2)] = FMA(KP1_902113032, Tq, Tp);
			 R0[WS(rs, 1)] = FMA(KP1_902113032, To, Th);
			 R0[WS(rs, 4)] = FNMS(KP1_902113032, To, Th);
			 R1[WS(rs, 1)] = FNMS(KP1_902113032, Ty, Tx);
			 R1[WS(rs, 3)] = FMA(KP1_902113032, Ty, Tx);
			 R1[WS(rs, 4)] = FMA(KP1_902113032, Tw, Tt);
			 R1[0] = FNMS(KP1_902113032, Tw, Tt);
		    }
	       }
	  }
     }
}

static const kr2c_desc desc = { 10, "r2cb_10", {14, 0, 20, 0}, &GENUS };

void X(codelet_r2cb_10) (planner *p) {
     X(kr2c_register) (p, r2cb_10, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_r2cb.native -compact -variables 4 -pipeline-latency 4 -sign 1 -n 10 -name r2cb_10 -include r2cb.h */

/*
 * This function contains 34 FP additions, 14 FP multiplications,
 * (or, 26 additions, 6 multiplications, 8 fused multiply/add),
 * 26 stack variables, 5 constants, and 20 memory accesses
 */
#include "r2cb.h"

static void r2cb_10(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP1_902113032, +1.902113032590307144232878666758764286811397268);
     DK(KP1_175570504, +1.175570504584946258337411909278145537195304875);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     DK(KP1_118033988, +1.118033988749894848204586834365638117720309180);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(rs), MAKE_VOLATILE_STRIDE(csr), MAKE_VOLATILE_STRIDE(csi)) {
	       E T3, Tb, Tn, Tv, Tk, Tu, Ta, Ts, Te, Tg, Ti, Tj;
	       {
		    E T1, T2, Tl, Tm;
		    T1 = Cr[0];
		    T2 = Cr[WS(csr, 5)];
		    T3 = T1 - T2;
		    Tb = T1 + T2;
		    Tl = Ci[WS(csi, 4)];
		    Tm = Ci[WS(csi, 1)];
		    Tn = Tl - Tm;
		    Tv = Tl + Tm;
	       }
	       Ti = Ci[WS(csi, 2)];
	       Tj = Ci[WS(csi, 3)];
	       Tk = Ti - Tj;
	       Tu = Ti + Tj;
	       {
		    E T6, Tc, T9, Td;
		    {
			 E T4, T5, T7, T8;
			 T4 = Cr[WS(csr, 2)];
			 T5 = Cr[WS(csr, 3)];
			 T6 = T4 - T5;
			 Tc = T4 + T5;
			 T7 = Cr[WS(csr, 4)];
			 T8 = Cr[WS(csr, 1)];
			 T9 = T7 - T8;
			 Td = T7 + T8;
		    }
		    Ta = T6 + T9;
		    Ts = KP1_118033988 * (T6 - T9);
		    Te = Tc + Td;
		    Tg = KP1_118033988 * (Tc - Td);
	       }
	       R1[WS(rs, 2)] = FMA(KP2_000000000, Ta, T3);
	       R0[0] = FMA(KP2_000000000, Te, Tb);
	       {
		    E To, Tq, Th, Tp, Tf;
		    To = FNMS(KP1_902113032, Tn, KP1_175570504 * Tk);
		    Tq = FMA(KP1_902113032, Tk, KP1_175570504 * Tn);
		    Tf = FNMS(KP500000000, Te, Tb);
		    Th = Tf - Tg;
		    Tp = Tg + Tf;
		    R0[WS(rs, 1)] = Th - To;
		    R0[WS(rs, 2)] = Tp + Tq;
		    R0[WS(rs, 4)] = Th + To;
		    R0[WS(rs, 3)] = Tp - Tq;
	       }
	       {
		    E Tw, Ty, Tt, Tx, Tr;
		    Tw = FNMS(KP1_902113032, Tv, KP1_175570504 * Tu);
		    Ty = FMA(KP1_902113032, Tu, KP1_175570504 * Tv);
		    Tr = FNMS(KP500000000, Ta, T3);
		    Tt = Tr - Ts;
		    Tx = Ts + Tr;
		    R1[WS(rs, 3)] = Tt - Tw;
		    R1[WS(rs, 4)] = Tx + Ty;
		    R1[WS(rs, 1)] = Tt + Tw;
		    R1[0] = Tx - Ty;
	       }
	  }
     }
}

static const kr2c_desc desc = { 10, "r2cb_10", {26, 6, 8, 0}, &GENUS };

void X(codelet_r2cb_10) (planner *p) {
     X(kr2c_register) (p, r2cb_10, &desc);
}

#endif				/* HAVE_FMA */
