/*
 * Copyright (c) 1997-1999 Massachusetts Institute of Technology
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
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sun Nov  7 20:45:09 EST 1999 */

#include <fftw-int.h>
#include <fftw.h>

/* Generated by: ./genfft -magic-alignment-check -magic-twiddle-load-all -magic-variables 4 -magic-loopi -hc2hc-backward 3 */

/*
 * This function contains 24 FP additions, 16 FP multiplications,
 * (or, 16 additions, 8 multiplications, 8 fused multiply/add),
 * 15 stack variables, and 24 memory accesses
 */
static const fftw_real K500000000 = FFTW_KONST(+0.500000000000000000000000000000000000000000000);
static const fftw_real K866025403 = FFTW_KONST(+0.866025403784438646763723170752936183471402627);
static const fftw_real K2_000000000 = FFTW_KONST(+2.000000000000000000000000000000000000000000000);
static const fftw_real K1_732050807 = FFTW_KONST(+1.732050807568877293527446341505872366942805254);

/*
 * Generator Id's : 
 * $Id: fhb_3.c,v 1.1.1.1 2006/05/12 15:14:52 veplaini Exp $
 * $Id: fhb_3.c,v 1.1.1.1 2006/05/12 15:14:52 veplaini Exp $
 * $Id: fhb_3.c,v 1.1.1.1 2006/05/12 15:14:52 veplaini Exp $
 */

void fftw_hc2hc_backward_3(fftw_real *A, const fftw_complex *W, int iostride, int m, int dist)
{
     int i;
     fftw_real *X;
     fftw_real *Y;
     X = A;
     Y = A + (3 * iostride);
     {
	  fftw_real tmp30;
	  fftw_real tmp26;
	  fftw_real tmp27;
	  fftw_real tmp28;
	  fftw_real tmp29;
	  ASSERT_ALIGNED_DOUBLE;
	  tmp29 = Y[-iostride];
	  tmp30 = K1_732050807 * tmp29;
	  tmp26 = X[0];
	  tmp27 = X[iostride];
	  tmp28 = tmp26 - tmp27;
	  X[0] = tmp26 + (K2_000000000 * tmp27);
	  X[iostride] = tmp28 - tmp30;
	  X[2 * iostride] = tmp28 + tmp30;
     }
     X = X + dist;
     Y = Y - dist;
     for (i = 2; i < m; i = i + 2, X = X + dist, Y = Y - dist, W = W + 2) {
	  fftw_real tmp6;
	  fftw_real tmp9;
	  fftw_real tmp15;
	  fftw_real tmp19;
	  fftw_real tmp10;
	  fftw_real tmp13;
	  fftw_real tmp16;
	  fftw_real tmp20;
	  ASSERT_ALIGNED_DOUBLE;
	  {
	       fftw_real tmp7;
	       fftw_real tmp8;
	       fftw_real tmp11;
	       fftw_real tmp12;
	       ASSERT_ALIGNED_DOUBLE;
	       tmp6 = X[0];
	       tmp7 = X[iostride];
	       tmp8 = Y[-2 * iostride];
	       tmp9 = tmp7 + tmp8;
	       tmp15 = K866025403 * (tmp7 - tmp8);
	       tmp19 = tmp6 - (K500000000 * tmp9);
	       tmp10 = Y[0];
	       tmp11 = Y[-iostride];
	       tmp12 = X[2 * iostride];
	       tmp13 = tmp11 - tmp12;
	       tmp16 = tmp10 - (K500000000 * tmp13);
	       tmp20 = K866025403 * (tmp11 + tmp12);
	  }
	  X[0] = tmp6 + tmp9;
	  {
	       fftw_real tmp23;
	       fftw_real tmp25;
	       fftw_real tmp22;
	       fftw_real tmp24;
	       ASSERT_ALIGNED_DOUBLE;
	       tmp23 = tmp16 - tmp15;
	       tmp25 = tmp19 + tmp20;
	       tmp22 = c_re(W[1]);
	       tmp24 = c_im(W[1]);
	       Y[0] = (tmp22 * tmp23) - (tmp24 * tmp25);
	       X[2 * iostride] = (tmp24 * tmp23) + (tmp22 * tmp25);
	  }
	  Y[-2 * iostride] = tmp10 + tmp13;
	  {
	       fftw_real tmp17;
	       fftw_real tmp21;
	       fftw_real tmp14;
	       fftw_real tmp18;
	       ASSERT_ALIGNED_DOUBLE;
	       tmp17 = tmp15 + tmp16;
	       tmp21 = tmp19 - tmp20;
	       tmp14 = c_re(W[0]);
	       tmp18 = c_im(W[0]);
	       Y[-iostride] = (tmp14 * tmp17) - (tmp18 * tmp21);
	       X[iostride] = (tmp18 * tmp17) + (tmp14 * tmp21);
	  }
     }
     if (i == m) {
	  fftw_real tmp5;
	  fftw_real tmp1;
	  fftw_real tmp2;
	  fftw_real tmp3;
	  fftw_real tmp4;
	  ASSERT_ALIGNED_DOUBLE;
	  tmp4 = Y[0];
	  tmp5 = K1_732050807 * tmp4;
	  tmp1 = X[iostride];
	  tmp2 = X[0];
	  tmp3 = tmp2 - tmp1;
	  X[0] = tmp1 + (K2_000000000 * tmp2);
	  X[2 * iostride] = -(tmp3 + tmp5);
	  X[iostride] = tmp3 - tmp5;
     }
}

static const int twiddle_order[] =
{1, 2};
fftw_codelet_desc fftw_hc2hc_backward_3_desc =
{
     "fftw_hc2hc_backward_3",
     (void (*)()) fftw_hc2hc_backward_3,
     3,
     FFTW_BACKWARD,
     FFTW_HC2HC,
     80,
     2,
     twiddle_order,
};
