#include <stdint.h>
#include <immintrin.h>

#define VECTLENDP 2
#define VECTLENSP 4

typedef __m128d vdouble;
typedef __m128i vint;

typedef __m128 vfloat;
typedef __m128i vint2;

static vdouble vloadu(double *p) { return _mm_loadu_pd(p); }
static void vstoreu(double *p, vdouble v) { _mm_storeu_pd(p, v); }

static vfloat vloaduf(float *p) { return _mm_loadu_ps(p); }
static void vstoreuf(float *p, vfloat v) { _mm_storeu_ps(p, v); }

static vint2 vloadui2(int32_t *p) { return (vint2)_mm_loadu_si128((__m128i *)p); }
static void vstoreui2(int32_t *p, vint2 v) { _mm_storeu_si128((__m128i *)p, (__m128i)v); }