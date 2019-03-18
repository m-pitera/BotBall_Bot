#include <kipr/botball.h>

int main()
{
    create_connect();
    set_create_total_angle(0);
    set_create_distance(0);
    while (get_create_total_angle() < 90) {
        create_drive_direct(-200, 200);   
    }

    while (get_create_total_angle(90) && get_create_distance() < 100) {
        create_drive_direct(200, 200);
        msleep(3000);
    }
    create_stop();
    create_disconnect();
    return 0;
}
