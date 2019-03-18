#include <kipr/botball.h>

int main()
{
    create_connect();
    get_create_rlightbump();
    get_create_llightbump();
    set_create_total_angle(0);
    set_create_distance(0);
    while (get_create_total_angle() < 90) {
        create_drive_direct(-200, 200);   
    }

    create_drive_direct(200, 200);
    while (!get_create_rlightbump() && !get_create_llightbump());
    
    create_stop();
    create_disconnect();
    return 0;
}
