#include <Windows.h>
#include <stdio.h>

// http://www.vr-online.ru/content/s-rabotaem-s-reestrom-3235/

int main()
{
	HKEY hKey;
	DWORD dwDisposition;
	unsigned char szStr[2];
	szStr[0] = '1';
	szStr[1] = '\0';

	if (RegCreateKeyEx(HKEY_CURRENT_USER, TEXT(), 0, KEY_ALL_ACCESS, &hKey) != ERROR_SUCCESS)
	{

	}

}