#include "StdAfx.h"
#include "GameHooks.hpp"

#if IS_BP

DAPIFUNC_IMP(connect, int, WSAAPI, (SOCKET s, const sockaddr* name, int namelen))
{
	if (s == INVALID_SOCKET || namelen < 1)
		return -1;

	if (namelen == sizeof(sockaddr_in))
	{
		const sockaddr_in* pAddrIn = reinterpret_cast<const sockaddr_in*>(name);

		int port = ntohs(pAddrIn->sin_port);

		std::string ss = "connect: ";
		char ip[44];

		inet_ntop(pAddrIn->sin_family, &pAddrIn->sin_addr, ip, sizeof(ip));

		ss += ip;
		ss += ":";
		ss += std::to_string(port);

		MessageBoxA(NULL, ss.c_str(), "LOG", MB_OK);
	}

	return Trueconnect(s, name, namelen);
}

#endif // IS_BP
