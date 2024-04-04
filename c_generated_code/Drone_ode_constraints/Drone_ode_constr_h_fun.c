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
  #define CASADI_PREFIX(ID) Drone_ode_constr_h_fun_ ## ID
#endif

#include <math.h>

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int int
#endif

/* Add prefix to internal symbols */
#define casadi_c0 CASADI_PREFIX(c0)
#define casadi_clear CASADI_PREFIX(clear)
#define casadi_copy CASADI_PREFIX(copy)
#define casadi_dot CASADI_PREFIX(dot)
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_fill CASADI_PREFIX(fill)
#define casadi_house CASADI_PREFIX(house)
#define casadi_if_else CASADI_PREFIX(if_else)
#define casadi_mtimes CASADI_PREFIX(mtimes)
#define casadi_qr CASADI_PREFIX(qr)
#define casadi_qr_colcomb CASADI_PREFIX(qr_colcomb)
#define casadi_qr_mv CASADI_PREFIX(qr_mv)
#define casadi_qr_singular CASADI_PREFIX(qr_singular)
#define casadi_qr_solve CASADI_PREFIX(qr_solve)
#define casadi_qr_trs CASADI_PREFIX(qr_trs)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_s10 CASADI_PREFIX(s10)
#define casadi_s11 CASADI_PREFIX(s11)
#define casadi_s12 CASADI_PREFIX(s12)
#define casadi_s2 CASADI_PREFIX(s2)
#define casadi_s3 CASADI_PREFIX(s3)
#define casadi_s4 CASADI_PREFIX(s4)
#define casadi_s5 CASADI_PREFIX(s5)
#define casadi_s6 CASADI_PREFIX(s6)
#define casadi_s7 CASADI_PREFIX(s7)
#define casadi_s8 CASADI_PREFIX(s8)
#define casadi_s9 CASADI_PREFIX(s9)
#define casadi_scal CASADI_PREFIX(scal)
#define casadi_sq CASADI_PREFIX(sq)

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

casadi_real casadi_if_else(casadi_real c, casadi_real x, casadi_real y) { return c!=0 ? x : y;}

void casadi_scal(casadi_int n, casadi_real alpha, casadi_real* x) {
  casadi_int i;
  if (!x) return;
  for (i=0; i<n; ++i) *x++ *= alpha;
}

casadi_real casadi_dot(casadi_int n, const casadi_real* x, const casadi_real* y) {
  casadi_int i;
  casadi_real r = 0;
  for (i=0; i<n; ++i) r += *x++ * *y++;
  return r;
}

casadi_real casadi_house(casadi_real* v, casadi_real* beta, casadi_int nv) {
  casadi_int i;
  casadi_real v0, sigma, s, sigma_is_zero, v0_nonpos;
  v0 = v[0];
  sigma=0;
  for (i=1; i<nv; ++i) sigma += v[i]*v[i];
  s = sqrt(v0*v0 + sigma);
  sigma_is_zero = sigma==0;
  v0_nonpos = v0<=0;
  v[0] = casadi_if_else(sigma_is_zero, 1,
                 casadi_if_else(v0_nonpos, v0-s, -sigma/(v0+s)));
  *beta = casadi_if_else(sigma_is_zero, 2*v0_nonpos, -1/(s*v[0]));
  return s;
}
void casadi_qr(const casadi_int* sp_a, const casadi_real* nz_a, casadi_real* x,
               const casadi_int* sp_v, casadi_real* nz_v, const casadi_int* sp_r, casadi_real* nz_r, casadi_real* beta,
               const casadi_int* prinv, const casadi_int* pc) {
   casadi_int ncol, nrow, r, c, k, k1;
   casadi_real alpha;
   const casadi_int *a_colind, *a_row, *v_colind, *v_row, *r_colind, *r_row;
   ncol = sp_a[1];
   a_colind=sp_a+2; a_row=sp_a+2+ncol+1;
   nrow = sp_v[0];
   v_colind=sp_v+2; v_row=sp_v+2+ncol+1;
   r_colind=sp_r+2; r_row=sp_r+2+ncol+1;
   for (r=0; r<nrow; ++r) x[r] = 0;
   for (c=0; c<ncol; ++c) {
     for (k=a_colind[pc[c]]; k<a_colind[pc[c]+1]; ++k) x[prinv[a_row[k]]] = nz_a[k];
     for (k=r_colind[c]; k<r_colind[c+1] && (r=r_row[k])<c; ++k) {
       alpha = 0;
       for (k1=v_colind[r]; k1<v_colind[r+1]; ++k1) alpha += nz_v[k1]*x[v_row[k1]];
       alpha *= beta[r];
       for (k1=v_colind[r]; k1<v_colind[r+1]; ++k1) x[v_row[k1]] -= alpha*nz_v[k1];
       *nz_r++ = x[r];
       x[r] = 0;
     }
     for (k=v_colind[c]; k<v_colind[c+1]; ++k) {
       nz_v[k] = x[v_row[k]];
       x[v_row[k]] = 0;
     }
     *nz_r++ = casadi_house(nz_v + v_colind[c], beta + c, v_colind[c+1] - v_colind[c]);
   }
 }
