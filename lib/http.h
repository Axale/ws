#ifndef __HTTP__
#define __HTTP__
#include <stdint.h>

typedef enum req_type {
    FULL_REQ, FULL_RES, SIMP_REQ, SIMP_RES
} req_type_e;

typedef enum header_type {
    NO_HEADER, GEN_HEADER, REQ_HEADER, ENTITY_HEADER, RES_HEADER
} header_type_e;

typedef enum version_enum {
    HTTP09, HTTP10, HTTP11, HTTP20, HTTP30
} version_enum_e;

typedef enum method {
    GET, INVD
} method_e;

typedef enum content_type {
    HTML, GIF, PNG, JPG, JPEG
} content_type_e;

typedef enum resp_code {
    OK, CREATED, ACCEPTED, //2xx
    NO_CONTENT, MULTIPLE, MOVED_PERM, MOVED_TEMP, //3xx
    NOT_MOD, BAD_REQ, UNAUTH, FORBIDDEN, NOT_FOUND, //4xx
    INTERNAL_ERR, NOT_IMPLEMENTED, BAD_GATEWAY, SERVICE_UNAVIALABLE //5xx
} resp_code_e;

typedef struct message {
    char req_uri[2048];
    int req_uri_len;
    method_e method;
    version_enum_e version;
    req_type_e request_type;
    char* data;
    int bad;
} message_t;

typedef struct response {
    req_type_e response_type;
    resp_code_e status;
    header_type_e hdr_type;
    content_type_e cont_type;
    char hdr[256];
    char content[2048]; 

} response_t;

typedef struct resp_msg {
    char msgstr[4096];
    int len;
} resp_msg_t;
// Parse the message into the struct
// Return NULL on failure
message_t* parse_msg(char* str_msg);
response_t* exec(message_t* msg);
resp_msg_t* concat_resp(response_t* resp);
int clean(char* str_msg, resp_msg_t* resp_msg, message_t* msg, response_t* resp);



// Gets the data





#endif