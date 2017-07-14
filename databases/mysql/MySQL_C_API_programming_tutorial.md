MySQL C API programming tutorial
About this tutorial

This is a C programming tutorial for the MySQL database. It covers the basics of MySQL programming with the C API. You may also consider to look at the MySQL tutorial on ZetCode.
About MySQL database

MySQL is a leading open source database management system. It is a multi user, multithreaded database management system. MySQL is especially popular on the web. It is one of the parts of the very popular LAMP platform. Linux, Apache, MySQL, PHP. MySQL is owned by a swedish company called MySQL AB. This company and Trolltech are prominent open source companies. MySQL database is available on most important OS platforms. It runs under BSD Unix, Linux, Windows or Mac. Wikipedia and YouTube use MySQL. These sites manage millions of queries each day. MySQL comes in two versions. MySQL server system and MySQL embedded system.
First example

Our first example will test one MySQL function call.

#include <my_global.h>
#include <mysql.h>

int main(int argc, char **argv)
{
    printf("MySQL client version: %s\n", mysql_get_client_info());
}

The mysql_get_client_info() shows the MySQL client version.

gcc version.c -o version  `mysql_config --cflags --libs`

Here is how we compile the code example.

$ ./version
MySQL client version: 5.0.38

#include <my_global.h>
#include <mysql.h>

We include necessary header files. mysql.h is the most important header file for MySQL function calls. my_global.h includes some global declarations a functions. Among other thing, it includes the standard input/output header file.

printf("MySQL client version: %s\n", mysql_get_client_info());

This code line outputs the version of the MySQL client. For this, we use the mysql_get_client_info() function call.
Creating a database

The next code example will create a database.

#include <my_global.h>
#include <mysql.h>

int main(int argc, char **argv)
{

    MYSQL *conn;

    conn = mysql_init(NULL);

    if (conn == NULL) {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }

    if (mysql_real_connect(conn, "localhost", "zetcode", 
                "passwd", NULL, 0, NULL, 0) == NULL) {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }

    if (mysql_query(conn, "create database testdb")) {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }


    mysql_close(conn);

}

The code example connects to the MySQL database system and creates a new database called testdb.

mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| testdb             |
    +--------------------+
3 rows in set (0.00 sec)

    This is the proof, that the database was created.

    We include error checking in this example. It is important to check for possible errors. Database programming is a field, where many things might go wrong. For clarity reasons, later examples will be without error checking. I suppose that it is clear for everyone, that it is every programmers responsibility to do error checking.

    The code example can be divided into these parts.

    Initiation of a connection handle structure
    Creation of a connection
    Execution of a query
    Closing of the connection

    MYSQL *conn;

    We declare a pointer to a MYSQL structure. This structure will serve as a connection handler.

    conn = mysql_init(NULL);

    The mysql_init() function obtains a connection handler.

    if (conn == NULL) {
        printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }

We check the return value. If the mysql_init() function fails, we print the error message and terminate the application.


if (mysql_real_connect(conn, "localhost", "zetcode", 
            "passwd", NULL, 0, NULL, 0) == NULL) {
    printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
    exit(1);
}

The mysql_real_connect() function establishes a connection to the database. We provide connection handler, host name, user name and passwor parameters to the function. The other four parameters are the database name, port number, unix socket and finally the client flag.

if (mysql_query(conn, "create database testdb")) {
    printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
    exit(1);
}

The mysql_query() executes the SQL statement. In our case, the statement creates a new database.

mysql_close(conn);

Finally, we close the database connection.
Creating and populating a table

The next code example will create a table and insert some data into it.

#include <my_global.h>
#include <mysql.h>

int main(int argc, char **argv)
{

    MYSQL *conn;

    conn = mysql_init(NULL);
    mysql_real_connect(conn, "localhost", "zetcode", "passwd", "testdb", 0, NULL, 0);

    mysql_query(conn, "CREATE TABLE writers(name VARCHAR(25))");

    mysql_query(conn, "INSERT INTO writers VALUES('Leo Tolstoy')");
    mysql_query(conn, "INSERT INTO writers VALUES('Jack London')");
    mysql_query(conn, "INSERT INTO writers VALUES('Honore de Balzac')");
    mysql_query(conn, "INSERT INTO writers VALUES('Lion Feuchtwanger')");
    mysql_query(conn, "INSERT INTO writers VALUES('Emile Zola')");

    mysql_close(conn);

}

