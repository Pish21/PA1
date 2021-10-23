#include <iostream>
#include <string.h>
#include <string> 
#include "version.h"

using namespace std;

int main(int vargs, char* argv[])
{
	//This is just a comment.
	//This is a second comment for github project



	cout << "Current version is " ;
	cout << displayVersion(1.2) << endl;
	cout << "\n" << endl;



	string url = "https://cs.utdallas.edu:80/directory/faculty/people.html?name=Robert"; // enter the URL here. 
	// Predifined list of valid protocols
	string validProtocols[] = {"ftp","ftps", "http", "https" };
	string validHost[] = { "com", "net", "edu", "biz", "gov" };
	int index = 0;
	// Find the index of occurrance of "://" to get the protocol name
	string protocol = url.substr(0, url.find("://"));
	// Check if protocol name is present in validProtocols
	for (int i = 0; i < 4; i++)
	{
		if (protocol == validProtocols[i])
		{
			cout << "protocol: " << protocol << endl;
			break;
		}
		if (i == 3)
		{
			// If protocol not there print error messsage
			cout << protocol << " is not a valid protocol" << endl;
			return 1;
		}
	}
	// Get all characters after protocol (but not://)
	string afterProtocol = url.substr(url.find("://") + 3);
	// Get all characters upto "/" which contains domain and port
	string domain = afterProtocol.substr(0, afterProtocol.find("/"));
	// get port number from substring (number after ':')
	int port = stoi(domain.substr(domain.find(":") + 1));

	// Check if port is valid
	if (port < 1 || port > 65535)
	{
		// If not valid show error message and exit
		cout << "Port number must be between 1 and 65535" << endl;
	}

	// Get domain name (chars before ':')
	domain = domain.substr(0, domain.find(":"));
	cout << "Domain: " << domain << endl;
	cout << "Port: " << port << endl;

	// Get all characters after '/'
	string afterDomain = afterProtocol.substr(afterProtocol.find("/") + 1);
	//get all characters before ? (It contains file path)
	string filePath = afterDomain.substr(0, afterDomain.find("?"));
	cout << "File Path: " << filePath << endl;

	// get all characters after ? (It contains parameters)
	string parameters = afterDomain.substr(afterDomain.find("?") + 1);
	cout << "Parameters: " << parameters << endl;
}
