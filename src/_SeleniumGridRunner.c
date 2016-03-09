/*
 ============================================================================
 Name        : _SeleniumGridRunner.c
 Author      : Ivan Klymchuk
 Version     : 1.0
 Description : Selenium Grid runner in Docker container
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * @param:
 * 		argv[1] = count of firefox nodes
 * 		argv[2] = count of chrome nodes
 * 		argv[3] = path to the docker-compose.yml
 */
int main(int argc, char *argv[]) {

	if (argc == 4) {

		char *strcat(char *dest, const char *src);

		 FILE *fp;
		 char path[1035];

		  char _command [256];
		  strcpy(_command, "cd ");
			  strcat(_command, argv[3]);
			  strcat(_command, "; ");
			  strcat(_command, "docker-compose ");
			  strcat(_command, "scale ");
			  strcat(_command, "nodeff=");
			  strcat(_command, argv[1]);
			  strcat(_command, " ");
			  strcat(_command, "nodechrome=");
			  strcat(_command, argv[2]);

		  printf(_command);
		  printf("\n");

		  //Open the command for reading.
		  fp = popen(_command, "r");
		  if (fp == NULL) {
			printf("Failed to run command\n" );
			exit(1);
		  }

		  //Read the output a line at a time - output it.
		  while (fgets(path, sizeof(path)-1, fp) != NULL) {
			printf("%s", path);
		  }

		  //close
		  pclose(fp);

		  return 0;
	} else {
		printf("You should fill all paramethers \n" );
		exit(1);
	}
}
