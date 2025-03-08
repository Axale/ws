#ifndef __HTTP_DEFS__
#define __HTTP_DEFS__

#define SERVER_NAME "localhost\0"
#define VERSION "HTTP/1.0\0"
#define CONTENT_TYPE "Content-Type: \0"
#define TEXTHTML "text/html\n\0"

// Temp Content Defines
#define CONTENT_200 "<html>\nResponse 200 OK\n</html>\0"
#define CONTENT_201 "<html>\nResponse 201 CREATED\n</html>\0"
#define CONTENT_202 "<html>\nResponse 202 ACCEPTED\n</html>\0"
#define CONTENT_204 "<html>\nResponse 204 NO_CONTENT\n</html>\0"
#define CONTENT_301 "<html>\nResponse 301 MOVED PERMANENTLY\n</html>\0"
#define CONTENT_302 "<html>\nResponse 302 MOVED TEMPORARILY\n</html>\0"
#define CONTENT_304 "<html>\nResponse 304 NOT MODIFIED\n</html>\0"
#define CONTENT_400 "<html>\nResponse 400 BAD REQUEST\n</html>\0"
#define CONTENT_401 "<html>\nResponse 401 UNAUTHORIZED\n</html>\0"
#define CONTENT_403 "<html>\nResponse 403 FORBIDDEN\n</html>\0"
#define CONTENT_404 "<html>\nResponse 404 NOT FOUND\n</html>\0"
#define CONTENT_500 "<html>\nResponse 500 INTERNAL SERVER ERROR\n</html>\0"
#define CONTENT_501 "<html>\nResponse 501 NOT IMPLEMENTED\n</html>\0"
#define CONTENT_502 "<html>\nResponse 502 BAD GATEWAY\n</html>\0"
#define CONTENT_503 "<html>\nResponse 503 SERVICE UNAVAIABLE\n</html>\0"

// Header Defines
#define SL_200 "200 OK\n\0"
#define SL_400 "400 Bad Request\n\0"
#define SL_404 "404 Not Found\n\0"
#define SL_500 "500 Internal Server Error\n\0"
#define SL_501 "501 Not Implemented\n\0"

#endif