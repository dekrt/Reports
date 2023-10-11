#undef UNICODE
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string>


int i = 0;
std::string name[5] = { "0","1","2","3","4" };
int a[5] = { 1,1,1,1,1 };
int random(void) {
	int a = time(NULL);
	srand(a);
	return (rand() % 400 + 100);
}
//���̺߳���  
DWORD WINAPI philosopher(LPVOID lpParam) {
	srand((unsigned)time(NULL));
	int id = i++;
	int time;
	HANDLE chops[2];
	chops[0] = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, name[id].c_str());
	chops[1] = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, name[(id + 4) % 5].c_str());
	while (1) {
		time = random();
		printf("��ѧ��%d��ʼ˼������˼��%dms\n", id, time);
		Sleep(time);
		time = random();
		printf("��ѧ��%d��ʼ��Ϣ������Ϣ%dms\n", id, time);
		Sleep(time);
	
		//p
		WaitForMultipleObjects(2, chops, true, INFINITE);//true����ֻ�еȴ������ź�����Чʱ��������ִ�С���FALSE ��������һ���ź�����Чʱ������ִ�У�
		printf("��ѧ��%dͬʱȡ�����ߵĿ���\t%d��%d\n", id, id, (id + 4) % 5);

		//�Է�
		time = random();
		printf("��ѧ��%d��ʼ�Է������Է�%dms\n", id, time);
		Sleep(time);

		//v
		ReleaseSemaphore(chops[0], 1, NULL);
		printf("��ѧ��%d�������ֱߵĿ���\t%d\n", id, id);
		ReleaseSemaphore(chops[1], 1, NULL);
		printf("��ѧ��%d�������ֱߵĿ���\t%d\n", id, (id + 4) % 5);
	}
}
int main(void) {
	HANDLE S[5]; //����ź���
	HANDLE hThread[5]; //����߳�
	for (int i = 0; i < 5; i++) {
		S[i] = CreateSemaphore(NULL, 1, 1, name[i].c_str());
	}

	for (int i = 0; i < 5; i++) {
		hThread[i] = CreateThread(NULL, 0, philosopher, NULL, 0, NULL);
	}
	WaitForMultipleObjects(5, hThread, TRUE, INFINITE); 	//�ȴ����߳����� 
	for (int i = 0; i < 5; i++) {
		CloseHandle(S[i]);
	}
}


