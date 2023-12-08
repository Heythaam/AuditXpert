#include "connection.h"

connection::connection()
{

}

bool connection::createconnection()
{
db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("Source_ProjetQt");
db.setUserName("Heytham");
db.setPassword("esprit18");

if (db.open()) {test=true;}

return test;
}

void connection::closeConnection() {db.close();}
