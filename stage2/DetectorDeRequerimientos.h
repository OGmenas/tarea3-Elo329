#ifndef DETECTORDEREQUERIMIENTOS_H_
#define DETECTORDEREQUERIMIENTOS_H_

class DetectorDeRequerimientos
{
private:
    bool status;
public:
    DetectorDeRequerimientos();
    bool isON();
    void setOn();
    void setOff();
};

#endif