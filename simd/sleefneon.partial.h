#include <stdint.h>
#include <arm_neon.h>

#define VECTLENSP 4

//typedef __m128d vdouble;
typedef int32x4_t vint;
typedef uint32x4_t vmask;

typedef float32x4_t vfloat;
typedef int32x4_t vint2;

//static vdouble vloadu(double *p) { return _mm_loadu_pd(p); }
//static void vstoreu(double *p, vdouble v) { _mm_storeu_pd(p, v); }

static vfloat vloaduf(float *p) { return vld1q_f32(p); }
static void vstoreuf(float *p, vfloat v) { vst1q_f32(p, v); }

static vint2 vloadui2(int32_t *p) { return (vint2)vld1q_s32(p); }
static void vstoreui2(int32_t *p, vint2 v) { vst1q_s32(p, v); }