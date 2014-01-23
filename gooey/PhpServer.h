#pragma once
#include <Windows.h>
#include <shellapi.h>
#include <string>

class PhpServer
{
private:
	SHELLEXECUTEINFO g_phpShell;

public:
	PhpServer(void);
	~PhpServer(void);

	int StartServer(std::wstring phpExecutable, std::wstring portNumber, std::wstring webRootDirectory);
};

