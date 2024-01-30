#include <cstdio>
#include <cstdlib>
#include <cstdint>

#include <DirectXTex.h>

#include "TextureConverter.h"

// �R�}���h���C������
enum Argument
{
	kApplicationPath,	// �A�v���P�[�V�����̃p�X
	kFilePath,			// �n���ꂽ�t�@�C���̃p�X

	NumArgument
};

int main(int argc, char* argv[])
{
	// �R�}���h���C�������w�薳��
	if (argc < NumArgument)
	{
		// �g�p���@�̕\��
		TextureConverter::OutputUsage();
		return 0;
	}

	// COM���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	// �e�N�X�`���R���o�[�^
	TextureConverter converter;

	// �I�v�V�����̐�
	int numOptions = argc - NumArgument;
	// �I�v�V�����z�� (�_�u���|�C���^)
	char** options = argv + NumArgument;

	// �e�N�X�`���ϊ�
	converter.ConvertTextureWICToDDS(argv[kFilePath], numOptions, options);

	// COM���C�u�����̏I��
	CoUninitialize();

	// �t�@�C�����ɃL�[���͂𖳂����ꍇ�̓R�����g�A�E�g
	//system("pause");
	return 0;
}