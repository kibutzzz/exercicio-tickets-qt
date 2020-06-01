#ifndef TICKET_H
#define TICKET_H

#include <QDateTime>

class Ticket
{
private:
    int id;
    QDateTime data;

    static int nextId;


public:
    Ticket();
    int getId() const;
    QDateTime getData() const;

};

#endif // TICKET_H
