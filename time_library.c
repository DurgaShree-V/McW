/* Time library */
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main()
{
    time_t now = time(NULL);            // Provide current time
    printf("Now: %ld\n",now);

    sleep(2);                           // Sleep for 2 seconds

    time_t two_sec = time(NULL);
    printf("After 2 sec: %ld\n",two_sec);

    double diff = difftime(two_sec,now);
    printf("Difference between current and after two seconds: %f\n",diff);

    char *string_now = ctime(&now);     // O/P : Tue Dec 31 15:54:29 2024
    printf("Current time: %s\n",string_now);

    struct tm *gm_time =  gmtime(&now);
    printf("tm_sec: %d\n",gm_time -> tm_sec);
    printf("tm_min: %d\n",gm_time -> tm_min);
    printf("tm_hour: %d\n",gm_time -> tm_hour);
    printf("tm_mon: %d\n",gm_time -> tm_mon);
    printf("tm_mday: %d\n",gm_time -> tm_mday);
    printf("tm_year: %d\n",gm_time -> tm_year);
    printf("tm_wday: %d\n",gm_time -> tm_wday);
    printf("tm_yday: %d\n",gm_time -> tm_yday);
    printf("tm_isdst: %d\n",gm_time -> tm_isdst);

    printf("\nLocal time\n-------------\n");
    struct tm *curr_time = localtime(&now);
    printf("tm_sec: %d\n",curr_time -> tm_sec);
    printf("tm_min: %d\n",curr_time -> tm_min);
    printf("tm_hour: %d\n",curr_time -> tm_hour);
    printf("tm_mon: %d\n",curr_time -> tm_mon);
    printf("tm_mday: %d\n",curr_time -> tm_mday);
    printf("tm_year: %d\n",curr_time -> tm_year);
    printf("tm_wday: %d\n",curr_time -> tm_wday);
    printf("tm_yday: %d\n",curr_time -> tm_yday);
    printf("tm_isdst: %d\n",curr_time -> tm_isdst);

    char *other_string =asctime(curr_time); 
    printf("%s\n",other_string);

    curr_time->tm_sec = curr_time->tm_sec + 1;
    time_t new_time = mktime(curr_time);
    printf("Now : %ld\n",now);
    printf("New_time: %ld\n",new_time);

    char s[100];
    strftime(s,100,"%A %B %d", curr_time);
    printf("\nFormatted time: %s\n",s);
}
