#include "head.h"

int login(struct member *mp) {
	MYSQL connect = { 0 };
	mysql_init(&connect);
	char buffer[200];
	MYSQL* connection = NULL;
	MYSQL_RES* result = NULL;
	MYSQL_ROW row = { 0 };


	connection = mysql_real_connect(&connect, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3308, NULL, 0);

	mysql_query(connection, "select * from member");
	result = mysql_store_result(connection);

	while ((row = mysql_fetch_row(result)) != NULL) {
		if (!strcmp(mp->email, row[1])) {
			if (!strcmp(mp->pw, row[3])) {
				mp->id = atoi(row[0]);
				strcpy(mp->name, row[2]);
				return 1;
			}
			else {
				return 3;
			}
		}
	}
	return 2;
	mysql_free_result(result);
	mysql_close(connection);
}