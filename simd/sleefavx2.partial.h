#pragma once

#include <stdint.h>
#include <immintrin.h>

#define VECTLENDP 4
#define VECTLENSP 8

typedef __m256d vdouble;
typedef __m128i vint;

typedef __m256 vfloat;
typedef __m256i vint2;

static vdouble vloadu(double *p) { return _mm256_loadu_pd(p); }
static void vstoreu(double *p, vdouble v) { return _mm256_storeu_pd(p, v); }

static vfloat vloaduf(float *p) { return _mm256_loadu_ps(p); }
static void vstoreuf(float *p, vfloat v) { return _mm256_storeu_ps(p, v); }

static vint2 vloadui2(int32_t *p) { return _mm256_loadu_si256((__m256i const *)p); }
static void vstoreui2(int32_t *p, vint2 v) { return _mm256_storeu_si256((__m256i *)p, v); }