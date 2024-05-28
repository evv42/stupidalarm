#include <time.h>
#include <stdio.h>
#include <stdlib.h>/*atoi*/
#include <unistd.h>/*sleep*/

int main(int argc, char** argv){
	time_t ep;
	struct tm* cal;
	signed char a_hour, a_min;

	if(argc>2){/*if alarm values were properly set, transfer them, otherwise we set a_hour to -1*/
		a_hour = atoi(argv[1]);
		a_min = atoi(argv[2]);
		if( !(a_hour>=0 && a_hour<=23 && a_min>=0 && a_min <=59) )a_hour = -1;
	}else{
		a_hour = -1;
	}
	while(1){
		ep = time(NULL);
		cal = localtime(&ep);
		printf("Time is %02d:%02d. ",cal->tm_hour,cal->tm_min);
		if(a_hour >= 0){
			printf("Alarm set to %02d:%02d. ",a_hour,a_min);
			/*this will ring the system bell (if possible) every second, and set a message confirming that the alarm did trigger*/
			if(a_hour == cal->tm_hour && a_min == cal->tm_min)printf("(Alarm triggered)\a");
		}
		printf("\r");
		fflush(stdout);
		sleep(1);/*can be modified if wanted, will affect ring interval and time refresh*/
	}
}
