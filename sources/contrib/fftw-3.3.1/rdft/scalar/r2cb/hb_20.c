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
/* Generated on Tue Feb 21 19:03:30 EST 2012 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_hc2hc.native -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -sign 1 -n 20 -dif -name hb_20 -include hb.h */

/*
 * This function contains 246 FP additions, 148 FP multiplications,
 * (or, 136 additions, 38 multiplications, 110 fused multiply/add),
 * 101 stack variables, 4 constants, and 80 memory accesses
 */
#include "hb.h"

static void hb_20(R *cr, R *ci, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 38); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 38, MAKE_VOLATILE_STRIDE(rs)) {
	       E T1T, T1Q, T1P;
	       {
		    E T2W, T4e, T7, TE, T3z, T4z, T1t, T2l, T3a, T3G, T13, T33, T3H, T1i, T2g;
		    E T4H, T4G, T2d, T1B, T4u, T4B, T4A, T4r, T1A, T2s, T3l, T2t, T3s, T2o, T2q;
		    E T1w, T1y, TC, T29, T3E, T3C, T4n, T4l, TN, TL;
		    {
			 E T4, T2U, T3, T2V, T1s, T5, T1n, T1o;
			 {
			      E T1, T2, T1q, T1r;
			      T1 = cr[0];
			      T2 = ci[WS(rs, 9)];
			      T1q = ci[WS(rs, 14)];
			      T1r = cr[WS(rs, 15)];
			      T4 = cr[WS(rs, 5)];
			      T2U = T1 - T2;
			      T3 = T1 + T2;
			      T2V = T1q + T1r;
			      T1s = T1q - T1r;
			      T5 = ci[WS(rs, 4)];
			      T1n = ci[WS(rs, 19)];
			      T1o = cr[WS(rs, 10)];
			 }
			 {
			      E T3y, T6, T3x, T1p;
			      T2W = T2U + T2V;
			      T4e = T2U - T2V;
			      T3y = T4 - T5;
			      T6 = T4 + T5;
			      T3x = T1n + T1o;
			      T1p = T1n - T1o;
			      T7 = T3 + T6;
			      TE = T3 - T6;
			      T3z = T3x - T3y;
			      T4z = T3y + T3x;
			      T1t = T1p - T1s;
			      T2l = T1p + T1s;
			 }
		    }
		    {
			 E T2Z, T4f, Te, TF, T3o, T4p, T1a, T2b, TJ, TA, T4t, T3k, T4j, T39, T2f;
			 E T12, T32, T4g, Tl, TG, T3r, T4q, T1h, T2c, T36, T4i, Tt, TI, T3h, T4s;
			 E TV, T2e;
			 {
			      E Tb, T2X, Ta, T2Y, T19, Tc, T14, T15;
			      {
				   E T8, T9, T17, T18;
				   T8 = cr[WS(rs, 4)];
				   T9 = ci[WS(rs, 5)];
				   T17 = ci[WS(rs, 10)];
				   T18 = cr[WS(rs, 19)];
				   Tb = cr[WS(rs, 9)];
				   T2X = T8 - T9;
				   Ta = T8 + T9;
				   T2Y = T17 + T18;
				   T19 = T17 - T18;
				   Tc = ci[0];
				   T14 = ci[WS(rs, 15)];
				   T15 = cr[WS(rs, 14)];
			      }
			      {
				   E T3n, Td, T3m, T16;
				   T2Z = T2X + T2Y;
				   T4f = T2X - T2Y;
				   T3n = Tb - Tc;
				   Td = Tb + Tc;
				   T3m = T14 + T15;
				   T16 = T14 - T15;
				   Te = Ta + Td;
				   TF = Ta - Td;
				   T3o = T3m - T3n;
				   T4p = T3n + T3m;
				   T1a = T16 - T19;
				   T2b = T16 + T19;
			      }
			 }
			 {
			      E TW, T37, Tw, T3i, Tz, TX, TZ, T10;
			      {
				   E Tu, Tv, Tx, Ty;
				   Tu = ci[WS(rs, 7)];
				   Tv = cr[WS(rs, 2)];
				   Tx = ci[WS(rs, 2)];
				   Ty = cr[WS(rs, 7)];
				   TW = ci[WS(rs, 17)];
				   T37 = Tu - Tv;
				   Tw = Tu + Tv;
				   T3i = Tx - Ty;
				   Tz = Tx + Ty;
				   TX = cr[WS(rs, 12)];
				   TZ = ci[WS(rs, 12)];
				   T10 = cr[WS(rs, 17)];
			      }
			      {
				   E TY, T38, T11, T3j;
				   TJ = Tw - Tz;
				   TA = Tw + Tz;
				   T3j = TW + TX;
				   TY = TW - TX;
				   T38 = TZ + T10;
				   T11 = TZ - T10;
				   T4t = T3i - T3j;
				   T3k = T3i + T3j;
				   T4j = T37 + T38;
				   T39 = T37 - T38;
				   T2f = TY + T11;
				   T12 = TY - T11;
			      }
			 }
			 {
			      E Ti, T30, Th, T31, T1g, Tj, T1b, T1c;
			      {
				   E Tf, Tg, T1e, T1f;
				   Tf = ci[WS(rs, 3)];
				   Tg = cr[WS(rs, 6)];
				   T1e = ci[WS(rs, 18)];
				   T1f = cr[WS(rs, 11)];
				   Ti = cr[WS(rs, 1)];
				   T30 = Tf - Tg;
				   Th = Tf + Tg;
				   T31 = T1e + T1f;
				   T1g = T1e - T1f;
				   Tj = ci[WS(rs, 8)];
				   T1b = ci[WS(rs, 13)];
				   T1c = cr[WS(rs, 16)];
			      }
			      {
				   E T3p, Tk, T3q, T1d;
				   T32 = T30 + T31;
				   T4g = T30 - T31;
				   T3p = Ti - Tj;
				   Tk = Ti + Tj;
				   T3q = T1b + T1c;
				   T1d = T1b - T1c;
				   Tl = Th + Tk;
				   TG = Th - Tk;
				   T3r = T3p + T3q;
				   T4q = T3p - T3q;
				   T1h = T1d - T1g;
				   T2c = T1d + T1g;
			      }
			 }
			 {
			      E Tq, T34, Tp, T35, TU, Tr, TP, TQ;
			      {
				   E Tn, To, TS, TT;
				   Tn = cr[WS(rs, 8)];
				   To = ci[WS(rs, 1)];
				   TS = ci[WS(rs, 16)];
				   TT = cr[WS(rs, 13)];
				   Tq = ci[WS(rs, 6)];
				   T34 = Tn - To;
				   Tp = Tn + To;
				   T35 = TS + TT;
				   TU = TS - TT;
				   Tr = cr[WS(rs, 3)];
				   TP = ci[WS(rs, 11)];
				   TQ = cr[WS(rs, 18)];
			      }
			      {
				   E T3g, Ts, T3f, TR;
				   T36 = T34 - T35;
				   T4i = T34 + T35;
				   T3g = Tq - Tr;
				   Ts = Tq + Tr;
				   T3f = TP + TQ;
				   TR = TP - TQ;
				   Tt = Tp + Ts;
				   TI = Tp - Ts;
				   T3h = T3f - T3g;
				   T4s = T3g + T3f;
				   TV = TR - TU;
				   T2e = TR + TU;
			      }
			 }
			 {
			      E T1v, T1u, T2n, T4k, T4h, T2m, TH, TK;
			      T3a = T36 + T39;
			      T3G = T36 - T39;
			      T13 = TV - T12;
			      T1v = TV + T12;
			      T33 = T2Z + T32;
			      T3H = T2Z - T32;
			      T1i = T1a - T1h;
			      T1u = T1a + T1h;
			      T2n = T2e + T2f;
			      T2g = T2e - T2f;
			      T4H = T4i - T4j;
			      T4k = T4i + T4j;
			      T4h = T4f + T4g;
			      T4G = T4f - T4g;
			      T2d = T2b - T2c;
			      T2m = T2b + T2c;
			      TH = TF + TG;
			      T1B = TF - TG;
			      T4u = T4s - T4t;
			      T4B = T4s + T4t;
			      T4A = T4p + T4q;
			      T4r = T4p - T4q;
			      T1A = TI - TJ;
			      TK = TI + TJ;
			      {
				   E Tm, T3B, TB, T3A;
				   Tm = Te + Tl;
				   T2s = Te - Tl;
				   T3l = T3h + T3k;
				   T3B = T3h - T3k;
				   TB = Tt + TA;
				   T2t = Tt - TA;
				   T3s = T3o + T3r;
				   T3A = T3o - T3r;
				   T2o = T2m + T2n;
				   T2q = T2m - T2n;
				   T1w = T1u + T1v;
				   T1y = T1u - T1v;
				   TC = Tm + TB;
				   T29 = Tm - TB;
				   T3E = T3A - T3B;
				   T3C = T3A + T3B;
				   T4n = T4h - T4k;
				   T4l = T4h + T4k;
				   TN = TH - TK;
				   TL = TH + TK;
			      }
			 }
		    }
		    {
			 E T3d, T3b, T4E, T1x, TM, T4m, T58, T5b, T4D, T5a, T5c, T59, T4C;
			 cr[0] = T7 + TC;
			 T3d = T33 - T3a;
			 T3b = T33 + T3a;
			 T4E = T4A - T4B;
			 T4C = T4A + T4B;
			 ci[0] = T2l + T2o;
			 {
			      E T25, T22, T21, T24, T23, T26, T57;
			      T1x = FNMS(KP250000000, T1w, T1t);
			      T25 = T1t + T1w;
			      T22 = TE + TL;
			      TM = FNMS(KP250000000, TL, TE);
			      T21 = W[18];
			      T24 = W[19];
			      T4m = FNMS(KP250000000, T4l, T4e);
			      T58 = T4e + T4l;
			      T5b = T4z + T4C;
			      T4D = FNMS(KP250000000, T4C, T4z);
			      T23 = T21 * T22;
			      T26 = T24 * T22;
			      T57 = W[8];
			      T5a = W[9];
			      cr[WS(rs, 10)] = FNMS(T24, T25, T23);
			      ci[WS(rs, 10)] = FMA(T21, T25, T26);
			      T5c = T57 * T5b;
			      T59 = T57 * T58;
			 }
			 {
			      E T3U, T3Z, T3W, T40, T3V;
			      {
				   E T3c, T48, T4b, T3D, T47, T4a;
				   T3c = FNMS(KP250000000, T3b, T2W);
				   T48 = T2W + T3b;
				   T4b = T3z + T3C;
				   T3D = FNMS(KP250000000, T3C, T3z);
				   ci[WS(rs, 5)] = FMA(T5a, T58, T5c);
				   cr[WS(rs, 5)] = FNMS(T5a, T5b, T59);
				   T47 = W[28];
				   T4a = W[29];
				   {
					E T3I, T3Y, T42, T3u, T3M, T3X, T3F;
					{
					     E T3T, T3t, T4c, T49, T3e, T3S;
					     T3T = FMA(KP618033988, T3l, T3s);
					     T3t = FNMS(KP618033988, T3s, T3l);
					     T4c = T47 * T4b;
					     T49 = T47 * T48;
					     T3I = FNMS(KP618033988, T3H, T3G);
					     T3Y = FMA(KP618033988, T3G, T3H);
					     ci[WS(rs, 15)] = FMA(T4a, T48, T4c);
					     cr[WS(rs, 15)] = FNMS(T4a, T4b, T49);
					     T3e = FNMS(KP559016994, T3d, T3c);
					     T3S = FMA(KP559016994, T3d, T3c);
					     T42 = FMA(KP951056516, T3T, T3S);
					     T3U = FNMS(KP951056516, T3T, T3S);
					     T3u = FNMS(KP951056516, T3t, T3e);
					     T3M = FMA(KP951056516, T3t, T3e);
					     T3X = FMA(KP559016994, T3E, T3D);
					     T3F = FNMS(KP559016994, T3E, T3D);
					}
					{
					     E T3P, T45, T44, T46, T43;
					     {
						  E T3w, T3J, T3v, T3K, T2T, T41;
						  T2T = W[4];
						  T3w = W[5];
						  T3J = FMA(KP951056516, T3I, T3F);
						  T3P = FNMS(KP951056516, T3I, T3F);
						  T45 = FNMS(KP951056516, T3Y, T3X);
						  T3Z = FMA(KP951056516, T3Y, T3X);
						  T3v = T2T * T3u;
						  T3K = T2T * T3J;
						  T41 = W[36];
						  T44 = W[37];
						  cr[WS(rs, 3)] = FNMS(T3w, T3J, T3v);
						  ci[WS(rs, 3)] = FMA(T3w, T3u, T3K);
						  T46 = T41 * T45;
						  T43 = T41 * T42;
					     }
					     {
						  E T3O, T3Q, T3N, T3L, T3R;
						  T3L = W[12];
						  T3O = W[13];
						  ci[WS(rs, 19)] = FMA(T44, T42, T46);
						  cr[WS(rs, 19)] = FNMS(T44, T45, T43);
						  T3Q = T3L * T3P;
						  T3N = T3L * T3M;
						  T3R = W[20];
						  T3W = W[21];
						  ci[WS(rs, 7)] = FMA(T3O, T3M, T3Q);
						  cr[WS(rs, 7)] = FNMS(T3O, T3P, T3N);
						  T40 = T3R * T3Z;
						  T3V = T3R * T3U;
					     }
					}
				   }
			      }
			      {
				   E T4U, T4Z, T4W, T50, T4V, T2L, T2I, T2H;
				   {
					E T4T, T4v, T4I, T4Y, T4o, T4S;
					T4T = FNMS(KP618033988, T4r, T4u);
					T4v = FMA(KP618033988, T4u, T4r);
					ci[WS(rs, 11)] = FMA(T3W, T3U, T40);
					cr[WS(rs, 11)] = FNMS(T3W, T3Z, T3V);
					T4I = FMA(KP618033988, T4H, T4G);
					T4Y = FNMS(KP618033988, T4G, T4H);
					T4o = FMA(KP559016994, T4n, T4m);
					T4S = FNMS(KP559016994, T4n, T4m);
					{
					     E T52, T4M, T55, T4P, T54, T56, T53;
					     {
						  E T4d, T4w, T4J, T4x, T4y, T4X, T4F, T51, T4K;
						  T4d = W[0];
						  T4X = FNMS(KP559016994, T4E, T4D);
						  T4F = FMA(KP559016994, T4E, T4D);
						  T4U = FNMS(KP951056516, T4T, T4S);
						  T52 = FMA(KP951056516, T4T, T4S);
						  T4M = FMA(KP951056516, T4v, T4o);
						  T4w = FNMS(KP951056516, T4v, T4o);
						  T4Z = FMA(KP951056516, T4Y, T4X);
						  T55 = FNMS(KP951056516, T4Y, T4X);
						  T4P = FNMS(KP951056516, T4I, T4F);
						  T4J = FMA(KP951056516, T4I, T4F);
						  T4x = T4d * T4w;
						  T4y = W[1];
						  T51 = W[32];
						  T4K = T4d * T4J;
						  T54 = W[33];
						  cr[WS(rs, 1)] = FNMS(T4y, T4J, T4x);
						  T56 = T51 * T55;
						  T53 = T51 * T52;
						  ci[WS(rs, 1)] = FMA(T4y, T4w, T4K);
					     }
					     {
						  E T4O, T4Q, T4N, T4L, T4R;
						  T4L = W[16];
						  ci[WS(rs, 17)] = FMA(T54, T52, T56);
						  cr[WS(rs, 17)] = FNMS(T54, T55, T53);
						  T4O = W[17];
						  T4Q = T4L * T4P;
						  T4N = T4L * T4M;
						  T4R = W[24];
						  T4W = W[25];
						  ci[WS(rs, 9)] = FMA(T4O, T4M, T4Q);
						  cr[WS(rs, 9)] = FNMS(T4O, T4P, T4N);
						  T50 = T4R * T4Z;
						  T4V = T4R * T4U;
					     }
					}
				   }
				   {
					E T2K, T2u, T2F, T2h, T28, T2J, T2r, T2p;
					T2K = FNMS(KP618033988, T2s, T2t);
					T2u = FMA(KP618033988, T2t, T2s);
					ci[WS(rs, 13)] = FMA(T4W, T4U, T50);
					cr[WS(rs, 13)] = FNMS(T4W, T4Z, T4V);
					T2p = FNMS(KP250000000, T2o, T2l);
					T2F = FNMS(KP618033988, T2d, T2g);
					T2h = FMA(KP618033988, T2g, T2d);
					T28 = FNMS(KP250000000, TC, T7);
					T2J = FNMS(KP559016994, T2q, T2p);
					T2r = FMA(KP559016994, T2q, T2p);
					{
					     E T2B, T2G, T2y, T2R, T2Q, T2P, T2A, T2x;
					     {
						  E T2k, T2v, T27, T2O, T2i, T2a, T2E;
						  T2k = W[7];
						  T2a = FMA(KP559016994, T29, T28);
						  T2E = FNMS(KP559016994, T29, T28);
						  T2B = FMA(KP951056516, T2u, T2r);
						  T2v = FNMS(KP951056516, T2u, T2r);
						  T27 = W[6];
						  T2O = FMA(KP951056516, T2F, T2E);
						  T2G = FNMS(KP951056516, T2F, T2E);
						  T2i = FMA(KP951056516, T2h, T2a);
						  T2y = FNMS(KP951056516, T2h, T2a);
						  {
						       E T2N, T2j, T2w, T2S;
						       T2L = FMA(KP951056516, T2K, T2J);
						       T2R = FNMS(KP951056516, T2K, T2J);
						       T2Q = W[23];
						       T2N = W[22];
						       T2j = T27 * T2i;
						       T2w = T2k * T2i;
						       T2S = T2Q * T2O;
						       T2P = T2N * T2O;
						       cr[WS(rs, 4)] = FNMS(T2k, T2v, T2j);
						       ci[WS(rs, 4)] = FMA(T27, T2v, T2w);
						       ci[WS(rs, 12)] = FMA(T2N, T2R, T2S);
						  }
					     }
					     cr[WS(rs, 12)] = FNMS(T2Q, T2R, T2P);
					     T2A = W[31];
					     T2x = W[30];
					     {
						  E T2D, T2M, T2C, T2z;
						  T2I = W[15];
						  T2C = T2A * T2y;
						  T2z = T2x * T2y;
						  T2D = W[14];
						  T2M = T2I * T2G;
						  ci[WS(rs, 16)] = FMA(T2x, T2B, T2C);
						  cr[WS(rs, 16)] = FNMS(T2A, T2B, T2z);
						  T2H = T2D * T2G;
						  ci[WS(rs, 8)] = FMA(T2D, T2L, T2M);
					     }
					}
				   }
				   {
					E T1S, T1C, T1j, T1N, T1z, T1R;
					T1S = FMA(KP618033988, T1A, T1B);
					T1C = FNMS(KP618033988, T1B, T1A);
					cr[WS(rs, 8)] = FNMS(T2I, T2L, T2H);
					T1j = FNMS(KP618033988, T1i, T13);
					T1N = FMA(KP618033988, T13, T1i);
					T1z = FNMS(KP559016994, T1y, T1x);
					T1R = FMA(KP559016994, T1y, T1x);
					{
					     E T1J, T1O, T1G, T1Z, T1Y, T1X, T1I, T1F;
					     {
						  E T1m, T1D, TD, T1W, T1k, T1M, TO;
						  T1m = W[3];
						  T1M = FMA(KP559016994, TN, TM);
						  TO = FNMS(KP559016994, TN, TM);
						  T1D = FNMS(KP951056516, T1C, T1z);
						  T1J = FMA(KP951056516, T1C, T1z);
						  TD = W[2];
						  T1O = FNMS(KP951056516, T1N, T1M);
						  T1W = FMA(KP951056516, T1N, T1M);
						  T1G = FNMS(KP951056516, T1j, TO);
						  T1k = FMA(KP951056516, T1j, TO);
						  {
						       E T1V, T1l, T1E, T20;
						       T1Z = FNMS(KP951056516, T1S, T1R);
						       T1T = FMA(KP951056516, T1S, T1R);
						       T1Y = W[27];
						       T1V = W[26];
						       T1l = TD * T1k;
						       T1E = T1m * T1k;
						       T20 = T1Y * T1W;
						       T1X = T1V * T1W;
						       cr[WS(rs, 2)] = FNMS(T1m, T1D, T1l);
						       ci[WS(rs, 2)] = FMA(TD, T1D, T1E);
						       ci[WS(rs, 14)] = FMA(T1V, T1Z, T20);
						  }
					     }
					     cr[WS(rs, 14)] = FNMS(T1Y, T1Z, T1X);
					     T1I = W[35];
					     T1F = W[34];
					     {
						  E T1L, T1U, T1K, T1H;
						  T1Q = W[11];
						  T1K = T1I * T1G;
						  T1H = T1F * T1G;
						  T1L = W[10];
						  T1U = T1Q * T1O;
						  ci[WS(rs, 18)] = FMA(T1F, T1J, T1K);
						  cr[WS(rs, 18)] = FNMS(T1I, T1J, T1H);
						  T1P = T1L * T1O;
						  ci[WS(rs, 6)] = FMA(T1L, T1T, T1U);
					     }
					}
				   }
			      }
			 }
		    }
	       }
	       cr[WS(rs, 6)] = FNMS(T1Q, T1T, T1P);
	  }
     }
}