void casadi_qr_mv(const casadi_int* sp_v, const casadi_real* v, const casadi_real* beta, casadi_real* x,
                  casadi_int tr) {
  casadi_int ncol, c, c1, k;
  casadi_real alpha;
  const casadi_int *colind, *row;
  ncol=sp_v[1];
  colind=sp_v+2; row=sp_v+2+ncol+1;
  for (c1=0; c1<ncol; ++c1) {
    c = tr ? c1 : ncol-1-c1;
    alpha=0;
    for (k=colind[c]; k<colind[c+1]; ++k) alpha += v[k]*x[row[k]];
    alpha *= beta[c];
    for (k=colind[c]; k<colind[c+1]; ++k) x[row[k]] -= alpha*v[k];
  }
}
void casadi_qr_trs(const casadi_int* sp_r, const casadi_real* nz_r, casadi_real* x, casadi_int tr) {
  casadi_int ncol, r, c, k;
  const casadi_int *colind, *row;
  ncol=sp_r[1];
  colind=sp_r+2; row=sp_r+2+ncol+1;
  if (tr) {
    for (c=0; c<ncol; ++c) {
      for (k=colind[c]; k<colind[c+1]; ++k) {
        r = row[k];
        if (r==c) {
          x[c] /= nz_r[k];
        } else {
          x[c] -= nz_r[k]*x[r];
        }
      }
    }
  } else {
    for (c=ncol-1; c>=0; --c) {
      for (k=colind[c+1]-1; k>=colind[c]; --k) {
        r=row[k];
        if (r==c) {
          x[r] /= nz_r[k];
        } else {
          x[r] -= nz_r[k]*x[c];
        }
      }
    }
  }
}
void casadi_qr_solve(casadi_real* x, casadi_int nrhs, casadi_int tr,
                     const casadi_int* sp_v, const casadi_real* v, const casadi_int* sp_r, const casadi_real* r,
                     const casadi_real* beta, const casadi_int* prinv, const casadi_int* pc, casadi_real* w) {
  casadi_int k, c, nrow_ext, ncol;
  nrow_ext = sp_v[0]; ncol = sp_v[1];
  for (k=0; k<nrhs; ++k) {
    if (tr) {
      for (c=0; c<ncol; ++c) w[c] = x[pc[c]];
      casadi_qr_trs(sp_r, r, w, 1);
      casadi_qr_mv(sp_v, v, beta, w, 0);
      for (c=0; c<ncol; ++c) x[c] = w[prinv[c]];
    } else {
      for (c=0; c<nrow_ext; ++c) w[c] = 0;
      for (c=0; c<ncol; ++c) w[prinv[c]] = x[c];
      casadi_qr_mv(sp_v, v, beta, w, 1);
      casadi_qr_trs(sp_r, r, w, 0);
      for (c=0; c<ncol; ++c) x[pc[c]] = w[c];
    }
    x += ncol;
  }
}
casadi_int casadi_qr_singular(casadi_real* rmin, casadi_int* irmin, const casadi_real* nz_r,
                             const casadi_int* sp_r, const casadi_int* pc, casadi_real eps) {
  casadi_real rd, rd_min;
  casadi_int ncol, c, nullity;
  const casadi_int* r_colind;
  nullity = 0;
  ncol = sp_r[1];
  r_colind = sp_r + 2;
  for (c=0; c<ncol; ++c) {
    rd = fabs(nz_r[r_colind[c+1]-1]);
    if (rd<eps) nullity++;
    if (c==0 || rd < rd_min) {
      rd_min = rd;
      if (rmin) *rmin = rd;
      if (irmin) *irmin = pc[c];
    }
  }
  return nullity;
}
void casadi_qr_colcomb(casadi_real* v, const casadi_real* nz_r, const casadi_int* sp_r,
                       const casadi_int* pc, casadi_real eps, casadi_int ind) {
  casadi_int ncol, r, c, k;
  const casadi_int *r_colind, *r_row;
  ncol = sp_r[1];
  r_colind = sp_r + 2;
  r_row = r_colind + ncol + 1;
  for (c=0; c<ncol; ++c) {
    if (fabs(nz_r[r_colind[c+1]-1])<eps && 0==ind--) {
      ind = c;
      break;
    }
  }
  casadi_clear(v, ncol);
  v[pc[ind]] = 1.;
  for (k=r_colind[ind]; k<r_colind[ind+1]-1; ++k) {
    v[pc[r_row[k]]] = -nz_r[k];
  }
  for (c=ind-1; c>=0; --c) {
    for (k=r_colind[c+1]-1; k>=r_colind[c]; --k) {
      r=r_row[k];
      if (r==c) {
        if (fabs(nz_r[k])<eps) {
          v[pc[r]] = 0;
        } else {
          v[pc[r]] /= nz_r[k];
        }
      } else {
        v[pc[r]] -= nz_r[k]*v[pc[c]];
      }
    }
  }
  casadi_scal(ncol, 1./sqrt(casadi_dot(ncol, v, v)), v);
}

void casadi_fill(casadi_real* x, casadi_int n, casadi_real alpha) {
  casadi_int i;
  if (x) {
    for (i=0; i<n; ++i) *x++ = alpha;
  }
}

casadi_real casadi_sq(casadi_real x) { return x*x;}

