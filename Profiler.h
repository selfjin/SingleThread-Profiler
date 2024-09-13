#pragma once


#include <iostream>
#include <map>
#include <Windows.h>

struct Profile_Data
{
	std::string st_TagName;

	LARGE_INTEGER st_StartTime;		// �������� ���� ��

	__int64 st_TotalTime;			// ��ü �ҿ��� �ð�
	__int64 st_Min[2];				// �ּ� ���� �� 2��
	__int64 st_Max[2];				// �ִ� ���� �� 2��

	__int64 st_Call;				// ��ü �� Ƚ��
};

class ProfileManager
{
public:

	static ProfileManager& GetInstance();

	//---------------------------------------------------------------------/
	//							���� ���� �Լ�
	//--------------------------------------------------------------------/
	void ProfileBegin(std::string tagName);
	void ProfileEnd(std::string tagName);

	//---------------------------------------------------------------------/
	//						    ��� ���� �Լ�
	//--------------------------------------------------------------------/
	void Log(std::string tagName);

	//---------------------------------------------------------------------/
	//						    ���� ���� �Լ�
	//--------------------------------------------------------------------/

	~ProfileManager(); // �Ҹ��ڿ��� ����ȭ ó��
private:
	std::map<std::string, Profile_Data> _ProfileMap;
};

