/* This file was automatically generated by CasADi.
   The CasADi copyright holders make no ownership claim of its contents. */
#ifdef __cplusplus
extern "C" {
#endif

/* How to prefix internal symbols */
#ifdef CASADI_CODEGEN_PREFIX
  #define CASADI_NAMESPACE_CONCAT(NS, ID) _CASADI_NAMESPACE_CONCAT(NS, ID)
  #define _CASADI_NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) CASADI_NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else
  #define CASADI_PREFIX(ID) Drone_ode_cost_ext_cost_0_fun_jac_ ## ID
#endif

#include <math.h>

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int int
#endif

/* Add prefix to internal symbols */
#define casadi_clear CASADI_PREFIX(clear)
#define casadi_copy CASADI_PREFIX(copy)
#define casadi_dot CASADI_PREFIX(dot)
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_s2 CASADI_PREFIX(s2)
#define casadi_s3 CASADI_PREFIX(s3)
#define casadi_s4 CASADI_PREFIX(s4)
#define casadi_s5 CASADI_PREFIX(s5)

/* Symbol visibility in DLLs */
#ifndef CASADI_SYMBOL_EXPORT
  #if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
    #if defined(STATIC_LINKED)
      #define CASADI_SYMBOL_EXPORT
    #else
      #define CASADI_SYMBOL_EXPORT __declspec(dllexport)
    #endif
  #elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
    #define CASADI_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
  #else
    #define CASADI_SYMBOL_EXPORT
  #endif
#endif

void casadi_clear(casadi_real* x, casadi_int n) {
  casadi_int i;
  if (x) {
    for (i=0; i<n; ++i) *x++ = 0;
  }
}

void casadi_copy(const casadi_real* x, casadi_int n, casadi_real* y) {
  casadi_int i;
  if (y) {
    if (x) {
      for (i=0; i<n; ++i) *y++ = *x++;
    } else {
      for (i=0; i<n; ++i) *y++ = 0.;
    }
  }
}

casadi_real casadi_dot(casadi_int n, const casadi_real* x, const casadi_real* y) {
  casadi_int i;
  casadi_real r = 0;
  for (i=0; i<n; ++i) r += *x++ * *y++;
  return r;
}

static const casadi_int casadi_s0[15] = {11, 1, 0, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
static const casadi_int casadi_s1[8] = {4, 1, 0, 4, 0, 1, 2, 3};
static const casadi_int casadi_s2[3] = {0, 0, 0};
static const casadi_int casadi_s3[21] = {17, 1, 0, 17, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
static const casadi_int casadi_s4[5] = {1, 1, 0, 1, 0};
static const casadi_int casadi_s5[19] = {15, 1, 0, 15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

/* Drone_ode_cost_ext_cost_0_fun_jac:(i0[11],i1[4],i2[],i3[17])->(o0,o1[15]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_int i, j, k;
  casadi_real *rr, *ss, *tt;
  const casadi_real *cs;
  casadi_real w0, *w1=w+2, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12, w13, w14, w15, w16, w17, w18, *w19=w+22, *w20=w+39, *w21=w+42, *w22=w+53, *w23=w+56, *w24=w+65, *w25=w+69, *w26=w+73, *w27=w+77, *w28=w+93, *w29=w+97, *w30=w+100, *w31=w+116, *w32=w+119;
  /* #0: @0 = 0 */
  w0 = 0.;
  /* #1: @1 = zeros(1x3) */
  casadi_clear(w1, 3);
  /* #2: @2 = input[3][0] */
  w2 = arg[3] ? arg[3][0] : 0;
  /* #3: @3 = input[3][1] */
  w3 = arg[3] ? arg[3][1] : 0;
  /* #4: @4 = input[3][2] */
  w4 = arg[3] ? arg[3][2] : 0;
  /* #5: @5 = input[3][3] */
  w5 = arg[3] ? arg[3][3] : 0;
  /* #6: @6 = input[3][4] */
  w6 = arg[3] ? arg[3][4] : 0;
  /* #7: @7 = input[3][5] */
  w7 = arg[3] ? arg[3][5] : 0;
  /* #8: @8 = input[3][6] */
  w8 = arg[3] ? arg[3][6] : 0;
  /* #9: @9 = input[3][7] */
  w9 = arg[3] ? arg[3][7] : 0;
  /* #10: @10 = input[3][8] */
  w10 = arg[3] ? arg[3][8] : 0;
  /* #11: @11 = input[3][9] */
  w11 = arg[3] ? arg[3][9] : 0;
  /* #12: @12 = input[3][10] */
  w12 = arg[3] ? arg[3][10] : 0;
  /* #13: @13 = input[3][11] */
  w13 = arg[3] ? arg[3][11] : 0;
  /* #14: @14 = input[3][12] */
  w14 = arg[3] ? arg[3][12] : 0;
  /* #15: @15 = input[3][13] */
  w15 = arg[3] ? arg[3][13] : 0;
  /* #16: @16 = input[3][14] */
  w16 = arg[3] ? arg[3][14] : 0;
  /* #17: @17 = input[3][15] */
  w17 = arg[3] ? arg[3][15] : 0;
  /* #18: @18 = input[3][16] */
  w18 = arg[3] ? arg[3][16] : 0;
  /* #19: @19 = vertcat(@2, @3, @4, @5, @6, @7, @8, @9, @10, @11, @12, @13, @14, @15, @16, @17, @18) */
  rr=w19;
  *rr++ = w2;
  *rr++ = w3;
  *rr++ = w4;
  *rr++ = w5;
  *rr++ = w6;
  *rr++ = w7;
  *rr++ = w8;
  *rr++ = w9;
  *rr++ = w10;
  *rr++ = w11;
  *rr++ = w12;
  *rr++ = w13;
  *rr++ = w14;
  *rr++ = w15;
  *rr++ = w16;
  *rr++ = w17;
  *rr++ = w18;
  /* #20: @20 = @19[:3] */
  for (rr=w20, ss=w19+0; ss!=w19+3; ss+=1) *rr++ = *ss;
  /* #21: @2 = input[0][0] */
  w2 = arg[0] ? arg[0][0] : 0;
  /* #22: @3 = input[0][1] */
  w3 = arg[0] ? arg[0][1] : 0;
  /* #23: @4 = input[0][2] */
  w4 = arg[0] ? arg[0][2] : 0;
  /* #24: @9 = input[0][3] */
  w9 = arg[0] ? arg[0][3] : 0;
  /* #25: @10 = input[0][4] */
  w10 = arg[0] ? arg[0][4] : 0;
  /* #26: @11 = input[0][5] */
  w11 = arg[0] ? arg[0][5] : 0;
  /* #27: @12 = input[0][6] */
  w12 = arg[0] ? arg[0][6] : 0;
  /* #28: @13 = input[0][7] */
  w13 = arg[0] ? arg[0][7] : 0;
  /* #29: @14 = input[0][8] */
  w14 = arg[0] ? arg[0][8] : 0;
  /* #30: @15 = input[0][9] */
  w15 = arg[0] ? arg[0][9] : 0;
  /* #31: @16 = input[0][10] */
  w16 = arg[0] ? arg[0][10] : 0;
  /* #32: @21 = vertcat(@2, @3, @4, @9, @10, @11, @12, @13, @14, @15, @16) */
  rr=w21;
  *rr++ = w2;
  *rr++ = w3;
  *rr++ = w4;
  *rr++ = w9;
  *rr++ = w10;
  *rr++ = w11;
  *rr++ = w12;
  *rr++ = w13;
  *rr++ = w14;
  *rr++ = w15;
  *rr++ = w16;
  /* #33: @22 = @21[:3] */
  for (rr=w22, ss=w21+0; ss!=w21+3; ss+=1) *rr++ = *ss;
  /* #34: @20 = (@20-@22) */
  for (i=0, rr=w20, cs=w22; i<3; ++i) (*rr++) -= (*cs++);
  /* #35: @22 = @20' */
  casadi_copy(w20, 3, w22);
  /* #36: @23 = zeros(3x3) */
  casadi_clear(w23, 9);
  /* #37: @2 = 1.1 */
  w2 = 1.1000000000000001e+00;
  /* #38: (@23[0] = @2) */
  for (rr=w23+0, ss=(&w2); rr!=w23+1; rr+=1) *rr = *ss++;
  /* #39: @2 = 1.1 */
  w2 = 1.1000000000000001e+00;
  /* #40: (@23[4] = @2) */
  for (rr=w23+4, ss=(&w2); rr!=w23+5; rr+=1) *rr = *ss++;
  /* #41: @2 = 1.1 */
  w2 = 1.1000000000000001e+00;
  /* #42: (@23[8] = @2) */
  for (rr=w23+8, ss=(&w2); rr!=w23+9; rr+=1) *rr = *ss++;
  /* #43: @1 = mac(@22,@23,@1) */
  for (i=0, rr=w1; i<3; ++i) for (j=0; j<1; ++j, ++rr) for (k=0, ss=w22+j, tt=w23+i*3; k<3; ++k) *rr += ss[k*1]**tt++;
  /* #44: @0 = mac(@1,@20,@0) */
  for (i=0, rr=(&w0); i<1; ++i) for (j=0; j<1; ++j, ++rr) for (k=0, ss=w1+j, tt=w20+i*3; k<3; ++k) *rr += ss[k*1]**tt++;
  /* #45: @2 = 0 */
  w2 = 0.;
  /* #46: @24 = zeros(1x4) */
  casadi_clear(w24, 4);
  /* #47: @3 = input[1][0] */
  w3 = arg[1] ? arg[1][0] : 0;
  /* #48: @4 = input[1][1] */
  w4 = arg[1] ? arg[1][1] : 0;
  /* #49: @13 = input[1][2] */
  w13 = arg[1] ? arg[1][2] : 0;
  /* #50: @14 = input[1][3] */
  w14 = arg[1] ? arg[1][3] : 0;
  /* #51: @25 = vertcat(@3, @4, @13, @14) */
  rr=w25;
  *rr++ = w3;
  *rr++ = w4;
  *rr++ = w13;
  *rr++ = w14;
  /* #52: @26 = @25' */
  casadi_copy(w25, 4, w26);
  /* #53: @27 = zeros(4x4) */
  casadi_clear(w27, 16);
  /* #54: @3 = 1 */
  w3 = 1.;
  /* #55: (@27[0] = @3) */
  for (rr=w27+0, ss=(&w3); rr!=w27+1; rr+=1) *rr = *ss++;
  /* #56: @3 = 1 */
  w3 = 1.;
  /* #57: (@27[5] = @3) */
  for (rr=w27+5, ss=(&w3); rr!=w27+6; rr+=1) *rr = *ss++;
  /* #58: @3 = 1 */
  w3 = 1.;
  /* #59: (@27[10] = @3) */
  for (rr=w27+10, ss=(&w3); rr!=w27+11; rr+=1) *rr = *ss++;
  /* #60: @3 = 1 */
  w3 = 1.;
  /* #61: (@27[15] = @3) */
  for (rr=w27+15, ss=(&w3); rr!=w27+16; rr+=1) *rr = *ss++;
  /* #62: @24 = mac(@26,@27,@24) */
  for (i=0, rr=w24; i<4; ++i) for (j=0; j<1; ++j, ++rr) for (k=0, ss=w26+j, tt=w27+i*4; k<4; ++k) *rr += ss[k*1]**tt++;
  /* #63: @2 = mac(@24,@25,@2) */
  for (i=0, rr=(&w2); i<1; ++i) for (j=0; j<1; ++j, ++rr) for (k=0, ss=w24+j, tt=w25+i*4; k<4; ++k) *rr += ss[k*1]**tt++;
  /* #64: @0 = (@0+@2) */
  w0 += w2;
  /* #65: @2 = 1 */
  w2 = 1.;
  /* #66: @6 = (-@6) */
  w6 = (- w6 );
  /* #67: @7 = (-@7) */
  w7 = (- w7 );
  /* #68: @8 = (-@8) */
  w8 = (- w8 );
  /* #69: @26 = vertcat(@5, @6, @7, @8) */
  rr=w26;
  *rr++ = w5;
  *rr++ = w6;
  *rr++ = w7;
  *rr++ = w8;
  /* #70: @28 = @19[3:7] */
  for (rr=w28, ss=w19+3; ss!=w19+7; ss+=1) *rr++ = *ss;
  /* #71: @5 = ||@28||_F */
  w5 = sqrt(casadi_dot(4, w28, w28));
  /* #72: @26 = (@26/@5) */
  for (i=0, rr=w26; i<4; ++i) (*rr++) /= w5;
  /* #73: @5 = @26[0] */
  for (rr=(&w5), ss=w26+0; ss!=w26+1; ss+=1) *rr++ = *ss;
  /* #74: @6 = (@5*@9) */
  w6  = (w5*w9);
  /* #75: @7 = @26[1] */
  for (rr=(&w7), ss=w26+1; ss!=w26+2; ss+=1) *rr++ = *ss;
  /* #76: @8 = (@7*@10) */
  w8  = (w7*w10);
  /* #77: @6 = (@6-@8) */
  w6 -= w8;
  /* #78: @8 = @26[2] */
  for (rr=(&w8), ss=w26+2; ss!=w26+3; ss+=1) *rr++ = *ss;
  /* #79: @3 = (@8*@11) */
  w3  = (w8*w11);
  /* #80: @6 = (@6-@3) */
  w6 -= w3;
  /* #81: @3 = @26[3] */
  for (rr=(&w3), ss=w26+3; ss!=w26+4; ss+=1) *rr++ = *ss;
  /* #82: @4 = (@3*@12) */
  w4  = (w3*w12);
  /* #83: @6 = (@6-@4) */
  w6 -= w4;
  /* #84: @2 = (@2-@6) */
  w2 -= w6;
  /* #85: @0 = (@0+@2) */
  w0 += w2;
  /* #86: @2 = 0 */
  w2 = 0.;
  /* #87: @4 = 7 */
  w4 = 7.;
  /* #88: @13 = (@5*@10) */
  w13  = (w5*w10);
  /* #89: @14 = (@7*@9) */
  w14  = (w7*w9);
  /* #90: @13 = (@13+@14) */
  w13 += w14;
  /* #91: @14 = (@8*@12) */
  w14  = (w8*w12);
  /* #92: @13 = (@13+@14) */
  w13 += w14;
  /* #93: @14 = (@3*@11) */
  w14  = (w3*w11);
  /* #94: @13 = (@13-@14) */
  w13 -= w14;
  /* #95: @14 = (@5*@11) */
  w14  = (w5*w11);
  /* #96: @15 = (@7*@12) */
  w15  = (w7*w12);
  /* #97: @14 = (@14-@15) */
  w14 -= w15;
  /* #98: @15 = (@8*@9) */
  w15  = (w8*w9);
  /* #99: @14 = (@14+@15) */
  w14 += w15;
  /* #100: @15 = (@3*@10) */
  w15  = (w3*w10);
  /* #101: @14 = (@14+@15) */
  w14 += w15;
  /* #102: @12 = (@5*@12) */
  w12  = (w5*w12);
  /* #103: @11 = (@7*@11) */
  w11  = (w7*w11);
  /* #104: @12 = (@12+@11) */
  w12 += w11;
  /* #105: @10 = (@8*@10) */
  w10  = (w8*w10);
  /* #106: @12 = (@12-@10) */
  w12 -= w10;
  /* #107: @9 = (@3*@9) */
  w9  = (w3*w9);
  /* #108: @12 = (@12+@9) */
  w12 += w9;
  /* #109: @26 = vertcat(@6, @13, @14, @12) */
  rr=w26;
  *rr++ = w6;
  *rr++ = w13;
  *rr++ = w14;
  *rr++ = w12;
  /* #110: @22 = @26[1:4] */
  for (rr=w22, ss=w26+1; ss!=w26+4; ss+=1) *rr++ = *ss;
  /* #111: @22 = @22' */
  /* #112: @22 = (@4*@22) */
  for (i=0, rr=w22, cs=w22; i<3; ++i) (*rr++)  = (w4*(*cs++));
  /* #113: @29 = @26[1:4] */
  for (rr=w29, ss=w26+1; ss!=w26+4; ss+=1) *rr++ = *ss;
  /* #114: @2 = mac(@22,@29,@2) */
  for (i=0, rr=(&w2); i<1; ++i) for (j=0; j<1; ++j, ++rr) for (k=0, ss=w22+j, tt=w29+i*3; k<3; ++k) *rr += ss[k*1]**tt++;
  /* #115: @0 = (@0+@2) */
  w0 += w2;
  /* #116: output[0][0] = @0 */
  if (res[0]) res[0][0] = w0;
  /* #117: @24 = @24' */
  /* #118: @26 = zeros(1x4) */
  casadi_clear(w26, 4);
  /* #119: @25 = @25' */
  /* #120: @30 = @27' */
  for (i=0, rr=w30, cs=w27; i<4; ++i) for (j=0; j<4; ++j) rr[i+j*4] = *cs++;
  /* #121: @26 = mac(@25,@30,@26) */
  for (i=0, rr=w26; i<4; ++i) for (j=0; j<1; ++j, ++rr) for (k=0, ss=w25+j, tt=w30+i*4; k<4; ++k) *rr += ss[k*1]**tt++;
  /* #122: @26 = @26' */
  /* #123: @24 = (@24+@26) */
  for (i=0, rr=w24, cs=w26; i<4; ++i) (*rr++) += (*cs++);
  /* #124: {@0, @2, @6, @13} = vertsplit(@24) */
  w0 = w24[0];
  w2 = w24[1];
  w6 = w24[2];
  w13 = w24[3];
  /* #125: output[1][0] = @0 */
  if (res[1]) res[1][0] = w0;
  /* #126: output[1][1] = @2 */
  if (res[1]) res[1][1] = w2;
  /* #127: output[1][2] = @6 */
  if (res[1]) res[1][2] = w6;
  /* #128: output[1][3] = @13 */
  if (res[1]) res[1][3] = w13;
  /* #129: @21 = zeros(11x1) */
  casadi_clear(w21, 11);
  /* #130: @1 = @1' */
  /* #131: @31 = zeros(1x3) */
  casadi_clear(w31, 3);
  /* #132: @20 = @20' */
  /* #133: @32 = @23' */
  for (i=0, rr=w32, cs=w23; i<3; ++i) for (j=0; j<3; ++j) rr[i+j*3] = *cs++;
  /* #134: @31 = mac(@20,@32,@31) */
  for (i=0, rr=w31; i<3; ++i) for (j=0; j<1; ++j, ++rr) for (k=0, ss=w20+j, tt=w32+i*3; k<3; ++k) *rr += ss[k*1]**tt++;
  /* #135: @31 = @31' */
  /* #136: @1 = (@1+@31) */
  for (i=0, rr=w1, cs=w31; i<3; ++i) (*rr++) += (*cs++);
  /* #137: @1 = (-@1) */
  for (i=0, rr=w1, cs=w1; i<3; ++i) *rr++ = (- *cs++ );
  /* #138: (@21[:3] += @1) */
  for (rr=w21+0, ss=w1; rr!=w21+3; rr+=1) *rr += *ss++;
  /* #139: {@13, @6, @2, @0, @14, @12, @9, @10, @11, @15, @16} = vertsplit(@21) */
  w13 = w21[0];
  w6 = w21[1];
  w2 = w21[2];
  w0 = w21[3];
  w14 = w21[4];
  w12 = w21[5];
  w9 = w21[6];
  w10 = w21[7];
  w11 = w21[8];
  w15 = w21[9];
  w16 = w21[10];
  /* #140: output[1][4] = @13 */
  if (res[1]) res[1][4] = w13;
  /* #141: output[1][5] = @6 */
  if (res[1]) res[1][5] = w6;
  /* #142: output[1][6] = @2 */
  if (res[1]) res[1][6] = w2;
  /* #143: @24 = zeros(4x1) */
  casadi_clear(w24, 4);
  /* #144: @22 = @22' */
  /* #145: (@24[1:4] += @22) */
  for (rr=w24+1, ss=w22; rr!=w24+4; rr+=1) *rr += *ss++;
  /* #146: @29 = @29' */
  /* #147: @29 = (@4*@29) */
  for (i=0, rr=w29, cs=w29; i<3; ++i) (*rr++)  = (w4*(*cs++));
  /* #148: @29 = @29' */
  /* #149: (@24[1:4] += @29) */
  for (rr=w24+1, ss=w29; rr!=w24+4; rr+=1) *rr += *ss++;
  /* #150: {@4, @2, @6, @13} = vertsplit(@24) */
  w4 = w24[0];
  w2 = w24[1];
  w6 = w24[2];
  w13 = w24[3];
  /* #151: @17 = (@3*@13) */
  w17  = (w3*w13);
  /* #152: @18 = (@8*@6) */
  w18  = (w8*w6);
  /* #153: @17 = (@17+@18) */
  w17 += w18;
  /* #154: @18 = (@7*@2) */
  w18  = (w7*w2);
  /* #155: @17 = (@17+@18) */
  w17 += w18;
  /* #156: @18 = -1 */
  w18 = -1.;
  /* #157: @18 = (@18+@4) */
  w18 += w4;
  /* #158: @4 = (@5*@18) */
  w4  = (w5*w18);
  /* #159: @17 = (@17+@4) */
  w17 += w4;
  /* #160: @17 = (@17+@0) */
  w17 += w0;
  /* #161: output[1][7] = @17 */
  if (res[1]) res[1][7] = w17;
  /* #162: @17 = (@3*@6) */
  w17  = (w3*w6);
  /* #163: @0 = (@8*@13) */
  w0  = (w8*w13);
  /* #164: @17 = (@17-@0) */
  w17 -= w0;
  /* #165: @0 = (@5*@2) */
  w0  = (w5*w2);
  /* #166: @17 = (@17+@0) */
  w17 += w0;
  /* #167: @0 = (@7*@18) */
  w0  = (w7*w18);
  /* #168: @17 = (@17-@0) */
  w17 -= w0;
  /* #169: @17 = (@17+@14) */
  w17 += w14;
  /* #170: output[1][8] = @17 */
  if (res[1]) res[1][8] = w17;
  /* #171: @17 = (@7*@13) */
  w17  = (w7*w13);
  /* #172: @14 = (@5*@6) */
  w14  = (w5*w6);
  /* #173: @17 = (@17+@14) */
  w17 += w14;
  /* #174: @14 = (@3*@2) */
  w14  = (w3*w2);
  /* #175: @17 = (@17-@14) */
  w17 -= w14;
  /* #176: @14 = (@8*@18) */
  w14  = (w8*w18);
  /* #177: @17 = (@17-@14) */
  w17 -= w14;
  /* #178: @17 = (@17+@12) */
  w17 += w12;
  /* #179: output[1][9] = @17 */
  if (res[1]) res[1][9] = w17;
  /* #180: @5 = (@5*@13) */
  w5 *= w13;
  /* #181: @7 = (@7*@6) */
  w7 *= w6;
  /* #182: @5 = (@5-@7) */
  w5 -= w7;
  /* #183: @8 = (@8*@2) */
  w8 *= w2;
  /* #184: @5 = (@5+@8) */
  w5 += w8;
  /* #185: @3 = (@3*@18) */
  w3 *= w18;
  /* #186: @5 = (@5-@3) */
  w5 -= w3;
  /* #187: @5 = (@5+@9) */
  w5 += w9;
  /* #188: output[1][10] = @5 */
  if (res[1]) res[1][10] = w5;
  /* #189: output[1][11] = @10 */
  if (res[1]) res[1][11] = w10;
  /* #190: output[1][12] = @11 */
  if (res[1]) res[1][12] = w11;
  /* #191: output[1][13] = @15 */
  if (res[1]) res[1][13] = w15;
  /* #192: output[1][14] = @16 */
  if (res[1]) res[1][14] = w16;
  return 0;
}

CASADI_SYMBOL_EXPORT int Drone_ode_cost_ext_cost_0_fun_jac(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int Drone_ode_cost_ext_cost_0_fun_jac_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int Drone_ode_cost_ext_cost_0_fun_jac_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void Drone_ode_cost_ext_cost_0_fun_jac_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int Drone_ode_cost_ext_cost_0_fun_jac_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void Drone_ode_cost_ext_cost_0_fun_jac_release(int mem) {
}

CASADI_SYMBOL_EXPORT void Drone_ode_cost_ext_cost_0_fun_jac_incref(void) {
}

CASADI_SYMBOL_EXPORT void Drone_ode_cost_ext_cost_0_fun_jac_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int Drone_ode_cost_ext_cost_0_fun_jac_n_in(void) { return 4;}

CASADI_SYMBOL_EXPORT casadi_int Drone_ode_cost_ext_cost_0_fun_jac_n_out(void) { return 2;}

CASADI_SYMBOL_EXPORT casadi_real Drone_ode_cost_ext_cost_0_fun_jac_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* Drone_ode_cost_ext_cost_0_fun_jac_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    case 3: return "i3";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* Drone_ode_cost_ext_cost_0_fun_jac_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    case 1: return "o1";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* Drone_ode_cost_ext_cost_0_fun_jac_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s0;
    case 1: return casadi_s1;
    case 2: return casadi_s2;
    case 3: return casadi_s3;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* Drone_ode_cost_ext_cost_0_fun_jac_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s4;
    case 1: return casadi_s5;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int Drone_ode_cost_ext_cost_0_fun_jac_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 21;
  if (sz_res) *sz_res = 13;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 128;
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif
