#include <arduino.h>
#include <my_Wave.h>

my_Wave wave(48,49);

void setup()
{

}
void loop()
{
    wave.getDistance();
    delay(500);
}