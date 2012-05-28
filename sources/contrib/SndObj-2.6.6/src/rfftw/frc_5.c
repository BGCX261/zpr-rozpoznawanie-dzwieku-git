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
/* Generated on Sun Nov  7 20:43:53 EST 1999 */

#include <fftw-int.h>
#include <fftw.h>

/* Generated by: ./genfft -magic-alignment-check -magic-twiddle-load-all -magic-variables 4 -magic-loopi -real2hc 5 */

/*
 * This function contains 12 FP additions, 6 FP multiplications,
 * (or, 9 additions, 3 multiplications, 3 fused multiply/add),
 * 12 stack variables, and 10 memory accesses
 */
static const fftw_real K250000000 = FFTW_KONST(+0.250000000000000000000000000000000000000000000);
static const fftw_real K559016994 = FFTW_KONST(+0.559016994374947424102293417182819058860154590);
static const fftw_real K587785252 = FFTW_KONST(+0.587785252292473129168705954639072768597652438);
static const fftw_real K951056516 = FFTW_KONST(+0.951056516295153572116439333379382143405698634);

/*
 * Generator Id's : 
 * $Id: frc_5.c,v 1.1.1.1 2006/05/12 15:14:56 veplaini Exp $
 * $Id: frc_5.c,v 1.1.1.1 2006/05/12 15:14:56 veplaini Exp $
 * $Id: frc_5.c,v 1.1.1.1 2006/05/12 15:14:56 veplaini Exp $
 */

void fftw_real2hc_5(const fftw_real *input, fftw_real *real_output, fftw_real *imag_output, int istride, int real_ostride, int imag_ostride)
{
     fftw_real tmp10;
     fftw_real tmp7;
     fftw_real tmp8;
     fftw_real tmp3;
     fftw_real tmp11;
     fftw_real tmp6;
     fftw_real tmp9;
     fftw_real tmp12;
     ASSERT_ALIGNED_DOUBLE;
     tmp10 = input[0];
     {
	  fftw_real tmp1;
	  fftw_real tmp2;
	  fftw_real tmp4;
	  fftw_real tmp5;
	  ASSERT_ALIGNED_DOUBLE;
	  tmp1 = input[istride];
	  tmp2 = input[4 * istride];
	  tmp7 = tmp1 + tmp2;
	  tmp4 = input[2 * istride];
	  tmp5 = input[3 * istride];
	  tmp8 = tmp4 + tmp5;
	  tmp3 = tmp1 - tmp2;
	  tmp11 = tmp7 + tmp8;
	  tmp6 = tmp4 - tmp5;
     }
     imag_output[imag_ostride] = -((K951056516 * tmp3) + (K587785252 * tmp6));
     imag_output[2 * imag_ostride] = (K951056516 * tmp6) - (K587785252 * tmp3);
     real_output[0] = tmp10 + tmp11;
     tmp9 = K559016994 * (tmp7 - tmp8);
     tmp12 = tmp10 - (K250000000 * tmp11);
     real_output[real_ostride] = tmp9 + tmp12;
     real_output[2 * real_ostride] = tmp12 - tmp9;
}

fftw_codelet_desc fftw_real2hc_5_desc =
{
     "fftw_real2hc_5",
     (void (*)()) fftw_real2hc_5,
     5,
     FFTW_FORWARD,
     FFTW_REAL2HC,
     112,
     0,
     (const int *) 0,
};
