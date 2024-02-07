#pragma once

class Date {
    unsigned short day;
    unsigned short month;
    long long year;
public:
    Date();
    Date(unsigned short day, unsigned short month, long long year);
    Date(unsigned short day, unsigned short month);

    void PrintDate() const;

    void SetDay(unsigned short day);
    void SetMonth(unsigned short month);
    void SetYear(long long year);

    unsigned short GetDay() const;
    unsigned short GetMonth() const;
    long long GetYear() const;
};

