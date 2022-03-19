#ifndef FMVIEWCONTROLLER_H
#define FMVIEWCONTROLLER_H

class FMViewController
{
private:
    static FMViewController* _Ins;;
public:
    static FMViewController* Instance()
    {
        return _Ins;
    }

};

#endif // FMVIEWCONTROLLER_H