void casadi_mtimes(const casadi_real* x, const casadi_int* sp_x, const casadi_real* y, const casadi_int* sp_y, casadi_real* z, const casadi_int* sp_z, casadi_real* w, casadi_int tr) {
  casadi_int ncol_x, ncol_y, ncol_z, cc;
  const casadi_int *colind_x, *row_x, *colind_y, *row_y, *colind_z, *row_z;
  ncol_x = sp_x[1];
  colind_x = sp_x+2; row_x = sp_x + 2 + ncol_x+1;
  ncol_y = sp_y[1];
  colind_y = sp_y+2; row_y = sp_y + 2 + ncol_y+1;
  ncol_z = sp_z[1];
  colind_z = sp_z+2; row_z = sp_z + 2 + ncol_z+1;
  if (tr) {
    for (cc=0; cc<ncol_z; ++cc) {
      casadi_int kk;
      for (kk=colind_y[cc]; kk<colind_y[cc+1]; ++kk) {
        w[row_y[kk]] = y[kk];
      }
      for (kk=colind_z[cc]; kk<colind_z[cc+1]; ++kk) {
        casadi_int kk1;
        casadi_int rr = row_z[kk];
        for (kk1=colind_x[rr]; kk1<colind_x[rr+1]; ++kk1) {
          z[kk] += x[kk1] * w[row_x[kk1]];
        }
      }
    }
  } else {
    for (cc=0; cc<ncol_y; ++cc) {
      casadi_int kk;
      for (kk=colind_z[cc]; kk<colind_z[cc+1]; ++kk) {
        w[row_z[kk]] = z[kk];
      }
      for (kk=colind_y[cc]; kk<colind_y[cc+1]; ++kk) {
        casadi_int kk1;
        casadi_int rr = row_y[kk];
        for (kk1=colind_x[rr]; kk1<colind_x[rr+1]; ++kk1) {
          w[row_x[kk1]] += x[kk1]*y[kk];
        }
      }
      for (kk=colind_z[cc]; kk<colind_z[cc+1]; ++kk) {
        z[kk] = w[row_z[kk]];
      }
    }
  }
}