We don't use any new MySQL function call here. We use mysql_query() function call to both create a table and insert data into it.

mysql_real_connect(conn, "localhost", "zetcode", "passwd", "testdb", 0, NULL, 0);

We connect to testdb database. The user name is zetcode and password is passwd.

mysql_query(conn, "CREATE TABLE writers(name VARCHAR(25))");

Here we create a table named writers. It has one varchar column.

mysql_query(conn, "INSERT INTO writers VALUES('Leo Tolstoy')");

We insert one writer name into the writers table.

mysql> show tables;
+------------------+
| Tables_in_testdb |
+------------------+
| writers          |
    +------------------+
1 row in set (0.00 sec)

    We show tables in the database.

    mysql> select * from writers;
    +-------------------+
    | name              |
    +-------------------+
    | Leo Tolstoy       |
    | Jack London       |
    | Honore de Balzac  |
    | Lion Feuchtwanger |
    | Emile Zola        |
    +-------------------+
5 rows in set (0.00 sec)

    We select all data from the table.
    Retrieving data from the database

    In the next example, we will retrieva data from a table.

    Steps:

    Create a connection
    Execute query
    Get the result set
    Fetch all available rows
    Free the result set

#include <my_global.h>
#include <mysql.h>

int main(int argc, char **argv)
{

    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    int num_fields;
    int i;

    conn = mysql_init(NULL);
    mysql_real_connect(conn, "localhost", "zetcode", "passwd", "testdb", 0, NULL, 0);

    mysql_query(conn, "SELECT * FROM writers");
    result = mysql_store_result(conn);

    num_fields = mysql_num_fields(result);

    while ((row = mysql_fetch_row(result)))
    {
        for(i = 0; i < num_fields; i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(conn);

}

The example prints all names from the writers table.

$ ./select
Leo Tolstoy
Jack London
Honore de Balzac
Lion Feuchtwanger
Emile Zola

mysql_query(conn, "SELECT * FROM writers");

We execute the query, that will retrieve all names from the writers database.

result = mysql_store_result(conn);

We get the result set.

num_fields = mysql_num_fields(result);

We get the number of fields in the table.

while ((row = mysql_fetch_row(result)))
{
    for(i = 0; i < num_fields; i++)
    {
        printf("%s ", row[i] ? row[i] : "NULL");
    }
    printf("\n");
}

We fetch the rows and print them to the screen.

mysql_free_result(result);

We free the resources.
Column headers

In the next example, we will retrieve data and show the their column names from the table.

For this, we will create a new table friends.

mysql> create table friends (id int not null primary key auto_increment,
        name varchar(20), age int);

mysql> insert into friends(name, age) values('Tom', 25);
mysql> insert into friends(name, age) values('Elisabeth', 32);
mysql> insert into friends(name, age) values('Jane', 22);
mysql> insert into friends(name, age) values('Luke', 28);

We insert some data into the table.

#include <my_global.h>
#include <mysql.h>

int main(int argc, char **argv)
{

    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL_FIELD *field;

    int num_fields;
    int i;

    conn = mysql_init(NULL);
    mysql_real_connect(conn, "localhost", "zetcode", "passwd", "testdb", 0, NULL, 0);

    mysql_query(conn, "SELECT * FROM friends");
    result = mysql_store_result(conn);

    num_fields = mysql_num_fields(result);

    while ((row = mysql_fetch_row(result)))
    {
        for(i = 0; i < num_fields; i++)
        {
            if (i == 0) {
                while(field = mysql_fetch_field(result)) {
                    printf("%s ", field->name);
                }
                printf("\n");
            }
            printf("%s  ", row[i] ? row[i] : "NULL");
        }
    }
    printf("\n");

    mysql_free_result(result);
    mysql_close(conn);
}

The example is similar to the previous one. It just adds column header names to it.

while(field = mysql_fetch_field(result)) {
    printf("%s ", field->name);
}

The mysql_fetch_field() call returns a MYSQL_FIELD structure. We get the column header names from this structure.

$ ./headers
id name age
1  Tom  25
2  Elisabeth  32
3  Jane  22
4  Luke  28

And this is the output of our program.
Inserting images into MySQL database

Some people prefer to put their images into the database, some prefer to keep them on the file system for their applications. Technical difficulties arise when we work with millions of images. Images are binary data. MySQL database has a special data type to store binary data called BLOB (Binary Large Object).

mysql> describe images;
+-------+------------+------+-----+---------+-------+
| Field | Type       | Null | Key | Default | Extra |
+-------+------------+------+-----+---------+-------+
| id    | int(11)    | NO   | PRI |         |       |
| data  | mediumblob | YES  |     | NULL    |       |
    +-------+------------+------+-----+---------+-------+
2 rows in set (0.00 sec)

    This is the table, that we will use in our example. It can be created by the following SQL statement.

    create table images(id int not null primary key, data mediumblob);

#include <my_global.h>
#include <mysql.h>

int main(int argc, char **argv)
{
    MYSQL *conn;

    int len, size;
    char data[1000*1024];
    char chunk[2*1000*1024+1];
    char query[1024*5000];

    FILE *fp;

    conn = mysql_init(NULL);
    mysql_real_connect(conn, "localhost", "zetcode", "passwd", "testdb", 0, NULL, 0);

    fp = fopen("image.png", "rb");
    size = fread(data, 1, 1024*1000, fp);

    mysql_real_escape_string(conn, chunk, data, size);

    char *stat = "INSERT INTO images(id, data) VALUES('1', '%s')";
    len = snprintf(query, sizeof(stat)+sizeof(chunk) , stat, chunk);

    mysql_real_query(conn, query, len);

    fclose(fp);
    mysql_close(conn);
}

In this example, we will insert one image into the images table. The image can be max 1 MB.

fp = fopen("image.png", "rb");
size = fread(data, 1, 1024*1000, fp);

Here we open the image and read it into the data array.

mysql_real_escape_string(conn, chunk, data, size);

Binary data can obtain special characters, that might cause troubles in the statements. We must escape them. The mysql_real_escape_string() puts the encoded data into the chunk array. In theory, every character might be a special character. That's why the chunk array two times as big as the data array. The function also adds a terminating null character.

char *stat = "INSERT INTO images(id, data) VALUES('1', '%s')";
len = snprintf(query, sizeof(stat)+sizeof(chunk) , stat, chunk);

These two code lines prepare the MySQL query.

mysql_real_query(conn, query, len);

Finally, we execute the query.
Selecting images from MySQL database

In the previous example, we have inserted an image into the database. In the following example, we will select the inserted image back from the database.

#include <my_global.h>
#include <mysql.h>

int main(int argc, char **argv)
{
    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;

    unsigned long *lengths;
    FILE *fp;

    conn = mysql_init(NULL);
    mysql_real_connect(conn, "localhost", "zetcode", "passwd", "testdb", 0, NULL, 0);

    fp = fopen("image.png", "wb");

    mysql_query(conn, "SELECT data FROM images WHERE id=1");
    result = mysql_store_result(conn);

    row = mysql_fetch_row(result);
    lengths = mysql_fetch_lengths(result);

    fwrite(row[0], lengths[0], 1, fp);
    mysql_free_result(result);

    fclose(fp);
    mysql_close(conn);
}

In this example, we will create an image file from the database.

fp = fopen("image.png", "wb");

We open a file for writing.

mysql_query(conn, "SELECT data FROM images WHERE id=1");

We select an image with id 1.

row = mysql_fetch_row(result);

The row contains raw data.

lengths = mysql_fetch_lengths(result);

We get the length of the image.

fwrite(row[0], lengths[0], 1, fp);

We create the image file using the fwrite() standard function call.
