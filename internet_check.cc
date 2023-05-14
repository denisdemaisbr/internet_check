#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <wininet.h>

int main(int argc, char **argv) {
	int vflag = 0;
	int eflag = 0;
	int c;

	DWORD flags;
	int rc;
	BOOL isConnected;

	setbuf(stdout, NULL);

	while ((c = getopt (argc, argv, "hev")) != -1) {
		switch (c) {
			case 'h': 
				printf("internet check, v1.0\n");
				printf("https://github.com/denisdemaisbr/internet_check\n");
				printf("usage:\n");
				printf("\t-h = this help\n");
				printf("\t-v = verbose\n");
				printf("\t-e = extended code\n");
				printf("\n");
				printf("BUILD: %s %s\n", __DATE__, __TIME__);
				#ifdef __GNUC__
				printf("GCC: %d.%d\n", __GNUC__, __GNUC_MINOR__);
				#endif
				printf("\n\n");
				exit(0);
			case 'v': vflag=1; break;
			case 'e': eflag=1; break;
			default:
				abort();
		}
	}

	isConnected = InternetGetConnectedState(&flags, 0);
	rc = (isConnected) ? 1 : 0;

	if (vflag)
	printf("%s", (rc == 1) ? "online" : "offline");

	if (eflag)
	rc = (argc == 1) ? 1 : flags;

	exit(rc);
}
