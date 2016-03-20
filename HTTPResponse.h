#ifndef _HTTP_RESPONSE_H_
#define _HTTP_RESPONSE_H_

#include <string>
#include <vector>
#include <fstream>

#include "HTTP.h"

class HTTPResponse{
	public:
		HTTPResponse();
		~HTTPResponse();

		void printResponse(void );
		void addData(const char *, int);
	
		int setProtocol(Protocol );
		Protocol getProtocol();

		int setStatusCode(size_t );
		size_t getStatusCode();

		int setReasonPhrase();
		std::string getReasonPhrase();
		
		int setHTTPHeader(const std::string &headerName, const std::string &headerContent);
		std::string getHTTPHeader(const std::string &headerName);

		int setHTTPHeaderVector(std::vector<std::pair<std::string, std::string>>* const );
		std::vector<std::pair<std::string, std::string>>* getHTTPHeaderVector();

		int setResponseBody(const std::string* );
		std::string* getResponseBodyPtr();

		int prepareResponse();
		int parseResponse();
	
		size_t getResponseSize();
		std::string* getResponseDataPtr();

		int copyToFile(ofstream& );
		int copyFromFile(ifstream&, int);

	private:
		Protocol m_protocol;
		size_t m_statusCode;
		std::string m_reasonPhrase;

		std::vector<std::pair<std::string, std::string>> m_httpHeaders;
		std::string m_responseBody;

		std::string m_data;
};

#endif
