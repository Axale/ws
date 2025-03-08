#include "http.h"
#include "http_defs.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

int __get_method(char* strmsg, message_t* msg) {
    // better search coming soon tm
    if(strncmp(strmsg, "GET", 3)) {
        msg->method = GET;
    } else {
        msg->bad = 1;
        return -1;
    }

    return 0;
}

int __get_uri(char* strmsg, message_t* msg, int *index) {

    if(strmsg[(*index)++] != ' ') {
        msg->bad = 1;
        return -1;
    }

    // implement no space error
    for(; strmsg[*index] == ' ' || strmsg[*index] == '\r'; (*index)++) {

        if(strmsg[*index] != NULL && (*index - 3) < 2048) {
            msg->req_uri[*index - 3] = strmsg[*index];
        } else {
            msg->bad = 1;
            return -1;
        }
    }
    
    msg->req_uri_len = *index - 3;

    return 0;
}

// IMPLEMENT OOB PROTECTION!!!!!!!!!!!!!!!!!!!!!!!!
message_t* parse_msg(char* strmsg, int strlen) {
    message_t* msg = malloc(sizeof(*msg));

    if(msg == NULL) return NULL;

    msg->method = INVD;
    msg->request_type = SIMP_REQ;
    msg->version = HTTP09;
    msg->bad = 0;

    if(__get_method(strmsg, msg) < 0) return msg;
    int index = 3;

    if(__get_uri(strmsg, msg, &index) < 0) return msg;

    if(strmsg[index] == '\r' && strmsg[index + 1] == '\n') {
        return msg;
    }

    // Full request handling will be in a bit.
    return msg;

}  

int __get_data(message_t* msg, response_t* resp) {
    strcpy(resp->content, CONTENT_200);
    return 0;
}

void __exec_bad(message_t* msg, response_t* resp) {
    if(msg->method == INVD) {
        resp->status = NOT_IMPLEMENTED;
        strcpy(resp->content, CONTENT_501);
        return;
    }

    resp->status = BAD_REQ;
    strcpy(resp->content, CONTENT_400);

    return;
}

response_t* exec(message_t* msg) {
    response_t* resp =  malloc(sizeof(*resp));
    if(resp == NULL) return NULL;

    resp->response_type = FULL_RES;
    resp->hdr_type = RES_HEADER;
    resp->cont_type = HTML;
    resp->status = OK;

    if(msg->bad == 1) {
        __exec_bad(msg, resp);
        return resp;
    }

    int err = 0;
    switch(msg->method) {
        case GET: 
            err = __get_data(msg, resp);
            break;
        default: 
            __exec_bad(msg, resp);
    }

    if(err) {
        strcpy(resp->content, CONTENT_404);
    }

    return resp;
}

void __strcpy_iterate(resp_msg_t* rmsg, char* source) {
    
    int src_index = 0;
    for(; source[src_index] != '\0'; src_index++) {
        rmsg->msgstr[src_index + rmsg->len] = source[src_index];
    }

    rmsg->len += src_index;
}

void __construct_header(response_t* resp, resp_msg_t* rmsg) {
    
    __strcpy_iterate(rmsg, VERSION);
    __strcpy_iterate(rmsg, ' ');

    switch(resp->response_type) {
        case OK: 
            __strcpy_iterate(rmsg, SL_200);
            break;
        case BAD_REQ: 
            __strcpy_iterate(rmsg, SL_400);
            break;
        case NOT_FOUND: 
            __strcpy_iterate(rmsg, SL_404);
            break;
        case INTERNAL_ERR: 
            __strcpy_iterate(rmsg, SL_500);
            break;
        default: 
            __strcpy_iterate(rmsg, SL_501);
            break;
    }

    __strcpy_iterate(rmsg, CONTENT_TYPE);
    __strcpy_iterate(rmsg, TEXTHTML);
}

resp_msg_t* concat_resp(response_t* resp) {
    
    resp_msg_t* rmsg = malloc(sizeof(*rmsg));
    if(rmsg = NULL) return NULL;
    
    rmsg->len = 0;
    memset(rmsg->msgstr, 0, 4096);
    
    __construct_header(rmsg, resp);
    __strcpy_iterate(resp, "\r\0");

    switch(resp->response_type) {
        case OK: 
            __strcpy_iterate(rmsg, CONTENT_200);
            break;
        case BAD_REQ: 
            __strcpy_iterate(rmsg, CONTENT_400);
            break;
        case NOT_FOUND: 
            __strcpy_iterate(rmsg, CONTENT_404);
            break;
        case INTERNAL_ERR: 
            __strcpy_iterate(rmsg, CONTENT_500);
            break;
        default: 
            __strcpy_iterate(rmsg, CONTENT_501);
            break;
    }

    rmsg->msgstr[rmsg->len++] = '\0';

    return rmsg;

}