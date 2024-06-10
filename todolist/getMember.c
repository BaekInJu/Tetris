#include "head.h"

void getMembers(struct member* members, int* rn) {
	MYSQL connect = { 0 };
	mysql_init(&connect);
	char buffer[200];
	MYSQL* connection = NULL;
	MYSQL_RES* result = NULL;
	MYSQL_ROW row = { 0 };
	int index = 0;

	connection = mysql_real_connect(&connect, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3308, NULL, 0);

	mysql_query(connection, "select * from member");
	result = mysql_store_result(connection);

	// 결과 처리
	while ((row = mysql_fetch_row(result)) != NULL) {
		members[index].id = atoi(row[0]);
		strcpy(members[index].email, row[1]);
		strcpy(members[index].name, row[2]);
		index++;
		(*rn)++;
	}
	mysql_free_result(result);
	mysql_close(connection);
}