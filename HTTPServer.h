#ifndef _HTTP_SERVER_H_
#define _HTTP_SERVER_H_

#include <arpa/inet.h>
#include <sys/socket.h>

#include "HTTPRequest.h"
#include "HTTPResponse.h"

#define SVR_ROOT "www"

class HTTPServer{
	public:
		HTTPServer();
		HTTPServer(int );
		~HTTPServer();

		int run(void );
		int setPort(size_t );
		int initSocket();

		int handleRequest();
		int recvRequest();
		int parseRequest();
		int prepareResponse();
		int sendResponse();
		int processRequest();
	
	private:
		std::string getMimeType(const std::string &);

		size_t svrPort;
		int sockfd, newsockfd;
		socklen_t cliLen;
		struct sockaddr_in servAddr, cliAddr;

		std::string m_url;
		std::string m_mimeType;
		HTTPRequest* m_httpRequest;
		HTTPResponse* m_httpResponse;
		static const int buf_sz = 32;
};

#endif
