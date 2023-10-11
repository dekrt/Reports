#include <Windows.h>
#include <iostream>
#include <thread>
#include <chrono>

#define BUFFER_SIZE 10

CRITICAL_SECTION g_csBuffer;
int g_Buffer[BUFFER_SIZE] = {0};
int g_nCount = 0;

HANDLE g_hSemProd1;
HANDLE g_hSemProd2;
HANDLE g_hSemCons;

void PrintBuffer()
{
	std::cout << "Buffer Status: ";
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		if (g_Buffer[i] == 0)
		{
			std::cout << "[    ]";
		}
		else
		{
			std::cout << "[" << g_Buffer[i] << "]";
		}
	}
	std::cout << std::endl;
}

DWORD WINAPI ProducerThread(LPVOID lpParam)
{
	int nProducerID = *(int *)lpParam;
	int nStartNum = nProducerID * 1000;
	srand(GetCurrentThreadId());

	while (true)
	{
		int nData = nStartNum + rand() % 1000;
		Sleep(rand() % 901 + 100); // 等待100ms-1s
		EnterCriticalSection(&g_csBuffer);
		if (g_nCount == BUFFER_SIZE)
		{
			LeaveCriticalSection(&g_csBuffer);
			if (nProducerID == 1)
			{
				WaitForSingleObject(g_hSemProd1, INFINITE);
			}
			else
			{
				WaitForSingleObject(g_hSemProd2, INFINITE);
			}
		}
		else
		{
			g_Buffer[g_nCount] = nData;
			g_nCount++;
			std::cout << "Producer " << nProducerID << " produced data: " << nData << std::endl;
			PrintBuffer();
			LeaveCriticalSection(&g_csBuffer);
			ReleaseSemaphore(g_hSemCons, 1, NULL);
		}
	}
	return 0;
}

DWORD WINAPI ConsumerThread(LPVOID lpParam)
{
	int nConsumerID = *(int *)lpParam;
	srand(GetCurrentThreadId());

	while (true)
	{
		Sleep(rand() % 901 + 100); // 等待100ms-1s
		EnterCriticalSection(&g_csBuffer);
		if (g_nCount == 0)
		{
			LeaveCriticalSection(&g_csBuffer);
			WaitForSingleObject(g_hSemCons, INFINITE);
		}
		else
		{
			int nData = g_Buffer[0];
			for (int i = 0; i < g_nCount - 1; i++)
			{
				g_Buffer[i] = g_Buffer[i + 1];
			}
			g_Buffer[g_nCount - 1] = 0;
			g_nCount--;
			std::cout << "Consumer " << nConsumerID << " consumed data: " << nData << std::endl;
			PrintBuffer();
			LeaveCriticalSection(&g_csBuffer);
			if (nData >= 1000 && nData <= 1999)
			{
				ReleaseSemaphore(g_hSemProd1, 1, NULL);
			}
			else
			{
				ReleaseSemaphore(g_hSemProd2, 1, NULL);
			}
		}
	}
	return 0;
}

int main()
{
	InitializeCriticalSection(&g_csBuffer);
	g_hSemProd1 = CreateSemaphore(NULL, BUFFER_SIZE, BUFFER_SIZE, NULL);
	g_hSemProd2 = CreateSemaphore(NULL, BUFFER_SIZE, BUFFER_SIZE, NULL);
	g_hSemCons = CreateSemaphore(NULL, 0, BUFFER_SIZE, NULL);
	int nProd1ID = 1, nProd2ID = 2, nCons1ID = 1, nCons2ID = 2, nCons3ID = 3;
	HANDLE hProd1 = CreateThread(NULL, 0, ProducerThread, &nProd1ID, 0, NULL);
	HANDLE hProd2 = CreateThread(NULL, 0, ProducerThread, &nProd2ID, 0, NULL);
	HANDLE hCons1 = CreateThread(NULL, 0, ConsumerThread, &nCons1ID, 0, NULL);
	HANDLE hCons2 = CreateThread(NULL, 0, ConsumerThread, &nCons2ID, 0, NULL);
	HANDLE hCons3 = CreateThread(NULL, 0, ConsumerThread, &nCons3ID, 0, NULL);

	WaitForSingleObject(hProd1, INFINITE);
	WaitForSingleObject(hProd2, INFINITE);
	WaitForSingleObject(hCons1, INFINITE);
	WaitForSingleObject(hCons2, INFINITE);
	WaitForSingleObject(hCons3, INFINITE);

	CloseHandle(hProd1);
	CloseHandle(hProd2);
	CloseHandle(hCons1);
	CloseHandle(hCons2);
	CloseHandle(hCons3);
	CloseHandle(g_hSemProd1);
	CloseHandle(g_hSemProd2);
	CloseHandle(g_hSemCons);
	DeleteCriticalSection(&g_csBuffer);

	return 0;
}
