#pragma once
#include "../FileControl.h"

//�ړI	:x��y�����ꂼ��̃`�b�v�������߂�
//����	:T *x
//		:T *y
//		:FileName
template<typename T>
int fileControl::GetMapSizeForTxt(T* x, T* y, std::string FileName, char countChar)
{
	char checkChar;
	int lineSize = 0;	//	�s���Ƃ̃t�@�C���̑傫��
	int filePos = 0;	// �t�@�C���̈ʒu

	std::fstream fs(FileName, std::ios_base::in);

	// �t�@�C���̓ǂݍ��݂ɐ���
	if (fs)
	{
		// 1�s���̃T�C�Y���擾
		std::string line;
		getline(fs, line);
		lineSize = (int)(fs.tellg());
		fs.seekp(0, std::ios::beg);
		// x���̃}�b�v�`�b�v���擾
		while (lineSize > filePos)
		{
			// ���݂̓ǂݎ��ʒu���擾
			// �ꕶ�����ǂݍ���
			fs.read(&checkChar, 1);
			filePos = (int)(fs.tellg());

			fs.seekp(fs.tellp());

			// ","���Ȃ����m�F����
			if (checkChar == countChar)
			{
				(*x)++;
			}
		}
		// �t�@�C���������ʒu�ɖ߂�
		fs.seekp(0, std::ios::beg);
		// y���̃}�b�v�`�b�v���擾
		// �t�@�C���̏I�[
		while (!fs.eof())
		{
			getline(fs, line);
			lineSize = line.length();
			filePos += lineSize;
			fs.seekp(fs.tellp());
			(*y)++;
		}
		fs.close();
		return 0;
	}
	return -1;
}

template<typename T>
int fileControl::LoadMapDataForTxt(T size_x, T size_y, T* mapChipData, std::string FileName, char checkChar)
{
	int lineSize = 0;	// �s�̑傫��

	std::fstream fs(FileName, std::ios_base::in);
	// false:�t�@�C���ǂݍ��ݎ��s
	if (!fs.bad())
	{

		fs.seekp(0, std::ios::beg);


		for (int y = 0; y < size_y; y++)
		{
			int strPos = 0;
			// 1�s���̃T�C�Y���擾
			std::string line;
			std::string getChipID;

			getline(fs, line);
			lineSize = (int)(fs.tellg());

			for (int x = 0; x < size_x; x++)
			{
				while (line[strPos] != checkChar)
				{
					getChipID.push_back(line[strPos]);
					strPos++;
				}
				strPos++;
				(*mapChipData) = stoi(getChipID);
				*mapChipData++;
				getChipID = "\0";
			}

			fs.seekp(fs.tellp());
		}

		return 0;
		fs.close();
	}
	return -1;
}
