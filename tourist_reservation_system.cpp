#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

char adminf[20] = "Trip.txt";
char userf[20] = "Reservation.txt";

struct tour{
    char ad_place[20], ad_code[20], ad_country[20], ad_days[20], ad_prices[20];
    char us_phone[20], us_name[20], us_people[20], us_date[20], us_status[20], us_dcode[20];
};

class Tourist{
    public:
      void ad_pack(tour r);
      tour ad_unpack(char a[]);
      void ad_writedata();
      void ad_display();
      void ad_modify();
      void us_pack(tour r);
      tour us_unpack(char a[]);
      void us_writedata();
      void us_display();
      void us_search();
      void us_modify();
};

// ADMIN PANEL
void Tourist::ad_pack(tour r){
    fstream fp;
    fp.open(adminf,ios::out|ios::app);
    if(!fp){
        cout << "\nCannot open file";
        exit (0);
    }
    char buff[45];
    strcpy(buff,r.ad_code);
    strcat(buff,"|");
    strcat(buff,r.ad_place);
    strcat(buff,"|");
    strcat(buff,r.ad_country);
    strcat(buff,"|");
    strcat(buff,r.ad_days);
    strcat(buff,"|");
    strcat(buff,r.ad_prices);
    strcat(buff,"|");	
    for (int i = 0; i < 45-strlen(buff); i++)
        strcat(buff, "|");
    fp<<buff<<endl;
    fp.close();
}

tour Tourist::ad_unpack(char buff[]){
    tour r;
    int i = 0 , j = 0;
    while(buff[j] !='|')
        r.ad_code[i++]=buff[j++];
    r.ad_code[i]='\0';
    i=0;
    j++;
    while(buff[j] !='|')
        r.ad_place[i++]=buff[j++];
    r.ad_place[i]='\0';
    i=0;
    j++;
    while(buff[j] !='|')
        r.ad_country[i++]=buff[j++];
    r.ad_country[i]='\0';
    i=0;
    j++;
    while(buff[j] !='|')
        r.ad_days[i++]=buff[j++];
    r.ad_days[i]='\0';
    i=0;
    j++;
    while(buff[j] !='|')
        r.ad_prices[i++]=buff[j++];
    r.ad_prices[i]='\0';
    return (r);
}

void Tourist::ad_writedata(){
    tour s;
    cout << "Enter the Destination Code\nD-";
    cin >> s.ad_code;
    cout << "Enter the Destination Place\n";
    cin >> s.ad_place;
    cout << "Enter the Country of the Destination\n";
    cin >> s.ad_country;
    cout << "Enter the Number of the days of the Trip\n";
    cin >> s.ad_days;
    cout << "Enter the Cost of the trip\n";
    cin >> s.ad_prices;
    ad_pack(s);
}
