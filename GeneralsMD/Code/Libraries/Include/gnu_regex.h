#pragma once
#ifndef _GNU_REGEX_H_
#define _GNU_REGEX_H_

#include <cstddef>
#include <cstring>

typedef long regoff_t;
typedef struct re_pattern_buffer regex_t;
typedef int re_syntax_t;
typedef re_syntax_t reg_syntax_t;

#define RE_CHAR_CLASSES 1
#define RE_CONTEXT_INDEP_ANCHORS 2
#define RE_CONTEXT_INDEP_OPS 4
#define RE_CONTEXT_INVALID_OPS 8
#define RE_INTERVALS 16
#define RE_NO_BK_BRACES 32
#define RE_NO_BK_PARENS 64
#define RE_NO_BK_VBAR 128
#define RE_NO_EMPTY_RANGES 256
#define RE_SYNTAX_GREP 0
#define RE_SYNTAX_EMACS 0
#define RE_SYNTAX_AWK 0
#define RE_SYNTAX_POSIX_BASIC 0
#define RE_SYNTAX_POSIX_MINIMAL_BASIC 0
#define RE_SYNTAX_POSIX_EXTENDED 0
#define RE_SYNTAX_POSIX_MINIMAL_EXTENDED 0
#define RE_SYNTAX_SED 0
#define RE_SYNTAX_EGREP 0

struct re_pattern_buffer {
    unsigned char *buffer;
    unsigned long allocated;
    unsigned long used;
    re_syntax_t syntax;
    char *fastmap;
    char *translate;
    size_t re_nsub;
    unsigned can_be_null : 1;
    unsigned regs_allocated : 2;
    unsigned no_sub : 1;
    unsigned not_bol : 1;
    unsigned not_eol : 1;
};

struct re_registers {
    size_t num_regs;
    regoff_t *start;
    regoff_t *end;
};

inline const char *re_compile_pattern(const char *, size_t, struct re_pattern_buffer *) { return NULL; }
inline reg_syntax_t re_set_syntax(reg_syntax_t syntax) { return syntax; }
inline int re_search(struct re_pattern_buffer *, const char *, int, int, int, struct re_registers *) { return -1; }
inline int re_match(struct re_pattern_buffer *, const char *, int, int, struct re_registers *) { return -1; }
inline int re_match(struct re_pattern_buffer *, const char *, int, int, int) { return -1; }
inline void re_compile_fastmap(struct re_pattern_buffer *) {}
inline int re_search_2(struct re_pattern_buffer *, const char *, int, const char *, int, int, int, struct re_registers *, int) { return -1; }
inline int re_match_2(struct re_pattern_buffer *, const char *, int, const char *, int, int, struct re_registers *, int) { return -1; }
inline void re_set_registers(struct re_pattern_buffer *, struct re_registers *, size_t, regoff_t *, regoff_t *) {}
inline void regfree(struct re_pattern_buffer *) {}

#endif