static const casadi_int casadi_s0[4] = {0, 1, 2, 3};
static const casadi_int casadi_s1[23] = {4, 4, 0, 4, 8, 12, 16, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3};
static const casadi_int casadi_s2[17] = {4, 4, 0, 4, 7, 9, 10, 0, 1, 2, 3, 1, 2, 3, 2, 3, 3};
static const casadi_int casadi_s3[17] = {4, 4, 0, 1, 3, 6, 10, 0, 0, 1, 0, 1, 2, 0, 1, 2, 3};
static const casadi_int casadi_s4[5] = {1, 1, 0, 1, 0};
static const casadi_int casadi_s5[12] = {8, 1, 0, 8, 0, 1, 2, 3, 4, 5, 6, 7};
static const casadi_int casadi_s6[13] = {1, 8, 0, 1, 2, 2, 2, 2, 2, 2, 2, 0, 0};
static const casadi_int casadi_s7[11] = {1, 4, 0, 1, 2, 3, 4, 0, 0, 0, 0};
static const casadi_int casadi_s8[39] = {8, 4, 0, 8, 16, 24, 32, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7, 0, 1, 2, 3, 4, 5, 6, 7};
static const casadi_int casadi_s9[8] = {4, 1, 0, 4, 0, 1, 2, 3};
static const casadi_int casadi_s10[3] = {0, 0, 0};
static const casadi_int casadi_s11[16] = {12, 1, 0, 12, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
static const casadi_int casadi_s12[6] = {2, 1, 0, 2, 0, 1};

static const casadi_real casadi_c0[16] = {1., 0., 0., 0., 0., 1., 0., 0., 0., 0., 1., 0., 0., 0., 0., 1.};

/* Drone_ode_constr_h_fun:(i0[8],i1[4],i2[],i3[12])->(o0[2]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_int i, j, k;
  casadi_real *rr, *ss, *tt;
  const casadi_real *cr, *cs;
  casadi_real w0, *w1=w+9, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12, w13, *w14=w+29, *w15=w+41, *w16=w+49, *w17=w+57, *w18=w+65, *w19=w+129, *w20=w+145, *w21=w+161, *w22=w+193, *w23=w+225, *w24=w+241, *w25=w+257, *w26=w+273, *w27=w+305, *w28=w+369, *w29=w+433, *w30=w+437, *w31=w+439, *w32=w+446;
  /* #0: @0 = 0 */
  w0 = 0.;
  /* #1: @1 = zeros(1x8) */
  casadi_clear(w1, 8);
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
  /* #14: @14 = vertcat(@2, @3, @4, @5, @6, @7, @8, @9, @10, @11, @12, @13) */
  rr=w14;
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
  /* #15: @15 = @14[:8] */
  for (rr=w15, ss=w14+0; ss!=w14+8; ss+=1) *rr++ = *ss;
  /* #16: @2 = input[0][0] */
  w2 = arg[0] ? arg[0][0] : 0;
  /* #17: @3 = input[0][1] */
  w3 = arg[0] ? arg[0][1] : 0;
  /* #18: @4 = input[0][2] */
  w4 = arg[0] ? arg[0][2] : 0;
  /* #19: @5 = input[0][3] */
  w5 = arg[0] ? arg[0][3] : 0;
  /* #20: @6 = input[0][4] */
  w6 = arg[0] ? arg[0][4] : 0;
  /* #21: @7 = input[0][5] */
  w7 = arg[0] ? arg[0][5] : 0;
  /* #22: @8 = input[0][6] */
  w8 = arg[0] ? arg[0][6] : 0;
  /* #23: @9 = input[0][7] */
  w9 = arg[0] ? arg[0][7] : 0;
  /* #24: @16 = vertcat(@2, @3, @4, @5, @6, @7, @8, @9) */
  rr=w16;
  *rr++ = w2;
  *rr++ = w3;
  *rr++ = w4;
  *rr++ = w5;
  *rr++ = w6;
  *rr++ = w7;
  *rr++ = w8;
  *rr++ = w9;
  /* #25: @15 = (@15-@16) */
  for (i=0, rr=w15, cs=w16; i<8; ++i) (*rr++) -= (*cs++);
  /* #26: @17 = @15' */
  casadi_copy(w15, 8, w17);
  /* #27: @17 = (-@17) */
  for (i=0, rr=w17, cs=w17; i<8; ++i) *rr++ = (- *cs++ );
  /* #28: @18 = zeros(8x8) */
  casadi_clear(w18, 64);
  /* #29: @4 = 2 */
  w4 = 2.;
  /* #30: (@18[0] = @4) */
  for (rr=w18+0, ss=(&w4); rr!=w18+1; rr+=1) *rr = *ss++;
  /* #31: @4 = 2 */
  w4 = 2.;
  /* #32: (@18[9] = @4) */
  for (rr=w18+9, ss=(&w4); rr!=w18+10; rr+=1) *rr = *ss++;
  /* #33: @4 = 2 */
  w4 = 2.;
  /* #34: (@18[18] = @4) */
  for (rr=w18+18, ss=(&w4); rr!=w18+19; rr+=1) *rr = *ss++;
  /* #35: @4 = 2 */
  w4 = 2.;
  /* #36: (@18[27] = @4) */
  for (rr=w18+27, ss=(&w4); rr!=w18+28; rr+=1) *rr = *ss++;
  /* #37: @1 = mac(@17,@18,@1) */
  for (i=0, rr=w1; i<8; ++i) for (j=0; j<1; ++j, ++rr) for (k=0, ss=w17+j, tt=w18+i*8; k<8; ++k) *rr += ss[k*1]**tt++;
  /* #38: @17 = zeros(8x1) */
  casadi_clear(w17, 8);
  /* #39: @19 = zeros(4x4) */
  casadi_clear(w19, 16);
  /* #40: @20 = zeros(4x4) */
  casadi_clear(w20, 16);
  /* #41: @4 = cos(@5) */
  w4 = cos( w5 );
  /* #42: (@20[0] = @4) */
  for (rr=w20+0, ss=(&w4); rr!=w20+1; rr+=1) *rr = *ss++;
  /* #43: @4 = sin(@5) */
  w4 = sin( w5 );
  /* #44: @4 = (-@4) */
  w4 = (- w4 );
  /* #45: (@20[4] = @4) */
  for (rr=w20+4, ss=(&w4); rr!=w20+5; rr+=1) *rr = *ss++;
  /* #46: @4 = 0 */
  w4 = 0.;
  /* #47: (@20[8] = @4) */
  for (rr=w20+8, ss=(&w4); rr!=w20+9; rr+=1) *rr = *ss++;
  /* #48: @4 = 0 */
  w4 = 0.;
  /* #49: (@20[12] = @4) */
  for (rr=w20+12, ss=(&w4); rr!=w20+13; rr+=1) *rr = *ss++;
  /* #50: @4 = sin(@5) */
  w4 = sin( w5 );
  /* #51: (@20[1] = @4) */
  for (rr=w20+1, ss=(&w4); rr!=w20+2; rr+=1) *rr = *ss++;
  /* #52: @5 = cos(@5) */
  w5 = cos( w5 );
  /* #53: (@20[5] = @5) */
  for (rr=w20+5, ss=(&w5); rr!=w20+6; rr+=1) *rr = *ss++;
  /* #54: @5 = 0 */
  w5 = 0.;
  /* #55: (@20[9] = @5) */
  for (rr=w20+9, ss=(&w5); rr!=w20+10; rr+=1) *rr = *ss++;
  /* #56: @5 = 0 */
  w5 = 0.;
  /* #57: (@20[13] = @5) */
  for (rr=w20+13, ss=(&w5); rr!=w20+14; rr+=1) *rr = *ss++;
  /* #58: @5 = 0 */
  w5 = 0.;
  /* #59: (@20[2] = @5) */
  for (rr=w20+2, ss=(&w5); rr!=w20+3; rr+=1) *rr = *ss++;
  /* #60: @5 = 0 */
  w5 = 0.;
  /* #61: (@20[6] = @5) */
  for (rr=w20+6, ss=(&w5); rr!=w20+7; rr+=1) *rr = *ss++;
  /* #62: @5 = 1 */
  w5 = 1.;
  /* #63: (@20[10] = @5) */
  for (rr=w20+10, ss=(&w5); rr!=w20+11; rr+=1) *rr = *ss++;
  /* #64: @5 = 0 */
  w5 = 0.;
  /* #65: (@20[14] = @5) */
  for (rr=w20+14, ss=(&w5); rr!=w20+15; rr+=1) *rr = *ss++;
  /* #66: @5 = 0 */
  w5 = 0.;
  /* #67: (@20[3] = @5) */
  for (rr=w20+3, ss=(&w5); rr!=w20+4; rr+=1) *rr = *ss++;
  /* #68: @5 = 0 */
  w5 = 0.;
  /* #69: (@20[7] = @5) */
  for (rr=w20+7, ss=(&w5); rr!=w20+8; rr+=1) *rr = *ss++;
  /* #70: @5 = 0 */
  w5 = 0.;
  /* #71: (@20[11] = @5) */
  for (rr=w20+11, ss=(&w5); rr!=w20+12; rr+=1) *rr = *ss++;
  /* #72: @5 = 1 */
  w5 = 1.;
  /* #73: (@20[15] = @5) */
  for (rr=w20+15, ss=(&w5); rr!=w20+16; rr+=1) *rr = *ss++;
  /* #74: @21 = horzcat(@19, @20) */
  rr=w21;
  for (i=0, cs=w19; i<16; ++i) *rr++ = *cs++;
  for (i=0, cs=w20; i<16; ++i) *rr++ = *cs++;
  /* #75: @22 = @21' */
  for (i=0, rr=w22, cs=w21; i<8; ++i) for (j=0; j<4; ++j) rr[i+j*8] = *cs++;
  /* #76: @19 = zeros(4x4) */
  casadi_clear(w19, 16);
  /* #77: @20 = zeros(4x4) */
  casadi_clear(w20, 16);
  /* #78: @23 = 
  [[1, 0, 0, 0], 
   [0, 1, 0, 0], 
   [0, 0, 1, 0], 
   [0, 0, 0, 1]] */
  casadi_copy(casadi_c0, 16, w23);
  /* #79: @24 = zeros(4x4) */
  casadi_clear(w24, 16);
  /* #80: @5 = 0.6756 */
  w5 = 6.7559999999999998e-01;
  /* #81: (@24[0] = @5) */
  for (rr=w24+0, ss=(&w5); rr!=w24+1; rr+=1) *rr = *ss++;
  /* #82: @5 = 0 */
  w5 = 0.;
  /* #83: (@24[4] = @5) */
  for (rr=w24+4, ss=(&w5); rr!=w24+5; rr+=1) *rr = *ss++;
  /* #84: @5 = 0 */
  w5 = 0.;
  /* #85: (@24[8] = @5) */
  for (rr=w24+8, ss=(&w5); rr!=w24+9; rr+=1) *rr = *ss++;
  /* #86: @5 = 0 */
  w5 = 0.;
  /* #87: (@24[12] = @5) */
  for (rr=w24+12, ss=(&w5); rr!=w24+13; rr+=1) *rr = *ss++;
  /* #88: @5 = 0 */
  w5 = 0.;
  /* #89: (@24[1] = @5) */
  for (rr=w24+1, ss=(&w5); rr!=w24+2; rr+=1) *rr = *ss++;
  /* #90: @5 = 0.6344 */
  w5 = 6.3439999999999996e-01;
  /* #91: (@24[5] = @5) */
  for (rr=w24+5, ss=(&w5); rr!=w24+6; rr+=1) *rr = *ss++;
  /* #92: @5 = 0 */
  w5 = 0.;
  /* #93: (@24[9] = @5) */
  for (rr=w24+9, ss=(&w5); rr!=w24+10; rr+=1) *rr = *ss++;
  /* #94: @5 = 0 */
  w5 = 0.;
  /* #95: (@24[13] = @5) */
  for (rr=w24+13, ss=(&w5); rr!=w24+14; rr+=1) *rr = *ss++;
  /* #96: @5 = 0 */
  w5 = 0.;
  /* #97: (@24[2] = @5) */
  for (rr=w24+2, ss=(&w5); rr!=w24+3; rr+=1) *rr = *ss++;
  /* #98: @5 = 0 */
  w5 = 0.;
  /* #99: (@24[6] = @5) */
  for (rr=w24+6, ss=(&w5); rr!=w24+7; rr+=1) *rr = *ss++;
  /* #100: @5 = 0.408 */
  w5 = 4.0799999999999997e-01;
  /* #101: (@24[10] = @5) */
  for (rr=w24+10, ss=(&w5); rr!=w24+11; rr+=1) *rr = *ss++;
  /* #102: @5 = 0 */
  w5 = 0.;
  /* #103: (@24[14] = @5) */
  for (rr=w24+14, ss=(&w5); rr!=w24+15; rr+=1) *rr = *ss++;
  /* #104: @5 = 0 */
  w5 = 0.;
  /* #105: (@24[3] = @5) */
  for (rr=w24+3, ss=(&w5); rr!=w24+4; rr+=1) *rr = *ss++;
  /* #106: @5 = 0 */
  w5 = 0.;
  /* #107: (@24[7] = @5) */
  for (rr=w24+7, ss=(&w5); rr!=w24+8; rr+=1) *rr = *ss++;
  /* #108: @5 = 0 */
  w5 = 0.;
  /* #109: (@24[11] = @5) */
  for (rr=w24+11, ss=(&w5); rr!=w24+12; rr+=1) *rr = *ss++;
  /* #110: @5 = 0.2953 */
  w5 = 2.9530000000000001e-01;
  /* #111: (@24[15] = @5) */
  for (rr=w24+15, ss=(&w5); rr!=w24+16; rr+=1) *rr = *ss++;
  /* #112: @23 = (@24\@23) */
  rr = w23;
  ss = w24;
  {
    /* FIXME(@jaeandersson): Memory allocation can be avoided */
    casadi_real v[10], r[10], beta[4], w[8];
    casadi_qr(casadi_s1, ss, w, casadi_s2, v, casadi_s3, r, beta, casadi_s0, casadi_s0);
    casadi_qr_solve(rr, 4, 0, casadi_s2, v, casadi_s3, r, beta, casadi_s0, casadi_s0, w);
  }
  /* #113: @25 = zeros(4x4) */
  casadi_clear(w25, 16);
  /* #114: @5 = 0.5941 */
  w5 = 5.9409999999999996e-01;
  /* #115: (@25[0] = @5) */
  for (rr=w25+0, ss=(&w5); rr!=w25+1; rr+=1) *rr = *ss++;
  /* #116: @5 = -0.8109 */
  w5 = -8.1089999999999995e-01;
  /* #117: @5 = (@5*@9) */
  w5 *= w9;
  /* #118: (@25[4] = @5) */
  for (rr=w25+4, ss=(&w5); rr!=w25+5; rr+=1) *rr = *ss++;
  /* #119: @5 = 0 */
  w5 = 0.;
  /* #120: (@25[8] = @5) */
  for (rr=w25+8, ss=(&w5); rr!=w25+9; rr+=1) *rr = *ss++;
  /* #121: @5 = 0 */
  w5 = 0.;
  /* #122: (@25[12] = @5) */
  for (rr=w25+12, ss=(&w5); rr!=w25+13; rr+=1) *rr = *ss++;
  /* #123: @5 = 0.3984 */
  w5 = 3.9839999999999998e-01;
  /* #124: @5 = (@5*@9) */
  w5 *= w9;
  /* #125: (@25[1] = @5) */
  for (rr=w25+1, ss=(&w5); rr!=w25+2; rr+=1) *rr = *ss++;
  /* #126: @5 = 0.704 */
  w5 = 7.0399999999999996e-01;
  /* #127: (@25[5] = @5) */
  for (rr=w25+5, ss=(&w5); rr!=w25+6; rr+=1) *rr = *ss++;
  /* #128: @5 = 0 */
  w5 = 0.;
  /* #129: (@25[9] = @5) */
  for (rr=w25+9, ss=(&w5); rr!=w25+10; rr+=1) *rr = *ss++;
  /* #130: @5 = 0 */
  w5 = 0.;
  /* #131: (@25[13] = @5) */
  for (rr=w25+13, ss=(&w5); rr!=w25+14; rr+=1) *rr = *ss++;
  /* #132: @5 = 0 */
  w5 = 0.;
  /* #133: (@25[2] = @5) */
  for (rr=w25+2, ss=(&w5); rr!=w25+3; rr+=1) *rr = *ss++;
  /* #134: @5 = 0 */
  w5 = 0.;
  /* #135: (@25[6] = @5) */
  for (rr=w25+6, ss=(&w5); rr!=w25+7; rr+=1) *rr = *ss++;
  /* #136: @5 = 0.9365 */
  w5 = 9.3650000000000000e-01;
  /* #137: (@25[10] = @5) */
  for (rr=w25+10, ss=(&w5); rr!=w25+11; rr+=1) *rr = *ss++;
  /* #138: @5 = 0 */
  w5 = 0.;
  /* #139: (@25[14] = @5) */
  for (rr=w25+14, ss=(&w5); rr!=w25+15; rr+=1) *rr = *ss++;
  /* #140: @5 = 0 */
  w5 = 0.;
  /* #141: (@25[3] = @5) */
  for (rr=w25+3, ss=(&w5); rr!=w25+4; rr+=1) *rr = *ss++;
  /* #142: @5 = 0 */
  w5 = 0.;
  /* #143: (@25[7] = @5) */
  for (rr=w25+7, ss=(&w5); rr!=w25+8; rr+=1) *rr = *ss++;
  /* #144: @5 = 0 */
  w5 = 0.;
  /* #145: (@25[11] = @5) */
  for (rr=w25+11, ss=(&w5); rr!=w25+12; rr+=1) *rr = *ss++;
  /* #146: @5 = 0.9752 */
  w5 = 9.7519999999999996e-01;
  /* #147: (@25[15] = @5) */
  for (rr=w25+15, ss=(&w5); rr!=w25+16; rr+=1) *rr = *ss++;
  /* #148: @20 = mac(@23,@25,@20) */
  for (i=0, rr=w20; i<4; ++i) for (j=0; j<4; ++j, ++rr) for (k=0, ss=w23+j, tt=w25+i*4; k<4; ++k) *rr += ss[k*4]**tt++;
  /* #149: @20 = (-@20) */
  for (i=0, rr=w20, cs=w20; i<16; ++i) *rr++ = (- *cs++ );
  /* #150: @21 = horzcat(@19, @20) */
  rr=w21;
  for (i=0, cs=w19; i<16; ++i) *rr++ = *cs++;
  for (i=0, cs=w20; i<16; ++i) *rr++ = *cs++;
  /* #151: @26 = @21' */
  for (i=0, rr=w26, cs=w21; i<8; ++i) for (j=0; j<4; ++j) rr[i+j*8] = *cs++;
  /* #152: @27 = horzcat(@22, @26) */
  rr=w27;
  for (i=0, cs=w22; i<32; ++i) *rr++ = *cs++;
  for (i=0, cs=w26; i<32; ++i) *rr++ = *cs++;
  /* #153: @28 = @27' */
  for (i=0, rr=w28, cs=w27; i<8; ++i) for (j=0; j<8; ++j) rr[i+j*8] = *cs++;
  /* #154: @17 = mac(@28,@16,@17) */
  for (i=0, rr=w17; i<1; ++i) for (j=0; j<8; ++j, ++rr) for (k=0, ss=w28+j, tt=w16+i*8; k<8; ++k) *rr += ss[k*8]**tt++;
  /* #155: @16 = zeros(8x1) */
  casadi_clear(w16, 8);
  /* #156: @19 = zeros(4x4) */
  casadi_clear(w19, 16);
  /* #157: @20 = 
  [[1, 0, 0, 0], 
   [0, 1, 0, 0], 
   [0, 0, 1, 0], 
   [0, 0, 0, 1]] */
  casadi_copy(casadi_c0, 16, w20);
  /* #158: @20 = (@24\@20) */
  rr = w20;
  ss = w24;
  {
    /* FIXME(@jaeandersson): Memory allocation can be avoided */
    casadi_real v[10], r[10], beta[4], w[8];
    casadi_qr(casadi_s1, ss, w, casadi_s2, v, casadi_s3, r, beta, casadi_s0, casadi_s0);
    casadi_qr_solve(rr, 4, 0, casadi_s2, v, casadi_s3, r, beta, casadi_s0, casadi_s0, w);
  }
  /* #159: @24 = @20' */
  for (i=0, rr=w24, cs=w20; i<4; ++i) for (j=0; j<4; ++j) rr[i+j*4] = *cs++;
  /* #160: @22 = horzcat(@19, @24) */
  rr=w22;
  for (i=0, cs=w19; i<16; ++i) *rr++ = *cs++;
  for (i=0, cs=w24; i<16; ++i) *rr++ = *cs++;
  /* #161: @26 = @22' */
  for (i=0, rr=w26, cs=w22; i<8; ++i) for (j=0; j<4; ++j) rr[i+j*8] = *cs++;
  /* #162: @5 = input[1][0] */
  w5 = arg[1] ? arg[1][0] : 0;
  /* #163: @9 = input[1][1] */
  w9 = arg[1] ? arg[1][1] : 0;
  /* #164: @4 = input[1][2] */
  w4 = arg[1] ? arg[1][2] : 0;
  /* #165: @6 = input[1][3] */
  w6 = arg[1] ? arg[1][3] : 0;
  /* #166: @29 = vertcat(@5, @9, @4, @6) */
  rr=w29;
  *rr++ = w5;
  *rr++ = w9;
  *rr++ = w4;
  *rr++ = w6;
  /* #167: @16 = mac(@26,@29,@16) */
  for (i=0, rr=w16; i<1; ++i) for (j=0; j<8; ++j, ++rr) for (k=0, ss=w26+j, tt=w29+i*4; k<4; ++k) *rr += ss[k*8]**tt++;
  /* #168: @16 = (@17+@16) */
  for (i=0, rr=w16, cr=w17, cs=w16; i<8; ++i) (*rr++)  = ((*cr++)+(*cs++));
  /* #169: @0 = mac(@1,@16,@0) */
  for (i=0, rr=(&w0); i<1; ++i) for (j=0; j<1; ++j, ++rr) for (k=0, ss=w1+j, tt=w16+i*8; k<8; ++k) *rr += ss[k*1]**tt++;
  /* #170: @5 = 0.9 */
  w5 = 9.0000000000000002e-01;
  /* #171: @9 = 0 */
  w9 = 0.;
  /* #172: @1 = zeros(1x8) */
  casadi_clear(w1, 8);
  /* #173: @4 = 0.5 */
  w4 = 5.0000000000000000e-01;
  /* #174: @16 = @15' */
  casadi_copy(w15, 8, w16);
  /* #175: @16 = (@4*@16) */
  for (i=0, rr=w16, cs=w16; i<8; ++i) (*rr++)  = (w4*(*cs++));
  /* #176: @1 = mac(@16,@18,@1) */
  for (i=0, rr=w1; i<8; ++i) for (j=0; j<1; ++j, ++rr) for (k=0, ss=w16+j, tt=w18+i*8; k<8; ++k) *rr += ss[k*1]**tt++;
  /* #177: @9 = mac(@1,@15,@9) */
  for (i=0, rr=(&w9); i<1; ++i) for (j=0; j<1; ++j, ++rr) for (k=0, ss=w1+j, tt=w15+i*8; k<8; ++k) *rr += ss[k*1]**tt++;
  /* #178: @5 = (@5*@9) */
  w5 *= w9;
  /* #179: @0 = (@0+@5) */
  w0 += w5;
  /* #180: output[0][0] = @0 */
  if (res[0]) res[0][0] = w0;
  /* #181: @0 = 0 */
  w0 = 0.;
  /* #182: @30 = zeros(8x1,2nz) */
  casadi_clear(w30, 2);
  /* #183: @5 = 2.9 */
  w5 = 2.8999999999999999e+00;
  /* #184: @2 = (@2-@5) */
  w2 -= w5;
  /* #185: @5 = (2.*@2) */
  w5 = (2.* w2 );
  /* #186: @31 = ones(8x1,7nz) */
  casadi_fill(w31, 7, 1.);
  /* #187: {@9, NULL, NULL, NULL, NULL, NULL, NULL, NULL} = vertsplit(@31) */
  w9 = w31[0];
  /* #188: @5 = (@5*@9) */
  w5 *= w9;
  /* #189: @2 = sq(@2) */
  w2 = casadi_sq( w2 );
  /* #190: @9 = 0.17 */
  w9 = 1.7000000000000001e-01;
  /* #191: @3 = (@3-@9) */
  w3 -= w9;
  /* #192: @9 = sq(@3) */
  w9 = casadi_sq( w3 );
  /* #193: @2 = (@2+@9) */
  w2 += w9;
  /* #194: @2 = sqrt(@2) */
  w2 = sqrt( w2 );
  /* #195: @9 = (2.*@2) */
  w9 = (2.* w2 );
  /* #196: @5 = (@5/@9) */
  w5 /= w9;
  /* #197: @5 = (-@5) */
  w5 = (- w5 );
  /* #198: (@30[0] = @5) */
  for (rr=w30+0, ss=(&w5); rr!=w30+1; rr+=1) *rr = *ss++;
  /* #199: @3 = (2.*@3) */
  w3 = (2.* w3 );
  /* #200: @5 = ones(8x1,1nz) */
  w5 = 1.;
  /* #201: {NULL, @4, NULL, NULL, NULL, NULL, NULL, NULL} = vertsplit(@5) */
  w4 = w5;
  /* #202: @3 = (@3*@4) */
  w3 *= w4;
  /* #203: @3 = (@3/@9) */
  w3 /= w9;
  /* #204: @3 = (-@3) */
  w3 = (- w3 );
  /* #205: (@30[1] = @3) */
  for (rr=w30+1, ss=(&w3); rr!=w30+2; rr+=1) *rr = *ss++;
  /* #206: @30 = @30' */
  /* #207: @0 = mac(@30,@17,@0) */
  casadi_mtimes(w30, casadi_s6, w17, casadi_s5, (&w0), casadi_s4, w, 0);
  /* #208: @3 = 0 */
  w3 = 0.;
  /* #209: @32 = zeros(1x4) */
  casadi_clear(w32, 4);
  /* #210: @32 = mac(@30,@26,@32) */
  casadi_mtimes(w30, casadi_s6, w26, casadi_s8, w32, casadi_s7, w, 0);
  /* #211: @3 = mac(@32,@29,@3) */
  for (i=0, rr=(&w3); i<1; ++i) for (j=0; j<1; ++j, ++rr) for (k=0, ss=w32+j, tt=w29+i*4; k<4; ++k) *rr += ss[k*1]**tt++;
  /* #212: @0 = (@0+@3) */
  w0 += w3;
  /* #213: @3 = 0.8 */
  w3 = 8.0000000000000004e-01;
  /* #214: @3 = (@3-@2) */
  w3 -= w2;
  /* #215: @0 = (@0+@3) */
  w0 += w3;
  /* #216: output[0][1] = @0 */
  if (res[0]) res[0][1] = w0;
  return 0;
}

