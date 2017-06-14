#include<stdio.h>
#include"AutoShedding.h"
int main()
{
Time t1,t2,taday;
ls_group grp;
int opt,i;
printf("\nSelect one:\n1.Enter all week time.\n2.Enter One time.\n>");
scanf("%d",&opt);
if(opt==1){
    for(i=1;i<=7;i++){
        grp.day[i].morning[0].minute=0;
        grp.day[i].morning[0].second=0;
        grp.day[i].morning[1].minute=0;
        grp.day[i].morning[1].second=0;
        grp.day[i].night[0].minute=0;
        grp.day[i].night[0].second=0;
        grp.day[i].night[1].minute=0;
        grp.day[i].night[1].second=0;
    }
    for(i=1;i<=7;i++){
        printf("Enter Day(%d)times:\nEnter Morning time:(hh - hh)\n(hh)>",i);
        scanf("%d",&grp.day[i].morning[0].hour);
        printf("to\n(hh) >");
        scanf("%d",&grp.day[i].morning[1].hour);
        printf("Enter Day(%d)times:\nEnter Night time:(hh - hh)\n(hh)>",i);
        scanf("%d",&grp.day[i].night[0].hour);
        printf("to\n(hh) >");
        scanf("%d",&grp.day[i].night[1].hour);
    }
auto_schedule_make_week_time("ls-schedule.ls",grp);
}
else{
printf("Enter least morning time to start loadshedding:");
scanf("%d%d%d",&t1.hour,&t1.minute,&t1.second);
printf("Enter least night time to start loadshedding:");
scanf("%d%d%d",&t2.hour,&t2.minute,&t2.second);
printf("Enter time a day to cut electricity:");
scanf("%d%d%d",&taday.hour,&taday.minute,&taday.second);
auto_schedule_make("ls-schedule.ls",taday,t1,t2);
}
return 0;
}
