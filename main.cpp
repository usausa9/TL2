#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv[])
{
	// argv�̐��������肩����
	for (int i = 0; i < argc; i++)
	{
		// �������i�Ԃ�\��
		printf(argv[i]);
		printf("\n");
	}

	system("pause");
	return 0;
}