#ifndef _Hall_h
#define _Hall_h

#define hallPin 14

class HALL{
  public:
    int Read_HALL;
  public:
    void InitHALL(void);
    int ReadHALL(void);
};

#endif