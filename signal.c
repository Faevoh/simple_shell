#include "main.h"

/**
 * handle_segmfault - handle segmentaion fault
 * @signo: the signal number
 */
void handle_segmfault(int signo __attribute__((unused)))
{
	exit(1);
}
