#include <cstdio>
#include <cstdlib>
#include <cstdint>

#include <DirectXTex.h>

#include "TextureConverter.h"

// コマンドライン引数
enum Argument
{
	kApplicationPath,	// アプリケーションのパス
	kFilePath,			// 渡されたファイルのパス

	NumArgument
};

int main(int argc, char* argv[])
{
	// コマンドライン引数指定無し
	if (argc < NumArgument)
	{
		// 使用方法の表示
		TextureConverter::OutputUsage();
		return 0;
	}

	// COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	// テクスチャコンバータ
	TextureConverter converter;

	// オプションの数
	int numOptions = argc - NumArgument;
	// オプション配列 (ダブルポインタ)
	char** options = argv + NumArgument;

	// テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath], numOptions, options);

	// COMライブラリの終了
	CoUninitialize();

	// ファイル事にキー入力を無くす場合はコメントアウト
	//system("pause");
	return 0;
}