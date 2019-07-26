#ifndef IDISPLAYELEMENT_H
#define IDISPLAYELEMENT_H
class IDisplayElement
{
public:
    IDisplayElement() {}
    virtual ~IDisplayElement() {}
    virtual void display() const = 0;
};
#endif