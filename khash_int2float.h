#ifndef KHASH_INT2FLOAT_H
#define KHASH_INT2FLOAT_H

#include "khash.h"

KHASH_MAP_INIT_INT64(i2f, float)

static inline void *khash_int2float_init(void) {
    return kh_init(i2f);
}

static void khash_int2float_destroy(void *_hash) {
    khash_t(i2f) *hash = (khash_t(i2f)*)_hash;
    if (hash) kh_destroy(i2f, hash);
}

static inline khint_t khash_int2float_len(void *_hash)
{
    khash_t(i2f) *hash = (khash_t(i2f)*)_hash;
    return kh_size(hash);
}

static inline float khash_int2float_get(void *_hash, khint64_t key, float default_value) {
    khash_t(i2f) *hash = (khash_t(i2f)*)_hash;
    khint_t k = kh_get(i2f, hash, key);
    if ( k == kh_end(hash) ) return default_value;
    return kh_val(hash, k);
}

static inline khint64_t khash_int2float_get_firstkey(void *_hash) {
    khash_t(i2f) *hash = (khash_t(i2f)*)_hash;
    for (khint_t __i = kh_begin(hash); __i != kh_end(hash); ++__i) {
		if (!kh_exist(hash, __i)) continue;
		return kh_key(hash, __i);
    }
    return -1;
}

static inline khint64_t khash_int2float_get_maxkey(void *_hash) {
    float val = 0, max = 0;
    khint64_t maxkey = 0;
    khash_t(i2f) *hash = (khash_t(i2f)*)_hash;
    for (khint_t __i = kh_begin(hash); __i != kh_end(hash); ++__i) {
		if (!kh_exist(hash, __i)) continue;
        val = kh_val(hash, __i);
        if (val > max) {
            maxkey = kh_key(hash, __i);
            max = val;
        }
    }
    return maxkey;
}

static inline float khash_int2float_pop(void *_hash, khint64_t key, float default_value) {
    khash_t(i2f) *hash = (khash_t(i2f)*)_hash;
    khint_t k = kh_get(i2f, hash, key);
    if ( k == kh_end(hash) ) return default_value;
    float val = kh_val(hash, k);
    kh_del(i2f, hash, k);
    return val;
}

static inline void khash_int2float_set(void *_hash, khint64_t key, float value)
{
    khint_t k;
    int ret;
    khash_t(i2f) *hash = (khash_t(i2f)*)_hash;
    k = kh_put(i2f, hash, key, &ret);
    kh_val(hash, k) = value;
}

static inline void khash_int2float_delete(void *_hash, khint64_t key)
{
    khash_t(i2f) *hash = (khash_t(i2f)*)_hash;
    khint_t k = kh_get(i2f, hash, key);
    kh_del(i2f, hash, k);
}

#endif
