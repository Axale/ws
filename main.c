#define WIN

#include "lib/net.h"
#include "lib/http.h"


int main(int argc, char** argv){
    SOCKET ListenSocket = INVALID_SOCKET;
    if(net_init ((void*) &ListenSocket) != 0) {
        return 1;
    }

    for(;;) {
        
    }

}
