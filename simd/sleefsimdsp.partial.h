
typedef struct {
  vfloat x, y;
} vfloat2;

vfloat xldexpf(vfloat x, vint2 q);

vfloat xsinf(vfloat d);
vfloat xcosf(vfloat d);
vfloat2 xsincosf(vfloat d);
vfloat xtanf(vfloat d);
vfloat xasinf(vfloat s);
vfloat xacosf(vfloat s);
vfloat xatanf(vfloat s);
vfloat xatan2f(vfloat y, vfloat x);
vfloat xlogf(vfloat d);
vfloat xexpf(vfloat d);
vfloat xcbrtf(vfloat s);
vfloat xsqrtf(vfloat s);

vfloat xpowf(vfloat x, vfloat y);
vfloat xsinhf(vfloat x);
vfloat xcoshf(vfloat x);
vfloat xtanhf(vfloat x);
vfloat xasinhf(vfloat x);
vfloat xacoshf(vfloat x);
vfloat xatanhf(vfloat x);
vfloat xexp2f(vfloat a);
vfloat xexp10f(vfloat a);
vfloat xexpm1f(vfloat a);
vfloat xlog10f(vfloat a);
vfloat xlog1pf(vfloat a);

vfloat xsinf_u1(vfloat d);
vfloat xcosf_u1(vfloat d);
vfloat2 xsincosf_u1(vfloat d);
vfloat xtanf_u1(vfloat d);
vfloat xasinf_u1(vfloat s);
vfloat xacosf_u1(vfloat s);
vfloat xatanf_u1(vfloat s);
vfloat xatan2f_u1(vfloat y, vfloat x);
vfloat xlogf_u1(vfloat d);
vfloat xcbrtf_u1(vfloat s);
