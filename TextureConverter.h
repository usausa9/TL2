#pragma once
#include <DirectXTex.h>
#include <vector>
#include <string>

// �e�N�X�`���R���o�[�^�[
class TextureConverter
{
public:
	/// <summary>
	/// �e�N�X�`����WIC����DDS�ɕϊ�����
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void ConvertTextureWICToDDS(const std::string& filePath);

private:
	/// <summary>
	/// �e�N�X�`���t�@�C���ǂݍ���
	/// </summary>
	/// <param name="filePath">�t�@�C��</param>
	void LoadWICTextureFromFile(const std::string& filePath);

	/// <summary>
	/// �}���`�o�C�g����������C�h������ɕϊ�
	/// </summary>
	/// <param name="mString">�}���`�o�C�g������</param>
	/// <returns>���C�h������</returns>
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);

	/// <summary>
	/// �t�H���_�p�X�ƃt�@�C�����𕪗�����
	/// </summary>
	/// <param name="filePath">�t�@�C���p�X</param>
	void SeparateFilePath(const std::wstring& filePath);

private:
	// �摜�̏��
	DirectX::TexMetadata metadata_;
	// �摜�C���[�W�̃R���e�i
	DirectX::ScratchImage scratchImage_;

	// �f�B���N�g���p�X
	std::wstring directoryPath_;
	// �t�@�C����
	std::wstring fileName_;
	// �t�@�C���g���q
	std::wstring fileExt_;
};

