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
/* Generated on Tue Feb 21 19:00:14 EST 2012 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_notw_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -n 2 -name n1fv_2 -include n1f.h */

/*
 * This function contains 2 FP additions, 0 FP multiplications,
 * (or, 2 additions, 0 multiplications, 0 fused multiply/add),
 * 5 stack variables, 0 constants, and 4 memory accesses
 */
#include "n1f.h"

static void n1fv_2(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ri;
	  xo = ro;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(is), MAKE_VOLATILE_STRIDE(os)) {
	       V T1, T2;
	       T1 = LD(&(xi[0]), ivs, &(xi[0]));
	       T2 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
	       ST(&(xo[0]), VADD(T1, T2), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 1)]), VSUB(T1, T2), ovs, &(xo[WS(os, 1)]));
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 2, XSIMD_STRING("n1fv_2"), {2, 0, 0, 0}, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1fv_2) (planner *p) {
     X(kdft_register) (p, n1fv_2, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_notw_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 2 -name n1fv_2 -include n1f.h */

/*
 * This function contains 2 FP additions, 0 FP multiplications,
 * (or, 2 additions, 0 multiplications, 0 fused multiply/add),
 * 5 stack variables, 0 constants, and 4 memory accesses
 */
#include "n1f.h"

static void n1fv_2(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ri;
	  xo = ro;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(is), MAKE_VOLATILE_STRIDE(os)) {
	       V T1, T2;
	       T1 = LD(&(xi[0]), ivs, &(xi[0]));
	       T2 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
	       ST(&(xo[WS(os, 1)]), VSUB(T1, T2), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[0]), VADD(T1, T2), ovs, &(xo[0]));
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 2, XSIMD_STRING("n1fv_2"), {2, 0, 0, 0}, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1fv_2) (planner *p) {
     X(kdft_register) (p, n1fv_2, &desc);
}

#endif				/* HAVE_FMA */
