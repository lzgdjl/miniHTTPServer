#ifndef _HTTP_REQUEST_H_
#define _HTTP_REQUEST_H_

#include <string>
#include <vector>
#include <fstream>

#include "HTTP.h"

class HTTPRequest{
	public:
		HTTPRequest();
		~HTTPRequest();
	
		void printRequest();
		void addData(const char *, int);
		void addRequestBody(const std::string&);
		
		int setMethod(Method);
		Method getMethod();

		int setURL(std::string&);
		std::string getURL();

		int setProtocol(Protocol);
		Protocol getProtocol();

		int setUserAgent(std::string &userAgent);
		std::string getUserAgent();

		int setHTTPHeader(const std::string &header_name, const std::string &header_content);
		std::string getHTTPHeader(const std::string &headerName);

		int setHTTPHeaderVector(std::vector<std::pair<std::string, std::string>>* const );
		std::vector<std::pair<std::string,std::string>>* getHTTPHeaderVector();

		int setRequestBody(const std::string*);
		std::string* getRequestBodyPtr();

		int parseRequest();
		int prepareRequest();
		size_t getRequestSize();
		std::string* getRequestDataPtr();

		int copyToFile(ofstream& );
		int copyFromFile(ifstream&, size_t);

	private:
		Method m_httpMethod;
		std::string m_url;
		Protocol m_protocol;
		std::string m_hostName;
		std::string m_userAgent;

		std::vector<std::pair<std::string, std::string>> http_headers;
		std::string request_body;
		
		std::string data;
};

#endif

