import glob
import os

from cffi import FFI


# include_dirs = [os.path.join('libraries', 'Rmath', 'src'),
                # os.path.join('libraries', 'Rmath', 'include')]

# rmath_src = glob.glob(os.path.join('libraries', 'Rmath', 'src', '*.c'))

ffi = FFI()
ffi.set_source('_khash_ffi', '#include "khash_int2float.h"')

ffi.cdef('''\
typedef int... khint_t;
typedef int... khint64_t;

static inline void *khash_int2float_init(void);
static void khash_int2float_destroy(void *);
static inline khint_t khash_int2float_len(void *);
static inline float khash_int2float_get(void *, khint64_t, float);
static inline khint64_t khash_int2float_get_firstkey(void *);
static inline khint64_t khash_int2float_get_maxkey(void *);
static inline float khash_int2float_pop(void *, khint64_t, float);
static inline void khash_int2float_set(void *, khint64_t, float);
static inline void khash_int2float_delete(void *, khint64_t);
''')

if __name__ == '__main__':
    ffi.compile(verbose=True)
