#include "head.h"

void getRecord(struct member* mp, struct message* record, int* rn) {
	MYSQL connect = { 0 };
	mysql_init(&connect);
	char buffer[200];
	MYSQL* connection = NULL;
	MYSQL_RES* result = NULL;
	MYSQL_ROW row = { 0 };
	int index = 0;

	connection = mysql_real_connect(&connect, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3308, NULL, 0);

	mysql_query(connection, "select * from message");
	result = mysql_store_result(connection);

    // 결과 처리
    while ((row = mysql_fetch_row(result)) != NULL) {
        if ((mp->id == atoi(row[1])) || (mp->id == atoi(row[2]))) {
            record[index].sender_id = atoi(row[1]);
            record[index].receiver_id = atoi(row[2]);
            strcpy(record[index].content, row[3]);
			strcpy(record[index].reciever, row[4]);
            index++;
			(*rn)++;
        }
    }
	mysql_free_result(result);
	mysql_close(connection);
}