
typedef struct {
  vdouble x, y;
} vdouble2;

vdouble xldexp(vdouble x, vint q);
vint xilogb(vdouble d);

vdouble xsin(vdouble d);
vdouble xcos(vdouble d);
vdouble2 xsincos(vdouble d);
vdouble xtan(vdouble d);
vdouble xasin(vdouble s);
vdouble xacos(vdouble s);
vdouble xatan(vdouble s);
vdouble xatan2(vdouble y, vdouble x);
vdouble xlog(vdouble d);
vdouble xexp(vdouble d);
vdouble xpow(vdouble x, vdouble y);

vdouble xsinh(vdouble d);
vdouble xcosh(vdouble d);
vdouble xtanh(vdouble d);
vdouble xasinh(vdouble s);
vdouble xacosh(vdouble s);
vdouble xatanh(vdouble s);

vdouble xcbrt(vdouble d);

vdouble xexp2(vdouble a);
vdouble xexp10(vdouble a);
vdouble xexpm1(vdouble a);
vdouble xlog10(vdouble a);
vdouble xlog1p(vdouble a);

vdouble xsin_u1(vdouble d);
vdouble xcos_u1(vdouble d);
vdouble2 xsincos_u1(vdouble d);
vdouble xtan_u1(vdouble d);
vdouble xasin_u1(vdouble s);
vdouble xacos_u1(vdouble s);
vdouble xatan_u1(vdouble s);
vdouble xatan2_u1(vdouble y, vdouble x);
vdouble xlog_u1(vdouble d);
vdouble xcbrt_u1(vdouble d);