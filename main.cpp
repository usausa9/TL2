#include <cstdio>
#include <cstdlib>

int main(int argc, char* argv[])
{
	// argv‚Ì”‚¾‚¯‚­‚è‚©‚¦‚·
	for (int i = 0; i < argc; i++)
	{
		// •¶š—ñ‚Ìi”Ô‚ğ•\¦
		printf(argv[i]);
		printf("\n");
	}

	system("pause");
	return 0;
}