CASADI_SYMBOL_EXPORT int Drone_ode_constr_h_fun(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
  return casadi_f0(arg, res, iw, w, mem);
}

CASADI_SYMBOL_EXPORT int Drone_ode_constr_h_fun_alloc_mem(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT int Drone_ode_constr_h_fun_init_mem(int mem) {
  return 0;
}

CASADI_SYMBOL_EXPORT void Drone_ode_constr_h_fun_free_mem(int mem) {
}

CASADI_SYMBOL_EXPORT int Drone_ode_constr_h_fun_checkout(void) {
  return 0;
}

CASADI_SYMBOL_EXPORT void Drone_ode_constr_h_fun_release(int mem) {
}

CASADI_SYMBOL_EXPORT void Drone_ode_constr_h_fun_incref(void) {
}

CASADI_SYMBOL_EXPORT void Drone_ode_constr_h_fun_decref(void) {
}

CASADI_SYMBOL_EXPORT casadi_int Drone_ode_constr_h_fun_n_in(void) { return 4;}

CASADI_SYMBOL_EXPORT casadi_int Drone_ode_constr_h_fun_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT casadi_real Drone_ode_constr_h_fun_default_in(casadi_int i){
  switch (i) {
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* Drone_ode_constr_h_fun_name_in(casadi_int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    case 3: return "i3";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* Drone_ode_constr_h_fun_name_out(casadi_int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* Drone_ode_constr_h_fun_sparsity_in(casadi_int i) {
  switch (i) {
    case 0: return casadi_s5;
    case 1: return casadi_s9;
    case 2: return casadi_s10;
    case 3: return casadi_s11;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const casadi_int* Drone_ode_constr_h_fun_sparsity_out(casadi_int i) {
  switch (i) {
    case 0: return casadi_s12;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int Drone_ode_constr_h_fun_work(casadi_int *sz_arg, casadi_int* sz_res, casadi_int *sz_iw, casadi_int *sz_w) {
  if (sz_arg) *sz_arg = 16;
  if (sz_res) *sz_res = 9;
  if (sz_iw) *sz_iw = 0;
  if (sz_w) *sz_w = 450;
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif
