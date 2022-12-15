#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>
#include <malloc.h>

// http://www.vr-online.ru/content/s-rabotaem-s-reestrom-3235/

void saveChanges(HKEY);
void loadSettings();
void textSettings();
void textColor();
void textSize();
void textFont();
void textType();

HKEY hKey;
CONSOLE_FONT_INFOEX cfie;
HANDLE hout;

int main()
{
	system("chcp 1251>n");
	
	DWORD dwDisposition;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);

	loadSettings();
	/*if (RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("Test"), 0, NULL, 0, 0, NULL, &hKey, &dwDisposition) == ERROR_SUCCESS)
	{
		printf("hello");
	}
	else
	{
		printf("hello123");
	}

	if (RegOpenKeyEx(HKEY_CURRENT_USER, TEXT("Test"), 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS)
	{
		printf("aboba");

		if (RegSetValueEx(hKey, TEXT("stringName"), NULL, REG_SZ, szStr, sizeof(szStr)) == ERROR_SUCCESS)
		{
			printf("Удачно записалось");
		}
		else
		{
			printf("неудача");
		}
	}
	else 
	{
		printf("aboba123");
	}*/
	//system("color 2");
	
	
	/*cfie.cbSize = sizeof(cfie);
	cfie.nFont = 0;
	cfie.dwFontSize.X = 0;
	cfie.dwFontSize.Y = 24;
	cfie.FontFamily = FF_DONTCARE;
	cfie.FontWeight = FW_BOLD;
	
	lstrcpyW(cfie.FaceName, L"Cascadia Code");
	
	SetCurrentConsoleFontEx(
		hout,
		FALSE, 
		&cfie);*/

	//SetConsoleTextAttribute(hout, FOREGROUND_BLUE);
	
	/*COORD coord;
	coord.X = 0;
	coord.Y = 0;
	DWORD check;*/
	/*printf("awdawd\n");
	printf("awdawd\n");
	printf("awdawd\n");
	printf("awdawd\n");
	printf("awdawd\n");
	printf("awdawd\n");
	printf("awdawd\n");
	printf("awdawd\n");
	printf("awdawd\n");

	FillConsoleOutputAttribute(hout, FOREGROUND_GREEN | BACKGROUND_BLUE, 10000000, coord, &check);*/
	
}

void loadSettings()
{
	LPWSTR sizeText = L"0";
	DWORD countSymbols = 0;
	char* check = calloc(50, sizeof(char));
	DWORD data = 0;
	while (TRUE)
	{
		if (RegOpenKeyEx(HKEY_CURRENT_USER, L"cmdSettings\\textSettings", 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS)
		{
			if (RegQueryValueEx(hKey, L"sizeText", 0, &data, check, &countSymbols) == ERROR_FILE_NOT_FOUND)
			{
				RegSetValueEx(hKey, L"sizeText", 0, REG_SZ, sizeText, &countSymbols);
				break;
			}
		}
		else
		{
			RegCreateKeyEx(HKEY_CURRENT_USER, L"cmdSettings\\textSettings", 0, NULL, 0, 0, NULL, &hKey, NULL);
		}
	}
	
}

void textSettings()
{
	int optionTextSettings = 0;
	while (TRUE)
	{
		printf("1 - цвет текста\n2 - размер текста\n3 - шрифт текста\n4 - тип шрифта\n");
		scanf_s("%d", &optionTextSettings);
		switch (optionTextSettings)
		{
		case 1:
			textColor();
			break;
		case 2:
			textSize();
			break;
		case 3:
			textFont();
			break;
		case 4:
			textType();
			break;
		}
	}
}

void textColor()
{
	
}

void textSize()
{

}

void textFont()
{

}

void textType()
{

}


//void saveChanges(HKEY hKey)
//{
//	if (RegOpenKeyEx(HKEY_CURRENT_USER, TEXT("CmdSettings"), 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS)
//	{
//
//	}
//	else
//	{
//		RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("CmdSettings"), 0, NULL, 0, 0, NULL, &hKey, NULL);
//	}
//}
