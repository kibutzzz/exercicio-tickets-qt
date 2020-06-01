#include "ticket.h"

int Ticket::nextId = 1;

Ticket::Ticket() : id(Ticket::nextId++)
{
    data = QDateTime::currentDateTime();
}

int Ticket::getId() const
{
    return id;
}

QDateTime Ticket::getData() const
{
    return data;
}
