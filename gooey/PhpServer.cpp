#include "PhpServer.h"


PhpServer::PhpServer(void)
{
}


PhpServer::~PhpServer(void)
{
    TerminateProcess(g_phpShell.hProcess, EXIT_SUCCESS);
}

int PhpServer::StartServer(std::wstring phpExecutable, std::wstring portNumber, std::wstring webRootDirectory)
{
    // PHP shell parameters.
    std::wstring shellParams;
    shellParams.append(L"-S ");
    shellParams.append(L"localhost");
    shellParams.append(L":");
    shellParams.append(portNumber);
    shellParams.append(L" -t ");
    shellParams.append(webRootDirectory);

    memset(&g_phpShell, 0, sizeof(g_phpShell));
    g_phpShell.cbSize = sizeof(g_phpShell);
    g_phpShell.fMask = SEE_MASK_NOASYNC | SEE_MASK_NOCLOSEPROCESS;
    g_phpShell.hwnd = NULL;
    g_phpShell.lpVerb = L"open";

    g_phpShell.lpFile = phpExecutable.c_str();
    g_phpShell.lpParameters = shellParams.c_str();
    g_phpShell.lpDirectory = NULL;
    g_phpShell.nShow = SW_HIDE;
    g_phpShell.hInstApp = NULL;

    if (ShellExecuteEx(&g_phpShell)) {
        return true;
    }
    return false;
}