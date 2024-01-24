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
	assert(argc >= NumArgument);

	// COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	// テクスチャコンバータ
	TextureConverter converter;

	// テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	// COMライブラリの終了
	CoUninitialize();

	// ファイル事にキー入力を無くす場合はコメントアウト
	//system("pause");
	return 0;
}