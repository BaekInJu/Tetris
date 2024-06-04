#include "head.h"

int update(struct member* mp) {
	MYSQL connect = { 0 };
	mysql_init(&connect);
	char buffer[200];
	MYSQL* connection = NULL;
	MYSQL_RES* result = NULL;
	MYSQL_ROW row = { 0 };

	int id = 0;


	connection = mysql_real_connect(&connect, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3308, NULL, 0);

	mysql_query(connection, "select * from member");
	result = mysql_store_result(connection);

	while ((row = mysql_fetch_row(result)) != NULL) {
		if (!strcmp(mp->email, row[1])) {
			id = atoi(row[0]);
		}
	}
	sprintf(buffer, "UPDATE member SET name = '%s', password = '%s' WHERE id = %d; ", mp->name, mp->pw, id);
	mysql_query(connection, buffer);

	mysql_free_result(result);
	return 1;
}