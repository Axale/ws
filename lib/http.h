#ifndef __HTTP__
#define __HTTP__
#include <stdint.h>

typedef enum req_type {
    FULL_REQ, FULL_REP, SIMP_REQ, SIMP_RES
} req_type_e;

typedef enum header_type {
    NO_HEADER, GEN_HEADER, REQ_HEADER, ENTITY_HEADER
} header_type_e;

typedef struct message {
    char method[16];
    char req_uri[128];
    char version[16];
    req_type_e request_type;
    char* data;
} message_t;


#endif