static const tw_instr twinstr[] = {
     {TW_FULL, 1, 20},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 20, "hb_20", twinstr, &GENUS, {136, 38, 110, 0} };

void X(codelet_hb_20) (planner *p) {
     X(khc2hc_register) (p, hb_20, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_hc2hc.native -compact -variables 4 -pipeline-latency 4 -sign 1 -n 20 -dif -name hb_20 -include hb.h */

/*
 * This function contains 246 FP additions, 124 FP multiplications,
 * (or, 184 additions, 62 multiplications, 62 fused multiply/add),
 * 97 stack variables, 4 constants, and 80 memory accesses
 */
#include "hb.h"

static void hb_20(R *cr, R *ci, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 38); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 38, MAKE_VOLATILE_STRIDE(rs)) {
	       E T7, T3T, T49, TE, T1v, T2T, T3g, T2d, T13, T3n, T3o, T1i, T26, T4e, T4d;
	       E T23, T1n, T42, T3Z, T1m, T2h, T2I, T2i, T2P, T30, T37, T38, Tm, TB, TC;
	       E T46, T47, T4a, T2a, T2b, T2e, T1w, T1x, T1y, T3O, T3R, T3U, T3h, T3i, T3j;
	       E TH, TK, TL;
	       {
		    E T3, T2R, T1u, T2S, T6, T3f, T1r, T3e;
		    {
			 E T1, T2, T1s, T1t;
			 T1 = cr[0];
			 T2 = ci[WS(rs, 9)];
			 T3 = T1 + T2;
			 T2R = T1 - T2;
			 T1s = ci[WS(rs, 14)];
			 T1t = cr[WS(rs, 15)];
			 T1u = T1s - T1t;
			 T2S = T1s + T1t;
		    }
		    {
			 E T4, T5, T1p, T1q;
			 T4 = cr[WS(rs, 5)];
			 T5 = ci[WS(rs, 4)];
			 T6 = T4 + T5;
			 T3f = T4 - T5;
			 T1p = ci[WS(rs, 19)];
			 T1q = cr[WS(rs, 10)];
			 T1r = T1p - T1q;
			 T3e = T1p + T1q;
		    }
		    T7 = T3 + T6;
		    T3T = T2R - T2S;
		    T49 = T3f + T3e;
		    TE = T3 - T6;
		    T1v = T1r - T1u;
		    T2T = T2R + T2S;
		    T3g = T3e - T3f;
		    T2d = T1r + T1u;
	       }
	       {
		    E Te, T3M, T3X, TF, TV, T2E, T2W, T21, TA, T3Q, T41, TJ, T1h, T2O, T36;
		    E T25, Tl, T3N, T3Y, TG, T12, T2H, T2Z, T22, Tt, T3P, T40, TI, T1a, T2L;
		    E T33, T24;
		    {
			 E Ta, T2U, TU, T2V, Td, T2D, TR, T2C;
			 {
			      E T8, T9, TS, TT;
			      T8 = cr[WS(rs, 4)];
			      T9 = ci[WS(rs, 5)];
			      Ta = T8 + T9;
			      T2U = T8 - T9;
			      TS = ci[WS(rs, 10)];
			      TT = cr[WS(rs, 19)];
			      TU = TS - TT;
			      T2V = TS + TT;
			 }
			 {
			      E Tb, Tc, TP, TQ;
			      Tb = cr[WS(rs, 9)];
			      Tc = ci[0];
			      Td = Tb + Tc;
			      T2D = Tb - Tc;
			      TP = ci[WS(rs, 15)];
			      TQ = cr[WS(rs, 14)];
			      TR = TP - TQ;
			      T2C = TP + TQ;
			 }
			 Te = Ta + Td;
			 T3M = T2U - T2V;
			 T3X = T2D + T2C;
			 TF = Ta - Td;
			 TV = TR - TU;
			 T2E = T2C - T2D;
			 T2W = T2U + T2V;
			 T21 = TR + TU;
		    }
		    {
			 E Tw, T34, Tz, T2M, T1d, T2N, T1g, T35;
			 {
			      E Tu, Tv, Tx, Ty;
			      Tu = ci[WS(rs, 7)];
			      Tv = cr[WS(rs, 2)];
			      Tw = Tu + Tv;
			      T34 = Tu - Tv;
			      Tx = ci[WS(rs, 2)];
			      Ty = cr[WS(rs, 7)];
			      Tz = Tx + Ty;
			      T2M = Tx - Ty;
			 }
			 {
			      E T1b, T1c, T1e, T1f;
			      T1b = ci[WS(rs, 17)];
			      T1c = cr[WS(rs, 12)];
			      T1d = T1b - T1c;
			      T2N = T1b + T1c;
			      T1e = ci[WS(rs, 12)];
			      T1f = cr[WS(rs, 17)];
			      T1g = T1e - T1f;
			      T35 = T1e + T1f;
			 }
			 TA = Tw + Tz;
			 T3Q = T34 + T35;
			 T41 = T2M - T2N;
			 TJ = Tw - Tz;
			 T1h = T1d - T1g;
			 T2O = T2M + T2N;
			 T36 = T34 - T35;
			 T25 = T1d + T1g;
		    }
		    {
			 E Th, T2X, T11, T2Y, Tk, T2F, TY, T2G;
			 {
			      E Tf, Tg, TZ, T10;
			      Tf = ci[WS(rs, 3)];
			      Tg = cr[WS(rs, 6)];
			      Th = Tf + Tg;
			      T2X = Tf - Tg;
			      TZ = ci[WS(rs, 18)];
			      T10 = cr[WS(rs, 11)];
			      T11 = TZ - T10;
			      T2Y = TZ + T10;
			 }
			 {
			      E Ti, Tj, TW, TX;
			      Ti = cr[WS(rs, 1)];
			      Tj = ci[WS(rs, 8)];
			      Tk = Ti + Tj;
			      T2F = Ti - Tj;
			      TW = ci[WS(rs, 13)];
			      TX = cr[WS(rs, 16)];
			      TY = TW - TX;
			      T2G = TW + TX;
			 }
			 Tl = Th + Tk;
			 T3N = T2X - T2Y;
			 T3Y = T2F - T2G;
			 TG = Th - Tk;
			 T12 = TY - T11;
			 T2H = T2F + T2G;
			 T2Z = T2X + T2Y;
			 T22 = TY + T11;
		    }
		    {
			 E Tp, T31, T19, T32, Ts, T2K, T16, T2J;
			 {
			      E Tn, To, T17, T18;
			      Tn = cr[WS(rs, 8)];
			      To = ci[WS(rs, 1)];
			      Tp = Tn + To;
			      T31 = Tn - To;
			      T17 = ci[WS(rs, 16)];
			      T18 = cr[WS(rs, 13)];
			      T19 = T17 - T18;
			      T32 = T17 + T18;
			 }
			 {
			      E Tq, Tr, T14, T15;
			      Tq = ci[WS(rs, 6)];
			      Tr = cr[WS(rs, 3)];
			      Ts = Tq + Tr;
			      T2K = Tq - Tr;
			      T14 = ci[WS(rs, 11)];
			      T15 = cr[WS(rs, 18)];
			      T16 = T14 - T15;
			      T2J = T14 + T15;
			 }
			 Tt = Tp + Ts;
			 T3P = T31 + T32;
			 T40 = T2K + T2J;
			 TI = Tp - Ts;
			 T1a = T16 - T19;
			 T2L = T2J - T2K;
			 T33 = T31 - T32;
			 T24 = T16 + T19;
		    }
		    T13 = TV - T12;
		    T3n = T2W - T2Z;
		    T3o = T33 - T36;
		    T1i = T1a - T1h;
		    T26 = T24 - T25;
		    T4e = T3P - T3Q;
		    T4d = T3M - T3N;
		    T23 = T21 - T22;
		    T1n = TI - TJ;
		    T42 = T40 - T41;
		    T3Z = T3X - T3Y;
		    T1m = TF - TG;
		    T2h = Te - Tl;
		    T2I = T2E + T2H;
		    T2i = Tt - TA;
		    T2P = T2L + T2O;
		    T30 = T2W + T2Z;
		    T37 = T33 + T36;
		    T38 = T30 + T37;
		    Tm = Te + Tl;
		    TB = Tt + TA;
		    TC = Tm + TB;
		    T46 = T3X + T3Y;
		    T47 = T40 + T41;
		    T4a = T46 + T47;
		    T2a = T21 + T22;
		    T2b = T24 + T25;
		    T2e = T2a + T2b;
		    T1w = TV + T12;
		    T1x = T1a + T1h;
		    T1y = T1w + T1x;
		    T3O = T3M + T3N;
		    T3R = T3P + T3Q;
		    T3U = T3O + T3R;
		    T3h = T2E - T2H;
		    T3i = T2L - T2O;
		    T3j = T3h + T3i;
		    TH = TF + TG;
		    TK = TI + TJ;
		    TL = TH + TK;
	       }
	       cr[0] = T7 + TC;
	       ci[0] = T2d + T2e;
	       {
		    E T1U, T1W, T1T, T1V;
		    T1U = TE + TL;
		    T1W = T1v + T1y;
		    T1T = W[18];
		    T1V = W[19];
		    cr[WS(rs, 10)] = FNMS(T1V, T1W, T1T * T1U);
		    ci[WS(rs, 10)] = FMA(T1V, T1U, T1T * T1W);
	       }
	       {
		    E T4y, T4A, T4x, T4z;
		    T4y = T3T + T3U;
		    T4A = T49 + T4a;
		    T4x = W[8];
		    T4z = W[9];
		    cr[WS(rs, 5)] = FNMS(T4z, T4A, T4x * T4y);
		    ci[WS(rs, 5)] = FMA(T4x, T4A, T4z * T4y);
	       }
	       {
		    E T3I, T3K, T3H, T3J;
		    T3I = T2T + T38;
		    T3K = T3g + T3j;
		    T3H = W[28];
		    T3J = W[29];
		    cr[WS(rs, 15)] = FNMS(T3J, T3K, T3H * T3I);
		    ci[WS(rs, 15)] = FMA(T3H, T3K, T3J * T3I);
	       }
	       {
		    E T27, T2j, T2v, T2r, T2g, T2u, T20, T2q;
		    T27 = FMA(KP951056516, T23, KP587785252 * T26);
		    T2j = FMA(KP951056516, T2h, KP587785252 * T2i);
		    T2v = FNMS(KP951056516, T2i, KP587785252 * T2h);
		    T2r = FNMS(KP951056516, T26, KP587785252 * T23);
		    {
			 E T2c, T2f, T1Y, T1Z;
			 T2c = KP559016994 * (T2a - T2b);
			 T2f = FNMS(KP250000000, T2e, T2d);
			 T2g = T2c + T2f;
			 T2u = T2f - T2c;
			 T1Y = KP559016994 * (Tm - TB);
			 T1Z = FNMS(KP250000000, TC, T7);
			 T20 = T1Y + T1Z;
			 T2q = T1Z - T1Y;
		    }
		    {
			 E T28, T2k, T1X, T29;
			 T28 = T20 + T27;
			 T2k = T2g - T2j;
			 T1X = W[6];
			 T29 = W[7];
			 cr[WS(rs, 4)] = FNMS(T29, T2k, T1X * T28);
			 ci[WS(rs, 4)] = FMA(T29, T28, T1X * T2k);
		    }
		    {
			 E T2y, T2A, T2x, T2z;
			 T2y = T2q - T2r;
			 T2A = T2v + T2u;
			 T2x = W[22];
			 T2z = W[23];
			 cr[WS(rs, 12)] = FNMS(T2z, T2A, T2x * T2y);
			 ci[WS(rs, 12)] = FMA(T2z, T2y, T2x * T2A);
		    }
		    {
			 E T2m, T2o, T2l, T2n;
			 T2m = T20 - T27;
			 T2o = T2j + T2g;
			 T2l = W[30];
			 T2n = W[31];
			 cr[WS(rs, 16)] = FNMS(T2n, T2o, T2l * T2m);
			 ci[WS(rs, 16)] = FMA(T2n, T2m, T2l * T2o);
		    }
		    {
			 E T2s, T2w, T2p, T2t;
			 T2s = T2q + T2r;
			 T2w = T2u - T2v;
			 T2p = W[14];
			 T2t = W[15];
			 cr[WS(rs, 8)] = FNMS(T2t, T2w, T2p * T2s);
			 ci[WS(rs, 8)] = FMA(T2t, T2s, T2p * T2w);
		    }
	       }
	       {
		    E T43, T4f, T4r, T4m, T4c, T4q, T3W, T4n;
		    T43 = FMA(KP951056516, T3Z, KP587785252 * T42);
		    T4f = FMA(KP951056516, T4d, KP587785252 * T4e);
		    T4r = FNMS(KP951056516, T4e, KP587785252 * T4d);
		    T4m = FNMS(KP951056516, T42, KP587785252 * T3Z);
		    {
			 E T48, T4b, T3S, T3V;
			 T48 = KP559016994 * (T46 - T47);
			 T4b = FNMS(KP250000000, T4a, T49);
			 T4c = T48 + T4b;
			 T4q = T4b - T48;
			 T3S = KP559016994 * (T3O - T3R);
			 T3V = FNMS(KP250000000, T3U, T3T);
			 T3W = T3S + T3V;
			 T4n = T3V - T3S;
		    }
		    {
			 E T44, T4g, T3L, T45;
			 T44 = T3W - T43;
			 T4g = T4c + T4f;
			 T3L = W[0];
			 T45 = W[1];
			 cr[WS(rs, 1)] = FNMS(T45, T4g, T3L * T44);
			 ci[WS(rs, 1)] = FMA(T3L, T4g, T45 * T44);
		    }
		    {
			 E T4u, T4w, T4t, T4v;
			 T4u = T4n - T4m;
			 T4w = T4q + T4r;
			 T4t = W[32];
			 T4v = W[33];
			 cr[WS(rs, 17)] = FNMS(T4v, T4w, T4t * T4u);
			 ci[WS(rs, 17)] = FMA(T4t, T4w, T4v * T4u);
		    }
		    {
			 E T4i, T4k, T4h, T4j;
			 T4i = T43 + T3W;
			 T4k = T4c - T4f;
			 T4h = W[16];
			 T4j = W[17];
			 cr[WS(rs, 9)] = FNMS(T4j, T4k, T4h * T4i);
			 ci[WS(rs, 9)] = FMA(T4h, T4k, T4j * T4i);
		    }
		    {
			 E T4o, T4s, T4l, T4p;
			 T4o = T4m + T4n;
			 T4s = T4q - T4r;
			 T4l = W[24];
			 T4p = W[25];
			 cr[WS(rs, 13)] = FNMS(T4p, T4s, T4l * T4o);
			 ci[WS(rs, 13)] = FMA(T4l, T4s, T4p * T4o);
		    }
	       }
	       {
		    E T1j, T1o, T1M, T1J, T1B, T1N, TO, T1I;
		    T1j = FNMS(KP951056516, T1i, KP587785252 * T13);
		    T1o = FNMS(KP951056516, T1n, KP587785252 * T1m);
		    T1M = FMA(KP951056516, T1m, KP587785252 * T1n);
		    T1J = FMA(KP951056516, T13, KP587785252 * T1i);
		    {
			 E T1z, T1A, TM, TN;
			 T1z = FNMS(KP250000000, T1y, T1v);
			 T1A = KP559016994 * (T1w - T1x);
			 T1B = T1z - T1A;
			 T1N = T1A + T1z;
			 TM = FNMS(KP250000000, TL, TE);
			 TN = KP559016994 * (TH - TK);
			 TO = TM - TN;
			 T1I = TN + TM;
		    }
		    {
			 E T1k, T1C, TD, T1l;
			 T1k = TO - T1j;
			 T1C = T1o + T1B;
			 TD = W[2];
			 T1l = W[3];
			 cr[WS(rs, 2)] = FNMS(T1l, T1C, TD * T1k);
			 ci[WS(rs, 2)] = FMA(T1l, T1k, TD * T1C);
		    }
		    {
			 E T1Q, T1S, T1P, T1R;
			 T1Q = T1I + T1J;
			 T1S = T1N - T1M;
			 T1P = W[26];
			 T1R = W[27];
			 cr[WS(rs, 14)] = FNMS(T1R, T1S, T1P * T1Q);
			 ci[WS(rs, 14)] = FMA(T1R, T1Q, T1P * T1S);
		    }
		    {
			 E T1E, T1G, T1D, T1F;
			 T1E = TO + T1j;
			 T1G = T1B - T1o;
			 T1D = W[34];
			 T1F = W[35];
			 cr[WS(rs, 18)] = FNMS(T1F, T1G, T1D * T1E);
			 ci[WS(rs, 18)] = FMA(T1F, T1E, T1D * T1G);
		    }
		    {
			 E T1K, T1O, T1H, T1L;
			 T1K = T1I - T1J;
			 T1O = T1M + T1N;
			 T1H = W[10];
			 T1L = W[11];
			 cr[WS(rs, 6)] = FNMS(T1L, T1O, T1H * T1K);
			 ci[WS(rs, 6)] = FMA(T1L, T1K, T1H * T1O);
		    }
	       }
	       {
		    E T2Q, T3p, T3B, T3x, T3m, T3A, T3b, T3w;
		    T2Q = FNMS(KP951056516, T2P, KP587785252 * T2I);
		    T3p = FNMS(KP951056516, T3o, KP587785252 * T3n);
		    T3B = FMA(KP951056516, T3n, KP587785252 * T3o);
		    T3x = FMA(KP951056516, T2I, KP587785252 * T2P);
		    {
			 E T3k, T3l, T39, T3a;
			 T3k = FNMS(KP250000000, T3j, T3g);
			 T3l = KP559016994 * (T3h - T3i);
			 T3m = T3k - T3l;
			 T3A = T3l + T3k;
			 T39 = FNMS(KP250000000, T38, T2T);
			 T3a = KP559016994 * (T30 - T37);
			 T3b = T39 - T3a;
			 T3w = T3a + T39;
		    }
		    {
			 E T3c, T3q, T2B, T3d;
			 T3c = T2Q + T3b;
			 T3q = T3m - T3p;
			 T2B = W[4];
			 T3d = W[5];
			 cr[WS(rs, 3)] = FNMS(T3d, T3q, T2B * T3c);
			 ci[WS(rs, 3)] = FMA(T2B, T3q, T3d * T3c);
		    }
		    {
			 E T3E, T3G, T3D, T3F;
			 T3E = T3x + T3w;
			 T3G = T3A - T3B;
			 T3D = W[36];
			 T3F = W[37];
			 cr[WS(rs, 19)] = FNMS(T3F, T3G, T3D * T3E);
			 ci[WS(rs, 19)] = FMA(T3D, T3G, T3F * T3E);
		    }
		    {
			 E T3s, T3u, T3r, T3t;
			 T3s = T3b - T2Q;
			 T3u = T3m + T3p;
			 T3r = W[12];
			 T3t = W[13];
			 cr[WS(rs, 7)] = FNMS(T3t, T3u, T3r * T3s);
			 ci[WS(rs, 7)] = FMA(T3r, T3u, T3t * T3s);
		    }
		    {
			 E T3y, T3C, T3v, T3z;
			 T3y = T3w - T3x;
			 T3C = T3A + T3B;
			 T3v = W[20];
			 T3z = W[21];
			 cr[WS(rs, 11)] = FNMS(T3z, T3C, T3v * T3y);
			 ci[WS(rs, 11)] = FMA(T3v, T3C, T3z * T3y);
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     {TW_FULL, 1, 20},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 20, "hb_20", twinstr, &GENUS, {184, 62, 62, 0} };

void X(codelet_hb_20) (planner *p) {
     X(khc2hc_register) (p, hb_20, &desc);
}
#endif				/* HAVE_FMA */
