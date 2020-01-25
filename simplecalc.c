#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"simplecalc.h"

int main (int argc, char **argv) {
	char *cmd = NULL, *arg1 = NULL,*arg2 = NULL, *line = NULL;
	size_t lineLength = 1;//???
	FILE *filep;
	if (argc == 3) {
		if (strcmp(argv[1], "-F") != 0)
		{
			printHelp();
			return 1;
		}
		filep = fopen(argv[2], "r");
		getline(&line,&lineLength, filep);

        cmd = strtok(line, " ");
        arg1 = strtok(NULL, " ");
        arg2 = strtok(NULL, " ");

	}else if(argc == 4) {
		cmd = argv[1];
		arg1 = argv[2];
		arg2 = argv[3];
	} else {
		printHelp();
		return 1;
	}

	if (!strcmp(cmd, MULT_COMMAND)) {
		printf("%s * %s = %f\n", arg1, arg2, multiply(atof(arg1),atof(arg2)));
	}else if (!strcmp(cmd, DIV_COMMAND)) {
		printf("%s / %s = %f\n", arg1, arg2,divide(atof(arg1),atof(arg2)));
	}else if (!strcmp(cmd, SUB_COMMAND)) {
		printf("%s - %s = %f\n", arg1, arg2,sub(atof(arg1),atof(arg2)));

	}else if (!strcmp(cmd, ADD_COMMAND)) {
		printf("%s + %s = %f\n", arg1, arg2,add(atof(arg1),atof(arg2)));
	}else{
		printHelp();
		return 1;
	}
}

void printHelp() {
	// TODO maybe a little better than this.
	printf("USAGE: simplecalc COMMAND arg1 arg2\n");
}
double multiply(double num1, double num2) {
	return num1 * num2;
}
double add(double num1, double num2) {
	return num1 + num2;
}
double sub(double num1, double num2) {
	return num1 - num2;
}
double divide(double numerator, double denominator) {
	if (denominator == 0) {
		return INFINITY;
	}
	return numerator/denominator;
}

