#include <iostream>
using namespace std;

class Angle
{
       int degree;
       float min;
       char dir;

public:
       Angle() : degree(0), min(0), dir(0) {}
       Angle(int de, float mi, char an) : degree(de), min(mi), dir(an) {}

       //set_angle(int, float, char);
       void display();
};

class Ship
{
       int serial_no;
       static int num;
       Angle lattitude, longitude;

public:
       Ship();
       int get_serial();
       void set_ship_direction(Angle, Angle);
       void display_angle();
};
int Ship::num = 0;

Angle set_A();

int main()
{
       Angle lat, longi;
       Ship S1, S2, S3;
       cout << "Ship #" << S1.get_serial() << endl;
       cout << " Enter the Lattitude\n";
       lat = set_A();
       cout << " Enter the Longitude \n";
       longi = set_A();
       S1.set_ship_direction(lat, longi);
       cin.clear();
       cout << "Ship #" << S2.get_serial() << endl;
       cout << " Enter the Lattitude\n";
       lat = set_A();
       cout << " Enter the Longitude \n";
       longi = set_A();
       S2.set_ship_direction(lat, longi);
       cin.clear();
       cout << "Ship #" << S3.get_serial() << endl;
       cout << " Enter the Lattitude\n";
       lat = set_A();
       cout << " Enter the Longitude \n";
       longi = set_A();
       S3.set_ship_direction(lat, longi);

       S1.display_angle();
       S2.display_angle();
       S3.display_angle();
       system("pause");
}
void Angle::display()
{
       //cout << "Ship #" << serial_no << endl;
       cout << degree << "\xF8" << min << "\' " << dir << endl;
}
Ship::Ship()
{
       num++;
       serial_no = num;
}
void Ship::set_ship_direction(Angle la, Angle lon)
{
       lattitude = la;
       longitude = lon;
}
void Ship::display_angle()
{
       cout << "Ship #" << serial_no << endl;
       cout << "  Lattitude :";
       lattitude.display();
       cout << "  Longitude :";
       longitude.display();
}
Angle set_A()
{
       int d;
       float m;
       char a;
       cout << "   Degree :";
       while (!(cin >> d))
       {
              cin.clear();
              cin.ignore(900, '\n');
              cout << "  Again Enter the Degree:";
       }

       cout << "   Minuties :";
       while (!(cin >> m))
       {
              cin.clear();
              cin.ignore(900, '\n');
              cout << "  Again Enter the Minutes:";
       }
       cout << "   Direction :";
       while (!(cin >> a))
       {
              cin.clear();
              cin.ignore(900, '\n');
              cout << "  Again Enter the Direction:";
       }
       return Angle(d, m, a);
}
int Ship::get_serial()
{
       return serial_no;
}
